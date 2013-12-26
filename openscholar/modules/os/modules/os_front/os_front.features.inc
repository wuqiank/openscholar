<?php
/**
 * @file
 * os_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}
