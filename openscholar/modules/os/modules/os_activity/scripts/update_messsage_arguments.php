<?php
/**
 * @file update_messsage_arguments.php.
 *
 * Drush script for updating the hard coded title argument with a custom
 * argument.
 *
 * @arguments:
 *  - batch: Set the number to process each time. 250 by default.
 *  - memory_limit: The extended amount of memory for the script.
 *    500 by default.
 *  - id: The message ID. Used when you want to start the processing from a
 *    specific message.
 *
 *  @example:
 *
 *    drush scr hardcoding_the_message_arguments.php --id=30 --batch=450 --memory_limit=4000
 */
$batch = drush_get_option('batch', 250);
$memory_limit = drush_get_option('memory_limit', 500);
$id = drush_get_option('id', 1);

// Count how much messages we have.
$query = new EntityFieldQuery();
$max = $query
  ->entityCondition('entity_type', 'message')
  ->propertyCondition('mid', $id, '>=')
  ->count()
  ->execute();

$i = 0;

while ($max > $i) {

  // Collect the messages in batches.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'message')
    ->propertyCondition('mid', $id, '>=')
    ->propertyOrderBy('mid', 'DESC')
    ->range($i, $i + $batch)
    ->execute();

  if (empty($result['message'])) {
    return;
  }

  // Load the messages for the current batch.
  $messages = message_load_multiple($result['message']);

  foreach ($messages as $message) {
    $wrapper = entity_metadata_wrapper('message', $message);

    // Delete the message:field-node-reference:title argument.
    unset($message->arguments['@{message:field-node-reference:title}']);

    // Add the !title argument.
    $allowed_html_elements = variable_get('html_title_allowed_elements', array('em', 'sub', 'sup'));
    $message->arguments['!title'] = !empty($wrapper->field_node_ref->title_field) ? filter_xss($wrapper->field_node_ref->title_field->value->value(), $allowed_html_elements) : $wrapper->field_node_ref->label();

    $save_message = TRUE;

    if ($save_message) {
      $param = array(
        '@mid' => $message->mid,
        '@tokens' => implode(' ', $tokens),
      );
      drush_log(dt($message->mid . '\ ' . $max . ') Processing the @tokens in the message @mid', $param), 'success');

      // Saving the message and the display message for the user.
      message_save($message);

      // The script taking to much memory. Stop it and display message.
      if (round(memory_get_usage()/1048576) >= $memory_limit) {
        return drush_set_error('OS_ACTIVITY OUT_OF_MEMORY', dt('Stopped before out of memory. Last message ID was @mid', array('@mid' => $message->mid)));
      }
    }
  }

  $i = $i + $batch;
}

