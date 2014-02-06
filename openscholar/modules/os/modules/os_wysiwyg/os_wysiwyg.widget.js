/**
 * Adds behavior to self-hiding wysiwyg widget
 */
(function ($) {
  
  function wysiwyg_expand(e) {
    var parent;
    if (e.currentTarget.ownerDocument.defaultView.name.indexOf('_ifr') != -1) {
      parent = $('#'+e.currentTarget.ownerDocument.defaultView.name.replace('_ifr', '')).parents('.form-item');
    }
    else {
      parent = $(e.currentTarget).parents('.form-item');
    }
    var editor = parent.find('.mceEditor table.mceLayout'),
      height = (parseInt(parent.find('[data-maxrows]').attr('data-maxrows')) * 25);

    editor.removeClass('os-wysiwyg-collapsed');
    editor.animate({height: height+'px'}, 600, 'swing', function() {
      parent.find('.wysiwyg-toggle-wrapper').show();
    });
    $('iframe', editor).animate({height: height+1+'px'}, 600);
    editor.children('tbody').children('tr.mceFirst, tr.mceLast').animate({opacity: 1.0}, 600);
  }

  function wysiwyg_minimize() {
    var editor = $('.mceEditor table.mceLayout').not('.os-wysiwyg-collapsed'),
      parent = editor.parents('.form-item'),
      height = (parseInt(parent.find('[data-minrows]').attr('data-minrows')) * 20),
      scrollSize = document.body.scrollHeight,
      scrollPos = document.body.scrollTop;

    // when a scrollable area is resized, it calculates the new scroll position with the following formula:
    // document.body.scrollTop = min(document.body.scrollTop, document.body.scrollHeight - window.innerHeight)
    // if the old scroll position was higher than the new maximum, it gets set to maximum
    // otherwise, nothing happens
    // we need to get the difference between old scroll position and new, subtract it from the height the wysiwyg tags,
    // and then subtract that from the new position


    editor.animate({height: height+'px'}, 600)
      .addClass('os-wysiwyg-collapsed');
    $('iframe', editor).animate({height: height+1+'px'}, 600);
    parent.find('.wysiwyg-toggle-wrapper').hide();

    var scrollDiff = scrollSize - document.body.scrollHeight,
      scrollDelta = scrollPos - document.body.scrollTop;
    //document.body.scrollTop -= (scrollDiff - scrollDelta)
  }

  function listboxClickHandler(e) {
    // there's no easy way to get the editor this list element is for. I have to muck about with the id string to
    // figure out which editor should be expanded.
    var id_frags = e.currentTarget.id.split('_'),
      dummy = {
        currentTarget: document.getElementById(id_frags[1])
      };

    wysiwyg_expand(dummy);
  }

  function bindHandlers(ctx) {
    $('.os-wysiwyg-expandable', ctx).each(function () {
      var edit_id = $(this).attr('id');
      if (typeof tinyMCE.editors[edit_id] !== 'undefined' && typeof tinyMCE.editors[edit_id].contentDocument !== 'undefined') {
        tinyMCE.editors[edit_id].contentDocument.getElementsByTagName('body')[0].onclick = wysiwyg_expand;
        $('#'+edit_id+'_tbl').click(wysiwyg_expand);
        // use mouseup because it fires before click, and can't be prevented by other scripts' click handlers
        $('body').mouseup(wysiwyg_minimize);

        wysiwyg_minimize();
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
      if (typeof ctx.body != 'undefined') {
        $(ctx.body).delegate('.mceListBoxMenu[role="listbox"]', 'click', listboxClickHandler);
      }
    }
  };
})(jQuery);
