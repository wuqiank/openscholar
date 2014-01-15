<?php 

/**
 * @file slider.inc
 * 
 * Slider plugin for sv_list box.  @see `os_sv_list_preprocess_node()` for classes being added. 
 */

$plugin = array(
  'handler' => array('class' => 'sv_list_slider'),
  'entity_type' => array('node'),
  'bundle' => array(),
);

class sv_list_slider extends sv_list_plugin  {
  
  public function options_defaults() {
    return array('slider' => FALSE);
  }
  
  public function options_form($options, &$form) {
    //don't forget to show/hide
    $form['details']['slider'] = array(
      '#type' => 'checkbox',
      '#default_value' => $options['slider'],
      '#title' => 'Content slider',
      '#description' => t('Reveal content when title is clicked.'),
      
      // https://drupal.org/node/735528 means #states should take a list, but it isn't working.  jquery_update's fault?  
      //instead make a list of equivalent selectors with slightly different keys
      '#states' => array(
        'invisible' => array_reduce($this->slider_view_modes(), function($ret, $view_mode) {
          $ret[':input[name="display"],' . count($ret)] = array('!value' => $view_mode);
          return $ret;
        }, array()),
      ),
    );
  }

  public function entities_alter($options, &$entities) {
    if ($options['slider'] && in_array($options['display'], $this->slider_view_modes())) {
      foreach ($entities as $id => $entity) {
        $entities[$id]->sv_list_toggle = TRUE;
      }
      
      drupal_add_js(drupal_get_path('module', 'os').'/theme/os_toggle.js');
    }
  }
  
  /**
   * @function slider_view_modes
   * 
   * Lists the view modes available for the slider.
   */
  private function slider_view_modes() {
    return array('full', 'teaser', 'sidebar_teaser');
  }
}
