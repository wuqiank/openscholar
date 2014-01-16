/**
 * Adds behavior to self-hiding wysiwyg widget
 */
(function ($) {
  function wysiwyg_focus(e) {
    var base_id = e.currentTarget.name.replace('_ifr', ''),
      editor = $('#'+base_id+' + .mceEditor table.mceLayout'),
      height = (parseInt($('#'+base_id).attr('data-maxrows')) * 25);

    editor.css('height', height+'px')
      .removeClass('os-wysiwyg-collapsed');
    $('iframe', editor).css('height', height+1+'px')

  }

  function wysiwyg_minimize(element) {
    var base_id = element.name?element.name.replace('_ifr', ''):element.id.replace('_ifr', ''),
      editor = $('#'+base_id+' + .mceEditor table.mceLayout'),
      height = (parseInt($('#'+base_id).attr('data-minrows')) * 20);

    editor.css('height', height+'px')
      .addClass('os-wysiwyg-collapsed');
    $('iframe', editor).css('height', height+1+'px');
  }

  function blurHandler (e) {
    wysiwyg_minimize(e.currentTarget);
  }

  function bindHandlers(ctx) {
    $('.os-wysiwyg-expandable', ctx).each(function () {
      var edit_id = $(this).attr('id');
      if (typeof tinyMCE.editors[edit_id] !== 'undefined' && typeof tinyMCE.editors[edit_id].contentDocument !== 'undefined') {
        tinyMCE.editors[edit_id].contentDocument.getElementsByTagName('body')[0].onfocus = wysiwyg_focus;
        tinyMCE.editors[edit_id].contentDocument.getElementsByTagName('body')[0].onblur = blurHandler;
        wysiwyg_minimize($('#'+edit_id+' + .mceEditor .mceIframeContainer iframe').get(0));
        $('.os-wysiwyg-expandable ~ .wysiwyg-toggle-wrapper a').click(toggleHandlers);
      }
      else {
        setTimeout(function () { bindHandlers(ctx); }, 500);
      }
    });
  }

  function toggleHandlers(e) {
    bindHandlers($(this).parents('.text-format-wrapper'));
  }

  Drupal.behaviors.osWysiwygExpandingTextarea = {
    attach: function (ctx) {
      setTimeout(function () { bindHandlers(ctx); }, 500);
    }
  };
})(jQuery);
