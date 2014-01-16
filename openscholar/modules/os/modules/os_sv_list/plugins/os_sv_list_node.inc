<?php 

class os_sv_list_box extends os_sv_list {
  public function __construct() {
    parent::__construct();
    $this->entity_type = 'node';
  }
  
  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $form = parent::options_form($form_state);

    $content_types = array('all' => t('All')) + os_get_bundles(array(1));
    $form['content']['content_type']['#options'] = $content_types;

    return $form;
  }

  /**
   * Overrides query() to filter only published nodes.
   *
   * @return EntityFieldQuery
   */
  public function query() {
    $efq = parent::query();
    $efq->propertyCondition('status', 1);
    return $efq;
  }
}
