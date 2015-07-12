<?php

/**
 * @file
 * Pageload Configuration Page.
 */

/**
 * Callback for Pageload configuration page.
 */
function pageloader_configuration_page($form, &$form_state) {

  $pageload = array('Lazy Stretch', 'Circle', 'Spill' ,'Frame it', 'Tunnel vision', 'Windscreen wiper', 'Jammed blind', 'Parallelogram', 'Tilted', 'Lateral Swipe', 'Wave', 'Origami', 'Curtain');

  $form['pageload_effect'] = array(
    '#type' => 'radios',
    '#title' => t('Page Load Effect'),
    '#options' => $pageload,
    '#default_value' => variable_get('pageload_effect', 1),
  );

  $form['pageload_exclude_option'] = array(
    '#type'          => 'radios',
    '#title'         => t('Enable on specific pages'),
    '#default_value' => variable_get('pageload_exclude_option', 'exclude'),
    '#options'       => array(
      'exclude' => t('All pages except those listed'),
      'include' => t('Only the listed pages'),
    ),
  );

  $form['pageload_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#title_display' => 'invisible',
    '#default_value' => variable_get('pageload_paths', ''),
    '#description'   => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page."),
  );

  return system_settings_form($form);
}
