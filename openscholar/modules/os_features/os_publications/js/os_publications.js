(function ($) {
  Drupal.behaviors.os_publications = {
    attach: function(context, settings) {
      var coded = $('#edit-biblio-year-coded');
      $('#edit-biblio-year').change(function(){
        alert("Hello");
        if (this.getVal != '') {
          $('.form-item-biblio-year-coded').each(function () {
            $(this).prop('checked', false);
          });
        }
      });
//      coded.onChange();

    }
  };
}(jQuery));
