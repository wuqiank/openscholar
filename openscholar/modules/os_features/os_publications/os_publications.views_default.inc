<?php
/**
 * @file
 * os_publications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os_publications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'os_publications';
  $view->description = 'OS Publications > Recent Publications';
  $view->tag = 'default';
  $view->base_table = 'biblio';
  $view->human_name = 'os_publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'spaces_feature';
  $handler->display->display_options['access']['spaces_feature'] = 'os_publications';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Publication: Export links */
  $handler->display->display_options['header']['biblio_export']['id'] = 'biblio_export';
  $handler->display->display_options['header']['biblio_export']['table'] = 'biblio';
  $handler->display->display_options['header']['biblio_export']['field'] = 'biblio_export';
  /* Relationship: OG membership: OG membership from Publication */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'biblio';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'OG';
  /* Field: Publication: Render bilbio (Get text) */
  $handler->display->display_options['fields']['biblio_render']['id'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_render']['field'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['label'] = '';
  $handler->display->display_options['fields']['biblio_render']['element_label_colon'] = FALSE;
  /* Sort criterion: Publication: Year of Publication (biblio_year) */
  $handler->display->display_options['sorts']['biblio_year_value']['id'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['table'] = 'field_data_biblio_year';
  $handler->display->display_options['sorts']['biblio_year_value']['field'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['order'] = 'DESC';
  /* Contextual filter: Field: Groups audience (og_group_ref) */
  $handler->display->display_options['arguments']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['os_publications'] = $view;

  $view = new view();
  $view->name = 'os_publications_issued';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'biblio';
  $view->human_name = 'OS publications Issued';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'biblio_status',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'biblio_year',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Biblio: Publication status */
  $handler->display->display_options['fields']['biblio_status']['id'] = 'biblio_status';
  $handler->display->display_options['fields']['biblio_status']['table'] = 'field_data_biblio_status';
  $handler->display->display_options['fields']['biblio_status']['field'] = 'biblio_status';
  $handler->display->display_options['fields']['biblio_status']['label'] = '';
  $handler->display->display_options['fields']['biblio_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['biblio_status']['element_label_colon'] = FALSE;
  /* Field: Biblio: Year of Publication */
  $handler->display->display_options['fields']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['table'] = 'field_data_biblio_year';
  $handler->display->display_options['fields']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['label'] = '';
  $handler->display->display_options['fields']['biblio_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['biblio_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['biblio_year']['alter']['text'] = '<div class=\'biblio-separator-bar\'>[biblio_year]</div>';
  $handler->display->display_options['fields']['biblio_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['biblio_year']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['biblio_year']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Header: Publication: Export links */
  $handler->display->display_options['header']['biblio_export']['id'] = 'biblio_export';
  $handler->display->display_options['header']['biblio_export']['table'] = 'biblio';
  $handler->display->display_options['header']['biblio_export']['field'] = 'biblio_export';
  /* Field: Publication: Render bilbio (Get text) */
  $handler->display->display_options['fields']['biblio_render']['id'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_render']['field'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['label'] = '';
  $handler->display->display_options['fields']['biblio_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_render']['style_name'] = 'os_publications';
  /* Sort criterion: Biblio: Year of Publication (biblio_year) */
  $handler->display->display_options['sorts']['biblio_year_value']['id'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['table'] = 'field_data_biblio_year';
  $handler->display->display_options['sorts']['biblio_year_value']['field'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'primary-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['os_publications_issued'] = $view;

  $view = new view();
  $view->name = 'publication_contributors';
  $view->description = 'Publications By Co-Author';
  $view->tag = 'widgets';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'spaces_feature';
  $handler->display->display_options['access']['spaces_feature'] = 'os_publications';
  $handler->display->display_options['access']['perm'] = 'access biblio content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'name';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Publication: Type of Publication */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'biblio_types';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Publication: Biblio Citation */
  $handler->display->display_options['fields']['citation']['id'] = 'citation';
  $handler->display->display_options['fields']['citation']['table'] = 'biblio';
  $handler->display->display_options['fields']['citation']['field'] = 'citation';
  $handler->display->display_options['fields']['citation']['label'] = '';
  $handler->display->display_options['fields']['citation']['style_name'] = 'cse';
  /* Sort criterion: Publication: Type of Publication */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'biblio_types';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Publication: Author last name */
  $handler->display->display_options['arguments']['lastname']['id'] = 'lastname';
  $handler->display->display_options['arguments']['lastname']['table'] = 'biblio_contributor_data';
  $handler->display->display_options['arguments']['lastname']['field'] = 'lastname';
  $handler->display->display_options['arguments']['lastname']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['lastname']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['lastname']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['lastname']['title'] = 'Coauthored Publications with: %1';
  $handler->display->display_options['arguments']['lastname']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['lastname']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['lastname']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['lastname']['summary_options']['base_path'] = 'publications/author';
  $handler->display->display_options['arguments']['lastname']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['lastname']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['lastname']['limit'] = '0';
  $handler->display->display_options['arguments']['lastname']['case'] = 'ucwords';
  $handler->display->display_options['arguments']['lastname']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['lastname']['transform_dash'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biblio' => 'biblio',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Spaces: Content in current space */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'spaces';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['operator'] = 'all';
  $handler->display->display_options['filters']['current']['group'] = '0';
  $handler->display->display_options['filters']['current']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications By Co-Author';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['tags']['previous'] = decode_entities('&laquo;');
  $handler->display->display_options['pager']['options']['tags']['next'] = decode_entities('&raquo;');
  $export['publication_contributors'] = $view;

  $view = new view();
  $view->name = 'publication_types';
  $view->description = 'Publications By Type';
  $view->tag = 'widgets';
  $view->base_table = 'biblio';
  $view->human_name = 'publication_types';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'spaces_feature';
  $handler->display->display_options['access']['spaces_feature'] = 'os_publications';
  $handler->display->display_options['access']['perm'] = 'access biblio content';
  $handler->display->display_options['cache']['type'] = 'time_per_gorup';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Publication: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'biblio';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Sort criterion: Publication: Year of Publication (biblio_year) */
  $handler->display->display_options['sorts']['biblio_year_value']['id'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['table'] = 'field_data_biblio_year';
  $handler->display->display_options['sorts']['biblio_year_value']['field'] = 'biblio_year_value';
  $handler->display->display_options['sorts']['biblio_year_value']['order'] = 'DESC';
  /* Contextual filter: Publication: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'biblio';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  /* Filter criterion: Publication: Publication status (biblio_status) */
  $handler->display->display_options['filters']['biblio_status_value']['id'] = 'biblio_status_value';
  $handler->display->display_options['filters']['biblio_status_value']['table'] = 'field_data_biblio_status';
  $handler->display->display_options['filters']['biblio_status_value']['field'] = 'biblio_status_value';
  $handler->display->display_options['filters']['biblio_status_value']['value'] = array(
    'published' => 'published',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Publication: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'biblio';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['base_path'] = 'publications/type';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Publication: Render bilbio (Get text) */
  $handler->display->display_options['fields']['biblio_render']['id'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_render']['field'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['label'] = '';
  $handler->display->display_options['fields']['biblio_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_render']['style_name'] = 'os_publications';
  $handler->display->display_options['path'] = 'publications/types/%';

  /* Display: Block By Taxonomy */
  $handler = $view->new_display('block', 'Block By Taxonomy', 'block_by_taxonomy');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tag by Type';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';

  /* Display: List of Publications */
  $handler = $view->new_display('block', 'List of Publications', 'block_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Publication: Render bilbio (Get text) */
  $handler->display->display_options['fields']['biblio_render']['id'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_render']['field'] = 'biblio_render';
  $handler->display->display_options['fields']['biblio_render']['label'] = '';
  $handler->display->display_options['fields']['biblio_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['biblio_render']['style_name'] = 'os_publications';
  $export['publication_types'] = $view;

  $view = new view();
  $view->name = 'publication_years';
  $view->description = 'Publications By Year';
  $view->tag = 'widgets';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Publications By Year';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'spaces_feature';
  $handler->display->display_options['access']['spaces_feature'] = 'os_publications';
  $handler->display->display_options['access']['perm'] = 'access biblio content';
  $handler->display->display_options['cache']['type'] = 'time_per_gorup';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['og_access'] = 0;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = 'name';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Publication: Type of Publication */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'biblio_types';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Publication: Biblio Citation */
  $handler->display->display_options['fields']['citation']['id'] = 'citation';
  $handler->display->display_options['fields']['citation']['table'] = 'biblio';
  $handler->display->display_options['fields']['citation']['field'] = 'citation';
  $handler->display->display_options['fields']['citation']['label'] = '';
  $handler->display->display_options['fields']['citation']['style_name'] = 'cse';
  /* Sort criterion: Publication: Type of Publication */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'biblio_types';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'biblio' => 'biblio',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Spaces: Content in current space */
  $handler->display->display_options['filters']['current']['id'] = 'current';
  $handler->display->display_options['filters']['current']['table'] = 'spaces';
  $handler->display->display_options['filters']['current']['field'] = 'current';
  $handler->display->display_options['filters']['current']['operator'] = 'all';
  $handler->display->display_options['filters']['current']['group'] = '0';
  $handler->display->display_options['filters']['current']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['tags']['previous'] = decode_entities('&laquo;');
  $handler->display->display_options['pager']['options']['tags']['next'] = decode_entities('&raquo;');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'biblio_year' => 'biblio_year',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Publication: Year of Publication */
  $handler->display->display_options['fields']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['fields']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['fields']['biblio_year']['label'] = '';
  $handler->display->display_options['fields']['biblio_year']['biblio_label'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Publication: Year of Publication */
  $handler->display->display_options['arguments']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['arguments']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['biblio_year']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['biblio_year']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['biblio_year']['title'] = 'Publications in the Year: %1';
  $handler->display->display_options['arguments']['biblio_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['biblio_year']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['biblio_year']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['biblio_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['biblio_year']['summary_options']['base_path'] = 'publications/year';
  $handler->display->display_options['arguments']['biblio_year']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['biblio_year']['specify_validation'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Publication: Year of Publication */
  $handler->display->display_options['arguments']['biblio_year']['id'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['table'] = 'biblio';
  $handler->display->display_options['arguments']['biblio_year']['field'] = 'biblio_year';
  $handler->display->display_options['arguments']['biblio_year']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['biblio_year']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['biblio_year']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['biblio_year']['title'] = 'Publications in the Year: %1';
  $handler->display->display_options['arguments']['biblio_year']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['biblio_year']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['biblio_year']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['biblio_year']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['biblio_year']['specify_validation'] = TRUE;
  $handler->display->display_options['path'] = 'publications/year/%';
  $export['publication_years'] = $view;

  return $export;
}
