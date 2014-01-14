<?php

/**
 * This is an example of a Plugin extending CiteProc.
 */
if (module_exists('libraries') && file_exists(libraries_get_path('citeproc-php') . '/CiteProc.php')) {
  $plugin = array(
    'title' => t('OS publications'),
    'description' => t('Open scholar publication plugin type.'),
    'class' => 'OsPublicationsCiteProc',
    'options' => array(
      // Default values.
      'style_name' => 'chicago-author-date',
      // Allow settings the path to custom CSL styles (should include the .csl
      // extension). If the style exists in the "styles" library, set the style
      // path to the that library. Else set the path to the "style" folder in
      // the "citeproc-php" library.
      'style_path' => file_exists(libraries_get_path('styles') . '/chicago-author-date.csl') ? libraries_get_path('styles') : libraries_get_path('citeproc-php') . '/style',
      // Link to the biblio.
      'label_as_link' => TRUE,
    ),
    'assets' => array(
      'js' => array(
        drupal_get_path('module', 'os_publications') . '/js/os_publications.js',
      ),
      'css' => array(
        drupal_get_path('module', 'os_publications') . '/css/os_publications.css',
      ),
    ),
  );
}
