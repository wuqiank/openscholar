<?php
/**
 * @file os_solr_search_more_like_this.inc
 *
 * Display content similar to the current node the user watching.
 */
class os_solr_search_more_like_this extends os_boxes_default {

  /**
   * Implements of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['num_results'] = 5;
    $options['mlt_type_filters'] = array();
    $options['results_from_type'] = TRUE;
    $options['mlt_fl'] = array('label');

    return $options;
  }

  /**
   * Implements of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $form = parent::options_form($form_state);
    $this->options = ($this->options) ? array_merge($this->options_defaults(), $this->options) : $this->options_defaults();

    $form['num_results'] = array(
      '#type' => 'textfield',
      '#title' => t('Results number'),
      '#description' => t('Define hoe much results should the block display.'),
      '#default_value' => $this->options['num_results'],
    );

    $form['mlt_fl'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Fields for finding related content'),
      '#description' => t('Choose the fields to be used in calculating similarity.'),
      '#options' => array(
        'label' => t('Title'),
        'content' => t('The full content  of the posts(body)'),
        'taxonomy_names' => t('Taxonomy names'),
      ),
      '#default_value' => $this->options['mlt_fl'],
      '#required' => TRUE,
    );

    $form['results_from_type'] = array(
      '#type' => 'checkbox',
      '#title' => t('Related posts must be of the same type as the post being viewed.'),
      '#default_value' => $this->options['results_from_type'],
    );

    $form['mlt_type_filters'] = array(
      '#type' => 'select',
      '#title' => t('Node types'),
      '#description' => t('Select which node types to display'),
      '#element_validate' => array('os_search_solr_more_like_this_bundles_element_validate'),
      '#options' => array('all' => t('All')) + os_get_bundles(array(OS_PUBLIC_APP)),
      '#default_value' => $this->options['mlt_type_filters'],
      '#multiple' => TRUE,
      '#size' => 10,
      '#states' => array(
        'visible' => array(
          ':input[name="results_from_type"]' => array('checked' => FALSE),
        ),
      ),
    );

    return $form;
  }

  /**
   * Implements boxes_content::render().
   *
   * @see apachesolr_search_block_view()
   */
  public function render() {
    if (module_exists('vsite') && !vsite_get_vsite()) {
      return array('delta' => $this->delta);
    }

    $node = menu_get_object();

    if (empty($node)) {
      return array('delta' => $this->delta);
    }

    return $this->apacheSolrQuery($node);
  }

  /**
   * Get more like this nodes using Apache Solr. We need to build our own query
   * basing on the API function for applying the settings. We could alter the
   * query in the function os_search_solr_apachesolr_query_alter() but we need
   * the query the database for the delta of the plugin and load the settings
   * which is an overkill for the process.
   *
   * @pram $node
   *  The node object.
   *
   * @see apachesolr_search_block_view().
   */
  private function apacheSolrQuery($node) {
    // Get the delta of the MLT blocks.
    $mlt_blocks = array_keys(apachesolr_search_load_all_mlt_blocks());
    $delta = reset($mlt_blocks);

    // Load the block with the first delta.
    $block = apachesolr_search_mlt_block_load($delta);

    if ($this->options['results_from_type']) {
      $this->options['mlt_type_filters'] = array($node->type);
    }
    elseif (in_array('all', $this->options['mlt_type_filters'])) {
      // The user select all the bundles. Set as an empty string.
      $this->options['mlt_type_filters'] = '';
    }

    // Adding the settings of the widget.
    $block = array_merge($block, $this->options);
    $env_id = (!empty($block['mlt_env_id'])) ? $block['mlt_env_id'] : '';

    try {
      $solr = apachesolr_get_solr($env_id);
      $context['search_type'] = 'apachesolr_search_mlt';
      $context['block_id'] = $delta;
      $docs = $this->ApacheSolrSuggestions($block, apachesolr_document_id($node->nid), $solr, $context);

      if (empty($docs)) {
        return array('delta' => $this->delta);
      }

      $block['title'] = $this->description;
      $block['delta'] = $this->delta;
      $block['content'] = theme('apachesolr_search_mlt_recommendation_block', array('docs' => $docs));

      return $block;
    }
    catch (Exception $e) {
      watchdog('Apache Solr', nl2br(check_plain($e->getMessage())), NULL, WATCHDOG_ERROR);
    }
  }

  /**
   * Get the suggestion from Apache solr.
   *
   * @param $settings
   *  An array of settings.
   * @param $id
   *  The Solr ID of the document for which you want related content.
   *  For a node that is apachesolr_document_id($node->nid).
   * @param $solr
   *  The solr environment you want to query against.
   * @param array $context
   *  Additional information for Apache solr.
   *
   * @return array
   *  The results of the query.
   *
   * @see apachesolr_search_mlt_suggestions().
   */
  private function ApacheSolrSuggestions($settings, $id, $solr = NULL, $context = array()) {
    try {
      $fields = array(
        'mlt_mintf' => 'mlt.mintf',
        'mlt_mindf' => 'mlt.mindf',
        'mlt_minwl' => 'mlt.minwl',
        'mlt_maxwl' => 'mlt.maxwl',
        'mlt_maxqt' => 'mlt.maxqt',
        'mlt_boost' => 'mlt.boost',
        'mlt_qf' => 'mlt.qf',
      );

      $params = array(
        'q' => 'id:' . $id,
        'qt' => 'mlt',
        'fl' => array('entity_id', 'entity_type', 'label', 'path', 'url'),
        'mlt.fl' => $settings['mlt_fl'],
        'start' => 0,
        'rows' => $settings['num_results'],
      );

      // We can optionally specify a Solr object.
      $query = apachesolr_drupal_query('apachesolr_mlt', $params, '', '', $solr, $context);

      foreach ($fields as $form_key => $name) {
        if (!empty($settings[$form_key])) {
          $query->addParam($name, $settings[$form_key]);
        }
      }

      if (is_array($settings['mlt_type_filters']) && !empty($settings['mlt_type_filters'])) {
        $query->addFilter('bundle', '(' . implode(' OR ', $settings['mlt_type_filters']) . ') ');
      }

      if ($custom_filters = $settings['mlt_custom_filters']) {
        // @todo - fix the settings form to take a comma-delimited set of filters.
        $query->addFilter('', $custom_filters);
      }

      if (!variable_get('os_search_solr_query_multisites', FALSE)) {
        // Limit searches to just this OpenScholar install in shared indexes.
        $query->addFilter('hash', apachesolr_site_hash());
      }

      if (module_exists('vsite') && ($vsite = spaces_get_space())) {
        $query->addFilter("sm_og_group_ref", $vsite->group_type . ":" . $vsite->id);
      }

      $response = $query->search();

      if (isset($response->response->docs)) {
        return (array) $response->response->docs;
      }
    }
    catch (Exception $e) {
      watchdog('Apache Solr', nl2br(check_plain($e->getMessage())), NULL, WATCHDOG_ERROR);
    }
  }
}

