<?php
// $Id: features.filter.inc,v 1.1.2.9.2.5 2010/09/29 18:22:04 yhahn Exp $

/**
 * Implementation of hook_features_api().
 */
function filter_features_api() {
  return array(
    'filter' => array(
      'name' => t('Filter formats'),
      'default_hook' => 'filter_default_formats',
      'default_file' => FEATURES_DEFAULTS_INCLUDED,
      'feature_source' => TRUE
    ),
  );
}

/**
 * Implementation of hook_features_export_options().
 */
function filter_features_export_options() {
  $options = array();
  foreach (filter_formats() as $name => $info) {
    $options[features_filter_format_identifier($info)] = $info->name;
  }
  return $options;
}

/**
 * Implementation of hook_features_export().
 */
function filter_features_export($data, &$export, $module_name = '') {
  // The filter_default_formats() hook integration is provided by the
  // features module so we need to add it as a dependency.
  $export['dependencies']['features'] = 'features';

  $filter_info = filter_get_filters();
  foreach ($data as $name) {
    if ($format = features_filter_format_load($name)) {
      // Add format to exports
      $identifier = features_filter_format_identifier($format);
      $export['features']['filter'][$identifier] = $identifier;

      // Iterate through filters and ensure each filter's module is included as a dependency
      foreach (array_keys($format->filters) as $name) {
        if (isset($filter_info[$name], $filter_info[$name]['module'])) {
          $module = $filter_info[$name]['module'];
          $export['dependencies'][$module] = $module;
        }
      }
    }
  }

  $pipe = array();
  return $pipe;
}

/**
 * Implementation of hook_features_export_render().
 */
function filter_features_export_render($module, $data, $export = NULL) {
  $code = array();
  $code[] = '  $formats = array();';
  $code[] = '';

  foreach ($data as $name) {
    if ($format = features_filter_format_load($name)) {
      unset($format->format);
      $format_export = features_var_export($format, '  ');
      $format_identifier = features_var_export(features_filter_format_identifier($format));
      $code[] = "  // Exported format: {$format->name}";
      $code[] = "  \$formats[{$format_identifier}] = {$format_export};";
      $code[] = "";
    }
  }

  $code[] = '  return $formats;';
  $code = implode("\n", $code);
  return array('filter_default_formats' => $code);
}

/**
 * Implementation of hook_features_revert().
 */
function filter_features_revert($module) {
  return filter_features_rebuild($module);
}

/**
 * Implementation of hook_features_rebuild().
 */
function filter_features_rebuild($module) {
  if ($defaults = features_get_default('filter', $module)) {
    foreach ($defaults as $format) {
      $format = (object) $format;
      $identifier = features_filter_format_identifier($format);
      if ($existing = features_filter_format_load($identifier)) {
        $format->format = $existing->format;
      }
      filter_format_save($format);
    }
  }
}

/**
 * Load a filter format by its name.
 */
function features_filter_format_load($name) {
  // Use machine name for retrieving the format if available.
  $query = db_select('filter_format');
  $query->fields('filter_format');
  $schema = drupal_get_schema('filter_format');
  if (isset($schema['fields']['machine_name'])) {
    $query->condition('machine_name', $name);
  }
  else {
    $query->condition('name', $name);
  }

  // Retrieve filters for the format and attach.
  if ($format = $query->execute()->fetchObject()) {
    $format->filters = array();
    foreach (filter_list_format($format->format) as $filter) {
      if (!empty($filter->status)) {
        $format->filters[$filter->name]['weight'] = $filter->weight;
        $format->filters[$filter->name]['status'] = $filter->status;
        $format->filters[$filter->name]['settings'] = $filter->settings;
      }
    }
    return $format;
  }
  return FALSE;
}

/**
 * Retrieve the filter format identifier.
 */
function features_filter_format_identifier($format) {
  return isset($format->machine_name) ? $format->machine_name : $format->name;
}
