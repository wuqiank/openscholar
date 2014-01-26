<?php

/**
 * @file
 */

class os_boxes_facetapi extends os_boxes_default {

  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults();
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form(&$form_state) {
    $realm_name = 'block';
    $facets = array();

    $form = parent::options_form($form_state);

    // Gets delta map, iterates over all enabled facets.
    $map = facetapi_get_delta_map();
    foreach (facetapi_get_searcher_info() as $searcher => $info) {

      // Adds blocks for facets that are enabled or whose delta mapping is forced.
      foreach (facetapi_get_delta_map_queue($searcher, $realm_name) as $facet_name) {
        if ($facet = facetapi_facet_load($facet_name, $searcher)) {
          // Gets the delta from the delta map.
          $string = facetapi_build_delta($searcher, $realm_name, $facet_name);
          $delta = array_search($string, $map);

          // Builds the info. For non-block realm, append the realm name.
          $subject = 'Facet API: ' . $info['label'] . ' : ' . $facet['label'];
          if ('block' != $realm_name && ($realm = facetapi_realm_load($realm_name))) {
            $subject .= ' (' . $realm['label'] . ')';
          }
          $facets[$delta] = $subject;
        }
      }
    }

    $form['facet'] = array(
      '#type' => 'select',
      '#title' => t('Facet'),
      '#description' => t('Select Solr search facet to use.'),
      '#options' => $facets,
    );

    return $form;
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render() {
    //@todo
    $block = parent::render();

    return $block;
  }

}
