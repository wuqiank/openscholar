<?php
class os_boxes_facetapi_vocabulary extends os_boxes_default {

  /**
   * Create a new box.
   */
  protected function __construct() {
    ctools_include('taxonomy', 'os');
    parent::__construct();
    $this->title = t('Filter by taxonomy');
  }

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['vocabularies'] = $this->get_bundle_vocabularies();

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $form = parent::options_form($form_state);

    $form['vocabularies'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#description' => t('Select which vocabularies to show. No selection will show all vocabularies.'),
      '#options' => $this->get_bundle_vocabularies(),
      '#default_value' => (!empty($this->options['vocabularies']) ? $this->options['vocabularies'] : array()),
    );
    return $form;
  }

  /**
   * Facet widgets that in a non-solr search page must fake a search page in
   * order to show the facet. To do so we execute a "silent" search on solr
   * without showing the results.
   */
  public function call_empty_search_if_needed($delta) {
    $parsed = &drupal_static('facetapi_parsed_deltas', array());
    // Test block visibility if not already tested.
    if (empty($delta) || !empty($parsed[$delta])) {
      return;
    }
    $map = facetapi_get_delta_map();
    list($searcher, $realm_name, $facet_name) = facetapi_parse_delta($map[$delta]);

    ctools_include('apachesolr_search.pages', 'apachesolr', '');
    apachesolr_search_custom_page('browse_person');
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    $block = parent::render();

    $searcher_name = os_search_solr_get_searcher_name();
    // Gets delta map
    if (!$map = facetapi_get_delta_map()) {
      return $block;
    }

    $delta = $block['delta'];

    // Filter by OG vocab.
    $string_og_vocab = facetapi_build_delta($searcher_name, 'block', 'sm_og_vocabulary');
    $delta_og_vocab = array_search($string_og_vocab, $map);

    // Verify the facet block has something to work on (means - it is in a solr
    // search page). If not - execute the empty solr search without showing
    // the results.
    $this->call_empty_search_if_needed($delta_og_vocab);

    $block = module_invoke('facetapi', 'block_view', $delta_og_vocab);
    $block['delta'] = $delta;

    // Set block subject/title from box configuration.
    $block['subject'] = $this->title;
    $block['title'] = $this->title;

    if (empty($block['content'])) {
      // Block content must be defined, even if it is empty, to avoid errors.
      $block['content'] = '';
    }
    else {
      if (!empty($this->options['vocabularies'])) {
        // Get the list of selected vocabularies
        $selected = array();
        foreach ($this->options['vocabularies'] as $vocabulary_name => $value) {
          if ($value) {
            $selected[$vocabulary_name] = $value;
          }
        }
        // If no selection - show all. If there is selection - show only them.
        if (count($selected) > 0) {
          foreach (array_keys($block['content']['sm_og_vocabulary']) as $vocabulary_name) {
            if (empty($selected[$vocabulary_name])) {
              unset($block['content']['sm_og_vocabulary'][$vocabulary_name]);
            }
          }
        }
      }

      if (!empty($block['content']['sm_og_vocabulary'])) {
        // Sort by vocab's title.
        ksort($block['content']['sm_og_vocabulary']);
      }

      $block['content'] = render($block['content']);
    }
    return $block;
  }

  /**
   * Get all the vocabularies id using the taxonomy terms, relevant to the
   * current bundle.
   */
  private function get_bundle_vocabularies() {

    $taxonomy_vocabularies = os_get_vocabularies_by_bundle('node', str_replace("vocabulary_filter_", "", $this->delta));

    $vocabularies = array();

    if ($taxonomy_vocabularies) {
      foreach ($taxonomy_vocabularies as $taxonomy_vocabulary) {
        $vocabularies[$taxonomy_vocabulary->machine_name] = $taxonomy_vocabulary->name;
      }
    }

    return $vocabularies;
  }
}
