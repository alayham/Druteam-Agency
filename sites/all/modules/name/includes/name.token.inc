<?php
// $Id: name.token.inc,v 1.2.2.2 2010/10/10 05:32:06 aland Exp $

/**
 * @file
 * Provides the hooks required for Token module integration.
 */

/**
 * Internal implementation of hook_token_list().
 */
function _name_token_list($type = 'all') {
  $tokens = array();
  $tokens['name']['default'] = t('default');
  $tokens['name']['raw'] = t('default - raw');
  $tokens['name']['plain'] = t('default - plain');
  foreach (name_get_custom_format_options() as $machine_name => $name_title) {
    $tokens['name']['formatted-' . $machine_name] = t('%title', array('%title' => $name_title));
    $tokens['name']['formatted-' . $machine_name . '-raw'] = t('%title - raw', array('%title' => $name_title));
    $tokens['name']['formatted-' . $machine_name . '-plain'] = t('%title - plain', array('%title' => $name_title));
  }

  foreach (_name_translations() as $key => $title) {
    $tokens['name'][$key] = t('%part', array('%part' => $title));
    $tokens['name'][$key . '-raw'] = t('%part - raw', array('%part' => $title));
    $tokens['name'][$key . '-plain'] = t('%part - plain', array('%part' => $title));
  }

  return $tokens;
}

/**
 * Internal implementation of hook_token_values().
 */
function _name_token_values($type, $object = NULL) {
  global $language;

  $langcode = isset($language->language) ? $language->language : 'en';
  $item = $object[0];
  $param = array('object' => $object, 'type' => 'node');

  $name_components = array();
  foreach (_name_translations() as $key => $title) {
    if (!empty($item[$key])) {
      $name_components[$key] = $item[$key];
    }
    else {
      $name_components[$key] = '';
    }
  }
  $default = name_format($name_components, name_settings('default_format'), $param);
  foreach (_name_formatter_output_types() as $type => $type_title) {
    // The default type key is used for the short name tokens.
    $type_key = $type == 'default' ? '' : '-' . $type;

    $tokens[$type] = _name_value_sanitize($langcode, $default, NULL, $type);

    foreach (name_get_custom_format_options() as $machine_name => $name_title) {
      $format = name_get_format_by_machine_name($machine_name);
      $formated_name = name_format($name_components, $format, $param);
      $tokens['formatted-' . $machine_name . $type_key] =
          _name_value_sanitize($langcode, $formated_name, NULL, $type);
    }
    foreach (_name_translations() as $key => $title) {
      $tokens[$key]             = check_plain($name_components[$key]);
      $tokens[$key . '-raw']    = $name_components[$key];
      $tokens[$key . '-plain']  =  strip_tags($name_components[$key]);
    }
  }

  return $tokens;
}
