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

  Drupal.behaviors.os_rss_feed_submition = {
    attach: function(context, settings) {
      $('#edit-submit').click(function(event) {
        event.preventDefault();

        var baseUrl = settings.url + "/" + settings.pathPrefix + "os_rss_feed_export";
        var links = '';

        // Gather all the bundles.
        $("#edit-os-rss-feed-content-types").find("input:checked").each(function() {
          links += "<a href='" + baseUrl + "?type=" + $(this).val() + "'>" + $(this).siblings().text() + "</a><br />";
        });

        // Gather all the terms.
        $(".terms-select").find("option:selected").each(function() {
          links += "<a href='" + baseUrl + "?term=" + $(this).val() + "'>" + $(this).text() + "</a><br />";
        });

        // Print out the links we collected.
        $("#os_rss_feed_results").html(links);
      });
    }
  };

}(jQuery));
