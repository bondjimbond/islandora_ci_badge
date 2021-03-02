<?php

/**
 * @file
 * Utility functions.
 */

function islandora_ci_badge_get_attribution_notice(AbstractObject $object) {
  // Gets the Attribution Incomplete from the configured Solr field.
  $qp = new islandoraSolrQueryProcessor();
  $qp->buildQuery(format_string('@field:"@pid"', array(
    '@field' => 'PID',
    '@pid' =>"{$object->id}")
  ));
  $attribution_field = variable_get('islandora_ci_badge_attribution_field', 'mods_note_CI_Notice_s');
  $attribution_text = variable_get('islandora_ci_badge_attribution_text', 'Attribution incomplete');
  $qp->solrParams['fl'] = implode(', ', array(
    'PID',
    $attribution_field,
  ));
  $qp->solrStart = 0;
  $qp->solrLimit = 100000;
  $qp->executeQuery(FALSE);
  if ($qp->islandoraSolrResult['response']['numFound'] > 0) {
    if (array_key_exists($attribution_field, $qp->islandoraSolrResult['response']['objects']['0']['solr_doc'])) {
      $attribution_content = ($qp->islandoraSolrResult['response']['objects']['0']['solr_doc'][$attribution_field]);
      if ($attribution_content == $attribution_text) {
        $attribution_incomplete = $attribution_text;
      }
    }
  }
  if (!isset($attribution_incomplete)) {
    return;
  }
  else {
    return $attribution_incomplete;
  }
}

function islandora_ci_badge_html($attribution) {
  $text = "Collections and items in our institution have incomplete, inaccurate, and/or missing attribution. 
    We are using this notice to clearly identify this material so that it can be updated, or corrected by communities of origin. 
    Our institution is committed to collaboration and partnerships to address this problem of incorrect or missing attribution.";
  $title = "Attribution Incomplete";
  $image_url = "https://localcontexts.org/wp-content/uploads/2020/11/ci_notice_attribution_incomplete.png";
  $height = 160;

  $img = array(
    '#theme' => 'image',
    '#path' => $image_url,
    '#alt' => $text,
    '#height' => $height,
    '#title' => $title,
  );
  $title_element = variable_get('islandora_ci_badge_title_element', 'h3');
  $badge = '<' . $title_element . ' class="ci-title">' . $title . '</' . $title_element . '><div class="ci-icon">' . drupal_render($img) . '</div><div class="ci-text">' . $text . '</div>';

  return $badge;
}
