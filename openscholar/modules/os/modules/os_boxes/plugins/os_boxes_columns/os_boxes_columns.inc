<?php

class os_boxes_columns extends os_boxes_default {

  public function options_defaults() {
    return array(
      'num_cols' => 2,
      'layout' => 'two-2x50',
      'widgets' => array(),
    );
  }

  public function options_form(&$form_state) {

    // set up layout selection controls
    $form['layout_select'] = array(
      '#type' => 'container',
      '#id' => 'os-boxes-columns-layout-select'
    );

    $form['layout_select']['num_cols'] = array(
      '#type' => 'radio',
      '#options' => array(
        '2' => t('Two'),
        '3' => t('Three'),
        '4' => t('Four'),
        '5' => t('Five')
      ),
      '#default_value' => $this->options['num_cols'],
    );

    $form['layout_select']['layout'] = array(
      '#type' => 'radio',
      '#options' => array(
        'two-2x50' => 'two-2x50',
        'two-33-66' => 'two-33-66',
        'two-66-33' => 'two-66-33',
        'three-3x33' => 'three-3x33',
        'three-25-25-50' => 'three-25-25-50',
        'three-25-50-25' => 'three-50-25-25',
        'four-4x25' => 'four-4x25',
        'five-5x20' => 'five-5x20'
      ),
      '#default_value' => $this->options['layout'],
    );

    // set up unused widget container
    $form['unused'] = array(
      'search' => array(
        '#type' => 'textfield',
      ),
      'widgets' => array(
        '#type' => 'container',

      )
    );

    ctools_include('layout', 'os');
    $blocks = os_layout_get_multiple(array('os_public'), true, true);

    foreach ($blocks as $bid => $b) {
      if ($b['region'] == - 1 || $b['region'] === FALSE) {
        $form['unused']['widgets'][$bid] = array(
          '#theme' => 'cp_layout_widget',
          '#widget' => $b
        );
      }
    }

    // set up psuedo-regions
    // this element is for the hidden input elements
    $form['widgets'] = array(
      '#tree' => true,
    );

    // this element is for the actual regions
    // js will convert the input elements into a widget list
    // while
    $form['regions'] = array(
      '#type' => 'container',
    );

    for ($i = 1; $i < 5; $i++) {
      $form['regions']['reg-'.$i] = array(
        '#type' => 'container',
        '#id' => 'region-'.$i.'-container',
        '#attributes' => array(
          'class' => array(
            'region'
          ),
          'data-region_id' => $i
        ),
      );
      $form['widgets']['region-'.$i] = array(
        '#type' => 'hidden',
        '#default_value' => $this->options['widgets']['region-'.$i],
        '#id' => 'region-'.$i.'-storage',
        '#attributes' => array(
          'class' => array(
            'region_storage'
          )
        ),
        'data-region_id' => $i
      );
    }

    // add all the js and css we're gonna need
    $form['#attached'] = array(
      'js' => array(
        drupal_get_path('module', 'os_boxes').'/plugins/os_boxes_columns/js/os_boxes_columns.form.js'
      ),
      'css' => array(
        drupal_get_path('module', 'os_boxes').'/plugins/os_boxes_columns/css/os_boxes_columns.form.css'
      )
    );

    return $form;
  }

  /**
   * Hmm
   */
  public function render() {

  }
}