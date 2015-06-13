<?php
/**
 * @file
 * Logo plugin
 */

/**
* This plugin array is more or less self documenting
*/
$plugin = array(
  // the title in the admin
  'title' => t('Kalalogo'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Total Domination'), -9),
  'render callback' => 'total_domination_logo_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function total_domination_logo_content_type_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass;
  $block->content = '<img src="/' . drupal_get_path('module', 'total_domination') . '/images/logo.png'  . '" width="150" height="195" alt="">';
  return $block;
}
