<?php
// $Id: ds-2col.tpl.php,v 1.1.2.2 2010/11/04 21:35:30 swentel Exp $

/**
 * @file
 * Display Suite 2 column template.
 */
?>

<div class="group-left">
  <?php print ds_render_region($content, 'left', $ds_layout); ?>
</div>

<div class="group-right">
  <?php print ds_render_region($content, 'right', $ds_layout); ?>
</div>

<div class="clear-fix"></div>