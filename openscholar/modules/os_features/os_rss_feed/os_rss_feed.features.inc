<?php
/**
 * @file
 * os_rss_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_rss_feed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function os_rss_feed_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
