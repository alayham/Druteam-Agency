<?php
// $Id: views_handler_filter_system_status.inc,v 1.1.2.2 2010/10/31 16:14:07 flanker Exp $

/**
 * @file
 * Views filter handler for the views_system module.
 */


/**
 * Provides status filter options for the system item.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_system_status extends views_handler_filter_boolean_operator {


  function get_value_options() {

    if (isset($this->definition['type'])) {
      if ($this->definition['type'] == 'on-off') {
        $this->value_options = array(1 => t('On'), 0 => t('Off'));
      }
    }

    if (!isset($this->value_options)) {
     $this->value_options = array(1 => t('Enabled'), 0 => t('Disabled'));
    }
  }
}
