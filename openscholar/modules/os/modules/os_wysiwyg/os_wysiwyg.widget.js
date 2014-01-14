/**
 * Adds behavior to self-hiding wysiwyg widget
 */
(function ($) {
  function wysiwyg_focus(e) {
    console.log('focus');
    console.log(e);
  }

  function wysiwyg_blur(e) {
    console.log('blur');
    console.log(e);
  }

  Drupal.behaviors.osWysiwygExpandingTextarea = {
    attach: function (ctx) {
      setTimeout(function () {
        var edit_id = $('.os-wysiwyg-expandable').attr('id');
        tinyMCE.editors[edit_id].contentDocument.getElementsByTagName('body')[0].onfocus = wysiwyg_focus;
        tinyMCE.editors[edit_id].contentDocument.getElementsByTagName('body')[0].onblur = wysiwyg_blur;
      }, 500);
    }
  }
})(jQuery);
