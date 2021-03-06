
/**
 * @file
 * Layer handler for OpenLayers XYZ Plus layers
 */

/**
 * Openlayer layer handler for XYZ Plus layer
 */
Drupal.openlayers.layer.openlayersxyzplus = function(title, map, options) {
  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  if (options.maxExtent !== undefined) {
    options.maxExtent = new OpenLayers.Bounds.fromArray(options.maxExtent) || new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);
  }
  options.projection = 'EPSG:' + options.projection;
  options.sphericalMercator = true;
  options.isBaseLayer = options.baselayer;
  var layer = new OpenLayers.Layer.XYZ(title, options.base_url, options);
  layer.styleMap = styleMap;
  return layer;
};
