<?php
/**
 * @file
 * Batch function
 */

/*
 * CLEANSING Batch for drupal function
 */
function total_domination_cleanse_batch($nid, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Delete the nodes
  node_delete($nid);

  // Add nid to results
  $context['results'][] = $nid;

  $context['message'] = t('Now destroying %nid', array('%nid' => $nid));
}

/*
 * Batch finished
 */
function total_domination_batch_cleanse_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  $items = array();
  if ($success) {
    $message = format_plural(count($results), 'One URL destroyed.', '@count drones destroyed.');
  }
  else {
    $message = t('Assimilation was futile!');
  }

  drupal_set_message($message);

  // Providing data for the redirected page is done through $_SESSION.
  drupal_goto('admin/kalalead/clean');
}
