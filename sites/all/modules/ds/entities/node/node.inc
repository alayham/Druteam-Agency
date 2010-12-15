<?php
// $Id: node.inc,v 1.1.2.5 2010/11/03 12:53:57 swentel Exp $

/**
 * @file
 * Display Suite node entity base file.
 */

/**
 * Implements hook_ds_theme_registry().
 */
function node_ds_theme_registry() {
  $theme_functions = array();

  // Single theming functions.
  $formatters = array(
    'node_bodyfield', 'node_title_h1_nolink', 'node_title_h1_link', 'node_title_h2_nolink', 'node_title_h2_link',
    'node_title_h2_block_nolink', 'node_title_h2_block_link', 'node_title_p_nolink', 'node_title_p_link',
    'node_title_text', 'node_title_text_linked',
  );

  foreach ($formatters as $formatter) {
    $theme_functions[$formatter] = array(
      'variables' => array('node' => NULL),
      'file' => 'entities/node/node.theme.inc',
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
function node_ds_fields($entity_type, $bundle, $view_mode) {
  $fields = array();

  // Title
  $fields['title'] = array(
    'title' => t('Title'),
    'type' => DS_FIELD_TYPE_THEME,
    'status' => DS_FIELD_STATUS_STATIC,
    'properties' => array(
      'formatters' => array(
        'node_title_h1_nolink' => t('H1 title'),
        'node_title_h1_link' => t('H1 title, linked to node'),
        'node_title_h2_nolink' => t('H2 title'),
        'node_title_h2_link' => t('H2 title, linked to node'),
        'node_title_h2_block_nolink' => t('H2 block title'),
        'node_title_h2_block_link' => t('H2 block title, linked to node'),
        'node_title_p_nolink' => t('Paragraph title'),
        'node_title_p_link' => t('Paragraph title, linked to node'),
        'node_title_text' => t('Plain text'),
        'node_title_text_linked' => t('Plain text, linked to node'),
      ),
    )
  );

  // Links
  $fields['links'] = array(
    'title' => t('Links'),
    'type' => DS_FIELD_TYPE_IGNORE,
    'status' => DS_FIELD_STATUS_STATIC,
  );

  // Comments.
  // @todo check in_preview
  if (module_exists('comment') && ($view_mode == 'full' || $view_mode == 'default')) {
    $fields['comments'] = array(
      'title' => t('Comments'),
      'type' => DS_FIELD_TYPE_IGNORE,
      'status' => DS_FIELD_STATUS_STATIC,
    );
  }

  // Read more link.
  $fields['read_more'] = array(
    'title' => t('Read more'),
    'type' => DS_FIELD_TYPE_CODE,
    'status' => DS_FIELD_STATUS_DEFAULT,
    'properties' => array(
      'formatters' => array(
        'ds_eval_code' => t('Default'),
      ),
      'code' => '<?php echo l(t("Read more"), "node/$entity->nid"); ?>' // TODO theme this no ? // or use new tokens in Drupal Core
    ),
  );

  return array('node' => $fields);
}
