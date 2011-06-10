<?php

/**
 * @file
 * Openlayer xyz plus Layer Type
 */

/**
 * OpenLayers XYZ Plus Layer Type class
 */
class openlayers_layer_type_openlayersxyzplus extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      $this->data['params']['isBaseLayer'] = (bool) $this->data['params']['isBaseLayer'];
      $this->data['baselayer'] = $this->data['params']['isBaseLayer'];
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'serverResolutions' => openlayers_get_resolutions('900913'),
      'maxExtent' => openlayers_get_extent('900913'),
      'layer_handler' => 'openlayersxyzplus',
      'baselayer' => TRUE
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
      'base_url' => array(
        '#type' => 'textfield',
        '#title' => t('Base URL (template)'),
        '#default_value' => isset($this->data['base_url']) ?
          $this->data['base_url'] : ''
      ),

      'params' => array(
        'isBaseLayer' => array(
          '#type' => 'checkbox',
          '#default_value' => isset($this->data['params']['isBaseLayer']) ? 
            $this->data['params']['isBaseLayer'] : TRUE,
          '#return_value' => TRUE,
          '#title' => t('BaseLayer'),
          '#description' => t('Uncheck to make this map an overlay')
        ),
          ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_openlayersxyzplus'
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => array_combine(
          array_map('strval', openlayers_get_resolutions('900913')),
          range(0, 18)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['resolutions']) ?
          $this->data['resolutions'] :
          array_map('strval', openlayers_get_resolutions('900913'))
      ),
      'projection' =>
        array(
         '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayersxyzplus')
      . '/includes/layer_types/openlayersxyzplus.js');
    return $this->options;
  }
}
