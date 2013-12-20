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
        '#markup' => '<p>' . t('<div style="text-align:center;"><strong>Welcome to OpenScholar!</strong> <h3>The easiest way to create and manage all of your institution websites.</h3></div><br> You have successfully installed OpenScholar. This application makes it possible for you to create and manage multiple websites, or allow your users to create their own websites. Here are some things you can do right away:<br><br>') . '</p>',
      ),
      'list' => array(
        '#theme' => 'item_list',
        '#type' => 'ul',
        '#items' => array(
          0 => t('<a href="/site/register">Create your first website.</a>'),
           1 => t('<a href="/admin/config/openscholar/vsite_register">Customize</a> what type of sites can be created (personal / projects/ departments).'),
          2 => t('<a href="/admin/people/permissions">Configure</a> who will have access</a> to create websites in this installation of OpenScholar.'),
         
	      3 => t('Other <a href="/admin/config/openscholar">configuration</a> <a href="/admin/config/openscholar/vsite_register">settings</a>.'),
	      4 => t('For questions about administering and configuring your new OpenScholar installation, search and/or post to our <a href="https://github.com/openscholar/openscholar/issues">GitHub issue queue</a>.'),
	      5 => t('<a href="/admin/structure/context/list/os_sitewide_front/edit">Customize</a> this front page .  (examples:  <a href="http://openscholar.harard.edu">http://openscholar.harard.edu</a>, <a href="http://scholar.harvard.edu">http://scholar.harvard.edu</a>).'),
          6 => t('To provide your end-users with additional site-building guides and documentation, feel free to refer to OpenScholar @ Harvard\'s <a href="http://support.openscholar.harvard.edu">Help Center</a> and <a href="http://community.openscholar.harvard.edu">Community forum</a>.'),
          
         
         
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
