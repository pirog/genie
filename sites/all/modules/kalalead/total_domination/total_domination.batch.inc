<?php
/**
 * @file
 * Batch function
 */

/*
 * Batch for drupal function
 */
function total_domination_drupal_batch($url, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Many tries and headaches but this curl gets em all
  $agent = 'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)';
  $ch=curl_init();
  curl_setopt($ch, CURLOPT_URL,$url);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
  curl_setopt($ch, CURLOPT_USERAGENT, $agent);
  $check = curl_exec($ch);
  $info = curl_getinfo($ch);
  curl_close($ch);

  if (strpos($check, 'not-logged-in') !== false) {
    $title_check = preg_match("/<title>(.*)<\/title>/siU", $check, $title_matches);
    if (!$title_check) { return null; }
    $title_pre = preg_replace('/\s+/', ' ', $title_matches[1]);
    $title_pre = trim($title_pre);
    $title_clean = explode('|',$title_pre);
    $count = count($title_clean);
    if ($count == 1) {
      $title = $title_clean[0];
    } else {
      $new_url = explode('http://www.', trim($url));
      $url_check = substr($new_url[1], 0, -4);
      if ($url_check == strtolower(trim($title_clean[0]))) {
        $title = $title_clean[0];
      } elseif ($url_check == strtolower(trim($title_clean[1]))){
        $title = $title_clean[1];
      } else {
        $title = ucfirst($url_check);
      }
    }
    $count = strlen($title);
    if ($count > 200) {
      $title = substr($title, 0, 200);
    }


    $xh=curl_init();
    curl_setopt($xh, CURLOPT_URL,$url . '/CHANGELOG.txt');
    curl_setopt($xh, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($xh, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($xh, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($xh, CURLOPT_BINARYTRANSFER, true);
    curl_setopt($xh, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($xh, CURLOPT_TIMEOUT_MS, 10000);
    curl_setopt($xh, CURLOPT_USERAGENT, $agent);
    $version = curl_exec($xh);
    curl_close($xh);
    $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
    $ver_get = substr(trim($ver_get), -4);

    // get version #, tried a few different cases (like switch) but this worked the best
    if (substr(trim($ver_get), -1) == ',') {
      $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
      $ver_get = substr(trim($ver_get), -5, -1);
      $ver_get = 'Drupal ' . substr(trim($ver_get), 0, 1) . ' Site';
    } elseif (substr(trim($ver_get), 0, 1) != '7') {
      if (substr(trim($ver_get), 0, 1) != '6') {
        if (substr(trim($ver_get), 0, 1) != '5') {
          if (substr(trim($ver_get), 0, 1) != '8') {
            if (substr(trim($ver_get), 0, 1) != '4') {
              $ver_get = 'Drupal 7 Site'; //Unkown who cares.
            }
          }
        }
      }
    } else {
      $ver_get = 'Drupal ' . substr(trim($ver_get), 0, 1) . ' Site';
    }

    $node = new stdClass();
    $node->type = 'winning';
    node_object_prepare($node);
    $node->title    = $title;
    $node->language = LANGUAGE_NONE;
    $node->field_drupal_version[$node->language][0]['value'] = $ver_get;
    $node->field_drupal_version[$node->language][0]['safe_value'] = $ver_get;
    $node->field_url[$node->language][0]['url'] =  check_plain($url);
    $node->field_url[$node->language][0]['title'] =  check_plain($url);
    $node->field_url[$node->language][0]['display_url'] =  check_plain($url);
    $node->field_exported[$node->language][0]['value'] =  0;
    node_save($node);

    $context['results'][] = $node;
    //$context['results'][] = check_plain($url) . $drupal;
  }

  else {
    //watchdog('WTF', 'WTF - ' . $info['http_code']);
  }


  $context['message'] = t('Now assimilating %url', array('%url' => $url));
}

/*
 * Batch for ektron function
 */
function total_domination_ektron_batch($url, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Many tries and headaches but this curl gets em all
  $agent = 'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)';
  $ch=curl_init();
  curl_setopt($ch, CURLOPT_URL,$url);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
  curl_setopt($ch, CURLOPT_USERAGENT, $agent);
  $check = curl_exec($ch);
  $info = curl_getinfo($ch);
  curl_close($ch);


  if (strpos($check, 'EktronClientManager') !== false) {
    $title_check = preg_match("/<title>(.*)<\/title>/siU", $check, $title_matches);
    if (!$title_check) { return null; }
    $title_pre = preg_replace('/\s+/', ' ', $title_matches[1]);
    $title_pre = trim($title_pre);
    $title_clean = explode('|',$title_pre);
    $count = count($title_clean);
    if ($count == 1) {
      $title = $title_clean[0];
    } else {
      $new_url = explode('http://www.', trim($url));
      $url_check = substr($new_url[1], 0, -4);
      if ($url_check == strtolower(trim($title_clean[0]))) {
        $title = $title_clean[0];
      } elseif ($url_check == strtolower(trim($title_clean[1]))){
        $title = $title_clean[1];
      } else {
        $title = ucfirst($url_check);
      }
    }
    $count = strlen($title);
    if ($count > 200) {
      $title = substr($title, 0, 200);
    }

    $node = new stdClass();
    $node->type = 'winning';
    node_object_prepare($node);
    $node->title    = $title;
    $node->language = LANGUAGE_NONE;
    $node->field_drupal_version[$node->language][0]['value'] = 'Ektron';
    $node->field_drupal_version[$node->language][0]['safe_value'] = 'Ektron';
    $node->field_url[$node->language][0]['url'] =  check_plain($url);
    $node->field_url[$node->language][0]['title'] =  check_plain($url);
    $node->field_url[$node->language][0]['display_url'] =  check_plain($url);
    $node->field_exported[$node->language][0]['value'] =  0;
    node_save($node);
    $context['results'][] = $node;
  }
  else {
    //watchdog('WTF', 'WTF - ' . $info['http_code']);
  }


  $context['message'] = t('Now assimilating %url', array('%url' => $url));
}

/*
 * Batch for all function
 */
function total_domination_all_batch($url, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  // Many tries and headaches but this curl gets em all
  $agent = 'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)';
  $ch=curl_init();
  curl_setopt($ch, CURLOPT_URL,$url);
  curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
  curl_setopt($ch, CURLOPT_BINARYTRANSFER, true);
  curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
  curl_setopt($ch, CURLOPT_TIMEOUT_MS, 10000);
  curl_setopt($ch, CURLOPT_USERAGENT, $agent);
  $check = curl_exec($ch);
  $info = curl_getinfo($ch);
  curl_close($ch);

  if (strpos($check, 'not-logged-in') !== false) {
    $title_check = preg_match("/<title>(.*)<\/title>/siU", $check, $title_matches);
    if (!$title_check) { return null; }
    $title_pre = preg_replace('/\s+/', ' ', $title_matches[1]);
    $title_pre = trim($title_pre);
    $title_clean = explode('|',$title_pre);
    $count = count($title_clean);
    if ($count == 1) {
      $title = $title_clean[0];
    } else {
      $new_url = explode('http://www.', trim($url));
      $url_check = substr($new_url[1], 0, -4);
      if ($url_check == strtolower(trim($title_clean[0]))) {
        $title = $title_clean[0];
      } elseif ($url_check == strtolower(trim($title_clean[1]))){
        $title = $title_clean[1];
      } else {
        $title = ucfirst($url_check);
      }
    }
    $count = strlen($title);
    if ($count > 200) {
      $title = substr($title, 0, 200);
    }


    $xh=curl_init();
    curl_setopt($xh, CURLOPT_URL,$url . '/CHANGELOG.txt');
    curl_setopt($xh, CURLOPT_CONNECTTIMEOUT, 2);
    curl_setopt($xh, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($xh, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($xh, CURLOPT_BINARYTRANSFER, true);
    curl_setopt($xh, CURLOPT_FOLLOWLOCATION, true);
    curl_setopt($xh, CURLOPT_TIMEOUT_MS, 10000);
    curl_setopt($xh, CURLOPT_USERAGENT, $agent);
    $version = curl_exec($xh);
    curl_close($xh);
    $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
    $ver_get = substr(trim($ver_get), -4);

    // get version #, tried a few different cases (like switch) but this worked the best
    if (substr(trim($ver_get), -1) == ',') {
      $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
      $ver_get = substr(trim($ver_get), -5, -1);
      $ver_get = 'Drupal ' . substr(trim($ver_get), 0, 1) . ' Site';
    } elseif (substr(trim($ver_get), 0, 1) != '7') {
      if (substr(trim($ver_get), 0, 1) != '6') {
        if (substr(trim($ver_get), 0, 1) != '5') {
          if (substr(trim($ver_get), 0, 1) != '8') {
            if (substr(trim($ver_get), 0, 1) != '4') {
              $ver_get = 'Drupal 7 Site'; //Unkown who cares.
            }
          }
        }
      }
    } else {
      $ver_get = 'Drupal ' . substr(trim($ver_get), 0, 1) . ' Site';
    }

    $node = new stdClass();
    $node->type = 'winning';
    node_object_prepare($node);
    $node->title    = $title;
    $node->language = LANGUAGE_NONE;
    $node->field_drupal_version[$node->language][0]['value'] = $ver_get;
    $node->field_drupal_version[$node->language][0]['safe_value'] = $ver_get;
    $node->field_url[$node->language][0]['url'] =  check_plain($url);
    $node->field_url[$node->language][0]['title'] =  check_plain($url);
    $node->field_url[$node->language][0]['display_url'] =  check_plain($url);
    $node->field_exported[$node->language][0]['value'] =  0;
    node_save($node);

    $context['results'][] = $node;
    //$context['results'][] = check_plain($url) . $drupal;
  }

  else if (strpos($check, 'EktronClientManager') !== false) {
    $title_check = preg_match("/<title>(.*)<\/title>/siU", $check, $title_matches);
    if (!$title_check) { return null; }
    $title_pre = preg_replace('/\s+/', ' ', $title_matches[1]);
    $title_pre = trim($title_pre);
    $title_clean = explode('|',$title_pre);
    $count = count($title_clean);
    if ($count == 1) {
      $title = $title_clean[0];
    } else {
      $new_url = explode('http://www.', trim($url));
      $url_check = substr($new_url[1], 0, -4);
      if ($url_check == strtolower(trim($title_clean[0]))) {
        $title = $title_clean[0];
      } elseif ($url_check == strtolower(trim($title_clean[1]))){
        $title = $title_clean[1];
      } else {
        $title = ucfirst($url_check);
      }
    }
    $count = strlen($title);
    if ($count > 200) {
      $title = substr($title, 0, 200);
    }

    $node = new stdClass();
    $node->type = 'winning';
    node_object_prepare($node);
    $node->title    = $title;
    $node->language = LANGUAGE_NONE;
    $node->field_drupal_version[$node->language][0]['value'] = 'Ektron';
    $node->field_drupal_version[$node->language][0]['safe_value'] = 'Ektron';
    $node->field_url[$node->language][0]['url'] =  check_plain($url);
    $node->field_url[$node->language][0]['title'] =  check_plain($url);
    $node->field_url[$node->language][0]['display_url'] =  check_plain($url);
    $node->field_exported[$node->language][0]['value'] =  0;
    node_save($node);
    $context['results'][] = $node;
  }
  else {
    //watchdog('WTF', 'WTF - ' . $info['http_code']);
  }


  $context['message'] = t('Now assimilating %url', array('%url' => $url));
}

/*
 * Batch finished
 */
function total_domination_batch_finished($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  $items = array();
  if ($success) {
    $message = format_plural(count($results), 'One URL assimilated.', '@count drones assimilated.');
  }
  else {
    $message = t('Assimilation was futile!');
  }
  drupal_set_message($message);

  $to = "andrew@kalamuna.com, john@kalamuna.com";
  // multiple recipients:
  // The formatting of this string must comply with RFC 2822
  // $to = "recip@host.com, anotherrecip@host.com, again@agin.com";

  //this has to be from your server,
  //or you could get blocked by spam blocker
  $email_from = "theborg@kalamuna.com";

  //build an array called $params to pass
  //whatever you want to the email
  $params = array();

  $sent = drupal_mail('total_domination', 'key', $to, language_default(), $params, $email_from, TRUE);

  // Providing data for the redirected page is done through $_SESSION.
  drupal_goto('admin/kalalead/lead/new');
}

/*
 *  drupal mail looks for a function that matches the first parameter _ mail to build the message
 */
function total_domination_mail($key, &$message, $params) {
  $vars = array();
  $language = $message['language'];
  switch($key) {
    //switching on $key lets you create variations of the email based on the $key parameter
    case 'key':
      $message['subject'] = t('NEW LEADS!');
      //the email body is here, inside the $message array
      $output  = '';
      $output .= 'You have new leads to check out at http://assimilate.kalamuna.com';
      $message['body'][] = $output;
    break;
  }
}
