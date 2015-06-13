<?php
/**
 * @file
 * total_domination.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function total_domination_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|node|winning|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'winning';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Address',
    'weight' => '3',
    'children' => array(
      0 => 'field_first_name',
      1 => 'field_last_name',
      2 => 'field_job_title',
      3 => 'field_email',
      4 => 'field_phone',
      5 => 'field_address',
      6 => 'field_city',
      7 => 'field_state',
      8 => 'field_zip',
    ),
    'format_type' => 'field_group_multiple_container',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'parent_format_type' => 'div',
        'classes' => 'group-address field-group-field_group_multiple_container',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_address|node|winning|form'] = $field_group;

  return $export;
}
