<?php
// $Id: views_handler_field_system_info_description.inc,v 1.1.6.2 2010/11/08 15:26:36 flanker Exp $

/**
 * @file
 * Views field handler for the views_system module.
 */


/**
 * Renders the description field of the system item.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_system_info_description extends views_handler_field {


  function render($values) {

    $info = unserialize($values->{$this->field_alias});

    return isset($info['description']) ? $info['description'] : '';
  }
}
