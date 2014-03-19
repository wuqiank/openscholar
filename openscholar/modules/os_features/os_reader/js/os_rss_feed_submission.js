/**
 * Handle the submission of the feed settings form.
 */

(function($) {

  Drupal.behaviors.os_rss_feed_submition = {
    attach: function(context, settings) {

      if (settings.submission_handle) {
        return;
      }

      $('#edit-submit').click(function(event) {
        event.preventDefault();

        var baseUrl = settings.url + "/" + settings.pathPrefix + "os_rss_feed_export";
        var links = '';
        var count = 0;

        // Gather all the bundles.
        $("#edit-os-rss-feed-content-types").find("input:checked").each(function() {
          links += "<a href='" + baseUrl + "?type=" + $(this).val() + "'>" + $(this).siblings().text() + "</a><br />";
          count++;
        });

        // Gather all the terms.
        $(".terms-select").find("option:selected").each(function() {
          links += "<a href='" + baseUrl + "?term=" + $(this).val() + "'>" + $(this).text() + "</a><br />";
          count++;
        });

        if (links == '') {
          html = '<span class="empty-selection">' + Drupal.t("You must select of the options above.") + '</span>';
        }
        else {
          // Build the HTML output.
          var html = "<h4>" + Drupal.formatPlural(count, 'Your feed is ready', 'Your feeds are ready') + "</h4>";
          html += links;
        }

        $("#os_rss_feed_results").html(html).attr('class', 'os_rss_fees_results');
      });
    }
  };

}(jQuery));
