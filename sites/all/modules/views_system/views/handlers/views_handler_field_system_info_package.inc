<?php
// $Id: views_handler_field_system_info_package.inc,v 1.2.2.2 2010/11/08 15:26:36 flanker Exp $

/**
 * @file
 * Views field handler for the views_system module.
 */


/**
 * Renders the package field of the system item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_system_info_package extends views_handler_field {


  function render($values) {

    $info = unserialize($values->{$this->field_alias});

    return isset($info['package']) ? $info['package'] : '';
  }
}
