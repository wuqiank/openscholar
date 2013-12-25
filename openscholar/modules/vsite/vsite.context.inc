<?php
/**
 * @file
 * vsite.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function vsite_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_sitewide';
  $context->description = 'Context that is active on all non-vsite pages except the frontpage.';
  $context->tag = 'OpenScholar';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~os_sitewide_front' => '~os_sitewide_front',
        '~os_users' => '~os_users',
        '~os_cp' => '~os_cp',
      ),
    ),
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~user' => '~user',
        '~user/*' => '~user/*',
        '~admin/*' => '~admin/*',
        '~cp/*' => '~cp/*',
        '~site/register' => '~site/register',
      ),
    ),
    'os_site' => array(
      'values' => array(
        0 => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-iqss_projects_fp_logoblock' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_logoblock',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'boxes-iqss_projects_fp_navblock' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_navblock',
          'region' => 'header_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context that is active on all non-vsite pages except the frontpage.');
  t('OpenScholar');
  $export['os_sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_sitewide_front';
  $context->description = 'Active on the frontpage in multi-tenant installs';
  $context->tag = 'OpenScholar';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'os_site' => array(
      'values' => array(
        0 => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'os_search_solr-site-search' => array(
          'module' => 'os_search_solr',
          'delta' => 'site-search',
          'region' => 'footer',
          'weight' => 0,
        ),
        'os_search_db-site-search' => array(
          'module' => 'os_search_db',
          'delta' => 'site-search',
          'region' => 'footer',
          'weight' => 0,
        ),
        'os-install_status' => array(
          'module' => 'os',
          'delta' => 'install_status',
          'region' => 'footer',
          'weight' => '10',
        ),
        'boxes-iqss_projects_fp_infoblock' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_infoblock',
          'weight' => -100,
          'region' => 'content_top',
        ),
        'boxes-iqss_projects_fp_logoblock' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_logoblock',
          'weight' => -100,
          'region' => 'header_first',
        ),
        'boxes-iqss_projects_fp_features' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_features',
          'weight' => 10,
          'region' => 'content_first',
        ),
        'boxes-iqss_projects_fp_stats' => array(
          'module' => 'os_stats',
          'delta' => 'os_stats',
          'weight' => 10,
          'region' => 'footer',
        ),
        'boxes-iqss_projects_fp_navblock' => array(
          'module' => 'boxes',
          'delta' => 'iqss_projects_fp_navblock',
          'weight' => -100,
          'region' => 'header_second',
        ),
        'views-os_websites-block' => array(
          'module' => 'views',
          'delta' => 'os_websites-block',
          'region' => 'content_bottom',
          'weight' => '-9',
        ),
        'os_front-os_front_header' => array(
          'module' => 'os_front',
          'delta' => 'os_front_header',
          'weight' => 0,
          'region' => 'header_second',
        ),
        'boxes-os_front_main_support' => array(
          'module' => 'boxes',
          'delta' => 'os_front_main_support',
          'weight' => 0,
          'region' => 'content_first',
        ),
        'boxes-os_front_main_configure' => array(
          'module' => 'boxes',
          'delta' => 'os_front_main_configure',
          'weight' => 0,
          'region' => 'content_second',
        ),
        'vsite_register-get_your_site_block' => array(
          'weight' => 2,
          'region' => 'header_second',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active on the frontpage in multi-tenant installs');
  t('OpenScholar');
  $export['os_sitewide_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'os_users';
  $context->description = 'Context that is active when in a user area of an Openscholar site, like user profile or log in screen';
  $context->tag = 'OpenScholar';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'users' => 'users',
        'user/*' => 'user/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context that is active when in a user area of an Openscholar site, like user profile or log in screen');
  t('OpenScholar');
  $export['os_users'] = $context;

  return $export;
}
