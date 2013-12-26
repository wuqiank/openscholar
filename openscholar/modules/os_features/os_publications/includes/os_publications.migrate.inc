<?php

class OsBiblioMigrateEntries extends BiblioMigrateEntries {

  public function __construct() {
    parent::__construct();

    $this->query->innerJoin('og_membership', 'ogm', 'ogm.etid = b.nid');
    $this->query
      ->fields('ogm', array('gid'))
      ->condition('ogm.entity_type', 'node');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD);
  }
}
