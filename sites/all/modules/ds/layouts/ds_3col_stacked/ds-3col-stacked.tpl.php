<?php
// $Id: ds-3col-stacked.tpl.php,v 1.1.2.2 2010/11/04 21:35:30 swentel Exp $

/**
 * @file
 * Display Suite 3 column stacked template.
 */
?>

<div class="group-header">
  <?php print ds_render_region($content, 'header', $ds_layout); ?>
</div>

<div class="group-left">
  <?php print ds_render_region($content, 'left', $ds_layout); ?>
</div>

<div class="group-middle">
  <?php print ds_render_region($content, 'middle', $ds_layout); ?>
</div>

<div class="group-right">
  <?php print ds_render_region($content, 'right', $ds_layout); ?>
</div>

<div class="group-footer">
  <?php print ds_render_region($content, 'footer', $ds_layout); ?>
</div>