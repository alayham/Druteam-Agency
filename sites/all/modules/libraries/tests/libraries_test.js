// $Id: libraries_test.js,v 1.4 2010/11/03 22:22:42 tstoeckler Exp $

/**
 * @file
 * Test JavaScript file for Libraries loading.
 *
 * Replace the text in the 'libraries-test-javascript' div. See README.txt for
 * more information.
 */

(function ($) {

Drupal.behaviors.librariesTest = {
  attach: function(context, settings) {
    $('.libraries-test-javascript').text('If this text shows up, libraries_test.js was loaded successfully')
  }
};

})(jQuery);
