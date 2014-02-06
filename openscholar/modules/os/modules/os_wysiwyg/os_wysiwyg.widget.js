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
      height = (parseInt($('#'+base_id).attr('data-minrows')) * 20),
      scrollSize = document.body.scrollHeight,
      scrollPos = document.body.scrollTop;

    // when a scrollable area is resized, it calculates the new scroll position with the following formula:
    // document.body.scrollTop = min(document.body.scrollTop, document.body.scrollHeight - window.innerHeight)
    // if the old scroll position was higher than the new maximum, it gets set to maximum
    // otherwise, nothing happens
    // we need to get the difference between old scroll position and new, subtract it from the height the wysiwyg tags,
    // and then subtract that from the new position


    editor.css('height', height+'px')
      .addClass('os-wysiwyg-collapsed');
    $('iframe', editor).css('height', height+1+'px');

    var scrollDiff = scrollSize - document.body.scrollHeight,
      scrollDelta = scrollPos - document.body.scrollTop;
    document.body.scrollTop -= (scrollDiff - scrollDelta)
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
