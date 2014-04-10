/**
 * 
 */
Drupal.behaviors.osPublications = {
  attach: function (ctx) {
    // change the author category to the role when the form is submitted
    var $ = jQuery;
    $('.biblio-contributor-type .form-select', ctx).change(function (i) {
      var tar = $(this).parents('tr').find('.biblio-contributor-category input[type="hidden"]').not('.autocomplete');
      tar.val($(this).val());
    }).change();

    // Handle year fields.
    var codedYear = $("input[name='biblio_year_coded']");
    var yearField = $('#edit-biblio-year');
    yearField.change(function() {
      if (this.value != '') {
        // Uncheck all radio buttons.
        codedYear.each(function () {
          $(this).prop('checked', false);
        });
      }
    });
    codedYear.change(function() {
      if (this.value != '') {
        // Empty year field.
        yearField[0].value = '';
      }
    });
  }
};
