<?php
/**
 * @file
 * total_domination.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function total_domination_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cleansing_form';
  $page->task = 'page';
  $page->admin_title = 'Cleansing Form';
  $page->admin_description = '';
  $page->path = 'admin/kalalead/clean';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Assimilate More',
    'name' => 'main-menu',
    'weight' => '-10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_cleansing_form_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'cleansing_form';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Form of Doom',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'GET ALL THE LEADS/CLOSE ALL THE DEALZ';
  $display->uuid = '255855a2-c6a8-4eea-91a4-50c08c90f1c1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a69597f4-83d9-4452-89a9-401d6389f846';
  $pane->panel = 'contentmain';
  $pane->type = 'total_clean';
  $pane->subtype = 'total_clean';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a69597f4-83d9-4452-89a9-401d6389f846';
  $display->content['new-a69597f4-83d9-4452-89a9-401d6389f846'] = $pane;
  $display->panels['contentmain'][0] = 'new-a69597f4-83d9-4452-89a9-401d6389f846';
  $pane = new stdClass();
  $pane->pid = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $display->content['new-5b0b1e87-6cc7-49a1-b49d-974579075a6e'] = $pane;
  $display->panels['sidebar'][0] = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane = new stdClass();
  $pane->pid = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->content['new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4'] = $pane;
  $display->panels['sidebar'][1] = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cleansing_form'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'form_of_doom';
  $page->task = 'page';
  $page->admin_title = 'Form of Doom';
  $page->admin_description = '';
  $page->path = 'admin/kalalead';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Assimilate More',
    'name' => 'main-menu',
    'weight' => '-10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_form_of_doom_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'form_of_doom';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Form of Doom',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'GET ALL THE LEADS/CLOSE ALL THE DEALZ';
  $display->uuid = '255855a2-c6a8-4eea-91a4-50c08c90f1c1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f3da8256-8430-411a-b117-9f4f3085c86d';
  $pane->panel = 'contentmain';
  $pane->type = 'total_form';
  $pane->subtype = 'total_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f3da8256-8430-411a-b117-9f4f3085c86d';
  $display->content['new-f3da8256-8430-411a-b117-9f4f3085c86d'] = $pane;
  $display->panels['contentmain'][0] = 'new-f3da8256-8430-411a-b117-9f4f3085c86d';
  $pane = new stdClass();
  $pane->pid = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $display->content['new-5b0b1e87-6cc7-49a1-b49d-974579075a6e'] = $pane;
  $display->panels['sidebar'][0] = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane = new stdClass();
  $pane->pid = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->content['new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4'] = $pane;
  $display->panels['sidebar'][1] = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['form_of_doom'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page_mother_fucker';
  $page->task = 'page';
  $page->admin_title = 'FRONT PAGE MOTHER FUCKER';
  $page->admin_description = '';
  $page->path = 'hitme';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front_page_mother_fucker_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page_mother_fucker';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'LOGIN',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0e6371a1-2be9-4038-93c8-01b956f476fb';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-11b04d13-7e64-4df7-b3df-8b2664db29ab';
  $pane->panel = 'contentmain';
  $pane->type = 'total_alec';
  $pane->subtype = 'total_alec';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '11b04d13-7e64-4df7-b3df-8b2664db29ab';
  $display->content['new-11b04d13-7e64-4df7-b3df-8b2664db29ab'] = $pane;
  $display->panels['contentmain'][0] = 'new-11b04d13-7e64-4df7-b3df-8b2664db29ab';
  $pane = new stdClass();
  $pane->pid = 'new-37eeda7f-bbe6-49b1-9a97-80f48acfb7d5';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '37eeda7f-bbe6-49b1-9a97-80f48acfb7d5';
  $display->content['new-37eeda7f-bbe6-49b1-9a97-80f48acfb7d5'] = $pane;
  $display->panels['sidebar'][0] = 'new-37eeda7f-bbe6-49b1-9a97-80f48acfb7d5';
  $pane = new stdClass();
  $pane->pid = 'new-ebe03051-30a6-451f-a529-aa82fa5047ed';
  $pane->panel = 'sidebar';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ebe03051-30a6-451f-a529-aa82fa5047ed';
  $display->content['new-ebe03051-30a6-451f-a529-aa82fa5047ed'] = $pane;
  $display->panels['sidebar'][1] = 'new-ebe03051-30a6-451f-a529-aa82fa5047ed';
  $pane = new stdClass();
  $pane->pid = 'new-44899724-e672-4e78-b514-c9a0ccffe284';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '44899724-e672-4e78-b514-c9a0ccffe284';
  $display->content['new-44899724-e672-4e78-b514-c9a0ccffe284'] = $pane;
  $display->panels['sidebar'][2] = 'new-44899724-e672-4e78-b514-c9a0ccffe284';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page_mother_fucker'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kaladash';
  $page->task = 'page';
  $page->admin_title = 'Kaladash';
  $page->admin_description = '';
  $page->path = 'admin/kalalead/lead/new';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'New Leads',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_kaladash_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kaladash';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Kaladash',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'ALL YOUR LEADS ARE BELONG TO KALAMUNA';
  $display->uuid = '73f824c1-3d69-4b5e-866f-c3bf9325f146';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3d645853-7f9b-471f-8daf-f021a5e1d0bf';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'winning-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'table',
    'header_type' => 'titles',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d645853-7f9b-471f-8daf-f021a5e1d0bf';
  $display->content['new-3d645853-7f9b-471f-8daf-f021a5e1d0bf'] = $pane;
  $display->panels['contentmain'][0] = 'new-3d645853-7f9b-471f-8daf-f021a5e1d0bf';
  $pane = new stdClass();
  $pane->pid = 'new-5362b757-1498-48f4-9d01-feb77ff1dd80';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5362b757-1498-48f4-9d01-feb77ff1dd80';
  $display->content['new-5362b757-1498-48f4-9d01-feb77ff1dd80'] = $pane;
  $display->panels['sidebar'][0] = 'new-5362b757-1498-48f4-9d01-feb77ff1dd80';
  $pane = new stdClass();
  $pane->pid = 'new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $display->content['new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea'] = $pane;
  $display->panels['sidebar'][1] = 'new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kaladash'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'kaladash2';
  $page->task = 'page';
  $page->admin_title = 'Kaladash2';
  $page->admin_description = '';
  $page->path = 'admin/kalalead/lead/won';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Leads Won',
    'name' => 'main-menu',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_kaladash2_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'kaladash2';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Kaladash',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'ALL YOUR LEADS ARE BELONG TO KALAMUNA';
  $display->uuid = '73f824c1-3d69-4b5e-866f-c3bf9325f146';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ca7df0f3-9cc3-4f6a-883e-b1c2acc3c868';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'winning-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'table',
    'header_type' => 'titles',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ca7df0f3-9cc3-4f6a-883e-b1c2acc3c868';
  $display->content['new-ca7df0f3-9cc3-4f6a-883e-b1c2acc3c868'] = $pane;
  $display->panels['contentmain'][0] = 'new-ca7df0f3-9cc3-4f6a-883e-b1c2acc3c868';
  $pane = new stdClass();
  $pane->pid = 'new-5362b757-1498-48f4-9d01-feb77ff1dd80';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5362b757-1498-48f4-9d01-feb77ff1dd80';
  $display->content['new-5362b757-1498-48f4-9d01-feb77ff1dd80'] = $pane;
  $display->panels['sidebar'][0] = 'new-5362b757-1498-48f4-9d01-feb77ff1dd80';
  $pane = new stdClass();
  $pane->pid = 'new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $display->content['new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea'] = $pane;
  $display->panels['sidebar'][1] = 'new-a2af3859-8f75-40fa-afcb-2fb9e9d406ea';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['kaladash2'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'macro_form';
  $page->task = 'page';
  $page->admin_title = 'Macro Form';
  $page->admin_description = '';
  $page->path = 'admin/kalalead/macro';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Macro Cleanup',
    'name' => 'main-menu',
    'weight' => '-10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_macro_form__panel_context_9fffee37-74cb-4751-95dc-429ba3415958';
  $handler->task = 'page';
  $handler->subtask = 'macro_form';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Form of Macro',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'GET ALL THE LEADS/CLOSE ALL THE DEALZ';
  $display->uuid = '255855a2-c6a8-4eea-91a4-50c08c90f1c1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0551a754-274b-44a9-b06a-0cf37749d59d';
  $pane->panel = 'contentmain';
  $pane->type = 'total_marco';
  $pane->subtype = 'total_marco';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0551a754-274b-44a9-b06a-0cf37749d59d';
  $display->content['new-0551a754-274b-44a9-b06a-0cf37749d59d'] = $pane;
  $display->panels['contentmain'][0] = 'new-0551a754-274b-44a9-b06a-0cf37749d59d';
  $pane = new stdClass();
  $pane->pid = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane->panel = 'sidebar';
  $pane->type = 'total_logo';
  $pane->subtype = 'total_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $display->content['new-5b0b1e87-6cc7-49a1-b49d-974579075a6e'] = $pane;
  $display->panels['sidebar'][0] = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $pane = new stdClass();
  $pane->pid = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $pane->panel = 'sidebar';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'main-menu',
    'parent_mlid' => 'main-menu:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->content['new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4'] = $pane;
  $display->panels['sidebar'][1] = 'new-f3d3a935-cc8e-4dff-bf76-88f66e5329a4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b0b1e87-6cc7-49a1-b49d-974579075a6e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['macro_form'] = $page;

  return $pages;

}
