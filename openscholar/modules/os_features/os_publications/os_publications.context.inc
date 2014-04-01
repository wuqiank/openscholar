<?php
/**
 * @file
 * os_publications.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os_publications_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'publications_publications';
  $context->description = 'List of publications';
  $context->tag = 'OS features';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'publications' => 'publications',
        'publications/*' => 'publications/*',
        'biblio/*' => 'biblio/*',
        'browse/publications' => 'browse/publications',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-os_publications_recent' => array(
          'module' => 'boxes',
          'delta' => 'os_publications_recent',
          'region' => 'sidebar_second',
          'weight' => '21',
        ),
        'boxes-os_addthis' => array(
          'module' => 'boxes',
          'delta' => 'os_addthis',
          'region' => 'sidebar_second',
          'weight' => '22',
        ),
      ),
    ),
    'menu' => 'publications',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('List of publications');
  t('OS features');
  $export['publications_publications'] = $context;

  return $export;
}
