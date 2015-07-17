<?php
/**
 * @file
 * Batch function
 */

/*
 * CLEANSING Batch for drupal function
 */
function total_domination_macro_batch($line, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  $domains = variable_get('total_domination_macro_domains', NULL);

  list($pos, $match) = _strposm_min2($line, $domains);
  if ($pos != false) {
    $url = 'http://' . trim($line);
    $context['results'][] = $url;
  }
  $context['message'] = t('Now winning %line', array('%line' => $line));
}

/*
 * Batch finished
 */
function total_domination_batch_macro_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  $items = array();
  if ($success) {
    variable_del('total_domination_macro_domains');
    _total_domination_save_csv($results);
    $message = format_plural(count($results), 'WIN.', '@count hasth been WON.');
  }
  else {
    $message = t('Assimilation was futile!');
  }

  drupal_set_message($message);

  // Providing data for the redirected page is done through $_SESSION.
  drupal_goto('admin/kalalead/macro');
}

/**
 * /Create a CSV.
 *
 * @param object $results
 *   Success results
 *
 * @return
 *
 */
function _total_domination_save_csv($results) {
  // Use date to win
  $now = date('dMY-His', strtotime('now'));
  $textfile_name = 'sites/default/files/' . $now . '.txt';
  // Add TXT File
  $fp = fopen($textfile_name, 'w');
  // Trill out the array:
  $results = array_unique($results);
  foreach ($results as $result) {
    fwrite($fp, $result . "\n");
  }
  fclose($fp);
  // Win out the node.
  $uri = 'public://' . $now . '.txt';

  file_transfer($uri, array(
    'Content-disposition' => 'attachment; filename='. $textfile_name,
    'Content-Type' => 'text/plain; utf-8',
  ));
  // One day figure out how to redirct after file transfer.
}

/**
 * STRPOS for ARRAYS taken from:
 * http://creativeandcritical.net/php-strposm-a-strpos-variant-that-accepts-an-array-of-needles
 * @param  string  $haystack - content searching
 * @param  object  $needles  - array you are looking at.
 * @param  integer $offset   - offest if you want it
 * @return see url for diff returns
 */
function _strposm_min2($haystack, $needles, $offset = 0) {
  $pattern = '('.implode('|', array_map('preg_quote', (array)$needles)).')';
  return preg_match($pattern, $haystack, $matches, PREG_OFFSET_CAPTURE, $offset)
           ? array_reverse($matches[0])
           : array(false, null);
}
