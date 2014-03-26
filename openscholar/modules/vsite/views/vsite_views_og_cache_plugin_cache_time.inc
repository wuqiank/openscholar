<?php

class vsite_views_og_cache_plugin_cache_time extends views_og_cache_plugin_cache_time {

  public function get_results_key_data() {
    $key_data = parent::get_results_key_data();

    // Add OS Calendar's specific $_GET keys.
    foreach (array('type', 'year', 'week', 'day') as $key) {
      if (isset($_GET[$key])) {
        $key_data[$key] = $_GET[$key];
      }
    }

    return $key_data;
  }
}

