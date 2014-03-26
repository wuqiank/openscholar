<?php

class vsite_views_og_cache_plugin_cache_time extends views_og_cache_plugin_cache_time {

  public function get_key_data() {
    $key_data = parent::get_key_data();
    // Add OS Calendar's specific $_GET keys.
    return $key_data;
  }
}

