#pragma once

#include "JsonStreamingParser.h"
#include "JsonListener.h"
#include "ExampleParser.h"

class JsonInit_ {

	
  public:
	int chipSelect;
	JsonStreamingParser parser_INGRED;
	JsonStreamingParser parser_RECIPE;
	
	ExampleListener listener_INGRED;
	ExampleListener listener_RECIPE;
	
  
	JsonInit_( int mchipSelect = 4);
  boolean Init_(String INGRED_name, String RECIPE_name); 
  boolean JSON_INGRED_init(String INGRED_name);
  boolean JSON_RECIPE_init(String RECIPE_name);

  void JSON_withoutsd_init();
};
