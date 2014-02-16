<?php

/**
 * @file
 * The class for "Publication by Type" type widgets.
 */

class os_boxes_pub_type extends os_boxes_default {

  public $embed_as = array(
    'iframe',
  );

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['whitelist'] = array('all');
    $options['display_num'] = 1;

    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state){
    $rows = db_select('biblio_type', 'bt')
            ->fields('bt', array('name'))
            ->execute();
    $options = array('all' => 'Select All');
    $value = $this->options['whitelist'];
    $all = in_array('all', $value) && isset($value['all']) && $value['all'] === 'all';
    foreach ($rows as $key => $r) {
      $options[$r->name] = $r->name;
      if ($all) {
        $value[$r->name] = $r->name;
      }
    }

    $form['whitelist'] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => $value,
      '#title' => t('Show the following types:'),
      '#attributes' => array('class' => array('pub_type')),
      '#description' => t('Select the types you want to appear in the widget.'),
      '#attached' => array(
        'js' => array(
          drupal_get_path('module', 'os_boxes').'/misc/selectAll.js',
        ),
      ),
    );

    $form['display_num'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display number of items in category'),
      '#default_value' => $this->options['display_num'],
    );
    //drupal_add_js(drupal_get_path('module', 'os_boxes').'/theme/js/selectAll.js');

    $form += parent::options_form($form_state);

    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();

    $delta = 'publication_types-block';
    list($name, $display_id) = explode('-', $delta);
    if ($view = views_get_view($name)) {
      if ($view->access($display_id)) {
        $view->set_display('block');
        if (!in_array('all', $this->options['whitelist']) || !$this->options['whitelist']['all']) {
          $filter = array(
            'operator' => 'in',
            'value' => $this->options['whitelist'],
            'group' => '0',
            'exposed' => FALSE,
            'expose' => array(
              'operator' => FALSE,
              'label' => '',
            ),
            'id' => 'type',
            'table' => 'biblio_type',
            'field' => 'type',
            'override' => array(
              'button' => 'Use default',
            ),
            'relationship' => 'none',
          );
          $view->set_item('block', 'filter', 'type', $filter);
        }

        //Tie this view to this box (this tells the view to call this box's view alter)
        $view->dom_id = "boxes-".$this->delta;

        $view->set_display($display_id);
        $block['content'] = $view->preview();
      }
    }

    return $block;
  }

  /**
   * Called from views_pre_view
   *
   * @param view $view
   */
  public function views_alter(&$view, &$display_id, &$args){
  }

  /**
   * Return the cache parameters for this box
   */
  public function cache_info(){

//    //Clear when biblio nodes are saved
//    $cache_key = array(
//      'os_og' => array('current' => 'current'),
//      'node' => array('biblio' => 'biblio'),
//    );
//
//    return array('type' => BLOCK_CACHE_CONTENT_CACHE, 'keys' => $cache_key);

  	return array(); //caching disabled so ajax pager gets init'ed
  }

}
