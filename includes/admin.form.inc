<?php

/**
 * @file
 * form to configure which datastream to regenerate
 * and which datastream triggers regeneration
 * find at: Admin -> Islandora -> Islandora Utility Modules -> Islandora Regenerate DS
 */


/**
 * admin form and submission handler
 */

function islandora_regenerate_ds_admin_form($form, &$form_state) {
  $lazarus = variable_get('islandora_regenerate_ds_lazarus');
  $trigger = variable_get('islandora_regenerate_ds_trigger');
  $lazarus = isset($lazarus) ? $lazarus : '';
  $trigger = isset($trigger) ? $trigger : '';
  $form['lazarus'] = array(
    '#title' => 'Set regenerating datastream',
    '#type' => 'textfield',
    '#value' => $lazarus,
    '#description' => 'String value of a datastream, to be regenerated. ie: DC or MODS'
  );
  $form['trigger'] = array(
    '#title' => 'Set trigger datastream to cause regeneration',
    '#type' => 'textfield',
    '#value' => $trigger,
    '#description' => 'String value of a datastream, to trigger regeneration. ie: MODS or DC',
  );
  return $form;
}

function islandora_regenerate_ds_admin_form_submit($form, &$form_state) {
  variable_set('islandora_regenerate_ds_lazarus', $form_state['lazarus']);
  variable_set('islandora_regenerate_ds_trigger', $form_state['trigger']);
}
