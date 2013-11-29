<?php

/*
 * @file
 * Admin settings form for the module
 */


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function instagram_hashtag_admin_settings($form, &$form_state) {
  $form = array();

  $form['instagram_hashtag_hash'] = array(
    '#type' => 'textfield',
    '#title' => 'Hashtag to search for without the #',
    '#required' => TRUE,
    '#default_value' => variable_get('instagram_hashtag_hash'),
    '#description' => t('What hashtag do you want to display pictures for'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#default_value' => t('Save'),
    '#weight' => 100,
  );


  $form['html'] = array(
    '#type' => 'markup',
    '#markup' => instagram_hashtag_check_hashtag(),
  );

  return $form;
}

function instagram_hashtag_admin_settings_submit($form, $form_state) {
  if (!empty($form_state['values']['instagram_hashtag_hash'])) {
    
    variable_set('instagram_hashtag_hash', $form_state['values']['instagram_hashtag_hash']);
    
    instagram_hashtag_fetch_feed();

    drupal_set_message(t('Hashtag has been saved'));
  }
}

function instagram_hashtag_check_hashtag() {
  
  $hashtag = variable_get('instagram_hashtag_hash');

  if (isset($hashtag)) {
    
    $result = drupal_http_request('http://instagram.com/tags/' . $hashtag . '/feed/recent.rss');
    $xml_object = simplexml_load_string($result->data);
    
    $counter = 0;
    
    foreach ($xml_object->channel->item as $items) {
      $counter++;
    }
    return '<p>Number of items found: ' . $counter . '</p>';
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function instagram_hashtag_list_feed_form($form, &$form_state) {
  
  $query = db_select('instagram_hashtag', 'ih')->extend('PagerDefault');
  $query->limit(10);
  
  $query
    ->fields('ih', array('id', 'pub_date', 'media_title', 'media_hashtag', 'media_thumbnail', 'media_credit'))
    ->orderBy('ih.pub_date', 'DESC');

  $feed_items = $query
    ->execute()
    ->fetchAll();
  
  // $result->fields('SELECT ih.id, ih.pub_date, ih.media_title, ih.media_hashtag, ih.media_thumbnail, ih.media_credit FROM {instagram_hashtag} ih'->extend('PagerDefault');

  // $result->limit(5);
  
  //$feed_items = $result->fetchAll();

  // dsm($test);
  
  $header = array(
    'image' => t('Image'),
    'title' => t('Title'),
    'hashtag' => t('Hashtag'),
    'author' => t('Author'),
    'date' => t('Date'),
    'delete' => t('delete'),
  );

  $options = array();
  
  foreach($feed_items as $feed_item) {
    $options[$feed_item->id] = array(
      'image' => theme('image', array('path' => $feed_item->media_thumbnail)),
      'hashtag' => $feed_item->media_hashtag,
      'title' => substr($feed_item->media_title,0,97) . '...',
      'author' => $feed_item->media_credit,
      'date' => $feed_item->pub_date,
      'delete' => l('Delete', 'node/edit'),
    );
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No pics found'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  $form['pager'] = array('#markup' => theme('pager'));

  return $form;
}

