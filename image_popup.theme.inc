<?php

/**
 * @file
 * Image Popup theme functions.
 */

/**
 * Returns HTML for an Panzoom image field formatter.
 *
 * @param $variables
 *   An associative array containing:
 *   - item: An array of image data.
 *   - image_style: An optional image style.
 *   - path: An array containing the link 'path' and link 'options'.
 *
 * @ingroup themeable
 */
function theme_image_popup_image_formatter($variables) {

  $item = $variables['item'];
  $entity_type = $variables['entity_type'];
  $entity = $variables['entity'];
  $field = $variables['field'];
  $style = $variables['display_style'];
  $style_load =  image_style_load($style);
  
  $width = $style_load['effects'][0]['data']['width'];
  $height = $style_load['effects'][0]['data']['height'];
 
  
  $id='image_popup_'.$variables['delta'];
  $image = array(
    'path' => $item['uri'],
    'alt' => isset($item['alt']) ? $item['alt'] : '',
    'title' => isset($item['title']) ? $item['title'] : '',
    'attributes' => array('class' => 'img-pop', 'id' => $id , 'rel' => 'zoom'),
    'width' => $width,
    'height' => $height
      
  );

    $path = file_create_url($image['path']);

  return theme('image_popup_imagefield', array('image' => $image, 'path' => $path));
}

/**
 * Returns HTML for an image using a specific Image Popup style.
 *
 * @param $variables
 *   An associative array containing:
 *   - image: image item as array.
 *   - path: The path of the image that should be displayed in the Panzoom.
 *   - title: The title text that will be used as a caption in the Panzoom.

 *
 * @ingroup themeable
 */
function theme_image_popup_imagefield($variables) {
   $image = theme('image', $variables['image']);

        return $image;

 }
