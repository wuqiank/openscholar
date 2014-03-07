<?php

/**
 * @file
 * Provides mapping for contextual ids to documentation URLs.
 */

/**
 * Returns a docs URL for the given path or form element key.
 *
 * @param bool $is_path
 *   TRUE if the $id param being passed is a page path, FALSE otherwise.
 * @param string id
 *   The current path or form element.
 */
function os_help_get_variables_from_id($type, $id) {
  $variables = FALSE;

  switch ($type) {
    case 'path':
      $links = array(
        'cp/appearance' => array('url' => '', 'title' => ''),
        'cp/build' => array('url' => 'http://docs.openscholar.harvard.edu/content-apps-and-widgets', 'title' => 'Apps'),
        'cp/build/apps' => array('url' => 'http://docs.openscholar.harvard.edu/content-apps-and-widgets', 'title' => 'Apps'),
        'cp/build/layout' => array('url' => '', 'title' => ''),
        'cp/build/menu' => array('url' => '', 'title' => ''),
        'cp/build/taxonomy' => array('url' => '', 'title' => ''),
        'cp/content' => array('url' => '', 'title' => ''),
        'cp/content/content' => array('url' => '', 'title' => ''),
        'cp/content/files' => array('url' => '', 'title' => ''),
        'cp/settings' => array('url' => '', 'title' => ''),
        'cp/support' => array('url' => '', 'title' => ''),
        'cp/users' => array('url' => '', 'title' => ''),
      );
      break;
    case 'app':
      $links = array(
        'harvard_courses' => array('url' => '', 'title' => ''),
        'os_news' => array('url' => '', 'title' => ''),
        'os_biocv' => array('url' => 'http://docs.openscholar.harvard.edu/biocv', 'title' => 'Bio/CV app'),
        'os_blog' => array('url' => '', 'title' => ''),
        'os_booklets' => array('url' => '', 'title' => ''),
        'os_classes' => array('url' => '', 'title' => ''),
        'os_dataverse' => array('url' => '', 'title' => ''),
        'os_events' => array('url' => '', 'title' => ''),
        'os_faq' => array('url' => '', 'title' => ''),
        'os_files_private' => array('url' => '', 'title' => ''),
        'os_pages' => array('url' => '', 'title' => ''),
        'os_image_gallery' => array('url' => '', 'title' => ''),
        'os_links' => array('url' => '', 'title' => ''),
        'os_profiles' => array('url' => '', 'title' => ''),
        'os_publications' => array('url' => '', 'title' => ''),
        'os_presentations' => array('url' => '', 'title' => ''),
        'os_reader' => array('url' => '', 'title' => ''),
        'os_software' => array('url' => '', 'title' => ''),
      );
      break;
    case 'widget':
      $links = array(
        'os_boxes_html' => array('url' => 'http://docs.openscholar.harvard.edu/custom-texthtml-widget', 'title' => 'Custom text widget'),
        'os_taxonomy_fbt' => array('url' => '', 'title' => ''),
        'os_boxes_manual_list' => array('url' => '', 'title' => ''),
        'os_sv_list_box' => array('url' => '', 'title' => ''),
        'os_sv_list_file' => array('url' => '', 'title' => ''),
        'os_boxes_feedreader' => array('url' => '', 'title' => ''),
        'os_boxes_pub_year' => array('url' => '', 'title' => ''),
        'os_boxes_booktoc' => array('url' => '', 'title' => ''),
        'os_boxes_pub_ca' => array('url' => '', 'title' => ''),
        'os_boxes_pub_type' => array('url' => '', 'title' => ''),
        'os_slideshow_box' => array('url' => '', 'title' => ''),
        'os_boxes_media' => array('url' => '', 'title' => ''),
        'os_boxes_rss' => array('url' => '', 'title' => ''),
        'os_boxes_mailchimp' => array('url' => '', 'title' => ''),
        'os_boxes_follow' => array('url' => '', 'title' => ''),
        'os_boxes_twitterfeed' => array('url' => '', 'title' => ''),
        'os_boxes_bio' => array('url' => '', 'title' => ''),
        'os_boxes_addthis' => array('url' => '', 'title' => ''),
        'os_boxes_accordion' => array('url' => '', 'title' => ''),
        'os_boxes_tabs' => array('url' => '', 'title' => ''),
        'os_boxes_rand_widget' => array('url' => '', 'title' => ''),
        'os_boxes_columns' => array('url' => '', 'title' => ''),
        'os_boxes_facetapi_vocabulary' => array('url' => '', 'title' => ''),
        'fb_social_activityf' => array('url' => '', 'title' => ''),
        'fb_social_recommend' => array('url' => '', 'title' => ''),
        'fb_social_send' => array('url' => '', 'title' => ''),
        'fb_social_likebox' => array('url' => '', 'title' => ''),
        'fb_social_facepile' => array('url' => '', 'title' => ''),
        'fb_social_livestream' => array('url' => '', 'title' => ''),
        'fb_social_comments' => array('url' => '', 'title' => ''),
        'fb_social_like' => array('url' => '', 'title' => ''),
      );
      break;
  }

  if (isset($links[$id]) && !empty($links[$id]['url']) && !empty($links[$id]['title'])) {
    $variables = array(
      'path' => $links[$id]['url'] . '#main-content',
      'text' => '<span>' . t('Help') . '</span>',
      'options' => array(
        'attributes' => array(
          'class' => array(
            'os-help-link',
          ),
          'onclick' => "var w=window.open(this.href, 'os_help_link', 'width=480,height=600,scrollbars,resizable'); w.focus(); return false;",
          'title' => $links[$id]['title'],
        ),
        'html' => TRUE,
      ),
    );
  }

  return $variables;
}

/**
 * Returns the HTML content for the given article.
 */
function os_help_get_article($article_id) {
  $articles = &drupal_static(__FUNCTION__, array());

  if (!isset($articles[$article_id])) {
    $cid = "os_help:{$article_id}";
    if (($cache = cache_get($cid)) && !empty($cache->data)) {
      $articles[$article_id] = $cache->data;
    }
    else {
      $filename = drupal_get_path('module', 'os_help') . '/os_help.articles.ini';
      $data = file_get_contents($filename);
      $info = drupal_parse_info_format($data);
      if (!isset($info[$article_id]) || !isset($info[$article_id]['url'])) {
        $info[$article_id] = '<p>' . t('No help article found.') . '</p>';
      }
      else {
        $article = os_help_get_article_from_url($info[$article_id]['url']);
        $articles[$article_id] = $article;
        cache_set($cid, $article);
      }
    }
  }

  return $articles[$article_id];
}

/**
 *
 */
function os_help_get_article_from_url() {
  
}
