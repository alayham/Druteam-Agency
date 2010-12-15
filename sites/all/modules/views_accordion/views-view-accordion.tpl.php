<?php
// $Id: views-view-accordion.tpl.php,v 1.2.2.1 2010/10/08 12:22:22 manuelgarcia Exp $
/**
 * @file
 * Displays the items of the accordion.
 *
 * @ingroup views_templates
 *
 *  Note that the accordion NEEDS <?php print $row ?> to be wrapped by an element, or it will hide all fields on all rows under the first field.
 *  Also, if you use field grouping and use the headers of the groups as the accordion headers, these NEED to be inside h3 tags exactly as below (though u can add classes)
 *
 *  The current div wraping each row gets two css classes, which should be enough for most cases:
 *     "views-accordion-item"
 *      and a unique per row class like item-0
 *
 */
?>
<?php if (!empty($title)): ?>
  <h3 class="<?php print $view_accordion_id; ?>"><a href="#"><?php print $title; ?></a></h3>
<?php endif; ?>
<?php if($use_group_header == TRUE): ?><div><?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
<?php if($use_group_header == TRUE): ?></div><?php endif; ?>
