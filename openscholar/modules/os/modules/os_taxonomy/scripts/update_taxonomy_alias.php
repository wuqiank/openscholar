<?php

$results = db_select('url_alias', 'u')
  ->fields('u')
  ->condition('source', '%taxonomy/term%', 'LIKE')
  ->execute()
  ->fetchAllAssoc('pid');

foreach ($results as $result) {
  $info = explode('/', $result->source);
  $purl = os_taxonomy_vsite_path(end($info));

  if (!$purl) {
    continue;
  }

  if (strpos($result->alias, $purl) !== FALSE) {
    continue;
  }

  $alias = $purl . '/' . $result->alias;

  $new_path = (array) $result + array(
    'alias' => $alias,
  );

  $params = array(
    '@alias' => $result->alias,
    '@new-alias' => $alias,
  );

  drush_log(dt('The alias @alias has been updated to @new-alias', $params), 'success');
  path_save($new_path);
}

/**
 * Get the path of the vsite which the vocab belong.
 *
 * @param $tid
 *  The term ID.
 *
 * @return
 *  The path of the vsite.
 */
function os_taxonomy_vsite_path($tid) {
  $term = taxonomy_term_load($tid);
  $purls = &drupal_static(__FUNCTION__, array());

  if (in_array($term->vid, $purls)) {
    return $purls[$term->vid];
  }

  $relation = og_vocab_relation_get($term->vid);
  $vsite = vsite_get_vsite($relation->gid);
  $purls[$term->vid] = $vsite->group->purl;

  return $vsite->group->purl;
}
