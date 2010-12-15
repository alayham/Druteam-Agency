<?php
// $Id: views_handler_field_system_info_configure.inc,v 1.1.2.3 2010/11/08 15:26:36 flanker Exp $

/**
 * @file
 * Views field handler for the views_system module.
 */


/**
 * Provides display options and renders the configure field of the system item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_system_info_configure extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['system_info_configure_link'] = array('default' => FALSE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['system_info_configure_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as link'),
      '#description' => t('If checked, this configure line will be made into a link to the main configuration page of the module.'),
      '#default_value' => !empty($this->options['system_info_configure_link']),
    );
  }


  function render($values) {

    $info = unserialize($values->{$this->field_alias});

    if (isset($info['configure'])) {

      if ($this->options['system_info_configure_link']) {
        $output = l(t('Configure'), $info['configure'], array('html' => TRUE));
      }
      else {
        $output = $info['configure'];
      }
    }
    else {
      $output = '';
    }

    return $output;
  }
}
