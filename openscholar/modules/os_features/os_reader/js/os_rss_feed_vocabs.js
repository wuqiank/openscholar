/**
 * jQuery to toggle form elements according to content type.
 */

(function($) {

  Drupal.behaviors.os_rss_feed_list = {
    attach : function(context) {
      $("#edit-os-rss-feed-vocabs", context).addClass('select2-processed').find('.form-select:not(.select2-processed)').select2({
        placeholder: Drupal.t("Click here to select terms"),
        width: '20em'
      });
    }
  };

}(jQuery));
