<?php
/**
 * @file
 * TOTAL DOM FORM
 */

/**
* This plugin array is more or less self documenting
*/
$plugin = array(
  // the title in the admin
  'title' => t('Form of Cleanup'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Total Domination'), -9),
  'render callback' => 'total_clean_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function total_clean_content_type_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass;
  $block->content = drupal_get_form('total_clean_form');
  return $block;
}

/**
 * Form constructor of domination
 */
function total_clean_form($form, &$form_state) {

  $form['get'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('CLEAN THIS SHIZZY UP') . '</h2>',
  );

  $form['whatwedoin'] = array(
    '#type' => 'select',
    '#title' => t('Choose your poison:'),
    '#options' => array(
      '00' => t(' -- Must SELECT --'),
      'cache' => t('Cleanse Caches'),
      'batch' => t('Clean Batch Table'),
      'nodes' => t('Clean Nodes Older Than 1 Month'),
    ),
    '#default_value' => '00',
    '#required' => TRUE,
  );


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Make it so',
  );

  return $form;
}

/**
 * Validate the form of doom
 */
function total_clean_form_validate($form, &$form_state) {
  $test = '1';
  // Make sure the defualt options isnt chosen.
  if ($form_state['values']['whatwedoin'] == '00') {
    form_set_error('whatwedoin', 'You must say WHAT WE BE DOIN HERE');
  }
}

/**
 * Submit the form of doom
 */
function total_clean_form_submit($form, &$form_state) {
  $operations = array();
  $what = $form_state['values']['whatwedoin'];
  switch ($what) {
    case 'cache':
      _total_clean_caches();
      break;

    case 'batch':
      _total_clean_batch_cleanse();
      break;

    case 'nodes':
      _total_clean_old_nodes();
      break;
  }

}

function _total_clean_caches() {
  // This way we know all the caches are really being cleaned.
  // Grab all the tables.
  $caches = db_query('SHOW TABLES')->fetchAll();
  foreach ($caches as $cache) {
    $tables[] = $cache->Tables_in_kalabox;
  }
  // Flatten and search for cache then dominate.
  foreach ($tables as $clean) {
    if (strpos($clean, 'cache') !== false) {
      db_truncate($clean)->execute();
    }
  }
  drupal_set_message(t('ALL CACHE Tables hasth been cleansed of evil, WE WIN'), 'status', FALSE);
}

function _total_clean_batch_cleanse() {
  // See if any rowz to cleanse.
  $row = db_query('SELECT * FROM batch')->rowCount();
  // Then DO IT.
  if ($row > 0) {
    db_query('DELETE FROM batch');
    drupal_set_message(t('The Batch Tables hasth been cleansed of :row Rowz', array(':row' => $row)), 'status', FALSE);
  }
  else {
    drupal_set_message(t('The Batch Tables hasth already been cleansed of evil, WE WIN'), 'status', FALSE);
  }
}

function _total_clean_old_nodes() {
  $months = strtotime('-1 month');
  $nodez = db_query('SELECT nid from node WHERE created < :months', array(':months' => $months))->fetchAll();

  if (count($nodez) > 0) {
    foreach ($nodez as $node) {
      $operations[] = array('total_domination_cleanse_batch', array($node->nid));
    }

    $batch = array(
      'title' => t('CLEANSING...'),
      'operations' => $operations,
      'finished' => 'total_domination_batch_cleanse_finished',
      'file' => drupal_get_path('module', 'total_domination') . '/total_domination.batch-cleanse.inc',
    );
    batch_set($batch);
  }
  else {
    drupal_set_message(t('This mofo\'s nodes are so super trill, no nodes to cleanse!'), 'status', FALSE);
  }

}
