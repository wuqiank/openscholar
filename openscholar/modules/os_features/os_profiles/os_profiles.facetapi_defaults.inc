<?php
/**
 * @file
 * os_profiles.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function os_profiles_facetapi_default_facet_settings() {

  $searcher_name = os_search_solr_get_searcher_name();

  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = $searcher_name . ':block:os_profiles_og_vocabulary';
  $facet->searcher = $searcher_name;
  $facet->realm = 'block';
  $facet->facet = 'os_profiles_og_vocabulary';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );

  $export[$searcher_name . ':block:os_profiles_og_vocabulary'] = $facet;

  return $export;
}
