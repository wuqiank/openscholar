<?php

/**
 * @file
 * The class for "Shield" type widgets.
 */

class os_shields_box extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();

    $options['shield'] = variable_get('os_shields_shield', '');
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state){
    $default_shield = FALSE;
    if ($all_shields = variable_get('os_shields_shield_info', array())) {
      $shield_options = array();
      foreach ($all_shields as $file_name => $shield)  {
        if ($shield['hidden']) {
          // Shield should be hidden.
          continue;
        }

        $shield_file = file_load($shield['fid']);
        $shield_options[$shield_file->filename] = theme('os_shields_theme_shieldpicker', array('file' => $shield_file));

        if (!empty($shield['default'])) {
          $default_shield = $file_name;
        }
      }

      $selected_shield = !empty($this->options['shield']) ? $this->options['shield'] : $default_shield;

      $form['shield'] = array(
        '#prefix' => '<div class="shield_wrapper clear-block">',
        '#title' => t('Shield'),
        '#type' => 'radios',
        '#options' => $shield_options,
        '#default_value' => $selected_shield,
        '#suffix' => '</div>',
        '#attached' => array(
          'css' => array(
            drupal_get_path('module', 'os_shields') . '/theme/os_shields-shield-picker.css',
          ),
          'js' => array(
            drupal_get_path('module', 'os_shields') . '/theme/os_shields-shield-picker.js',
          ),
        ),
      );
    }
    if (empty($shield_options)) {
      $form['shield'] = array(
        '#type' => 'markup',
        '#value' => t('Your site has no shields to display.'),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }

    $form += parent::options_form($form_state);
    return $form;
  }

  /**
   * Implements boxes_content::render().
   */
  public function render() {
    if (module_exists('vsite') && !vsite_get_vsite()) {
      return;
    }

    $block = parent::render();
    $block['title'] = $block['content'] = '';

    $default_shield = variable_get('os_shields_shield', '');
    $filename = !empty($this->options['shield']) ? $this->options['shield'] : FALSE;

    if ($filename && file_exists('public://os_shields/' . $filename)) {
      $params = array(
        'path' => 'public://os_shields/' . $filename,
        'alt' => t('Shield'),
      );
      $image = theme('image', $params);
      $block['content'] = '<div id="scholar-shield">' . $image . '</div>';
    }
    elseif (spaces_access_admin() && !variable_get('os_shields_shield_info', array())) {
      $block['content'] = t('No shields have been added to your install. Contact your site administrator or remove this widget to hide this message.');
    }

    return $block;
  }

}
