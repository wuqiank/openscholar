/**
 * jQuery to toggle form elements according to content type.
 */
(function($) {
  Drupal.behaviors.os_boxes_facetapi_vocabulary = {
    attach : function(context) {
      $("#edit-vocabularies", context).addClass('select2-processed momo').find('.form-select:not(.select2-processed)').select2({
        placeholder: Drupal.t("Click here to select vocabularies"),
        width: '20em'
      });
    }
  }
}(jQuery));
