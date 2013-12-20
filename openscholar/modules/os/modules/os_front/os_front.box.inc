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
        '#markup' => '<p>' . t('<strong>Welcome to OpenScholar!</strong> The easiest way to create and manage all of your institution sites. <br><br>You have successfully installed OpenScholar. This application makes it possible for you to create and manage multiple websites, or allow your users to create their own websites. Here are some things you can do right away:') . '</p>',
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#type' => 'ul',
        '#items' => array(
          0 => t('<a href="/site/register">Create your first website now.</a>'),
          1 => t('Configure who will have access</a> to create websites in this installation of OpenScholar.'),
          2 => t('<a href="/admin/config/openscholar/vsite_register">Customize</a> what type of sites can be created</a> (personal / projects/ departments).'),
	      3 => t('Other configuration settings.'),
          4 => t('To provide your end-users with additional site-building guides and documentation, feel free to refer to OpenScholar @ Harvard\'s <a href="http://support.openscholar.harvard.edu">Help Center</a> and <a href="http://community.openscholar.harvard.edu">Community forum</a>.'),
          5 => t('For questions about administering and configuring your new OpenScholar installation, search and/or post to our <a href="https://github.com/openscholar/openscholar/issues">GitHub issue queue</a>.'),
         6 => t('Customize this front page .  (examples:  <a href="http://openscholar.harard.edu">http://openscholar.harard.edu</a>, <a href="http://scholar.harvard.edu">http://scholar.harvard.edu</a>).'),
         
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


  return $export;
}
