(function ($) {
  Drupal.behaviors.os_publications = {
    attach: function(context, settings) {
      var coded = $("input[name='biblio_year_coded']");
      var year_field = $('#edit-biblio-year');
      year_field.change(function() {
        if (this.value != '') {
          // Uncheck all radio buttons.
          coded.each(function () {
            $(this).prop('checked', false);
          });
        }
      });
      coded.change(function() {
        if (this.value != '') {
          // Empty year field.
          year_field[0].value = '';
        }
      });
    }
  };
}(jQuery));
