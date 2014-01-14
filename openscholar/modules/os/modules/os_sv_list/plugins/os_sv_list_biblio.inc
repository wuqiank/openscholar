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

    $content_types = array('all' => t('All')) + os_get_bundles(array(1));
    $form['content']['content_type']['#options'] = $content_types;

    return $form;
  }

  //add our node specific sorts
  protected function _sort_options() {
    $sorts = array(
      // Standard sorts,
      'sort_newest' => t('Newest Post'),
      'sort_oldest' => t('Oldest Post'),
      'sort_alpha' => t('Alphabetical'),
      'sort_random' => t('Random'),
    );

    return parent::_sort_options() + $sorts;
  }

  /**
   * Sorting functions.
   */
  function sort_newest(&$efq) {
    // Could these be made generic by using entity_get_info to figure out
    // $created and $title per type ?
    $efq->propertyOrderBy('created', 'DESC');
  }

  function sort_oldest(&$efq) {
    $efq->propertyOrderBy('created', 'ASC');
  }

  function sort_alpha(&$efq) {
    $efq->propertyOrderBy('title', 'ASC');
  }
}
