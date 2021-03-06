<?php
// $Id: flag_handler_argument_content_id.inc,v 1.3 2010/05/10 04:05:00 quicksketch Exp $

/**
 * @file
 * Contains the content ID argument handler.
 */

/**
 * Handler to accept an argument of the content ID of any object.
 *
 * @ingroup views
 */
class flag_handler_argument_content_id extends views_handler_argument_numeric {

  /**
   * Returns the flag object associated with our argument.
   *
   * An argument is in some relationship. This function reaches out for this
   * relationship and reads its 'flag' option, which holds the flag name.
   */
  function get_flag() {
    $flag_name = $this->view->relationship[$this->options['relationship']]->options['flag'];
    return flag_get_flag($flag_name);
  }

  /**
   * Override the behavior of title(). Get the title of the appropriate objects.
   */
  function title_query() {
    $flag = $this->get_flag();
    $views_info = $flag->get_views_info();

    $titles = array();
    $placeholders = implode(', ', array_fill(0, sizeof($this->value), '%d'));

    $result = db_select($views_info['views table'], 'o')
      ->fields('o', array($views_info['title field']))
      ->condition('o.' . $views_info['join field'], $this->value, 'IN')
      ->execute();
    foreach ($result as $title) {
      $titles[] = check_plain($title->$views_info['title field']);
    }
    return $titles;
  }
}
