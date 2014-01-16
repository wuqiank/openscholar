/**
 * Behaviors and scripts for the Columns widget
 *
 * There are 3 structures to this widget:
 * 1. The layout selection
 * 2. The unused widgets
 * 3. The regions themselves
 *
 * 1. Layout Selection
 * -------------------
 * The region arrangement is determined by a 2 step process. First the user selects the number of columns they want.
 * This is merely browsing, it has no effect on the final the widget arrangement. When they select the number of
 * columns, the list of layouts filters by the number of columns each layout has.
 * Now the user can click a layout, and the region arrangement will update. Any widgets in regions that are no longer
 * in the layout will be returned to 'Unused widgets'.
 *
 * 2. Unused Widgets
 * -----------------
 * A list of draggable widgets, with a search bar. The search bar will automatically filter the Unused Widgets list by
 * the title of the widget, as entered by the user.
 *
 * 3. Regions
 * -----------------
 * A group of regions that widgets can be dragged into. Which regions are present and when is determined by a class on
 * on the parent element. When a region is removed due to layout change, it's widgets are dumped back into unused
 * widgets. When the form is saved, all the widgets are translated into a {bid}|{bid} format and sent to the server.
 */

(function ($) {

  function filterLayouts(e) {
    $('#edit-layout .form-type-radio').hide().find('input').each(function (){
      var layout_count = this.value.split('-')[0];
      switch (layout_count) {
        case 'two':
          layout_count = 2;
          break;
        case 'three':
          layout_count = 3;
          break;
        case 'four':
          layout_count = 4;
          break;
        case 'five':
          layout_count = 5;
          break;
        default:
          return;
      }

      if (layout_count == e.currentTarget.value) {
        $(this).parents('.form-type-radio').show();
      }
    });
  }

  Drupal.behaviors.osBoxesColumns = {
    attach: function (ctx) {
      $('input[name="num_cols"]:radio').change(filterLayouts);
      $('input[name="layout"]:radio').change(regionsArrange);
    }
  };

})(jQuery);