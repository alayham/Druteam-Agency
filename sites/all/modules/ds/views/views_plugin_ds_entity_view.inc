<?php
// $Id: views_plugin_ds_entity_view.inc,v 1.1.2.2 2010/12/09 21:50:28 swentel Exp $

/**
 * @file
 * Provies the Display suite views entity style plugin.
 */

/**
 * Plugin which defines the view mode on the resulting entity object.
 */
class views_plugin_ds_entity_view extends views_plugin_row {

  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
    $this->base_table = $view->base_table;
    // Special case for apachesolr_views.
    if ($this->base_table == 'apachesolr') {
      $this->base_table = 'node';
    }
    $this->base_field = $this->ds_views_3_support();
  }

  // Return base_field based on base_table. It might not be
  // the cleanest solution, it's the fastest though. No
  // need to a lot of mumbo jumbo here.
  function ds_views_3_support() {
    $base_table_fields = array(
      'node' => 'nid',
      'user' => 'uid',
      'comment' => 'cid',
      'apachesolr' => 'nid',
    );
    return $base_table_fields[$this->base_table];
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['build_mode'] = array('default' => 'teaser');
    $options['changing'] = array('default' => FALSE);
    $options['advanced'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $view_mode_options = ds_entity_view_modes($this->view->base_table);

    // Default view mode.
    $form['default_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default view mode'),
      '#collapsible' => TRUE,
      '#collapsed' => ($this->options['advanced']),
    );
    $form['default_fieldset']['view_mode'] = array(
      '#type' => 'select',
      '#default_value' => $this->options['view_mode'],
      '#options' => $view_mode_options,
      '#description' => t('Make sure you select a view mode which is compatible with the base table of this view which is %base_table. <br />Also note that if you excluded build modes, you will still see them listed here as it\'s possible to list different types in a view.', array('%base_table' => $this->view->base_table))
    );

    // Changing view modes.
    $form['alternating_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Alternating view mode'),
      '#collapsible' => TRUE,
      '#collapsed' => !$this->options['alternate'],
    );
    $form['alternating_fieldset']['alternate'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the changing view mode selector'),
      '#default_value' => $this->options['changing'],
    );
    $form['alternating_fieldset']['allpages'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use this configuration on every page. Otherwhise the default view mode is used as soon you browse away from the first page of this view.'),
      '#default_value' => (isset($this->options['alternating_fieldset']['allpages'])) ? $this->options['alternating_fieldset']['allpages'] : FALSE,
    );
    $limit = $this->view->display_handler->get_option('items_per_page');
    if ($limit == 0 || $limit > 20) {
      $form['alternating_fieldset']['disabled'] = array(
        '#markup' => t('This option is disabled because you have unlimited items or listing more than 20 items.'),
      );
      $form['changing_fieldset']['changing']['#disabled'] = TRUE;
      $form['changing_fieldset']['allpages']['#disabled'] = TRUE;
    }
    else {
      $i = 1;
      $a = 0;
      while ($limit != 0) {
        $form['alternating_fieldset']['item_'. $a] = array(
          '#title' => 'Item '. $i,
          '#type' => 'select',
          '#default_value' => (isset($this->options['alternating_fieldset']['item_'. $a])) ? $this->options['changing_fieldset']['item_'. $a] : 'teaser',
          '#options' => $view_mode_options,
        );
        $limit--;
        $a++;
        $i++;
      }
    }

    // Grouping rows.
    $sorts = $this->view->display_handler->get_option('sorts');
    $groupable = !empty($sorts) && $this->options['grouping'];
    $form['grouping_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Group data'),
      '#collapsible' => TRUE,
      '#collapsed' => !$groupable,
    );
    $form['grouping_fieldset']['grouping'] = array(
      '#type' => 'checkbox',
      '#title' => t('Group data on a field. The value of this field will be displayed too.'),
      '#default_value' => $groupable,
    );
    if (!empty($sorts)) {
      $sort_options = array();
      foreach ($sorts as $key => $sort) {
        $sort_name = ucfirst(str_replace('_', ' ', $sort['table']) .' '. $sort['field']);
        $sort_options[$sort['table'] .'_'. $sort['field']] = $sort_name;
      }

      $form['grouping_fieldset']['group_field'] = array(
        '#type' => 'select',
        '#options' => $sort_options,
        '#default_value' => $this->options['grouping_fieldset']['group_field'],
      );
    }
    else {
      $form['grouping_fieldset']['grouping']['#disabled'] = TRUE;
      $form['grouping_fieldset']['grouping']['#description'] = t('Grouping is disabled because you do not have any sort fields.');
    }

    // Advanced function.
    $form['advanced_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced view mode'),
      '#collapsible' => TRUE,
      '#collapsed' => !$this->options['advanced'],
    );
    $form['advanced_fieldset']['advanced'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the advanced build mode selector'),
      '#description' => t('This gives you the opportunity to have full control of a list for really advanced features.<br /> There is no UI for this, you need to create a function named like this: <strong><em>ds_views_row_adv_@VIEWSNAME(&$variables, $view_mode)</em></strong>.<br />See <a href="http://drupal.org/node/697320#ds_views_row_adv_VIEWSNAME">http://drupal.org/node/697320#ds_views_row_adv_VIEWSNAME</a> for an example.', array('@VIEWSNAME' => $this->view->name)),
      '#default_value' => $this->options['advanced'],
    );
  }

  /**
   * Validate view mode type selector.
   */
  function options_validate($form, &$form_state) {
    if (($form_state['values']['row_options']['alternating_fieldset']['alternate'] || $form_state['values']['row_options']['grouping_fieldset']['grouping']) && $form_state['values']['row_options']['advanced_fieldset']['advanced']) {
      form_set_error('advanced', t('You can not have changing/grouping and advanced enabled at the same time'));
    }
  }

  /**
   * Reset all fieldsets except for changing.
   */
  function options_submit($form, &$form_state) {
    $form_state['values']['row_options']['view_mode'] = $form_state['values']['row_options']['default_fieldset']['view_mode'];
    $form_state['values']['row_options']['alternating'] = $form_state['values']['row_options']['alternating_fieldset']['alternate'];
    $form_state['values']['row_options']['grouping'] = $form_state['values']['row_options']['grouping_fieldset']['grouping'];
    $form_state['values']['row_options']['advanced'] = $form_state['values']['row_options']['advanced_fieldset']['advanced'];
  }
}
