<?php

/**
 * @file
 * Contains OSApacheSolrFacetapiAdapter.
 */

class OsApacheSolrFacetapiAdapter extends ApacheSolrFacetapiAdapter {

  /**
   * Overrides ApacheSolrFacetapiAdapter::getFacetSettingsGlobal().
   */
  public function getFacetSettingsGlobal(array $facet) {
    $result = parent::getFacetSettingsGlobal($facet);
    return $result;
  }

}
