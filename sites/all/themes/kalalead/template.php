<?php
/**
 * @file
 * Primary pre/preprocess functions and alterations.
 */

/*
 * Bootstrap our menu blockd
 */
function kalalead_menu_link__menu_block(&$variables) {
    $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  if (in_array('active', $element['#attributes']['class'])) {
    unset($element['#attributes']['class']);
    $element['#attributes']['class'][] = 'btn btn-primary btn-lg btn-block';
  }
  else {
    unset($element['#attributes']['class']);
    $element['#attributes']['class'][] = 'btn btn-default btn-lg btn-block';
  }
  return '<button' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</button>\n";
}
