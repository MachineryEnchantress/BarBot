#pragma once

#include "JsonListener.h"
#include <Vector.h>
 
struct INGREDIENTS {
      int  coordinate;
      int  hold;
      int  wait;
    };
struct RECIPES {
      int id;
      int amount;  
    };
    
class ExampleListener: public JsonListener {
  private :  
    char m_Listener_type;       
  public:
  
    Vector<INGREDIENTS> vi;
    Vector<RECIPES> vi_recipe_item;
    
    ExampleListener();
    void init_listen(char type);
    void INGREDinitWithoutSD();
    virtual void whitespace(char c);
  
    virtual void startDocument();

    virtual void key(String key);

    virtual void value(String value);

    virtual void endArray();

    virtual void endObject();

    virtual void endDocument();

    virtual void startArray();

    virtual void startObject();
};
