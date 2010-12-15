<?php
// $Id: ds-3col-html5.tpl.php,v 1.1.2.2 2010/11/04 21:35:30 swentel Exp $

/**
 * @file
 * Display Suite 3 column template HTML 5 version.
 */
?>

<aside>
  <?php print ds_render_region($content, 'left', $ds_layout); ?>
</aside>

<aside>
  <?php print ds_render_region($content, 'middle', $ds_layout); ?>
</aside>

<aside>
  <?php print ds_render_region($content, 'right', $ds_layout); ?>
</aside>

<div class="clear-fix"></div>