<?php
/**
 * @file
 * os_publications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os_publications_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access biblio content'.
  $permissions['access biblio content'] = array(
    'name' => 'access biblio content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'content editor' => 'content editor',
      'manager' => 'manager',
      'vsite admin' => 'vsite admin',
      'vsite user' => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'administer biblio'.
  $permissions['manage biblio structure'] = array(
    'name' => 'manage biblio structure',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'administer biblio'.
  $permissions['administer biblio'] = array(
    'name' => 'administer biblio',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'create biblio content'.
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'delete biblio content'.
  $permissions['delete biblio content'] = array(
    'name' => 'delete biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'delete own biblio content'.
  $permissions['delete own biblio content'] = array(
    'name' => 'delete own biblio content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'edit biblio content'.
  $permissions['edit biblio content'] = array(
    'name' => 'edit biblio content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'edit biblio authors'.
  $permissions['edit biblio authors'] = array(
    'name' => 'edit biblio authors',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'edit own biblio content'.
  $permissions['edit own biblio content'] = array(
    'name' => 'edit own biblio content',
    'roles' => array(
      'administrator' => 'administrator',
      'manager' => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'import from file'.
  $permissions['import from file'] = array(
    'name' => 'import from file',
    'roles' => array(
      'administrator' => 'administrator',
      'content editor' => 'content editor',
      'manager' => 'manager',
      'vsite admin' => 'vsite admin',
      'vsite user' => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: 'show export links'.
  $permissions['show export links'] = array(
    'name' => 'show export links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'manager' => 'manager',
      'vsite admin' => 'vsite admin',
      'vsite user' => 'vsite user',
    ),
    'module' => 'biblio',
  );

  return $permissions;
}
