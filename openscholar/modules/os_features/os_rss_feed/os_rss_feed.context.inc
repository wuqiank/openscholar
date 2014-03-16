<?php
/**
 * @file
 * os_rss_feed.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os_rss_feed_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_rss_feed';
  $context->description = '';
  $context->tag = 'OS features';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'rss-feed' => 'rss-feed',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OS features');
  $export['os_rss_feed'] = $context;

  return $export;
}
