api = 2
core = 7.x
projects[drupal][type] = "core"
projects[drupal][version] = "7.24"
projects[drupal][patch][] = "http://drupal.org/files/order-weighted-terms-941266-35-D7.patch"
projects[drupal][patch][] = "http://drupal.org/files/drupal-apc_redeclare_database-838744-24.patch"
projects[drupal][patch][] = "http://drupal.org/files/text-summary-word-break.patch"
projects[drupal][patch][] = "https://drupal.org/files/drupal.menu-theme-objects.18.patch"
; To be removed after this issue is included in Drupal 7 core
; @see https://drupal.org/node/2143461
projects[drupal][patch][] = "https://drupal.org/files/issues/drupal-7.x-dev-drupal_get_query_array_explosion_fix-2143461-4.patch"
