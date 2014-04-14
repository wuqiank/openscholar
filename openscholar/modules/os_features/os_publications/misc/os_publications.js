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

    // Publication year can be either given in a numerical value or by a coded
    // value ("in press", "submitted" and so on). If the user fills a numerical
    // value the radio buttons are unchecked and disabled. Clearing the numerical
    // value enables the radio buttons again.
    yearField.change(function() {
      if (this.value != '') {
        // Uncheck all radio buttons.
        codedYear.each(function () {
          $(this).prop('checked', false);
        });
      }
    }).focus(function() {
        codedYear.prop("disabled", true);
    }).blur(function() {
      if (yearField[0].value == '') {
        codedYear.prop("disabled", false);
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
