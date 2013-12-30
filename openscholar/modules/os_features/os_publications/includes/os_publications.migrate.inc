<?php

class OsBiblioMigrateEntries extends BiblioMigrateEntries {

  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    // Add group audience field to a Biblio entry.
    $this->query->innerJoin('og_membership', 'ogm', 'ogm.etid = b.nid');
    $this->query
      ->fields('ogm', array('gid'))
      ->condition('ogm.entity_type', 'node');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, 'gid');
  }

  /**
   * Map field API fields from the node to the new Biblio entity.
   */
  public function prepare($entity, $row) {
    // Load the Biblio node form to populate the appropriate field
    // in the new created Biblio entity.
    $node = node_load($row->nid);

    // In Biblio 3.x the image field is named "biblio_image".
    $entity->biblio_image = $node->field_biblio_image;

    // In Biblio 3.x the upload field is named "biblio_pdf".
    $entity->biblio_pdf = $node->field_upload;

    // @TODO: add mapping to remaining fields:
    // path, redirect, field_biblio_extra, ,og_vocabulary
  }
}
