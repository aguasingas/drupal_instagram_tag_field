<?php

function instagram_hashtag_views_data() {

  $data = array();

  $data['instagram_hashtag']['table']['group'] = t('Instagram Hashtag');

  // Advertise this table as a possible base table
  $data['instagram_hashtag']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Instagram hashtag table'),
    'help' => t("Table contains Instagram Hashtag feed"),
    'weight' => -10,
  );

  $data['instagram_hashtag']['pub_date'] = array(
    'title' => t('Pub date'),
    'help' => t('The pub_date of the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),

  );

  $data['instagram_hashtag']['media_title'] = array(
    'title' => t('Title'),
    'help' => t('The media_title of the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['instagram_hashtag']['media_hashtag'] = array(
    'title' => t('Title'),
    'help' => t('The media_hashtag of the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['instagram_hashtag']['media_content'] = array(
    'title' => t('Large image from feed'),
    'help' => t('The Large image from the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_instagram_hashtag_image',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['instagram_hashtag']['media_thumbnail'] = array(
    'title' => t('Thumbnail from feed'),
    'help' => t('The thumbnail image from the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_instagram_hashtag_image',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['instagram_hashtag']['media_credit'] = array(
    'title' => t('Author/Fotographer'),
    'help' => t('The photographers name from the Instagram Hashtag feed value.'), // The help that appears on the UI,
    
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  return $data;

}