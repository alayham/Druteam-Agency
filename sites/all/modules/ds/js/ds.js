/* $Id: ds.js,v 1.1.2.7.2.6 2010/11/12 16:03:44 swentel Exp $ */

(function($) {

/**
 * Creates tabs for visibility
 */
Drupal.behaviors.dsTabs = {
  attach: function (context) {
    $('#ds-tabs a').click(function() {
      // todo clean this up.
      if ($('#field-display-overview-wrapper').is(':visible')) {
        $('#field-display-overview-wrapper').css('display', 'none');
        $('#edit-modes').css('display', 'none');
        $('#edit-actions').css('display', 'none');
        $('#ds-layout-wrapper').css('display', 'block');        
      }
      else {
        $('#field-display-overview-wrapper').css('display', 'block');      
        $('#edit-actions').css('display', 'block');
        $('#edit-modes').css('display', 'block');
        $('#ds-layout-wrapper').css('display', 'none');
      }
      return false;
    });
  }
};

/**
 * Row handlers for the 'Manage display' screen.
 */
Drupal.fieldUIDisplayOverview = Drupal.fieldUIDisplayOverview || {};

Drupal.fieldUIDisplayOverview.ds = function (row, data) {

  this.row = row;
  this.name = data.name;
  this.region = data.region;
  this.tableDrag = data.tableDrag;

  this.$regionSelect = $('select.ds-field-region', row);
  this.$regionSelect.change(Drupal.fieldUIOverview.onChange);

  return this;
};

Drupal.fieldUIDisplayOverview.ds.prototype = {

  /**
   * Returns the region corresponding to the current form values of the row.
   */
  getRegion: function () {
    return this.$regionSelect.val();
  },

  /**
   * Reacts to a row being changed regions.
   *
   * This function is called when the row is moved to a different region, as a
   * result of either :
   * - a drag-and-drop action 
   * - user input in one of the form elements watched by the
   *   Drupal.fieldUIOverview.onChange change listener.
   *
   * @param region
   *   The name of the new region for the row.
   * @return
   *   A hash object indicating which rows should be AJAX-updated as a result
   *   of the change, in the format expected by
   *   Drupal.displayOverview.AJAXRefreshRows().
   */
  regionChange: function (region) {

    this.$regionSelect.val(region);    

    var refreshRows = {};
    refreshRows[this.name] = this.$regionSelect.get(0);
    
    return refreshRows;
  },
};

})(jQuery);
