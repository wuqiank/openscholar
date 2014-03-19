/**
 * Handle the submission of the feed settings form.
 */

(function($) {

  Drupal.behaviors.os_rss_feed_submition = {
    attach: function(context, settings) {
      $('#edit-submit').click(function(event) {
        event.preventDefault();

        var baseUrl = settings.url + "/" + settings.pathPrefix + "os_rss_feed_export";
        var links = '';
        var count = 0;
        var bundles = new Array();
        var terms = new Array();
        var query = '';

        // Gather all the bundles.
        $("#edit-os-rss-feed-content-types").find("input:checked").each(function(index) {
          bundles[index] = $(this).val();
        });

        // Gather all the terms.
        $(".terms-select").find("option:selected").each(function(index) {
          terms[index] = $(this).val();
        });

        // Build the link query argument.
        if (bundles.length > 0) {
          query = "?type=" + bundles.join();
        }

        if (terms.length > 0) {
          if (bundles.length > 0) {
            query += "?term=" + terms.join();
          }
          else {
            query += "&term=" + terms.join();
          }
        }

        // Build the HTML output.
        if (query == '') {
          html = '<span class="empty-selection">' + Drupal.t("You must select of the options above.") + '</span>';
        }
        else {
          var html = "<h4>" + Drupal.t('Your feed is ready') + "</h4>";
          html += "<a href='" + baseUrl + query + "'>" + Drupal.t("Click here") + "</a><br />";
        }

        $("#os_rss_feed_results").html(html).attr('class', 'os_rss_fees_results');
      });
    }
  };

}(jQuery));
