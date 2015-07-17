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
      // Check for a period to reduce total checks and times.
      $line_trill = (strpos($line_fix,'.') !== false) ? true : false;
      if ($line_trill) {
        $lines[] = $line_fix;
      }
    }
    fclose($handle);
    // Clean up temp files.
    file_delete($file);
    file_unmanaged_delete($uri);

    foreach ($lines as $line) {
      $operations[] = array('total_domination_macro_batch', array($line));
    }
    // Set up the global domains var.
    _total_domination_macro_domains();

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


/**
 * List of domain suffixes from the interwebz
 * Easier to set this as a Global since we dont have to run it everytime as it was
 * < PHP 5.6 doesnt allow constants as arrays very easily
 * so this is the easiest way to do this right meow.
 *
 * @return global object domain suffixes
 */
function _total_domination_macro_domains() {
  variable_set('total_domination_macro_domains', array(
'.ac','.ac.uk','.ad','.ae','.aero','.af','.ag','.ai','.al','.am','.an','.ao','.aq','.ar','.arpa','.as','.asia','.at','.au','.aw','.ax','.az','.ba','.bb','.bd','.be','.bf','.bg','.bh','.bi','.biz','.bj','.bm','.bn','.bo','.br','.bs','.bt','.bv','.bw','.by','.bz','.ca','.cat','.cc','.cd','.cf','.cg','.ch','.ci','.ck','.cl','.cm','.cn','.co','.co.uk','.com','.coop','.cr','.cs','.cu','.cv','.cx','.cy','.cz','.dd','.de','.dj','.dk','.dm','.do','.dz','.ec','.edu','.ee','.eg','.eh','.er','.es','.et','.eu','.fi','.firm','.fj','.fk','.fm','.fo','.fr','.fx','.ga','.gb','.gd','.ge','.gf','.gh','.gi','.gl','.gm','.gn','.gov','.gov.uk','.gp','.gq','.gr','.gs','.gt','.gu','.gw','.gy','.hk','.hm','.hn','.hr','.ht','.hu','.id','.ie','.il','.im','.in','.info','.int','.io','.iq','.ir','.is','.it','.je','.jm','.jo','.jobs','.jp','.ke','.kg','.kh','.ki','.km','.kn','.kp','.kr','.kw','.ky','.kz','.la','.lb','.lc','.li','.lk','.lr','.ls','.lt','.ltd.uk','.lu','.lv','.ly','.ma','.mc','.md','.me','.me.uk','.mg','.mh','.mil','.mk','.ml','.mm','.mn','.mo','.mobi','.mod.uk','.mp','.mq','.mr','.ms','.mt','.mu','.museum','.mv','.mw','.mx','.my','.mz','.na','.name','.nato','.nc','.ne','.net','.net.uk','.nf','.ng','.nhs.uk','.ni','.nl','.no','.nom','.np','.nr','.nt','.nu','.nz','.om','.org','.org.uk','.pa','.pe','.pf','.pg','.ph','.pk','.pl','.plc.uk','.pm','.pn','.post','.pr','.pro','.ps','.pt','.pw','.py','.qa','.re','.ro','.rs','.ru','.rw','.sa','.sb','.sc','.sch.uk','.sd','.se','.sg','.sh','.si','.sj','.sk','.sl','.sm','.sn','.so','.sr','.ss','.st','.store','.su','.sv','.sy','.sz','.tc','.td','.tel','.tf','.tg','.th','.tj','.tk','.tl','.tm','.tn','.to','.tp','.tr','.travel','.tt','.tv','.tw','.tz','.ua','.ug','.uk','.um','.us','.uy','.va','.vc','.ve','.vg','.vi','.vn','.vu','.web','.wf','.ws','.xxx','.ye','.yt','.yu','.za','.zm','.zr','.zw',
  ));
}
