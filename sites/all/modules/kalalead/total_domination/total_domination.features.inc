<?php
/**
 * @file
 * total_domination.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function total_domination_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function total_domination_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function total_domination_node_info() {
  $items = array(
    'winning' => array(
      'name' => t('Winning'),
      'base' => 'node_content',
      'description' => t('Just winning all day and all night tiger style'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
