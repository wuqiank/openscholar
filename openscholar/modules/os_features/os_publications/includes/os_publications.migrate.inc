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
    // Load the Biblio node form to populate the appropriate fields
    // in the new created Biblio entity.
    $node = node_load($row->nid);

    // In Biblio 3.x the image field is named "biblio_image".
    $entity->biblio_image = $node->field_biblio_image;

    // In Biblio 3.x the upload field is named "biblio_pdf".
    $entity->biblio_pdf = $node->field_upload;

    // In Biblio 3.x the extra field is named "biblio_extra".
    $entity->biblio_extra = $node->field_biblio_extra;

    // Add og_vocabulary field to a Biblio entry.
    $entity->og_vocabulary = $node->og_vocabulary;
    if (!empty($node->og_vocabulary)) {
      $this->createBiblioVocab($entity);
    }

    // @todo: add mapping to remaining fields:
    // path, redirect
  }

  /**
   * Apply needed changes to the new Biblio entity.
   */
  public function complete($entity, $row) {

  }

  /**
   * Create an og_vocab entity if the vocabulary is not linked yet to
   * the biblio entity and its bundle.
   *
   * @param $entity
   *    The biblio entity.
   */
  private function createBiblioVocab($entity) {
    $wrapper = entity_metadata_wrapper('biblio', $entity);

    foreach ($wrapper->{OG_VOCAB_FIELD} as $terms) {
      $vid = $terms->vocabulary->getIdentifier();

      // Create the OG vocabulary and the relation to the group.
      if (!og_vocab_load_og_vocab($vid, 'biblio', $entity->type)) {
        og_vocab_create_og_vocab($vid, 'biblio', $entity->type)->save();
        og_vocab_relation_save($vid, 'node', $wrapper->{OG_AUDIENCE_FIELD}->get(0)->getIdentifier());
      }
    }
  }
}
