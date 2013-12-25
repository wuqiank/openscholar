<?php
/**
 * @file
 * os_search_solr.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os_search_solr_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_search';
  $context->description = 'Search Pages';
  $context->tag = 'OpenScholar';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~os_cp' => '~os_cp',
      ),
    ),
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
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
        'facetapi-n18E4x0qRRaIP7nV6I0SDYiCJsq77HCB' => array(
          'module' => 'facetapi',
          'delta' => 'n18E4x0qRRaIP7nV6I0SDYiCJsq77HCB',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapiGiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'facetapi-CpjIe0iO04QY4VGdG5PfZfBQqRWCmc4G' => array(
          'module' => 'facetapi',
          'delta' => 'CpjIe0iO04QY4VGdG5PfZfBQqRWCmc4G',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'apachesolr_search-mlt-001' => array(
          'module' => 'apachesolr_search',
          'delta' => 'mlt-001',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'facetapi-CIWqxieiSlmL8r64OBPFrpQKCrfcgjJA' => array(
          'module' => 'facetapi',
          'delta' => 'CIWqxieiSlmL8r64OBPFrpQKCrfcgjJA',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenScholar');
  t('Search Pages');
  $export['os_search'] = $context;

  return $export;
}
