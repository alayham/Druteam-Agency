<?php
// $Id: admin_menu.api.php,v 1.5 2010/03/17 20:49:40 sun Exp $

/**
 * @file
 * API documentation for Administration menu.
 */

/**
 * Provide expansion arguments for dynamic menu items, i.e. menu paths
 * containing one or more %placeholders.
 *
 * The map items must be keyed by the dynamic path to expand. Each map item may
 * have the following properties:
 *
 * - parent: The parent menu path to link the expanded items to.
 * - arguments: An array of argument sets that will be used in the
 *   expansion. Each set consists of an array of one or more placeholders with
 *   an array of possible expansions as value. Upon expansion, each argument
 *   is combined with every other argument from the set (ie., the cartesian
 *   product of all arguments is created). The expansion values may be empty,
 *   that is, you don't need to insert logic to skip map items for which no
 *   values exist, since admin menu will take care of that.
 * - hide: (optional) Used to hide another menu item, usually a superfluous
 *   "List" item.
 *
 * @see admin_menu.map.inc
 */
function hook_admin_menu_map() {
  // Expand content types in Structure >> Content types.
  // The key denotes the dynamic path to expand to multiple menu items.
  $map['admin/structure/types/manage/%node_type'] = array(
    // Link generated items directly to the "Content types" item, and hide the
    // "List" item.
    'parent' => 'admin/structure/types',
    'hide' => 'admin/structure/types/list',
    // Create expansion arguments for the %node_type placeholder.
    'arguments' => array(
      array('%node_type' => array_keys(node_type_get_types())),
    ),
  );
  return $map;
}

/**
 * Alter content in Administration menu bar before it is rendered.
 *
 * @param $content
 *   A structured array suitable for drupal_render(), at the very least
 *   containing the keys 'menu' and 'links'.  Most implementations likely want
 *   to alter or add to 'links'.
 *
 * $content['menu'] contains the HTML representation of the 'admin_menu' menu
 * tree.
 * @see admin_menu_menu_alter()
 *
 * $content['links'] contains additional top-level links in the Administration
 * menu, such as the icon menu or the logout link. You can add more items here
 * or play with the #weight attribute to customize them.
 * @see theme_admin_menu_links()
 * @see admin_menu_links_icon()
 * @see admin_menu_links_user()
 */
function hook_admin_menu_output_alter(&$content) {
  // Add new top-level item.
  $content['menu']['myitem'] = array(
    '#title' => t('My item'),
    // #attributes are used for list items (LI).
    '#attributes' => array('class' => array('mymodule-myitem')),
    '#href' => 'mymodule/path',
    // #options are passed to l(). Note that you can apply 'attributes' for
    // links (A) here.
    '#options' => array(
      'query' => drupal_get_destination(),
    ),
    // #weight controls the order of links in the resulting item list.
    '#weight' => 50,
  );
  // Add link to manually run cron.
  $content['menu']['myitem']['cron'] = array(
    '#title' => t('Run cron'),
    '#access' => user_access('administer site configuration'),
    '#href' => 'admin/reports/status/run-cron',
  );
}

