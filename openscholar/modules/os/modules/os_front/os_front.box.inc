<?php
/**
 * @file
 * iqss_scholars_front.box.inc
 */

/**
 * Implements hook_default_box().
 */
function os_front_default_box() {
  $export = array();

  $path = drupal_get_path('theme', 'os_default');
  $build = array(
    'banner' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array(
          'os-align-center',
        ),
      ),
      'image' => array(
        '#theme' => 'image',
        '#path' => "$path/images/osfrontpg_logo.gif",
        '#alt' => t('OpenScholar'),
        '#title' => t('OpenScholar'),
        '#attributes' => array(
          'class' => array(
            'os-title-image',
          ),
        ),
      ),
    ),
    'tagline' => array(
      '#markup' => '<strong>' . t('The easiest way to manage all your institution\'s sites') . '</strong>',
    ),
  );
  $value = drupal_render($build);
  
  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_header';
  $box->plugin_key = 'os_boxes_html';
  $box->title = '';
  $box->description = 'Front Page Header Text';
  $box->options = array(
    'text' => array(
      'value' => $value,
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_header'] = $box;

  $value = '';
  if (!user_is_anonymous()) {
    $build = array(
      'banner' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'os-align-center',
          ),
        ),
        
      ),
      'intro' => array(
        '#markup' => '<p>' . t('<strong>Welcome!</strong> You have successfully installed OpenScholar. This application makes it possible for you to create and manage multiple websites, or allow your users to create their own websites. Here are some things you can do right away:') . '</p>',
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#type' => 'ul',
        '#items' => array(
          0 => t('<a href="/site/register">Create a website.</a>'),
          1 => t('Configure who will have access</a> to create websites in this installation of OpenScholar.'),
          2 => t('<a href="/admin/config/openscholar/vsite_register">Customize what type of sites can be created</a> (personal / projects/ departments).'),
          3 => t('Customize this front page .  (examples:  <a href="http://openscholar.harard.edu">http://openscholar.harard.edu</a>, <a href="http://scholar.harvard.edu">http://scholar.harvard.edu</a>).'),
          4 => t('Other configuration settings.'),
          5 => t('To provide your end-users with additional site-building guides and documentation, feel free to refer to OpenScholar @ Harvard\'s <a href="http://support.openscholar.harvard.edu">Help Center</a> and <a href="http://community.openscholar.harvard.edu">Community forum</a>.'),
          6 => t('For questions about administering and configuring your new OpenScholar installation, search and/or post to our <a href="https://github.com/openscholar/openscholar/issues">GitHub issue queue</a>.'),
        
         
        ),
      ),
    );
    $value = drupal_render($build);
  }
  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_main_support';
  $box->plugin_key = 'os_boxes_html';
  $box->title = 'Getting Started';
  $box->description = 'Getting Started';
  $box->options = array(
    'text' => array(
      'value' => $value,
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_main_support'] = $box;

  $value = '';
  if (!user_is_anonymous()) {
    $build = array(
      'banner' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => array(
            'os-align-center',
          ),
        ),
        
      ),
      
    );
    $value = drupal_render($build);
  }
 
  $export['os_front_main_configure'] = $box;


  $variables = array(
    'header' => t('Sample Websites'),
    'images' => array(
      0 => array(
        'path' => "$path/images/osfrontpg_samplesite1.png",
        'alt' => t('Sample site A'),
        'title' => t('Sample site A'),
      ),
      1 => array(
        'path' => "$path/images/osfrontpg_samplesite2.png",
        'alt' => t('Sample site B'),
        'title' => t('Sample site B'),
      ),
      2 => array(
        'path' => "$path/images/osfrontpg_samplesite3.png",
        'alt' => t('Sample site C'),
        'title' => t('Sample site C'),
      ),
    ),
  );
  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_sample';
  $box->plugin_key = 'os_boxes_html';
  $box->title = '';
  $box->description = t('List example site screenshots');
  $box->options = array(
    'text' => array(
      'value' => theme('os_front_boxcontent_sample', $variables),
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_sample'] = $box;

  return $export;
}
