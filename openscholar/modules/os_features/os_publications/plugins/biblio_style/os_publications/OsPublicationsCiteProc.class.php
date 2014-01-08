<?php

/**
 * @file
 * Extending Citeproc biblio style example.
 */

class OsPublicationsCiteProc extends BiblioStyleCiteProc {

  public function render($options = array(), $langcode = NULL) {
    $citation = parent::render($options, $langcode);

    // Get abstract.
    $wrapper = entity_metadata_wrapper('biblio', $this->biblio);
    $abstract = isset($wrapper->biblio_abstract) ? $wrapper->biblio_abstract->value() : '';

    $items = array();
    $options = array(
      'attributes' => array(
        'class' => 'publication-pdf',
      ),
    );
    foreach ($wrapper->biblio_pdf->value() as $pdf_file) {
      $url = file_create_url($pdf_file['uri']);
      $items[] = l($pdf_file['filename'], $url, $options);
    }

    $image = NULL;
    if ($image_info = $wrapper->biblio_image->value()) {
      $image = theme('image', array('path' => $image_info['uri'], 'width' => 50, 'height' => 50));
    }

    $variables = array(
      'bid' => $wrapper->getIdentifier(),
      'image' => $image,
      'citation' => $citation,
      'abstract' => $abstract,
      'pdf_list' => theme('item_list', array('items' => $items)),
    );

    return theme('os_publications_citeproc', $variables);
  }
}
