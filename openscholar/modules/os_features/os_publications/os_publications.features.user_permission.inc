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

  // Exported permission: access biblio content.
  $permissions['access biblio content'] = array(
    'name' => 'access biblio content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content editor',
      4 => 'manager',
      5 => 'vsite admin',
      6 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: administer biblio.
  $permissions['administer biblio'] = array(
    'name' => 'administer biblio',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: create biblio content.
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      0 => 'administrator',
      2 => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: delete biblio content.
  $permissions['delete biblio content'] = array(
    'name' => 'delete biblio content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: delete own biblio content.
  $permissions['delete own biblio content'] = array(
    'name' => 'delete own biblio content',
    'roles' => array(
      0 => 'administrator',
      2 => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit biblio content.
  $permissions['edit biblio content'] = array(
    'name' => 'edit biblio content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit biblio contributor.
  $permissions['edit biblio contributor'] = array(
    'name' => 'edit biblio contributor',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit own biblio content.
  $permissions['edit own biblio content'] = array(
    'name' => 'edit own biblio content',
    'roles' => array(
      0 => 'administrator',
      2 => 'manager',
    ),
    'module' => 'biblio',
  );

  // Exported permission: import from file.
  $permissions['import from file'] = array(
    'name' => 'import from file',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
      2 => 'manager',
      3 => 'vsite admin',
      4 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show download links.
  $_permissions['show download links'] = array(
    'name' => 'show download links',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'manager',
      4 => 'vsite admin',
      5 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show export links.
  $permissions['show export links'] = array(
    'name' => 'show export links',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'manager',
      4 => 'vsite admin',
      5 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show filter tab.
  $_permissions['show filter tab'] = array(
    'name' => 'show filter tab',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'manager',
      4 => 'vsite admin',
      5 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  // Exported permission: show sort links.
  $_permissions['show sort links'] = array(
    'name' => 'show sort links',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'manager',
      4 => 'vsite admin',
      5 => 'vsite user',
    ),
    'module' => 'biblio',
  );

    // Exported permission: create biblio content.
  $permissions['create biblio content'] = array(
    'name' => 'create biblio content',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
      2 => 'vsite admin',
      3 => 'vsite user',
      4 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: delete own biblio content.
  $permissions['delete own biblio entries'] = array(
    'name' => 'delete own biblio entries',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
      2 => 'vsite admin',
      3 => 'vsite user',
      4 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit biblio entries.
  $permissions['edit biblio entries'] = array(
    'name' => 'edit biblio entries',
    'roles' => array(
      0 => 'administrator',
      1 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: edit own biblio entries.
  $permissions['edit own biblio entries'] = array(
    'name' => 'edit own biblio entries',
    'roles' => array(
      0 => 'administrator',
      1 => 'manager',
      2 => 'vsite admin',
      3 => 'vsite user',
      4 => 'content editor',
    ),
    'module' => 'biblio',
  );

  // Exported permission: view full text
  $_permissions['view full text'] = array(
    'name' => 'view full text',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'content editor',
      4 => 'manager',
      5 => 'vsite admin',
      6 => 'vsite user',
    ),
    'module' => 'biblio',
  );

  return $permissions;
}
