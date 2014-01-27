/**
 * Required interactions:
 * * Clicking Browse button opens Media Browser, which returns a mediaFile object
 * * Dragging files to Drop region uploads and returns a mediaFile object
 * * Doing either of those things adds row to the list below the drop region
 * * Editing a file works, and should update the filename if necessary
 * * Removing a file removes it from the list
 * *
 * * Adding and Removing files both save properly to the node
 */

(function ($) {

  function openBrowser() {

  }

  function openEdit(e) {

  }

  function removeFile(e) {

  }

  Drupal.behaviors.mediaDraggableWidget = {
    attach: function (ctx) {
      $('.field-widget-media-draggable-file .form-type-dragndrop-upload').once('media-draggable', function () {
        $('.droppable-browse-button', this).unbind().click(openBrowser);
      });

      $('.field-widget-media-draggable-file .file-list-single').once('media-draggable', function () {
        $('.edit a', this).click(openEdit);
        $('.remove a', this).click(removeFile);
      });
    }
  };
})(jQuery);