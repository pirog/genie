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
    '#type' => 'checkboxes',
    '#title' => t('What type of droids are we searching for?'),
    '#options' => array(
      'drupal' => t('Drupal'),
      'ektron' => t('Ektron'),
      'wp' => t('Wordpress'),
    ),
    '#default_value' => array('drupal','ektron','wp'),
    '#required' => TRUE,
  );

  $form['upload'] = array(
    '#type' => 'checkbox',
    '#title' => t('Check here if you want to upload via file'),
  );

  $form['urls'] = array(
    '#type' => 'textarea',
    '#title' => t('URLS TO ASSIMILATE'),
    '#states' => array(
      'required' => array(':input[name="upload"]' =>  array('checked' => FALSE)),
      'visible' => array(':input[name="upload"]' =>  array('checked' => FALSE)),
    ),
  );

  $form['uploadz'] = array(
    '#type' => 'file',
    '#title' => t('FILE TO DOMINATE'),
    '#description' => t('Upload a file, allowed extensions: txt'),
    '#states' => array(
      'required' => array(':input[name="upload"]' =>  array('checked' => TRUE)),
      'visible' => array(':input[name="upload"]' =>  array('checked' => TRUE)),
    ),
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
  // Required doesnt work well with states it seemz.
  if (!$form['upload']['#checked'] && empty($form_state['values']['urls'])) {
    form_set_error('urls', 'You can\'t leave this blank, sup with DAT?');
  }
  elseif ($form['upload']['#checked']) {
    $file = file_save_upload('uploadz');
    if (!isset($file)) {
      form_set_error('uploadz', 'Where\'s your file at FOOL?');
    }
    else {
      $validators = array('file_validate_extensions' => array('txt'));
      $file = file_save_upload('uploadz', $validators);
    }
  }
}

/**
 * Submit the form of doom
 */
function total_domination_form_of_doom_form_submit($form, &$form_state) {
  $operations = array();
  $urls = _total_domination_process_urls($form, $form_state);
  $cms_check = $form_state['values']['cms'];

  // Remove empty checkboxes as it is causing oddness in the batch.
  foreach ($cms_check as $project) {
    if ($project) {
      $cms[] = $project;
    }
  }

  // Set the operations through batch magix.
  foreach ($urls as $url) {
    $operations[] = array('total_domination_cms_batch', array($url, $cms));
  }

  // Engage.
  $batch = array(
    'title' => t('Assimilating...'),
    'operations' => $operations,
    'finished' => 'total_domination_batch_finished',
    'file' => drupal_get_path('module', 'total_domination') . '/total_domination.batch.inc',
  );

  batch_set($batch);
}

/**
 * Make all the urls happy via text or file.
 *
 * @param object $form, $form_state
 *   Obvious form objects
 *
 * @return object $parsed_urls
 *   The parsed happiness of urls to win.
 */
function _total_domination_process_urls($form, $form_state) {
  // If a File
  if (empty($form_state['values']['urls'])) {
    $file = file_save_upload('uploadz');
    $uri = $file->uri;
    $fhandle = fopen($uri, 'r');
    $urlzzz = fread($fhandle, filesize($uri));
    fclose($fhandle);
  }
  // If the text box
  else {
    $urlzzz = $form_state['values']['urls'];
  }

  // Put the URLs into an array and try to get them in the best
  // format possible for domination
  $urls = preg_split("/\r\n|\n|\r/", $urlzzz);
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
  return $parsed_urls;
}
