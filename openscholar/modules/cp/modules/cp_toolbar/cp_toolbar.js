
(function ($) {

Drupal.cp_toolbar = Drupal.cp_toolbar || {};

/**
 * Attach toggling behavior and notify the overlay of the toolbar.
 */
Drupal.behaviors.cp_toolbar = {
  attach: function(context) {
    var $drawer_links = $('#toolbar .drawer-links a:not(#toolbar-link-admin-appearance)', context)
    $('#toolbar .toolbar-menu li').bind('mouseenter', Drupal.cp_toolbar.drawer_toggle);
    
    Drupal.cp_toolbar.path = $('#toolbar .active');
    //Drupal.cp_toolbar.original = Drupal.settings.toolbar.tooltips.default;

    //$(window).bind('hashchange.drupal-overlay', Drupal.cp_toolbar.activeTrail);
    //$(document).bind('drupalOverlayLoad', Drupal.cp_toolbar.activeTrail);
    //$(document).bind('drupalOverlayClose', Drupal.cp_toolbar.drawer_close);
    
    $('#toolbar li').bind('mouseenter', Drupal.cp_toolbar.tooltipShow);
    $('#toolbar').bind('mouseleave', Drupal.cp_toolbar.tooltipHide);
    $('#toolbar').bind('mouseleave', Drupal.cp_toolbar.drawer_close);
    $('#tooltip .toolbar-menu li').bind('mouseleave', Drupal.cp_toolbar.tooltipHide);
    
  }
};

Drupal.cp_toolbar.drawer_toggle = function (event) {
  event.preventDefault();
  event.stopPropagation();
  
  var $this = $(this).children('a:first');
  var $drawer = $('#' + $this.attr('data-drawer'));
  
  if (!$drawer.length) {
    // Let normal interaction proceed
    Drupal.cp_toolbar.drawer_close();
    $(this).addClass('active').blur();
    
    if ($this.attr('data-tooltip') != '') {
      $('#toolbar .active-path').removeClass('active-path');
      $('.toolbar-tooltips').parentsUntil('#toolbar').addClass('active-path');
    }
    return;
  }
  
  if ($drawer.hasClass('active-path') && $this.hasClass('active-path')) {
    Drupal.cp_toolbar.drawer_close();
    Drupal.cp_toolbar.path.addClass('active');
    Drupal.cp_toolbar.path.parentsUntil('#toolbar').addClass('active-path');
    $('#toolbar [data-drawer=' + $('.toolbar-drawer .drawer.active-path').attr('id') + ']').addClass('active-path');
  } else {
    $('#toolbar .active').removeClass('active');
    $('#toolbar .active-path').removeClass('active-path');
    $this.addClass('active-path').blur();
    $drawer.addClass('active-path');
    $drawer.parentsUntil('#toolbar').addClass('active-path');
    //$('body').css('paddingTop', Drupal.toolbar.height());
  }
  
  Drupal.overlay.eventhandlerAlterDisplacedElements();
};

Drupal.cp_toolbar.drawer_close = function (event) {
  $('#toolbar .active').removeClass('active').blur();
  $('#toolbar .active-path').removeClass('active-path').blur();
  $('body').css('paddingTop', Drupal.toolbar.height());
};

Drupal.cp_toolbar.activeTrail = function (event) {
  var path = Drupal.settings.basePath + $.bbq.getState('overlay');
  $('#toolbar a.active').removeClass('active');
  $('#toolbar .active-path').removeClass('active-path');
  var $link = $('#toolbar a[href=' + path + ']');
  $link.addClass('active');
  $link.parentsUntil('#toolbar').addClass('active-path');
  $('#toolbar [drawer=' + $('.toolbar-drawer .drawer.active-path').attr('id') + ']').addClass('active-path');
  Drupal.cp_toolbar.path = $('#toolbar .active');
  Drupal.overlay.eventhandlerAlterDisplacedElements();
};

Drupal.cp_toolbar.tooltipShow = function (event) {
  var link = $(this).find('a');

  var text = Drupal.t('This is your administrative toolbar.');
  if (event.type == 'mouseenter' && link.attr('data-tooltip') != '') {
    text = link.attr('data-tooltip');
  }
  
  if (!$('.toolbar-drawer').hasClass('active') && event.type == 'mouseleave') {
    Drupal.cp_toolbar.tooltipHide();
  }
  
  $('.toolbar-tooltips').html(text);
};

Drupal.cp_toolbar.tooltipHide = function (event) {
  event.stopPropagation();
  event.preventDefault();
  if ($(this).attr('id') == 'toolbar' || !$('#toolbar .toolbar-drawer').hasClass('active')) {
  }
};

/**
 * Retrieve last saved cookie settings and set up the initial toolbar state.
 * Overrides toolbar.module to include consideration of default given from
 * server (and not expanded be default as is in core module).
 */
Drupal.toolbar.init = function() {
  // Retrieve the collapsed status from a stored cookie.
  var collapsed = $.cookie('Drupal.toolbar.collapsed');
  var defaultCollapsed = Drupal.settings.cp_toolbar.collapsed;

  // Expand or collapse the toolbar based on the cookie value.
  if (collapsed == 1) {
    Drupal.toolbar.collapse();
  }
  else if (collapsed == 0) {
    Drupal.toolbar.expand();
  }
  else if (defaultCollapsed == 1) {
    Drupal.toolbar.collapse();
  }
  else {
    Drupal.toolbar.expand();
  }
};

})(jQuery);
