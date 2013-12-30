<?php

class OsBiblioMigrateEntries extends BiblioMigrateEntries {

  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->query->innerJoin('og_membership', 'ogm', 'ogm.etid = b.nid');
    $this->query
      ->fields('ogm', array('gid'))
      ->condition('ogm.entity_type', 'node');

    $this->addFieldMapping(OG_AUDIENCE_FIELD, 'gid');

  }
}
