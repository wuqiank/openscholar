<?php

/**
 * @file
 * Contains OSApacheSolrFacetapiAdapter.
 */

class OsApacheSolrFacetapiAdapter extends ApacheSolrFacetapiAdapter {

  /**
   * Overrides ApacheSolrFacetapiAdapter::getFacetSettingsGlobal().
   */
  public function __getFacetSettingsGlobal(array $facet) {
    $result = parent::getFacetSettingsGlobal($facet);
    return $result;
  }
}
