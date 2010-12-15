<?php
// $Id: acl.api.php,v 1.2 2010/11/04 21:48:04 salvis Exp $

/**
 * @file
 * API documentation for ACL.
 */

/**
 * Explain what your ACL grant records mean.
 */
function hook_acl_explain($acl_id, $name, $number, $users = NULL) {
  if (empty($users)) {
    return "ACL (id=$acl_id) would grant access to $name/$number.";
  }
  return "ACL (id=$acl_id) grants access to $name/$number to the listed user(s).";
}

