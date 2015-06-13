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
  'title' => t('Form of Doom'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Total Domination'), -9),
  'render callback' => 'total_domination_form_of_doom_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function total_domination_form_of_doom_content_type_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass;
  $block->content = drupal_get_form('total_domination_form_of_doom_form');
  return $block;
}

/**
 * Form constructor of domination
 */
function total_domination_form_of_doom_form($form, &$form_state) {

  $form['get'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('GET ALL THE LEADS') . '</h2>',
  );
  $form['close'] = array(
    '#type' => 'markup',
    '#markup' => '<h3>' . t('CLOSE ALL THE DEALZ') . '</h3>',
  );

  $form['cms'] = array(
    '#type' => 'select',
    '#title' => t('What type of droids are we searching for?'),
    '#options' => array(
      '00' => t(' -- Must SELECT --'),
      'all' => t('ALL CMS'),
      'drupal' => t('Drupal Only'),
      'ektron' => t('Ektron Only'),
    ),
    '#default_value' => 0,
    '#required' => TRUE,
  );

  $form['urls'] = array(
    '#required' => TRUE,
    '#type' => 'textarea',
    '#title' => t('URLS TO ASSIMILATE'),
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
function total_domination_form_of_doom_form_validate($form, &$form_state) {
  $test = '1';
  // Make sure the defualt options isnt chosen.
  if ($form_state['values']['cms'] == '00') {
    form_set_error('cms', 'You must select a DROID');
  }

  // Put the URLs into an array and try to get them in the best
  // format possible for domination
  $urls = preg_split("/\r\n|\n|\r/", $form_state['values']['urls']);
  $parsed_urls = array();
  foreach ($urls as $url) {
    $parsed_url = parse_url($url);
    if (isset($parsed_url['scheme']) && isset($parsed_url['host'])) {
      $built_url = $parsed_url['scheme'] . "://" . $parsed_url['host'];
      if (filter_var($built_url, FILTER_VALIDATE_URL)) {
        $parsed_urls[] = $built_url;
      }
    }
  }
  $form_state['values']['urls'] = $parsed_urls;
}

/**
 * Submit the form of doom
 */
function total_domination_form_of_doom_form_submit($form, &$form_state) {
  $operations = array();
  $cms = $form_state['values']['cms'];
  switch ($cms) {
    case 'all':
      foreach ($form_state['values']['urls'] as $url) {
        $operations[] = array('total_domination_all_batch', array($url));
      }
      break;

    case 'drupal':
      foreach ($form_state['values']['urls'] as $url) {
        $operations[] = array('total_domination_drupal_batch', array($url));
      }
      break;

    case 'ektron':
      foreach ($form_state['values']['urls'] as $url) {
        $operations[] = array('total_domination_ektron_batch', array($url));
      }
      break;

    default:
      # code...
      break;
  }

  $batch = array(
    'title' => t('Assimilating...'),
    'operations' => $operations,
    'finished' => 'total_domination_batch_finished',
    'file' => drupal_get_path('module', 'total_domination') . '/total_domination.batch.inc',
  );
  batch_set($batch);
}
