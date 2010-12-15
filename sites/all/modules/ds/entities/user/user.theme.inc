<?php
// $Id: user.theme.inc,v 1.1.2.1 2010/11/03 12:53:57 swentel Exp $

/**
 * @file
 * Theming functions for Display Suite User entity implementation.
 */

/**
 * User name theming functions
 */
function theme_user_title_h1_nolink($field) {
  return '<h1>'. $field['entity']->name .'</h1>';
}

function theme_user_title_h1_link($field) {
  return '<h1>'. l($field['entity']->name, 'user/'. $field['entity']->uid) .'</h1>';
}

function theme_user_title_h2_nolink($field) {
  return '<h2>'. $field['entity']->name .'</h2>';
}

function theme_user_title_h2_link($field) {
  return '<h2>'. l($field['entity']->name, 'user/'. $field['entity']->uid) .'</h2>';
}

function theme_user_title_h2_block_nolink($field) {
  return '<h2 class="block-title">'. $field['entity']->name .'</h2>';
}

function theme_user_title_h2_block_link($field) {
  return '<h2 class="block-title">'. l($field['entity']->name, 'user/'. $field['entity']->uid) .'</h2>';
}

function theme_user_title_p_nolink($field) {
  return '<p>'. $field['entity']->name .'</p>';
}

function theme_user_title_p_link($field) {
  return '<p>'. l($field['entity']->name, 'user/'. $field['entity']->uid) .'</p>';
}

function theme_user_title_text($field) {
  return $field['entity']->name;
}

function theme_user_title_text_linked($field) {
  return l($field['entity']->name, 'user/'. $field['entity']->uid);
}