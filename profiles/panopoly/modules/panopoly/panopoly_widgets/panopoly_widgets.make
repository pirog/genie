; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 2.3
projects[tablefield][subdir] = contrib

projects[simple_gmap][version] = 1.2
projects[simple_gmap][subdir] = contrib

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.5
projects[menu_block][subdir] = contrib
projects[menu_block][patch][2421645] = https://www.drupal.org/files/issues/2421645-menu-tree-prune-tree-parent-item-false_0.patch

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.0-beta1
projects[file_entity][subdir] = contrib

projects[media][version] = 2.0-alpha4
projects[media][subdir] = contrib
projects[media][patch][2126697] = https://www.drupal.org/files/issues/media_wysiwyg_2126697-53.patch
projects[media][patch][2308487] = https://www.drupal.org/files/issues/media-alt-title-double-encoded-2308487-2.patch
projects[media][patch][2084287] = http://www.drupal.org/files/issues/media-file-name-focus-2084287-2.patch
projects[media][patch][2421589] = https://www.drupal.org/files/issues/media-library-preview-overflow-2421589-3.patch

projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = d0377b3
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][version] = 2.0
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch
