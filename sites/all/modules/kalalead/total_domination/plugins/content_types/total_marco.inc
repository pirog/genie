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
  'title' => t('Marco List Win'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
  'category' => array(t('Total Domination'), -9),
  'render callback' => 'total_macro_content_type_render'
);

/**
* Run-time rendering of the body of the block (content type)
* See ctools_plugin_examples for more advanced info
*/
function total_macro_content_type_render($subtype, $conf, $context = NULL) {
  // our output is generate by js. Any markup or theme functions
  // could go here.
  // that private js function is so bad that fixing it will be the
  // basis of the next tutorial
  $block = new stdClass;
  $block->content = drupal_get_form('total_macro_form');
  return $block;
}

/**
 * Form constructor of domination
 */
function total_macro_form($form, &$form_state) {

  $form['get'] = array(
    '#type' => 'markup',
    '#markup' => '<h2>' . t('PROCESS THAT GIANT ARSE LIST') . '</h2>
                  <h4>' . t('Use this form process the giant text files generated from the macro') . '</h4>',
  );

  $form['uploadz'] = array(
    '#type' => 'file',
    '#title' => t('GIANT FILE TO DOMINATE'),
    '#description' => t('Upload a file, allowed extensions: txt'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'LETZ DO THIS',
  );

  return $form;
}

/**
 * Validate the form of macro
 */
function total_macro_form_validate($form, &$form_state) {
  // Make sure there is a file
  $file = file_save_upload('uploadz');
  if (!isset($file)) {
    form_set_error('uploadz', 'Where\'s your file at FOOL?');
  }
  else {
    $validators = array('file_validate_extensions' => array('txt'));
    $file = file_save_upload('uploadz', $validators);
  }
}

/**
 * Submit the form of macro
 */
function total_macro_form_submit($form, &$form_state) {
  $operations = array();
  $file = file_save_upload('uploadz');
  $uri = $file->uri;
  $handle = fopen($uri, 'r');

  // Better file handling for large filez.
  if ($handle) {
    while (($line = fgets($handle)) !== false) {
      // This is removing all the odd shizzy thay the file is spitting back
      $line_fix = utf8_decode($line);
      $line_fix = str_replace("\0", "", $line_fix);
      $line_fix = str_replace("??", "", $line_fix);
      $line_fix = preg_replace('/\s+/', '', $line_fix);
      $lines[] = $line_fix;
    }
    fclose($handle);
    // Clean up temp files.
    file_unmanaged_delete($uri);

    foreach ($lines as $line) {
      $operations[] = array('total_domination_macro_batch', array($line));
    }

    $batch = array(
      'title' => t('Making this so super tronic...'),
      'operations' => $operations,
      'finished' => 'total_domination_batch_macro_finished',
      'file' => drupal_get_path('module', 'total_domination') . '/total_domination.batch-macro.inc',
    );
    batch_set($batch);
  } else {
    drupal_set_message(t('Could not open file!'), 'error', FALSE);
  }
}
