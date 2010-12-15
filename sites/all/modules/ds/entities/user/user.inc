<?php
// $Id: user.inc,v 1.1.2.2 2010/11/03 12:53:57 swentel Exp $

/**
 * @file
 * Display Suite user entity base file.
 */

/**
 * Implements hook_ds_theme_registry().
 */
function node_user_theme_registry() {
  $theme_functions = array();

  // Single theming functions.
  $formatters = array(
    'user_title_h1_nolink', 'user_title_h1_link', 'user_title_h2_nolink', 'user_title_h2_link',
    'user_title_h2_block_nolink', 'user_title_h2_block_link', 'user_title_p_nolink', 'user_title_p_link',
    'user_title_text','user_title_text_linked',
  );

  foreach ($formatters as $formatter) {
    $theme_functions[$formatter] = array(
      'variables' => array('user' => NULL),
      'file' => 'entities/user/user.theme.inc',
    );
  }

  return $theme_functions;
}

/**
 * Implements hook_ds_fields().
 *
 * @param $entity_type
 *   The name of the entity type
 * @param $bundle
 *   The name of the bundle.
 * @param $view_mode
 *   The name of the view mode.
 * @return $fields
 *   A collection of fields.
 */
function user_ds_fields($entity_type, $bundle, $view_mode) {
  $fields = array();

  // Username
  $fields['name'] = array(
    'title' => 'Username',
    'type' => DS_FIELD_TYPE_THEME,
    'status' => DS_FIELD_STATUS_STATIC,
    'properties' => array(
      'formatters' => array(
        'user_title_h1_nolink' => t('H1 title'),
        'user_title_h1_link' => t('H1 title, linked to user'),
        'user_title_h2_nolink' => t('H2 title'),
        'user_title_h2_link' => t('H2 title, linked to user'),
        'user_title_h2_block_nolink' => t('H2 block title'),
        'user_title_h2_block_link' => t('H2 block title, linked to user'),
        'user_title_p_nolink' => t('Paragraph title'),
        'user_title_p_link' => t('Paragraph title, linked to user'),
        'user_title_text' => t('Plain text'),
        'user_title_text_linked' => t('Plain text, linked to user'),
      ),
    )
  );

  return array('user' => $fields);
}
