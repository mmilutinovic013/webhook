<?php
/**
 * @file
 * webhook_slack.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function webhook_slack_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "webhook" && $api == "webhook") {
    return array("version" => "1");
  }
}

function webhook_slack_feature_eck_entity_type_info() {
  $items = array(
    'slack_integration' => array(
      'name' => 'slack_integration',
      'label' => 'Slack Integration',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}