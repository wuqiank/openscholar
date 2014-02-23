<?php
/**
 * @file os_boxes_search_mlt.inc
 *
 * Display content similar to the current node the user watching.
 */
class os_boxes_search_mlt extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['num_results'] = 5;
    $options['mlt_type_filters'] = array();
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
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

    $form['mlt_type_filters'] = array(
      '#type' => 'select',
      '#title' => t('Node types'),
      '#description' => t('Select which node types to display'),
      '#options' => array('all' => t('All')) + os_get_bundles(array(OS_PUBLIC_APP)),
      '#default_value' => $this->options['mlt_type_filters'],
      '#multiple' => TRUE,
      '#size' => 10,
    );

    return $form;
  }

  /**
   * Implements boxes_content::render().
   */
  public function render() {
    if (module_exists('vsite') && !vsite_get_vsite()) {
      return array('delta' => $this->delta);
    }

    $object = menu_get_object();

    if (empty($object->nid)) {
      return array('delta' => $this->delta);
    }

    // @see apachesolr_search_block_view().
    $mlt_blocks = array_keys(apachesolr_search_load_all_mlt_blocks());

    $delta = reset($mlt_blocks);
    $block = apachesolr_search_mlt_block_load($delta);

    if (in_array('all', $this->options['mlt_type_filters'])) {
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
      $docs = apachesolr_search_mlt_suggestions($block, apachesolr_document_id($object->nid), $solr, $context);

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
}

