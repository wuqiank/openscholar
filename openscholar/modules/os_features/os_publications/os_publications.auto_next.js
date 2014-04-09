/**
 * Auto advance past biblio_type select by triggering the biblio_next submit.
 */
(function ($) {
  Drupal.behaviors.os_publications_auto_next = {
    attach: function (context, settings) {
      if (!$('#edit-submit--2').length) {
        $('#biblio-node-form', context).once('osPublicationsAutoNext', function () {
          $('#edit-biblio-next').click();
        });
      }
      else {
        // Otherwise, hide the progress indicator and show the full form.
        if ($('.osPublicationsAutoNext-processed').length) {
          $('#os-publications-auto-next').hide();
          $('#biblio-node-form').css('background-image','none');
          $('#biblio-node-form .node-form').fadeIn();
        }
      }
    }
  };
})(jQuery);
