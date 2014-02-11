<?php

/**
 * @file
 * Builds placeholder replacement tokens for node-related data.
 */

/**
 * Implements hook_token_info().
 */
function vsite_token_info() {
  $type = array(
    'name' => t('Vsite'),
    'description' => t('Tokens related to a individual subsite, or "vsite".'),
  );

  // Core tokens for vsites.
  $vsite_tokens['site-purl'] = array(
    'name' => t("Site PURL"),
    'description' => t('The distinct purl associated with a "vsite".'),
  );

  return array(
    'types' => array('vsite' => $type),
    'tokens' => array('vsite' => $vsite_tokens),
  );
}

/**
 * Implements hook_tokens().
 */
function vsite_tokens($type, $tokens, array$data = array(), array$options = array()) {

  $sanitize = !empty($options['sanitize']);
  $replacements = array();

  // Only continues if we are replacing a vsite token.
  if ($type != 'vsite') {
    return $replacements;
  }

  $group_node = $vsite = FALSE;

  // Tries and get the vsite in one of three ways:
  // Method 1: The entity we are acting on is the vsite (group type)
  if (!empty($data['node']) && og_is_group('node', $data['node'])) {
    $group_node = $data['node'];
  }

  // Method 2: The entity we are acting on is group content, extract the group from the og_grp_ref fields
  elseif (!empty($data['node']) && og_is_group_content_type('node', $data['node']->type) && ($groups = og_get_entity_groups('node', $data['node']))) {
    if (isset($groups['node'])) {
      foreach ($groups['node'] as $group) {
        $grp = entity_load_single('node', $group);
        if (is_object($grp) && og_is_group('node', $grp)) {
          $group_node = $grp;
          break;
        }
      }
    }
  }

  // Method 3:  We are in the space context but the entity does not hold the ref field
  if (!$group_node && ($vsite = spaces_get_space())) {
    $group_node = $vsite->group;
  }

  // Only continues if we have loaded a valid vsite.
  if (!$group_node) {
    return $replacements;
  }

  if (!isset($vsite->group) && isset($group_node->nid)) {
    $vsite = vsite_get_vsite($group_node->nid)
  }

  foreach ($tokens as $name => $original) {
    switch ($name) {
      case 'site-purl':
        $purl = ($sanitize) ? check_plain($group_node->purl) : $group_node->purl;
        $replacements[$original] = $purl;
        break;
      case 'site-favicon-url':
        $value = file_create_url(_vsite_tokens_site_favicon_uri());
        $replacements[$original] = $value;
        break;
      case 'site-rel-author':
        $value = '';
        $replacements[$original] = $value;
        break;
      case 'site-rel-publisher':
        $value = '';
        $replacements[$original] = $value;
        break;
      case 'site-page-title':
        $value = '';
        $replacements[$original] = $value;
        break;
      case 'site-slogan':
        $value = '';
        $replacements[$original] = $value;
        break;
    }
  }

  return $replacements;
}

/**
 * Gets the custom favicon, theme favicon, or default favicon.
 */
function _vsite_tokens_site_favicon_uri() {
  $uri = '';

  $fid = variable_get('site_favicon_fid', '');
  if (!empty($fid)) {
    $uri = db_query('SELECT uri FROM {file_managed} WHERE fid = :fid', array(':fid' => $fid))->fetchColumn();
  }

  // If we aren't in a vsite, or if this vsite hasn't uploaded a custom favicon.
  if (empty($uri)) {
    $theme = variable_get('theme_default');
    $uri = drupal_get_path('theme', $theme) . '/favicon.ico';
    if (!file_exists($uri)) {
      $uri = drupal_get_path('theme', 'os_basetheme') . '/favicon.ico';
    }
  }

  return $uri;
}
