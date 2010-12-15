<?php
// $Id: delete.action.inc,v 1.1.2.7.4.1 2010/03/11 04:28:31 kratib Exp $

function views_bulk_operations_delete_action_info() {
  return array(
    'views_bulk_operations_delete_node_action' => array(
      'type' => 'node',
      'label' => t('Delete node'),
      'configurable' => FALSE,
      'behavior' => array('deletes_node_property'),
    ),
    'views_bulk_operations_delete_user_action' => array(
      'type' => 'user',
      'label' => t('Delete user'),
      'configurable' => FALSE,
      'behavior' => array('deletes_node_property'),
    ),
    'views_bulk_operations_delete_comment_action' => array(
      'type' => 'comment',
      'label' => t('Delete comment'),
      'configurable' => FALSE,
      'behavior' => array('deletes_node_property'),
    ),
    'views_bulk_operations_delete_term_action' => array(
      'type' => 'term',
      'label' => t('Delete term'),
      'configurable' => FALSE,
      'behavior' => array('deletes_node_property'),
    ),
  );
}

function views_bulk_operations_delete_node_action($node) {
  node_delete($node->nid);
}

function views_bulk_operations_delete_user_action($user) {
  user_delete(null, $user->uid);
}

function views_bulk_operations_delete_comment_action($comment) {
  require_once(drupal_get_path('module', 'comment') .'/comment.admin.inc');
  _comment_delete_thread($comment);
  _comment_update_node_statistics($comment->nid);
}

function views_bulk_operations_delete_term_action($term) {
  taxonomy_del_term($term->tid);
}
