<?php

function cf_config_form($form, &$form_state) {
  $form = array();
 
  $form['cf_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => variable_get('global_admin_mail_address', ''),
    '#required' => TRUE,
  );
 
  $form['cf_node_types'] = array(
    '#type' => 'select',
    '#title' => t('Node types'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('cf_node_types',''),
    '#required' => TRUE,    
  );
  $form['#submit'][] = 'request_config';
  return system_settings_form($form);  
}

function request_config($form, $form_state){
    $values = array(
      'global_admin_mail_address' => $form_state['values']['cf_email'],
      'cf_node_types'=>$form_state['values']['cf_node_types'],
    );
   
    foreach ($values as $key => $value) {
      variable_set($key, $value);
     // dpm("$key || $value");
     
    }
  }