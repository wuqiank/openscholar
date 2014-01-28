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
  var template;

  function openBrowser() {

  }

  function openEdit(e) {

  }

  function removeFile(e) {

  }

  function addRow(file) {
    var str = template.html(),
      id = template.attr('id'),
      count = $('.file-list-single').length - 1;

    str = str.replace('template', count);
    str = str.replace('-1', file.fid);
    str = str.replace('value="blank"', 'value="'+file.fid+'"');
    str = str.replace(' blank', ' '+file.filename);
    id = id.replace('template', count);

    var $row = $(str),
      icon = $(file.preview).find('img.file-icon');
    $row.find('img.file-icon').replaceWith(icon);
    var $wrapper = $row.wrapAll('<div class="file-list-single form-wrapper media-draggable-processed" id="id"></div>').parent();
    setupRowHandlers.call($wrapper);
    $('.file-list-single').parent().append($wrapper);
  }

  function setupRowHandlers() {
    $('.edit a', this).click(openEdit);
    $('.remove a', this).click(removeFile);
  }

  Drupal.behaviors.mediaDraggableWidget = {
    attach: function (ctx, settings) {
      if (typeof template == 'undefined') {
        template = $('.file-list-single[hidden]');
      }
      $('.field-widget-media-draggable-file .form-type-dragndrop-upload').once('media-draggable', function () {
        $('.droppable-browse-button', this).unbind().click(openBrowser);
      });

      $('.field-widget-media-draggable-file .file-list-single').once('media-draggable', setupRowHandlers);

      if (typeof settings.mediaDraggable != 'undefined' && ctx.prop('tagName') == 'FORM') {
        addRow(settings.mediaDraggable.newFile);
        settings.mediaDraggable.newFile = false;
      }
    }
  };
})(jQuery);