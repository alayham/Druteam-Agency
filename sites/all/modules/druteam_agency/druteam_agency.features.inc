<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function druteam_agency_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function druteam_agency_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Application Title'),
      'help' => t('Submit your application to the desired university'),
    ),
  );
  return $items;
}
