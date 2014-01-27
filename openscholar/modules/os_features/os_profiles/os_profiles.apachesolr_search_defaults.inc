<?php
/**
 * @file
 * os_profiles.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function os_profiles_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'core_search_0';
  $searcher->label = 'Person';
  $searcher->description = 'Person Search';
  $searcher->search_path = 'browse/people';
  $searcher->page_title = 'Browse person';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:person',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_search_box' => 0,
    'apachesolr_search_per_page' => '10',
    'apachesolr_search_browse' => 'results',
    'apachesolr_search_spellcheck' => 0,
    'apachesolr_search_allow_user_input' => 0,
  );
  $export['core_search_0'] = $searcher;

  return $export;
}
