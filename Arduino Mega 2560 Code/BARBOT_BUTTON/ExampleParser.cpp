#include "ExampleParser.h"
#include "JsonListener.h"
#include <Vector.h>

//// we should be change the wire connections
/////as you can see, the correct pair is should be LED light
/// OK, let's change the connection
/// let's test with changed wire


String key_;

INGREDIENTS temp;
RECIPES     temp_re;
char isArray;
//#define IS_DEBUGGING_WITHOUT_SD

ExampleListener:: ExampleListener(){
 
}
void ExampleListener:: init_listen(char type){
   m_Listener_type = type;
}
void ExampleListener::whitespace(char c) {
#ifdef IS_DEBUGGING
 Serial.println("whitespace");
 #endif
}

void ExampleListener::startDocument() {
#ifdef IS_DEBUGGING
 Serial.println("start document");
#endif
}

void ExampleListener::key(String key) {
   key_ = key;
#ifdef IS_DEBUGGING
 Serial.println("key: " + key);
#endif
}

void ExampleListener::value(String value) {
   if (m_Listener_type == 1){
      if (key_ == "coordinate"){
        temp.coordinate = value.toInt();
      }
      if (key_ == "hold"){
        temp.hold = value.toInt();
      }
      if (key_ == "wait"){
        temp.wait = value.toInt();
      }      
   }
   if (m_Listener_type == 2 && isArray == 1){     
      if (key_ == "id"){
        temp_re.id = value.toInt();
      }
      if (key_ == "amount"){
        temp_re.amount = value.toInt();
      }        
   }
   
#ifdef IS_DEBUGGING
  Serial.println("value: " + value);
#endif
}

void ExampleListener::endArray() {
    temp_re = {0,0};
    if (m_Listener_type == 2 && isArray == 1) {
      vi_recipe_item.push_back(temp_re);
    }    
    isArray = 0;
#ifdef IS_DEBUGGING
  Serial.println("end array. ");
#endif
}

void ExampleListener::endObject() {
   
   if (m_Listener_type == 1){
      vi.push_back(temp);
   }
   if (m_Listener_type == 2 && isArray == 1)
   {     
      vi_recipe_item.push_back(temp_re);
   }   
#ifdef IS_DEBUGGING
  Serial.println("end object. ");
#endif
}

void ExampleListener::endDocument() {  
#ifdef IS_DEBUGGING
  Serial.println("end document. ");
#endif
}

void ExampleListener::startArray() {   
    isArray = 0;
    if (m_Listener_type == 2 && key_ == "ingredients") isArray = 1;
#ifdef IS_DEBUGGING
   Serial.println("start array. ");
  #endif
}

void ExampleListener::startObject() { 
  temp = {0,0,0};
  temp_re = {0,0}; 
#ifdef IS_DEBUGGING
   Serial.println("start object. ");
  #endif
}



void ExampleListener:: INGREDinitWithoutSD(){
Serial.println("INGREDinitWithoutSD");
#ifdef IS_DEBUGGING_WITHOUT_SD
Serial.println("IS_DEBUGGING_WITHOUT_SD");
  if (m_Listener_type == 1) {
    Serial.println("m_Listener_type == 1");
    temp = {-4995,2500,3000}; vi.push_back(temp);
    temp = {-2510,2400,2500}; vi.push_back(temp);
    temp = {-4010,2500,2400}; vi.push_back(temp);
    temp = {-1000,2500,2800}; vi.push_back(temp);
    temp = {-3500,2500,2400}; vi.push_back(temp);
    temp = {-1990,2300,2300}; vi.push_back(temp);
    temp = {-4495,2400,2400}; vi.push_back(temp);
    temp = {-1490,2600,2500}; vi.push_back(temp);
    temp = {-2995,2500,2400}; vi.push_back(temp);    
  }else{
    Serial.println("m_Listener_type != 1");
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {3,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {4,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {7,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {4,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,80}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {7,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {4,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {3,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {8,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {8,120}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {9,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {6,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {9,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    temp_re = {5,40}; vi_recipe_item.push_back(temp_re);
    temp_re = {1,20}; vi_recipe_item.push_back(temp_re);
    temp_re = {2,100}; vi_recipe_item.push_back(temp_re);
    temp_re = {0,0}; vi_recipe_item.push_back(temp_re);
    
  }
#endif 
}

