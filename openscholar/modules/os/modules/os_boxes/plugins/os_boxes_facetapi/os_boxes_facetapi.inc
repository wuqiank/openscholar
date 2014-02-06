<?php
class os_boxes_facetapi extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
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
    //@todo
    $block = parent::render();

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
      $vocabularies[$taxonomy_vocabulary->vid] = $taxonomy_vocabulary->name;
    }

    return $vocabularies;
  }
}
