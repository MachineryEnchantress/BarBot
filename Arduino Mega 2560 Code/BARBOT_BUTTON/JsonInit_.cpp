#include "JsonStreamingParser.h"
#include "JsonListener.h"
#include "ExampleParser.h"
#include <SPI.h>
#include <SD.h>
#include "JsonInit_.h"
//#define IS_DEBUGGING_WITHOUT_SD


#ifdef IS_DEBUGGING_WITHOUT_SD
void JsonInit_::JSON_withoutsd_init(){ 
  Serial.println("JSON_withoutsd_init");
  listener_INGRED.init_listen(1);
  parser_INGRED.setListener(&listener_INGRED);
     
  listener_RECIPE.init_listen(2);
  parser_RECIPE.setListener(&listener_RECIPE);
  
  listener_INGRED.INGREDinitWithoutSD();
  listener_RECIPE.INGREDinitWithoutSD();
  
  return true;
}

#endif
boolean SDCARD_Init(int cs){
   Serial.print("Initializing SD card...");
   // see if the card is present and can be initialized:
   
   if (!SD.begin(cs))  {
       Serial.println("Card failed, or not present");
       // don't do anything more:  
       return false;
  }
    Serial.println("card initialized.");
    return true;
}


boolean JsonInit_::JSON_INGRED_init(String INGRED_name){  
  char jsonBuf[128];  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open(INGRED_name);
  //File dataFile = SD.open("ingredients.json");
  // if the file is available, write to it:
  
  listener_INGRED.init_listen(1);
  parser_INGRED.setListener(&listener_INGRED);
   
  if (dataFile) {
    while (dataFile.available()) 
    {
       dataFile.read(jsonBuf,128);              
       for (int i = 0; i < sizeof(jsonBuf); i++) 
       {        
          parser_INGRED.parse(jsonBuf[i]); 
       }
     
    }       
    dataFile.close();
    Serial.println("JSON init Secceed");       
  }
  // if the file isn't open, pop up an error:
  else 
  {
    Serial.println("JSON init failed");    
    return false;
  }
  return true;
  
}



boolean JsonInit_:: JSON_RECIPE_init(String RECIPE_name){
  
  char jsonBuf[128];  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open(RECIPE_name);
  //File dataFile = SD.open("ingredients.json");
  // if the file is available, write to it:
  listener_RECIPE.init_listen(2);
  parser_RECIPE.setListener(&listener_RECIPE);
   
  if (dataFile) {
    while (dataFile.available()) 
    {
       dataFile.read(jsonBuf,128);          
       for (int i = 0; i < sizeof(jsonBuf); i++) 
       {        
          parser_RECIPE.parse(jsonBuf[i]); 
       }
      
    }       
    dataFile.close();
    Serial.println("JSON init Secceed");       
  }
  // if the file isn't open, pop up an error:
  else 
  {
    Serial.println("JSON init failed");    
   return false;
  }
  return true;
}
JsonInit_::JsonInit_(int mchipSelect){
	
   chipSelect = mchipSelect;
}

boolean JsonInit_::Init_(String INGRED_name, String RECIPE_name) { 
#ifndef IS_DEBUGGING_WITHOUT_SD
  if(!SDCARD_Init(chipSelect))return false;
  if(!JSON_INGRED_init(INGRED_name))return false;
  if(!JSON_RECIPE_init(RECIPE_name))return false;
#else
  Serial.println("JSonInit__");
  JSON_withoutsd_init();
#endif
  return true; 
}

