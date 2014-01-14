<?php 

class os_sv_list_biblio extends os_sv_list {
  public function __construct() {
    parent::__construct();
    $this->entity_type = 'biblio';
  }
  
  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $form = parent::options_form($form_state);

    $content_types = array('all' => t('All')) + os_publications_get_bundles();
    $form['content']['content_type']['#options'] = $content_types;

    return $form;
  }
}
