<?php

/**
 * @file
 * Template file for a droppable area of 'dragndrop_upload_widget_image' widget.
 */

$icon = theme('image', array('path' => drupal_get_path('module', 'os_publications') . '/misc/application-pdf.png'));
$publication_image = theme('image', array('path' => drupal_get_path('module', 'os_publications') . '/misc/publication-cover.png'));
?>

<div class="droppable droppable-image" id="<?php print $element['#dnd_id']; ?>">
  <div class="droppable-preview">
    <div class="droppable-preview-image">
      <div class="preview-remove">x</div>
      <img/>
    </div>
  </div>
  <div class="droppable-message">
    <span><?php print render($element['#text']); ?></span>

    <?php if ($element['#standard_upload']): ?>
      <div class="droppable-standard-upload">
        <span><?php print t('or'); ?></span>
        <a href="#" class="droppable-browse-button button">
          <?php print t('Browse'); ?>
        </a>
        <a href="#" class="biblio-pop os-publications-image-help" data-popbox="pop2"><span><?php print t('Help'); ?></span></a>
        <span id="pop2" class="biblio-stylebox2">
          <div class="biblio-dummy-wrapper">
            <div class="biblio-dummy-image"><?php print $publication_image; ?></div>
            <div class="biblio-dummy-body">
              Wand, Jonathan, Gary King and Olivia Lau. 2011.
              <a>Anchors: Software for Anchoring Vigenttes Data.</a>
              <em>Jornal of Statistical Software</em>
              <span>42, no. 3: 1-25.</span>
            </div>
            <div class="biblio-dummy-links">
              <a>Website</a>
              <a class="biblio-abstract-dummy-link">Abstract</a>
              <span>
                <span>
                  <?php print $icon; ?>
                  <a>Article</a>
                </span>
              </span>
            </div>
          </div>
        </span>
      </div>
    <?php endif ?>
  </div>
</div>
<div class="droppable-controls">
  <?php print render($element['remove_button']); ?>
  <?php print render($element['upload_button']); ?>
</div>
