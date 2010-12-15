<?php

/**
 * Implementation of hook_user_default_roles().
 */
function druteam_agency_user_default_roles() {
  $roles = array();

  // Exported role: Administrator
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => '3',
  );

  // Exported role: Consultant
  $roles['Consultant'] = array(
    'name' => 'Consultant',
    'weight' => '2',
  );

  return $roles;
}
