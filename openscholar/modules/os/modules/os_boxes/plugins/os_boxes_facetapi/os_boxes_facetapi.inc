<?php
class os_boxes_facetapi extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    $options['vocabularies'] = FALSE;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    ctools_include('taxonomy', 'os');
    $form = parent::options_form($form_state);

    $vocabularies = os_get_vocabularies();
    $form['vocabularies'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#description' => t('Select which vocabularies to show. No selection will show all vocabularies.'),
      '#options' => self::get_all_vocabularies(),
    );
    return $form;
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

    // Filter by OG vocab.
    $string_og_vocab = facetapi_build_delta($searcher_name, 'block', 'sm_og_vocabulary');
    $delta_og_vocab = array_search($string_og_vocab, $map);

    $block = module_invoke('facetapi', 'block_view', $delta_og_vocab);
    // Remove unselected vocabularies
    if ($this->options['vocabularies']) {
      foreach (array_keys($block['content']['sm_og_vocabulary']) as $vocabulary_name) {
        if (!($this->options['vocabularies'][$vocabulary_name])) {
          unset($block['content']['sm_og_vocabulary'][$vocabulary_name]);
        }
      }
    }
    $block['content'] = render($block['content']);
    return $block;
  }

  /**
   * Get all the vocabularies id using the taxonomy terms.
   */
  private function get_all_vocabularies() {

    ctools_include('taxonomy', 'os');
    $taxonomy_vocabularies = os_get_vocabularies();
    $vocabularies = array();

    foreach ($taxonomy_vocabularies as $taxonomy_vocabulary) {
      $vocabularies[$taxonomy_vocabulary->machine_name] = $taxonomy_vocabulary->name;
    }

    return $vocabularies;
  }
}
