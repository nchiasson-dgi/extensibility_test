<?php

/**
 * @file
 * Migration alterations for the dssi_nodes migration.
 */

use Symfony\Component\Yaml\Yaml;

/**
 * Migration alterations callback.
 *
 * @param array $mig
 *   A reference to the migration to be altered.
 */
function _extensibility_test_dssi_node_migration_alterations(array &$mig) {
  $proc = &$mig['process'];

  $file_system = \Drupal::service('file_system');
  $proc += Yaml::parse(file_get_contents($file_system->realpath(__DIR__ . '/dssi_node/fields.yaml')))['process'];

  $related_item =& $proc['field_related_item_paragraph'];
  $related_item[1]['keys'] = [
    'relationship_type',
    'title',
    'url',
    'extent',
    'duplicate_title',
  ];
  $related_item[2]['values'] += [
    'field_duplicate_title' => [
      [
        'plugin' => 'skip_on_empty',
        'method' => 'process',
        'source' => 'parent_value/duplicate_title',
      ],
    ],
  ];
}
