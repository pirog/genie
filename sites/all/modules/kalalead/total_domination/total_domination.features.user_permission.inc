<?php
/**
 * @file
 * total_domination.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function total_domination_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access navbar'.
  $permissions['access navbar'] = array(
    'name' => 'access navbar',
    'roles' => array(),
    'module' => 'navbar',
  );

  return $permissions;
}
