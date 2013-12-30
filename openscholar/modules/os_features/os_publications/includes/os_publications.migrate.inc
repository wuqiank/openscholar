<?php

class OsBiblioMigrateEntries extends BiblioMigrateEntries {

  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    // Add og_group_ref field to a biblio entry.
    $this->query->innerJoin('og_membership', 'ogm', 'ogm.etid = b.nid');
    $this->query
      ->fields('ogm', array('gid'))
      ->condition('ogm.entity_type', 'node');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, 'gid');
  }

  // Add biblio_image field to a biblio entry.
  public function prepare($entity, $row) {
    $node = node_load($row->nid);
    $entity->biblio_image = $node->field_biblio_image;
  }
}
