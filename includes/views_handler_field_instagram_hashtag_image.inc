<?php

class views_handler_field_instagram_hashtag_image extends views_handler_field {

	function render($values) {
    
	  $value = $values->{$this->field_alias};

	  if ($value) { 	
	  	
	  	$image = theme('image', array('path' => $value));
	  
	  }

   	return $image;
  }
}