<?php
// $Id: node.theme.inc,v 1.1.2.2 2010/11/03 12:53:57 swentel Exp $

/**
 * @file
 * Theming functions for Display Suite Node entity implementation.
 */

/**
 * Theme functions for title
 */
function theme_node_title_h1_nolink($field) {
  return '<h1>'. check_plain($field['entity']->title) .'</h1>';
}

function theme_node_title_h1_link($field) {
  return '<h1>'. l($field['entity']->title, 'node/'. $field['entity']->nid) .'</h1>';
}

function theme_node_title_h2_nolink($field) {
  return '<h2>'. check_plain($field['entity']->title) .'</h2>';
}

function theme_node_title_h2_link($field) {
  return '<h2>'. l($field['entity']->title, 'node/'. $field['entity']->nid) .'</h2>';
}

function theme_node_title_h2_block_nolink($field) {
  return '<h2 class="block-title">'. check_plain($field['entity']->title) .'</h2>';
}

function theme_node_title_h2_block_link($field) {
  return '<h2 class="block-title">'. l($field['entity']->title, 'node/'. $field['entity']->nid) .'</h2>';
}

function theme_node_title_p_nolink($field) {
  return '<p>'. check_plain($field['entity']->title) .'</p>';
}

function theme_node_title_p_link($field) {
  return '<p>'. l($field['entity']->title, 'node/'. $field['entity']->nid) .'</p>';
}

function theme_node_title_text($field) {
  return check_plain($field['entity']->title);
}

function theme_node_title_text_linked($field) {
  return l($field['entity']->title, 'node/'. $field['entity']->nid);
}