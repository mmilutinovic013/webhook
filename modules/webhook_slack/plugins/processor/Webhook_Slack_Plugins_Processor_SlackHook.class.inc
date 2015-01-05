<?php

/**
 * @file
 * Example plugin class for logging github pushes to watchdog
 */

/**
 * Webhook Processor Github Logger class.
 *
 * Records github actions in watchdog log.
 */
class Webhook_Slack_Plugins_Processor_SlackHook implements Webhook_Plugins_Processor_Interface {

  /**
   * Configuration form.
   */
  public function config_form() {
    // No configuration needed.
    return array();
  }

  /**
   * Processes data.
   */
  public function process(stdClass $data) {
    
    $vars = array(
      'created' => $data->timestamp,
      'team_id' => $data->team_id,
      'channel_id' => $data->channel_id,
      'channel_name' => $data->channel_name,
      'timestamp' => $data->timestamp,
      'user_id' => $data->user_id,
      'user_name' => $data->user_name,
      'text' => $data->text,
      'trigger_word' => $data->trigger_word,
    );

    $the_slack_entity = entity_create('slack_entity', $vars);
    entity_save('slack_entity', $the_slack_entity);

    watchdog("debug", serialize($the_slack_entity));
    watchdog("debug", serialize($vars));

    return TRUE;
  }
}
