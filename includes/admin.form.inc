<?php
/**
 * @file
 * CI badge admin options
 */
function islandora_ci_badge_admin_form($form, $form_settings) {
  $form['islandora_ci_badge_attribution_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr field for the CI Attribution Incomplete information'),
    '#description' => t('The solr field where Islandora will find the CI Attribution Incomplete information.'),
    '#default_value' => variable_get('islandora_ci_badge_attribution_field', 'mods_note_CI_Notice_s'),
  );
  $form['islandora_ci_badge_attribution_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text to identify if an object requires the Attribution Incomplete label'),
    '#description' => t('The complete value of the Solr field to match when identifying Attribution Incomplete objects.'),
    '#default_value' => variable_get('islandora_ci_badge_attribution_text', 'Attribution incomplete'),
  );
  $form['islandora_ci_badge_title_element'] = array(
    '#type' => 'textfield',
    '#title' => t('HTML element for the badge title'),
    '#description' => t('The HTML element used to style the title of the CI notice. Configurable so it can be easily themed.'),
    '#default_value' => variable_get('islandora_ci_badge_title_element', 'h3'),
  );
  $form = system_settings_form($form);
  return $form;
}
