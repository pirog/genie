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

  // If there is a period, then check if it is a domain.
  if (strpos($line, '.') !== false) {
    // Get all domain suffixes below:
    $suffixes = _total_domination_macro_domains();
    foreach ($suffixes as $suffix) {
      if (strpos($line, $suffix) !== false) {
        $url = 'http://' . trim($line);
        $context['results'][] = $url;
      }
    }
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
 * List of domain suffixes from the interwebz
 *
 * @return object domain suffixes
 */
function _total_domination_macro_domains() {
  return array(
'.ac','.ac.uk','.ad','.ae','.aero','.af','.ag','.ai','.al','.am','.an','.ao','.aq','.ar','.arpa','.as','.asia','.at','.au','.aw','.ax','.az','.ba','.bb','.bd','.be','.bf','.bg','.bh','.bi','.biz','.bj','.bm','.bn','.bo','.br','.bs','.bt','.bv','.bw','.by','.bz','.ca','.cat','.cc','.cd','.cf','.cg','.ch','.ci','.ck','.cl','.cm','.cn','.co','.co.uk','.com','.coop','.cr','.cs','.cu','.cv','.cx','.cy','.cz','.dd','.de','.dj','.dk','.dm','.do','.dz','.ec','.edu','.ee','.eg','.eh','.er','.es','.et','.eu','.fi','.firm','.fj','.fk','.fm','.fo','.fr','.fx','.ga','.gb','.gd','.ge','.gf','.gh','.gi','.gl','.gm','.gn','.gov','.gov.uk','.gp','.gq','.gr','.gs','.gt','.gu','.gw','.gy','.hk','.hm','.hn','.hr','.ht','.hu','.id','.ie','.il','.im','.in','.info','.int','.io','.iq','.ir','.is','.it','.je','.jm','.jo','.jobs','.jp','.ke','.kg','.kh','.ki','.km','.kn','.kp','.kr','.kw','.ky','.kz','.la','.lb','.lc','.li','.lk','.lr','.ls','.lt','.ltd.uk','.lu','.lv','.ly','.ma','.mc','.md','.me','.me.uk','.mg','.mh','.mil','.mk','.ml','.mm','.mn','.mo','.mobi','.mod.uk','.mp','.mq','.mr','.ms','.mt','.mu','.museum','.mv','.mw','.mx','.my','.mz','.na','.name','.nato','.nc','.ne','.net','.net.uk','.nf','.ng','.nhs.uk','.ni','.nl','.no','.nom','.np','.nr','.nt','.nu','.nz','.om','.org','.org.uk','.pa','.pe','.pf','.pg','.ph','.pk','.pl','.plc.uk','.pm','.pn','.post','.pr','.pro','.ps','.pt','.pw','.py','.qa','.re','.ro','.rs','.ru','.rw','.sa','.sb','.sc','.sch.uk','.sd','.se','.sg','.sh','.si','.sj','.sk','.sl','.sm','.sn','.so','.sr','.ss','.st','.store','.su','.sv','.sy','.sz','.tc','.td','.tel','.tf','.tg','.th','.tj','.tk','.tl','.tm','.tn','.to','.tp','.tr','.travel','.tt','.tv','.tw','.tz','.ua','.ug','.uk','.um','.us','.uy','.va','.vc','.ve','.vg','.vi','.vn','.vu','.web','.wf','.ws','.xxx','.ye','.yt','.yu','.za','.zm','.zr','.zw',
  );
}
