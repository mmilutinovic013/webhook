<?php
/**
 * @file
 * webhook_example.webhook.inc
 */

/**
 * Implements hook_webhook_default_config().
 */
function webhook_example_webhook_default_config() {
  $export = array();

  $webhook = new stdClass();
  $webhook->disabled = FALSE; /* Edit this to true to make a default webhook disabled initially */
  $webhook->api_version = 1;
  $webhook->whid = '1';
  $webhook->title = 'Slack Webhook';
  $webhook->machine_name = 'slack';
  $webhook->description = 'Example webhook for creating logging slack messages.';
  $webhook->unserializer = 'slack';
  $webhook->processor = 'slackhook';
  $webhook->config = '';
  $webhook->enabled = TRUE;
  $export['slack'] = $webhook;

  return $export;
}
