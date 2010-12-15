// $Id: views-accordion.js,v 1.2.2.4 2010/12/05 18:52:44 manuelgarcia Exp $
Drupal.behaviors.views_accordion =  {
  attach: function(context) {
    if(Drupal.settings.views_accordion){
      (function ($) {
        $.each(Drupal.settings.views_accordion, function(id) {
          /* Our view settings */
          var usegroupheader = this.usegroupheader;
          var viewname = this.viewname;
          var display = this.display;

          /* the selectors we have to play with */
          var displaySelector = '.view-id-'+ viewname +'.view-display-id-'+ display +' .view-content';
          var headerSelector = usegroupheader ? (this.header) : ('.' + this.header); // this.header is the class of our first field

          /* Prepare our markup for jquery ui accordion */
          $(headerSelector).each(function(i){
            var hash = "#"+ viewname +"-"+ display +"-"+ i; // hash to use for accordion navigation option
            var $this = $(this);
            var $link = $this.find('a');
            // if the header is not already using an anchor tag, add one
            if($link.length == 0){
              // setup anchor tag for navigation
              $this.wrapInner('<a href="'+hash+'"></a>');
            }
            // if there are already, they wont be clickable with js enabled, we'll use them for accordion navigation
            else{
              // @FIXME ?
              // We are currently destroying the original link, though search crawlers will stil see it.
              // Links in accordions are NOT clickable and leaving them would kill deep linking.
              $link.get(0).href = hash;
            }

            // Wrap the accordion content within a div if necessary
            if (!usegroupheader) {
               $this.siblings().wrapAll('<div></div');
             }
          });

          /* jQuery UI accordion call */
          $(displaySelector).accordion({
              header: headerSelector,
              animated: this.animated,
              active: this.rowstartopen,
              collapsible: this.collapsible,
              autoHeight: this.autoheight,
              event: this.event,
              fillSpace: this.fillspace,
              navigation: this.navigation,
              clearstyle: this.clearstyle,
          });
        });
      })(jQuery);
    }
  }
};