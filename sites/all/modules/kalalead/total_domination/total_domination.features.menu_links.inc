<?php
/**
 * @file
 * total_domination.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function total_domination_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_assimilate-more:admin/kalalead
  $menu_links['main-menu_assimilate-more:admin/kalalead'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/kalalead',
    'router_path' => 'admin/kalalead',
    'link_title' => 'Assimilate More',
    'options' => array(
      'identifier' => 'main-menu_assimilate-more:admin/kalalead',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_leads-won:admin/kalalead/lead/won
  $menu_links['main-menu_leads-won:admin/kalalead/lead/won'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/kalalead/lead/won',
    'router_path' => 'admin/kalalead/lead/won',
    'link_title' => 'Leads Won',
    'options' => array(
      'identifier' => 'main-menu_leads-won:admin/kalalead/lead/won',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_logout:user/logout
  $menu_links['main-menu_logout:user/logout'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_logout:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_new-leads:admin/kalalead/lead/new
  $menu_links['main-menu_new-leads:admin/kalalead/lead/new'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/kalalead/lead/new',
    'router_path' => 'admin/kalalead/lead/new',
    'link_title' => 'New Leads',
    'options' => array(
      'identifier' => 'main-menu_new-leads:admin/kalalead/lead/new',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Assimilate More');
  t('Leads Won');
  t('Logout');
  t('New Leads');

  return $menu_links;
}
