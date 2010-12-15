<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function druteam_agency_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: access content overview
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: admin_fields
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(),
  );

  // Exported permission: admin_view_modes
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(),
  );

  // Exported permission: administer CAPTCHA settings
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(),
  );

  // Exported permission: administer comments
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
  );

  // Exported permission: administer field permissions
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(),
  );

  // Exported permission: administer imce
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: create application content
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: create field_consultant
  $permissions['create field_consultant'] = array(
    'name' => 'create field_consultant',
    'roles' => array(),
  );

  // Exported permission: create field_notes
  $permissions['create field_notes'] = array(
    'name' => 'create field_notes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: create field_status
  $permissions['create field_status'] = array(
    'name' => 'create field_status',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: delete any application content
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
    'roles' => array(),
  );

  // Exported permission: delete own application content
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
    'roles' => array(),
  );

  // Exported permission: display drupal links
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: edit any application content
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: edit field_consultant
  $permissions['edit field_consultant'] = array(
    'name' => 'edit field_consultant',
    'roles' => array(),
  );

  // Exported permission: edit field_notes
  $permissions['edit field_notes'] = array(
    'name' => 'edit field_notes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: edit field_status
  $permissions['edit field_status'] = array(
    'name' => 'edit field_status',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: edit own application content
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit own field_consultant
  $permissions['edit own field_consultant'] = array(
    'name' => 'edit own field_consultant',
    'roles' => array(),
  );

  // Exported permission: edit own field_notes
  $permissions['edit own field_notes'] = array(
    'name' => 'edit own field_notes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: edit own field_status
  $permissions['edit own field_status'] = array(
    'name' => 'edit own field_status',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: flush caches
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: skip CAPTCHA
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: skip comment approval
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: view field_notes
  $permissions['view field_notes'] = array(
    'name' => 'view field_notes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  // Exported permission: view own field_notes
  $permissions['view own field_notes'] = array(
    'name' => 'view own field_notes',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Consultant',
    ),
  );

  return $permissions;
}
