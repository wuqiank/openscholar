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

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_header';
  $box->plugin_key = 'os_boxes_html';
  $box->title = '';
  $box->description = 'Front Page Header Text';
  $box->options = array(
    'text' => array(
      'value' => '<div align="center"><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_logo.gif" class="os-title-image" alt="OpenScholar"></div><br>
          <strong>The easiest way to manage all your institution\'s sites</strong><br/>
          Welcome! Log in and hover over this widget to customize your front page.',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_header'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_main_support';
  $box->plugin_key = 'os_boxes_html';
  $box->title = 'Support';
  $box->description = 'Support';
  $box->options = array(
    'text' => array(
      'value' => '<div align="center"><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_support.gif" class="os-title-image" alt="OpenScholar"></div><br>We have a very active community-style support site where questions, ideas, and problems can be searched for, posted, and replied to. <a href="http://community.openscholar.harvard.edu/openscholar">Visit the Community</a>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_main_support'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_main_configure';
  $box->plugin_key = 'os_boxes_html';
  $box->title = 'Configure this Page';
  $box->description = 'Create A Site';
  $box->options = array(
    'text' => array(
      'value' => '<div align="center"><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_configure.gif" class="os-title-image" alt="OpenScholar"></div><br><ol><li>To configure these widgets, simply log in and hover over the widget.</li><li>To add or remove widgets from this context, <a href="/admin/structure/context/list/os_sitewide_front/edit">edit the os_sitewide_front context</a>.</li></ol><br/>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_main_configure'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'os_front_sample';
  $box->plugin_key = 'os_boxes_html';
  $box->title = '';
  $box->description = 'Create A Site';
  $box->options = array(
    'text' => array(
      'value' => 'Sample Websites <ul>
        <li>
          <a href=""><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_samplesite1.gif"></a>
        </li>
        <li>
          <a href=""><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_samplesite2.gif"></a>
        </li>
        <li>
          <a href=""><img src="/profiles/openscholar/themes/os_default/images/osfrontpg_samplesite3.gif"></a>
        </li>
      </ul>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['os_front_sample'] = $box;

  return $export;
}
