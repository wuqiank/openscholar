<?php
/**
 * @file
 * os_profiles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os_profiles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'profiles_profiles';
  $context->description = '';
  $context->tag = 'OS features';
  $context->conditions = array(
    'menu' => array(
      'values' => array(
        'people' => 'people',
      ),
    ),
    'node' => array(
      'values' => array(
        'person' => 'person',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'people' => 'people',
        'people/*' => 'people/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'os_profiles' => 'os_profiles',
        'os_profiles:page' => 'os_profiles:page',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OS features');
  $export['profiles_profiles'] = $context;

  // First get the delta's for facetapi blocks.
  $delta_og_vocab = '';
  if (module_exists('os_search_solr')) {

    $searcher_name = os_search_solr_get_searcher_name();
    // Gets delta map
    $map = facetapi_get_delta_map();
    if(isset($map) && is_array($map)) {

      // Filter by OG vocab.
      $string_og_vocab = facetapi_build_delta($searcher_name, 'block', 'os_profiles_og_vocabulary');
      $delta_og_vocab = array_search($string_og_vocab, $map);
    }
  }
  $context = new stdClass();

  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_profiles';
  $context->description = 'Profiles Pages';
  $context->tag = 'OpenScholar';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'browse/people' => 'browse/people',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'current_search-standard' => array(
          'module' => 'current_search',
          'delta' => 'standard',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'apachesolr_search-sort' => array(
          'module' => 'apachesolr_search',
          'delta' => 'sort',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-' . $delta_og_vocab => array(
          'module' => 'facetapi',
          'delta' => $delta_og_vocab,
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  $export['os_profiles'] = $context;

  return $export;
}
