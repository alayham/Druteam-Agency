<?php
// $Id: views_system.views.inc,v 1.1.2.7 2010/11/15 06:08:05 flanker Exp $

/**
 * @file
 * Views data and handlers for the views_system module.
 */


/**
 * @defgroup views_system_module views_system.module handlers
 *
 * @{
 */


/**
 * Implements hook_views_data().
 */
function views_system_views_data() {

  $data = array();
  $data['system']['table'] = array(
    'base' => array(
      'field' => 'filename',
      'title' => t('System item'),
      'help' => t("System items are modules, themes, and theme engines that are or have been installed in Drupal's file system."),
      'weight' => 25,
    ),
    'group' => t('System'),
  );
  $data['system']['filename'] = array(
    'title' => t('Filename'),
    'help' => t('The path of the primary file for this item, relative to the Drupal root; e.g. modules/node/node.module.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['name'] = array(
    'title' => t('Name'),
    'help' => t('The name of the item; e.g. node.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['type'] = array(
    'title' => t('Type'),
    'help' => t('The type of the item, either module, theme, or theme_engine.'),
    'field' => array(
      'handler' => 'views_handler_field_system_type',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => '_views_system_get_type',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['owner'] = array(
    'title' => t('Owner'),
    'help' => t("A theme's 'parent'. Can be either a theme or an engine."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['status'] = array(
    'title' => t('Status'),
    'help' => t('Boolean indicating whether or not this item is enabled.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_system_status',
      'label' => t('Status'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['bootstrap'] = array(
    'title' => t('Bootstrap'),
    'help' => t("Boolean indicating whether this module is loaded during Drupal's early bootstrapping phase (e.g. even before the page cache is consulted)."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['schema_version'] = array(
    'title' => t('Schema version'),
    'help' => t("The module's database schema version number. -1 if the module is not installed (its tables do not exist); 0 or the largest N of the module's hook_update_N() function that has either been run or existed when the module was first installed."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['system']['weight'] = array(
    'title' => t('Weight'),
    'help' => t("The order in which this module's hooks should be invoked relative to other modules. Equal-weighted modules are ordered by name."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  //
  $data['system']['info_basetheme'] = array(
    'real field' => 'info',
    'title' => t('Base theme'),
    'help' => t('The name of the base theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_basetheme',
    ),
  );
  $data['system']['info_configure'] = array(
    'real field' => 'info',
    'title' => t('Configure'),
    'help' => t('The configure line of the module.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_configure',
    ),
  );
  $data['system']['info_core'] = array(
    'real field' => 'info',
    'title' => t('Core'),
    'help' => t('The Drupal core version of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_core',
    ),
  );
  $data['system']['info_datestamp'] = array(
    'real field' => 'info',
    'title' => t('Date stamp'),
    'help' => t('The date stamp of the project this item belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_datestamp',
    ),
  );
  $data['system']['info_dependencies'] = array(
    'real field' => 'info',
    'title' => t('Dependencies'),
    'help' => t('Required modules.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_dependencies',
      'label' => t('Depends on'),
    ),
  );
  $data['system']['info_description'] = array(
    'real field' => 'info',
    'title' => t('Description'),
    'help' => t('The brief description of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_description',
    ),
  );
  $data['system']['info_engine'] = array(
    'real field' => 'info',
    'title' => t('Engine'),
    'help' => t('The name of the theme engine; typically: engine = phptemplate.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_engine',
    ),
  );
  $data['system']['info_features'] = array(
    'real field' => 'info',
    'title' => t('Features'),
    'help' => t('The features of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_features',
    ),
  );
  $data['system']['info_files'] = array(
    'real field' => 'info',
    'title' => t('Files'),
    'help' => t('The declared files of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_files',
    ),
  );
  $data['system']['info_hidden'] = array(
    'real field' => 'info',
    'title' => t('Hidden'),
    'help' => t('Boolean indicating whether this item is hidden.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_hidden',
      'type' => 'yes-no',
    ),
  );
  $data['system']['info_name'] = array(
    'real field' => 'info',
    'title' => t('Display name'),
    'help' => t('The real name of the item for display purposes; e.g. Node.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_name',
    ),
  );
  $data['system']['info_package'] = array(
    'real field' => 'info',
    'title' => t('Package'),
    'help' => t('The name of the package this item belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_package',
    ),
  );
  $data['system']['info_php'] = array(
    'real field' => 'info',
    'title' => t('PHP'),
    'help' => t('The minimum PHP version of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_php',
    ),
  );
  $data['system']['info_project'] = array(
    'real field' => 'info',
    'title' => t('Project'),
    'help' => t('The name of the project this item belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_project',
    ),
  );
  $data['system']['info_regions'] = array(
    'real field' => 'info',
    'title' => t('Regions'),
    'help' => t('The regions of the theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_regions',
    ),
  );
  $data['system']['info_regions_hidden'] = array(
    'real field' => 'info',
    'title' => t('Regions hidden'),
    'help' => t('The hidden regions of the theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_regions_hidden',
    ),
  );
  $data['system']['info_screenshot'] = array(
    'real field' => 'info',
    'title' => t('Screenshot'),
    'help' => t('The screenshot of the theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_screenshot',
    ),
  );
  $data['system']['info_scripts'] = array(
    'real field' => 'info',
    'title' => t('Scripts'),
    'help' => t('The declared Javascript files of the system item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_scripts',
    ),
  );
  $data['system']['info_settings'] = array(
    'real field' => 'info',
    'title' => t('Settings'),
    'help' => t('The default settings of the theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_settings',
    ),
  );
  $data['system']['info_stylesheets'] = array(
    'real field' => 'info',
    'title' => t('Stylesheets'),
    'help' => t('The declared CSS files of the system item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_stylesheets',
    ),
  );
  $data['system']['info_version'] = array(
    'real field' => 'info',
    'title' => t('Version'),
    'help' => t('The version of the item.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_version',
    ),
  );
  //
  $data['system']['drupal_core'] = array(
    'real field' => 'filename',
    'title' => t('Drupal core'),
    'help' => t('Boolean indicating whether this item is part of Drupal core.'),
    'field' => array(
      'handler' => 'views_handler_field_system_drupal_core',
      'type' => 'yes-no',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_system_drupal_core',
      'label' => t('Drupal core'),
      'type' => 'yes-no',
    ),
  );

  return $data;
}


/**
 * @}
 */
