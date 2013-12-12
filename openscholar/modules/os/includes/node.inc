<?php

/**
 * @file
 * Common functions for working with node content in OpenScholar.
 */

/**
 * Prepares an EntityFieldQuery with any necessary vsite-sensitive conditions.
 */
class OSNodeFieldQuery extends EntityFieldQuery {

  /**
   * @param $node_types
   *   Optional; Array or string of node types to filter by. If empty, all node
   *   types would be used.
   * @param $filter_vsite
   *   Optional; Determine if content should be filtered by current VSite.
   *   Defaults to TRUE.
   */
  public function __construct($node_types = NULL, $filter_vsite = TRUE) {
    // Limits only to published nodes.
    $this
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('status', NODE_PUBLISHED);

    if (isset($node_types)) {
      // Adds node type condition.
      $node_types = is_array($node_types) ? $node_types : array($node_types);
      $this->propertyCondition('type', $node_types, 'IN');
    }

    // Only continues to filter by current space if we can load the vsite.
    if (!module_exists('vsite') || !$filter_vsite) {
      return;
    }
    if (!$vsite = vsite_get_vsite()) {
      return;
    }

    $this->fieldCondition(OG_AUDIENCE_FIELD, 'target_id', $vsite->id);
  }
}