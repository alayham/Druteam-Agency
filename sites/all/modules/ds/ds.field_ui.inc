<?php
// $Id: ds.field_ui.inc,v 1.1.2.7 2010/12/09 21:50:28 swentel Exp $

/**
 * @file
 * Field UI form alters for Display Suite.
 */

/**
 * Extend 'Manage fields/display' table with layout and fields.
 *
 * @param $form
 *   The form to add layout fieldset and extra display suite fields.
 * @param $form_state
 *   The current form state.
 */
function ds_extend_field_ui_table(&$form, $form_state) {

  // Get the entity_type, bundle and view mode.
  $entity_type = $form['#entity_type'];
  $bundle = $form['#bundle'];
  $view_mode = isset($form['#view_mode']) ? $form['#view_mode'] : 'form';

  // Alter the text of the custom display settings.
  if ($form['form_id']['#value'] == 'field_ui_display_overview_form') {
    $form['modes']['view_modes_custom']['#description'] = t('<a href="!url">Create new view modes</a>', array('!url' => url('admin/structure/ds/view_modes')));
  }

  // Add tabs for browsing through the options.
  ds_extend_field_ui_table_tabs($form);

  // Add layouts fieldset.
  ds_extend_field_ui_table_layouts($entity_type, $bundle, $view_mode, $form);

  // Add extra fields.
  ds_extend_field_ui_table_fields($entity_type, $bundle, $view_mode, $form);

  // Add extra submit handlers.
  $form['#submit'][] = 'ds_extend_field_ui_layouts_submit';
  $form['#submit'][] = 'ds_extend_field_ui_fields_submit';

  // Attach css and js.
  $form['#attached']['js'][] = drupal_get_path('module', 'ds') . '/js/ds.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'ds') . '/css/ds.css';
}

/**
 * @param $form
 *   A collection of form properties.
 */
function ds_extend_field_ui_table_tabs(&$form) {
  $ds_tabs = '<div id="ds-tabs"><a href="#">' . t('Fields') . '</a><a href="#">' . t('Layout') . '</a></div>';
  $form['ds_tabs'] = array(
    '#markup' => $ds_tabs,
    '#weight' => -10,
  );
}

/**
 * Adds the layouts fieldset to the form.
 *
 * @param $entity_type
 *   The name of the entity type.
 * @param $bundle
 *   The name of the bundle
 * @param $view_mode
 *   The name of the view_mode
 * @param $form
 *   A collection of form properties.
 */
function ds_extend_field_ui_table_layouts($entity_type, $bundle, $view_mode, &$form) {

  $layout_options = array();
  $ds_layouts = module_invoke_all('ds_layouts');
  $layout_options = array('' => t(' - None - '));
  foreach ($ds_layouts as $key => $layout) {
    $layout_options[$key] = $layout['label'];
  }

  // Add layouts form.
  $layout = db_query('SELECT layout, settings, load_html5 FROM {ds_layouts} WHERE entity_type = :entity_type AND bundle = :bundle AND view_mode = :view_mode', array(':entity_type' => $entity_type, ':bundle' => $bundle, ':view_mode' => $view_mode))->fetchObject();
  $form['ds_layouts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Layout'),
    '#weight' => -9,
    '#prefix' => '<div id="ds-layout-wrapper" style="display: none;">',
    '#suffix' => '</div>',
  );

  if (!empty($layout)) {
    $chosen_layout = $ds_layouts[$layout->layout];
    $layout_string = ($layout->load_html5) ? $layout->layout .'-html5' : $layout->layout;
    $suggestions = '- ' . $layout_string .'-'. $entity_type .'.tpl.php<br />';
    $suggestions .= '- ' . $layout_string .'-'. $entity_type .'-'. $bundle .'.tpl.php<br />';
    $suggestions .= '- ' . $layout_string .'-'. $entity_type .'-'. $bundle .'-' . $view_mode .'.tpl.php<br />';
    $form['ds_layouts']['#description'] = t('You have selected the %layout_label layout. The default template can be found in %path.<br />Possible template suggestions are: <br />!suggestions', array('%layout_label' => $chosen_layout['label'], '%path' => $chosen_layout['path'], '!suggestions' => strtr($suggestions, '_', '-')));
  }

  $form['ds_layouts']['layout'] = array(
    '#type' => 'select',
    '#title' => t('Select a layout'),
    '#options' => $layout_options,
    '#description' => t('Select a layout for !bundle in !view_mode.', array('!bundle' => $bundle, '!view_mode' => $view_mode)),
    '#default_value' => isset($layout->layout) ? $layout->layout : '',
  );

  $form['ds_layouts']['old_layout'] = array(
    '#type' => 'value',
    '#value' => isset($layout->layout) ? $layout->layout : 0
  );

  $form['ds_layouts']['load_html5'] = array(
    '#type' => 'checkbox',
    '#title' => t('Load the HTML 5 version of the template file'),
    '#default_value' => isset($layout->load_html5) ? $layout->load_html5 : '',
  );

  $form['ds_layouts']['save_button'] = array(
    '#type' => 'submit',
    '#value' => t('Save layout settings'),
  );

  if (isset($layout->layout)) {
    $layout->settings = unserialize($layout->settings);
    $layout->regions = $chosen_layout['regions'];
    $form['#ds_layout'] = $layout;
  }
}

/**
 * Adds the Display Suite fields to the form.
 *
 * @param $entity_type
 *   The name of the entity type.
 * @param $bundle
 *   The name of the bundle
 * @param $view_mode
 *   The name of the view_mode
 * @param $form
 *   A collection of form properties.
 */
function ds_extend_field_ui_table_fields($entity_type, $bundle, $view_mode, &$form) {

  $region_options = array();
  $layout = isset($form['#ds_layout']) ? $form['#ds_layout'] : FALSE;

  // Get the fields.
  $fields = ds_get_fields($entity_type, $bundle, $view_mode, TRUE, FALSE);
  $field_values = ds_get_fields_configuration($entity_type, $bundle, $view_mode);

  $table = &$form['fields'];
  $form['#ds_fields'] = array();

  $field_label_options = array(
    'above' => t('Above'),
    'inline' => t('Inline'),
    'hidden' => t('<Hidden>'),
  );

  // Change UI to add Region column.
  if ($layout) {
    $table['#header'] = array(
      t('Field'),
      t('Weight'),
      t('Parent'),
      t('Region'),
      t('Label'),
      array('data' => t('Format'), 'colspan' => 3),
    );

    $table['#regions'] = array();
    foreach ($layout->regions as $region_key => $region_title) {
      $region_options[$region_key] = $region_title;
      $table['#regions'][$region_key] = array(
        'title' => $region_title,
        'message' => t('No fields are displayed in this region'),
      );
    }
    $region_options['hidden'] = t('Disabled');
    $table['#regions']['hidden'] = array(
      'title' => t('Disabled'),
      'message' => t('No field are hidden.')
    );

    $region = array(
      '#type' => 'select',
      '#options' => $region_options,
      '#default_value' => 'hidden',
      '#attributes' => array(
        'class' => array('ds-field-region'),
      )
    );

    // Update existing rows by changing rowHandler and adding regions.
    foreach (element_children($table) as $name) {
      $row = &$table[$name];
      $row['#js_settings'] = array('rowHandler' => 'ds');
      $row['#region_callback'] = 'ds_field_ui_row_region';

      // Remove hidden format.
      if (isset($row['format']['type']['#options']['hidden'])) {
        unset($row['format']['type']['#options']['hidden']);
      }

      // Add region between parent_wrapper & label.
      $second = array_splice($row, 7);
      $row['region'] = $region;
      $row['region']['#default_value'] = (isset($layout->settings['fields'][$name])) ? $layout->settings['fields'][$name] : 'hidden';
      $row = array_merge($row, $second);
    }

    $form['#attached']['js'][] = drupal_get_path('module', 'ds') . '/js/ds.js';
  }

  foreach ($fields as $key => $field) {
    $form['#ds_fields'][] = $key;

    //$formatters = array('hidden' => t('<Hidden>'));
    $formatters = isset($field['properties']['formatters']) ? $field['properties']['formatters'] : array('default' => t('Default'));
    if (!$layout) {
      array_unshift($formatters, array('hidden' => t('<Hidden>')));
    }

    $table[$key] = array(
      //'#parents' => array($key),
      '#row_type' => 'field',
      '#js_settings' => array('rowHandler' => (!$layout) ? 'field' : 'ds'),
      '#region_callback' => (!$layout) ? 'field_ui_display_overview_row_region' : 'ds_field_ui_row_region',
      '#attributes' => array('class' => array('draggable', 'tabledrag-leaf')),
      'human_name' => array(
        '#markup' => check_plain($field['title']),
      ),
      'weight' => array(
        '#type' => 'textfield',
        '#default_value' => isset($field_values[$key]['weight']) ? $field_values[$key]['weight'] : 0,
        '#size' => 3,
        '#attributes' => array('class' => array('field-weight')),
      ),
      'parent_wrapper' => array(
        'parent' => array(
          '#type' => 'select',
          '#empty_value' => '',
          '#options' => array(), // This will be filled by field_group. Default value as well.
          '#attributes' => array('class' => array('field-parent')),
          '#parents' => array('fields', $key, 'parent'),
        ),
        'hidden_name' => array(
          '#type' => 'hidden',
          '#default_value' => $key,
          '#attributes' => array('class' => array('field-name')),
        ),
      ),
      'region' => array(
        '#type' => 'select',
        '#options' => $region_options,
        '#default_value' => isset($layout->settings['fields'][$key]) ? isset($layout->settings['fields'][$key]) : 'hidden',
        '#attributes' => array(
          'class' => array('ds-field-region'),
        ),
      ),
      'label' => array(
        '#type' => 'select',
        '#options' => $field_label_options,
        '#default_value' => isset($field_values[$key]['label']) ? $field_values[$key]['label'] : 'hidden',
      ),
      'format' => array(
        'type' => array(
          '#type' => 'select',
          '#options' => $formatters,
          '#default_value' => isset($field_values[$key]['format']) ? $field_values[$key]['format'] : 'hidden',
          '#attributes' => array('class' => array('field-formatter-type')),
        ),
      ),
      'settings_summary' => array(),
      'settings_edit' => array(),
    );

    // Remove region
    if (!$layout) {
      unset($table[$key]['region']);
    }
  }
}

/**
 * Save the layout settings from the 'Manage fields' & 'Manage display' screen.
 */
function ds_extend_field_ui_layouts_save($form, &$form_state) {

  // Get some default values.
  $entity_type = $form['#entity_type'];
  $bundle = $form['#bundle'];
  $view_mode = isset($form['#view_mode']) ? $form['#view_mode'] : 'form';

  // Determine layout variables.
  $layout = $form_state['values']['layout'];
  $old_layout = $form_state['values']['old_layout'];
  $new_layout = ($layout != $old_layout) || empty($old_layout);

  // Save layout and add regions if necessary.
  $record = new stdClass;
  $record->entity_type = $entity_type;
  $record->bundle = $bundle;
  $record->view_mode = $view_mode;
  $record->layout = $form_state['values']['layout'];
  $record->load_html5 = (isset($form_state['values']['load_html5']) && (!empty($form_state['values']['layout']))) ? $form_state['values']['load_html5'] : FALSE;

  // Remove old layout if necessary.
  if ($new_layout && !empty($old_layout)) {
    db_delete('ds_layouts')
      ->condition('entity_type', $entity_type)
      ->condition('bundle', $bundle)
      ->condition('view_mode', $view_mode)
      ->execute();
  }

  if ($new_layout && !empty($layout)) {
    // Save new layout.
    drupal_write_record('ds_layouts', $record);
  }
  // Update existing layout.
  elseif (!empty($layout)) {
    $record->settings = array();
    foreach ($form_state['values']['fields'] as $key => $field) {
      if ($key == '_add_new_group') {
        continue;
      }
      if (!isset($record->settings['regions'][$field['region']])) {
        $record->settings['regions'][$field['region']] = array();
      }
      $record->settings['regions'][$field['region']][] = $key;
      $record->settings['fields'][$key] = $field['region'];
    }
    $record->settings = serialize($record->settings);
    drupal_write_record('ds_layouts', $record, array('entity_type', 'bundle', 'view_mode', 'layout'));
  }
}

/**
 * Save the field settings from the 'Manage fields' & 'Manage display' screen.
 */
function ds_extend_field_ui_fields_save($form, &$form_state) {

  // Setup some variables.
  $entity_type = $form['#entity_type'];
  $bundle = $form['#bundle'];
  $view_mode = isset($form['#view_mode']) ? $form['#view_mode'] : 'form';

  // Delete previous field configuration configuration.
  db_delete('ds_settings')
    ->condition('entity_type', $entity_type)
    ->condition('bundle', $bundle)
    ->condition('view_mode', $view_mode)
    ->execute();

  // Create a record to insert into the ds_settings table.
  $record = new stdClass;
  $record->entity_type = $entity_type;
  $record->bundle = $bundle;
  $record->view_mode = $view_mode;

  // Save settings for each field.
  $fields = $form['#ds_fields'];
  foreach ($fields as $key => $field) {

    // Field values.
    $field_values = $form_state['values']['fields'][$field];

    // Build settings.
    $settings = array();
    $settings['weight'] = $field_values['weight'];
    $settings['label'] = $field_values['label'];
    $settings['format'] = $field_values['format']['type'];

    // Save the record.
    $record->field = $field;
    $record->settings = serialize($settings);
    drupal_write_record('ds_settings', $record);
  }

  // Clear the ds_fields_configuration cache.
  cache_clear_all('ds_fields_configuration', 'cache');

  // Clear entity cache.
  cache_clear_all('entity_info', 'cache', TRUE);
}

/**
 * Returns the region to which a row in the Field UI screen belongs.
 */
function ds_field_ui_row_region($row) {
  return ($row['region']['#value']);
}
