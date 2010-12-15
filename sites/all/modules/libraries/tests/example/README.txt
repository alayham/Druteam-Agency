; $Id: README.txt,v 1.1 2010/09/22 17:32:46 tstoeckler Exp $

Example library

Version 2

This file is an example file to test version detection.

The various other files in this directory are to test the loading of JavaScript,
CSS and PHP files.
- JavaScript: The filenames of the JavaScript files are asserted to be in the
  raw HTML via SimpleTest. Since the filename could appear, for instance, in an
  error message, this is not very robust. Explicit testing of JavaScript,
  though, is not yet possible with SimpleTest. Hence, the JavaScript files, if
  loaded, insert a div with the id 'libraries-test' after the page title and put
  some sample text in it of the form: "If this text shows up, the JavaScript
  file was loaded successfully. If this text is [color], the CSS file was loaded
  successfully." [color] is either 'red', 'green', 'orange' or 'blue' (see
  below). If you enable SimpleTest's verbose mode and see the above text in one
  of the debug pages, a JavaScript file was loaded successfully. Which file
  depends on the color that is mentioned in the shown text (see below).
- CSS: The filenames of the CSS files are asserted to be in the raw HTML via
  SimpleTest. Since the filename could appear, for instance, in an error
  message, this is not very robust. Explicit testing of CSS, though, is not yet
  possible with SimpleTest. Hence, the CSS files, if loaded, make the text that
  was inserted via JavaScipt (see above) a certain color. If you enable
  SimpleTest's verbose mode, and see the above text in a certain color (i.e. not
  in black), a CSS file was loaded successfully. Which file depends on the
  color:
  - example_1: red
  - example_2: green
  - example_3: orange
  - example_4: blue
  Note that, because the CSS affects a div that is inserted via JavaScript, the
  testing of CSS loading with this method is dependent on JavaScript loading.
- PHP: The loading of PHP files is tested by defining a dummy function in the
  PHP files and then checking whether this function was defined using
  function_exists(). This can be checked programatically with SimpleTest.
The loading of integration files is tested with the same method. The integration
files are libraries_test.js, libraries_test.css, libraries_test.inc and are
located in the tests directory alongside libraries_test.module (i.e. they are
not in the same directory as this file). The color that the JavaScript and CSS
integration files refer to is purple.
