<?php

class vsite_views_og_cache_plugin_cache_time extends views_og_cache_plugin_cache_time {

  function get_results_key() {
    global $user;
    $og_context = og_context();

    if (!isset($this->_results_key) && $og_context) {

      $build_info = $this->view->build_info;
      foreach (array('query','count_query') as $index) {
        // If the default query back-end is used generate SQL query strings from
        // the query objects.
        if ($build_info[$index] instanceof SelectQueryInterface) {
          // There could be a view with altered query which can lead to caching
          // problems. Using the rendered query will give us a unique cache
          // identifier.
          $query = $this->view->build_info[$index];
          $arguments = $query->getArguments();
          $build_info[$index] = strtr($query, $arguments);
        }
      }

      $key_data = array(
        'build_info' => $build_info,
        'language' => $GLOBALS['language']->language,
        'base_url' => $GLOBALS['base_url'],
        'og_roles' => og_get_user_roles($og_context['group_type'], $og_context['gid']),
        'admin' => user_access('administer group'),
        'display_handler' => array(
          $this->view->display_handler->get_option('style_options'),
          $this->view->display_handler->get_option('pager'),
          $this->view->display_handler->get_option('arguments'),
        ),
      );

      if ($this->options['og_access']) {
        // Check if the group is private, and if so, change the cache type
        // to per-user, instead of per-group.
        $wrapper = entity_metadata_wrapper($og_context['group_type'], $og_context['gid']);
        if (!empty($wrapper->{OG_ACCESS_FIELD}) && $wrapper->{OG_ACCESS_FIELD}->value() == OG_CONTENT_ACCESS_PRIVATE) {
          $key_data['user'] = $user->uid;
        }
      }

      foreach (array('exposed_info', 'page', 'sort', 'order') as $key) {
        if (isset($_GET[$key])) {
          $key_data[$key] = $_GET[$key];
        }
      }
      // Add OS Calendar's specific $_GET keys.
      foreach (array('type', 'year', 'week', 'day') as $key) {
        if (isset($_GET[$key])) {
          $key_data[$key] = $_GET[$key];
        }
      }
      $this->_results_key = 'og:' . $og_context['group_type'] . ':' . $og_context['gid'] . ':' . $this->view->name . ':' . $this->display->id . ':results:' . md5(serialize($key_data));
    }
    return !empty($this->_results_key) ? $this->_results_key : NULL;
  }

  function get_output_key() {
    global $user;
    $og_context = og_context();
    if (!isset($this->_output_key) && $og_context) {
      $key_data = array(
        'result' => $this->view->result,
        'theme' => $GLOBALS['theme'],
        'language' => $GLOBALS['language']->language,
        'base_url' => $GLOBALS['base_url'],
        'og_roles' => og_get_user_roles($og_context['group_type'], $og_context['gid']),
        'admin' => user_access('administer group'),
        'display_handler' => array(
          $this->view->display_handler->get_option('style_options'),
          $this->view->display_handler->get_option('pager'),
          $this->view->display_handler->get_option('arguments'),
        ),
      );

      if ($this->options['og_access']) {
        // Check if the group is private, and if so, change the cache type
        // to per-user, instead of per-group.
        $wrapper = entity_metadata_wrapper($og_context['group_type'], $og_context['gid']);
        if (!empty($wrapper->{OG_ACCESS_FIELD}) && $wrapper->{OG_ACCESS_FIELD}->value() == OG_CONTENT_ACCESS_PRIVATE) {
          $key_data['user'] = $user->uid;
        }
      }

      $this->_output_key = 'og:' . $og_context['group_type'] . ':' . $og_context['gid'] . ':' . $this->view->name . ':' . $this->display->id . ':output:' . md5(serialize($key_data));
    }

    return !empty($this->_output_key) ? $this->_output_key : NULL;
  }
}
