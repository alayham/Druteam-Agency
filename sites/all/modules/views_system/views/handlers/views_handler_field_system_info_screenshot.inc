<?php
// $Id: views_handler_field_system_info_screenshot.inc,v 1.2.2.3 2010/11/08 15:26:36 flanker Exp $

/**
 * @file
 * Views field handler for the views_system module.
 */


/**
 * Provides display options and renders the screenshot field of the system item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_system_info_screenshot extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['system_info_screenshot_image'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['system_info_screenshot_image'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as image'),
      '#default_value' => !empty($this->options['system_info_screenshot_image']),
    );
  }


  function render($values) {

    $info = unserialize($values->{$this->field_alias});

    if (isset($info['screenshot'])) {

      if ($this->options['system_info_screenshot_image'] && $path = _views_system_get_screenshot($info)) {

        $alt = t('Screenshot for %theme theme', array('%theme' => $info['name']));
        $output = theme('image', array('path' => $path, 'alt' => $alt, 'attributes' => array('class' => 'screenshot'), 'getsize' => FALSE));
      }
      else {
        $output = '';
      }
    }
    else {
      $output = '';
    }

    return $output;
  }
}
