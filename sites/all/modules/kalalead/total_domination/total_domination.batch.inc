<?php
/**
 * @file
 * Batch function
 */


/*
 * Batch for ALL CMS function.
 */
function total_domination_cms_batch($url, $cms, &$context) {
  // Update our progress information.
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
  }
  $context['sandbox']['progress']++;

  $checks = _total_domination_curl($url);
  list($check, $info) = $checks;

  // Is not a bad page
  if ($info['http_code']) {
    foreach ($cms as $project) {
      if ($project == 'drupal') {
        // Check Drupal.
        $drupal = _total_domination_check_drupal($url, $check);
        if ($drupal) {
          list($title, $cms_result) = $drupal;
          _total_domination_node_create($title, $cms_result, $url);
          $context['results'][] = $url;
        }
      }
      elseif ($project == 'ektron') {
        // Check Ektron
        $ektron = _total_domination_check_ektron($url, $check);
        if ($ektron) {
          list($title, $cms_result) = $ektron;
          _total_domination_node_create($title, $cms_result, $url);
          $context['results'][] = $url;
        }
      }
      elseif ($project == 'wp') {
        // Check WordPress
        $wp = _total_domination_check_wp($url, $check);
        if ($wp) {
          list($title, $cms_result) = $wp;
          _total_domination_node_create($title, $cms_result, $url);
          $context['results'][] = $url;
        }
      }
    }
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

/**
 * Curl function for all magix happen.
 *
 * @param string $url
 *   The url in question
 *
 * @return object $return
 *   curl response + info
 */
function _total_domination_curl($url) {
  // Many tries and headaches but this curl gets em all
  $agent = 'Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)';
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL,$url);
  curl_setopt($ch, CURLOPT_ENCODING,  '');
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

  $result = array($check, $info);
  return $result;
}

/**
 * Get the title.
 *
 * @param string $url
 *   The url in question
 *
 * @param string $check
 *   curl response
 *
 * @return string $title
 *   formatted title string
 */
function _total_domination_check_title($url, $check) {
  $title_check = preg_match("/<title>(.*)<\/title>/siU", $check, $title_matches);
  // Error handling:
  if (!$title_check) { return null; }
  $title_pre = preg_replace('/\s+/', ' ', $title_matches[1]);
  $title_pre = trim($title_pre);
  $title_clean = explode('|',$title_pre);
  $count = count($title_clean);
  if ($count == 1) {
    $title = $title_clean[0];
  } else {
    // Match up title to preg_match.
    if (strpos(trim($url), 'http://www.') !== false) {
      $new_url = explode('http://www.', $url);
    }
    elseif (strpos(trim($url), 'https://www.') !== false) {
      $new_url = explode('https://www.', $url);
    }
    elseif (strpos(trim($url), 'http://') !== false) {
      $new_url = explode('http://', $url);
    }
    elseif (strpos(trim($url), 'https://') !== false) {
      $new_url = explode('https://', $url);
    }
    else {
      $new_url = $url;
    }
    // Check and set the title.
    $url_check = isset($new_url[1]) ? substr($new_url[1], 0, -4) : substr($new_url, 0, -4) ;
    if ($url_check == strtolower(trim($title_clean[0]))) {
      $title = $title_clean[0];
    } elseif ($url_check == strtolower(trim($title_clean[1]))){
      $title = $title_clean[1];
    } else {
      $title = ucfirst($url_check);
    }
  }
  // Fix large titles.
  $count = strlen($title);
  if ($count > 200) {
    $title = substr($title, 0, 200);
  }

  return $title;
}

/**
 * Creates the node.
 */
function _total_domination_node_create($title, $cms, $url) {
  $node = new stdClass();
  $node->type = 'winning';
  node_object_prepare($node);
  $node->title    = $title;
  $node->language = LANGUAGE_NONE;
  $node->field_drupal_version[$node->language][0]['value'] = $cms;
  $node->field_drupal_version[$node->language][0]['safe_value'] = $cms;
  $node->field_url[$node->language][0]['url'] =  check_plain($url);
  $node->field_url[$node->language][0]['title'] =  check_plain($url);
  $node->field_url[$node->language][0]['display_url'] =  check_plain($url);
  $node->field_exported[$node->language][0]['value'] =  0;
  node_save($node);
}

/**
 * Check for Drupal.
 *
 * @param string $url
 *   The url in question
 *
 * @param string $check
 *   curl response
 *
 * @return object $result
 *    the title and version OR return FALSE if not drupal.
 */
function _total_domination_check_drupal($url, $check) {
  // Check for up to Drupal 7.
  if (strpos($check, 'not-logged-in') !== false) {
    // Set the title.
    $title = _total_domination_check_title($url, $check);
    // Check CHANGELOG for versions.
    $versions = _total_domination_curl($url . '/CHANGELOG.txt');
    list($version, $info) = $versions;
    // If page is there.
    if ($info['http_code'] == 200) {
      $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
      $ver_get = substr(trim($ver_get), -4);

      // get version #.
      if (substr(trim($ver_get), -1) == ',') {
        $ver_get = str_replace(array("\r", "\n"), "", substr($version, 0, 12));
        $ver_get = substr(trim($ver_get), -5, -1);
        $ver_get = 'Drupal ' . substr(trim($ver_get), 0, 1) . ' Site';
      }
      else {
        $ver = substr(trim($ver_get), 0, 1);
        $ver_check = array('4','5','6','7','8');
        if (in_array($ver, $ver_check)) {
          $ver_get = 'Drupal ' . $ver . ' Site';
        }
        else {
          $ver_get = 'Drupal 7 Site'; //Unknown who cares.
        }
      }
    }
    else {
      $ver_get = 'Drupal 7 Site'; //Unkown 403, whatevz.
    }
    // Package it all up.
    $result = array($title, $ver_get);
    return $result;
  }
  else {
    return FALSE;
  }
}


/**
 * Check for Ektron.
 *
 * @param string $url
 *   The url in question
 *
 * @param string $check
 *   curl response
 *
 * @return object $result
 *    the title and version OR return FALSE if not Ektron.
 */
function _total_domination_check_ektron($url, $check) {
  if (strpos($check, 'EktronClientManager') !== false) {
    $title = _total_domination_check_title($url, $check);

    // Package it all up.
    $result = array($title, 'Ektron');
    return $result;
  }
  else {
    return FALSE;
  }
}

/**
 * Check for WordPress.
 *
 * @param string $url
 *   The url in question
 *
 * @param string $check
 *   curl response
 *
 * @return object $result
 *    the title and version OR return FALSE if not WordPress.
 */
function _total_domination_check_wp($url, $check) {
  if (strpos($check, 'wp-content') !== false) {
    $title = _total_domination_check_title($url, $check);

    // Package it all up.
    $result = array($title, 'Wordpress Site');
    return $result;
  }
  else {
    return FALSE;
  }
}
