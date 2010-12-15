<?php
// $Id: ds-3col-stacked-html5.tpl.php,v 1.1.2.2 2010/11/04 21:35:30 swentel Exp $

/**
 * @file
 * Display Suite 3 column stacked template HTML 5 version.
 */
?>

<header>
  <?php print ds_render_region($content, 'header', $ds_layout); ?>
</header>

<aside>
  <?php print ds_render_region($content, 'left', $ds_layout); ?>
</aside>

<aside>
  <?php print ds_render_region($content, 'middle', $ds_layout); ?>
</aside>

<aside>
  <?php print ds_render_region($content, 'right', $ds_layout); ?>
</aside>

<footer>
  <?php print ds_render_region($content, 'footer', $ds_layout); ?>
</footer>