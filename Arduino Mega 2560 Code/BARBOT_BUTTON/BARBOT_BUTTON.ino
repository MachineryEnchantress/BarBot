

#include "JsonInit_.h"

#include "AccelStepper.h"
#include "Configuration.h"
#include <Vector.h>
#include <Servo.h>

/*-------------------coin accepter time-------------*/
unsigned long coin_accepted_time_old = 0;
int coin_accepted = 0;



const int chipSelect = 53;

JsonInit_ mJson(chipSelect);

Vector<INGREDIENTS> v_i;
Vector<RECIPES> v_re;

AccelStepper stepper(X_INTERFACE_TYPE, X_STEP_PIN, X_DIR_PIN); // Define a stepper and the pins it will use
AccelStepper stepperZ(Z_INTERFACE_TYPE, Z_STEP_PIN, Z_DIR_PIN); // Define a stepper and the pins it will use



void serial_init(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("serial port inited");
}


void homeXAxis() {
    
  int endStopState = digitalRead(X_ENDSTOP_PIN); 
   while (endStopState == HIGH) {
    stepper.moveTo(100);
    stepper.setSpeed(X_HOME_SPEED);
    stepper.runSpeed();
   endStopState = digitalRead(X_ENDSTOP_PIN);  
  }  

  stepper.moveTo(stepper.currentPosition() - 50);
   while (stepper.distanceToGo() != 0) {
    stepper.setSpeed(X_PARK_SPEED * -1);
    stepper.runSpeed();      
  }
  
  endStopState = digitalRead(X_ENDSTOP_PIN);  
  while (endStopState == HIGH) {
     stepper.moveTo(100);
    stepper.setSpeed(X_PARK_SPEED);
    stepper.runSpeed();   
    endStopState = digitalRead(X_ENDSTOP_PIN);
  }

  stepper.setCurrentPosition(0); 
}


void moveXTo(int pos) {  
  
  Serial.print("X goes to: ");
  Serial.println(pos);
  
  if(pos <= 0 && pos >= X_MAX_POS) {
    stepper.setAcceleration(X_ACCELERATION);
    stepper.moveTo(pos);
      if(pos < stepper.currentPosition()) {
      
        stepper.setSpeed(-100);
      } else {
       
        stepper.setSpeed(100);
      }
    while(stepper.distanceToGo() != 0) {
      stepper.run(); 
    }
  } else {
    Serial.println("Position should be between -4995 and 0");
  }
}


void button_init(){    
  pinMode(16, INPUT_PULLUP); 
  pinMode(17, INPUT_PULLUP); 
  pinMode(23, INPUT_PULLUP); 
  pinMode(25, INPUT_PULLUP); 

  pinMode(27, INPUT_PULLUP); 
  pinMode(29, INPUT_PULLUP); 
  pinMode(31, INPUT_PULLUP); 
  pinMode(33, INPUT_PULLUP); 

  pinMode(35, INPUT_PULLUP); 
  pinMode(37, INPUT_PULLUP); 
  pinMode(39, INPUT_PULLUP); 
  pinMode(41, INPUT_PULLUP); 

  pinMode(43, INPUT_PULLUP); 
  pinMode(45, INPUT_PULLUP); 
  pinMode(47, INPUT_PULLUP);  
  pinMode(32, INPUT_PULLUP);  
  
  pinMode(18, INPUT_PULLUP); // Coin Accepter signal input
  pinMode(19, INPUT_PULLUP); // Debugging button
  
}
  
void setup() {
  
  // Open serial communications and wait for port to open:
  pinMode(24, OUTPUT);   // enable A4988
  digitalWrite(24, LOW); // enable A4988

  pinMode(30, OUTPUT);   // enable A4988
  digitalWrite(30, LOW); // enable A4988

  
  serial_init();
  button_init();
  
  
  mJson.Init_("INGRED~1.JSO","RECIPE~1.JSO");
  Serial.println("Json Testing-----------------------");

      
  v_re = mJson.listener_RECIPE.vi_recipe_item;
  v_i  = mJson.listener_INGRED.vi;

  Serial.println(v_re.size());
//  mJson.Init_("ingredients.json","recipes.json");
  stepper.setMaxSpeed(X_MAX_SPEED); // Sets the maximum speed the X axis accelerate up to
  stepperZ.setMaxSpeed(Z_MAX_SPEED); // Sets the maximum speed the Z axis accelerate up to
  pinMode(Z_ENDSTOP_PIN, INPUT_PULLUP); // Initialize Z- endstop pin with the internal pull-up resistor enabled 
  pinMode(X_ENDSTOP_PIN, INPUT_PULLUP); // Initialize X- endstop pin with the internal pull-up resistor enabled
  pinMode(14, INPUT_PULLUP);// for Stop Interrupt
  pinMode(15, INPUT_PULLUP);// for Home z, x 
  homeZAxis(); // Return the Z axis to it's home position at the startup
  homeXAxis(); // Return the X axis to it's home position at the startup


  coin_accepted = 0;
}
void coin_acceptor_handler(){
  if (digitalRead(18) == 0){ // coin accepted 
    delay(100); // --------------------------------------- coin accepting delay time
    coin_accepted = 1;
    coin_accepted_time_old = millis();
  }
}
void loop() {
 
  unsigned long current_time = 0;  
  coin_acceptor_handler();  
  button_scheduler();
  current_time = millis();
  if ((current_time - coin_accepted_time_old) > 60000) // no reponse for 60s
  {
    coin_accepted_time_old = current_time;
    coin_accepted = 0;
  }
  delay(5);
}


int get_button_state(){      
  if (!digitalRead(16)) return 0;
  if (!digitalRead(17)) return 1;
  if (!digitalRead(23)) return 2;
  if (!digitalRead(25)) return 3;
  
  if (!digitalRead(27)) return 4;
  if (!digitalRead(29)) return 5;
  if (!digitalRead(31)) return 6;
  if (!digitalRead(33)) return 7;
  
  if (!digitalRead(35)) return 8;
  if (!digitalRead(37)) return 9;
  if (!digitalRead(39)) return 10;
  if (!digitalRead(41)) return 11;  

  if (!digitalRead(43)) return 12;  
  if (!digitalRead(45)) return 13;  
  if (!digitalRead(47)) return 14;    
  if (!digitalRead(32)) return 15;    
  
  return 100;
}

void get_RecipeData(int butState){
  int bufIndex = butState;
  for (int i = 0; i < v_re.size(); i++){
    if(v_re[i].id == 0 && v_re[i].amount == 0) {bufIndex--; continue;}
    if (bufIndex < 0) return;
    if (bufIndex == 0){
      moveXTo(v_i[v_re[i].id - 1].coordinate);  
      pourZ(v_re[i].amount/ 20,v_i[v_re[i].id - 1].hold, v_i[v_re[i].id - 1].wait);      
    }
  }
}

void button_scheduler(){   
 if (digitalRead(19) &&!coin_accepted) return;  
 int butState = get_button_state();
 if (butState == 100) return; 
 coin_accepted = 0; 
 get_RecipeData(butState); 
 moveZTo(0); // Return the Z axis to it's home position at the startup
 Serial.println("return to x home");
 moveXTo(0); // Return the X axis to it's home position at the startup

}

void homeZAxis() {          
  
        int endStopState = digitalRead(Z_ENDSTOP_PIN);         
        while (endStopState == HIGH) {
        
          stepperZ.moveTo(50);
          stepperZ.setSpeed(Z_HOME_SPEED);
          stepperZ.runSpeed();
          endStopState = digitalRead(Z_ENDSTOP_PIN);  
        }  
        
        stepperZ.moveTo(stepperZ.currentPosition() - 25);
        
        while (stepperZ.distanceToGo() != 0) {        
          stepperZ.setSpeed(Z_PARK_SPEED * -1);
          stepperZ.runSpeed();            
        }
        endStopState = digitalRead(Z_ENDSTOP_PIN);

      
        while (endStopState == HIGH) {
          stepperZ.moveTo(50);        
          stepperZ.setSpeed(Z_PARK_SPEED);
          stepperZ.runSpeed();   
          endStopState = digitalRead(Z_ENDSTOP_PIN);
        }  
       
        stepperZ.setCurrentPosition(0); 
      }
      
void moveZTo(int pos) {    
            
      Serial.print("Z goes to: ");
      Serial.println(pos);    
      
      stepperZ.setAcceleration(Z_ACCELERATION);
      stepperZ.moveTo(pos);
      
      if(pos < stepperZ.currentPosition()) {
            stepperZ.setSpeed(-100);
          } else {
            stepperZ.setSpeed(100);
          }
        while(stepperZ.distanceToGo() != 0) {
          stepperZ.run(); 
        }      
    }
 
void pourZ(int times, int holdDuration,int waitDuration) {
        int count = 0; // Pour counter 
        if(holdDuration > 0 && waitDuration > 0) {
          for(int i=0; i<times; i++) {            
              moveZTo(Z_MAX_POS);
              delay(holdDuration - HOLD_DELAY_IN_Z_MAX);              
              moveZTo(0); // Return the Z axis to it's home position at the startup
             if(times - 1 > count) {
                      delay(waitDuration);
                } else {
                      delay(DELAY_BETWEEN_INGREDIENTS);
                }
              count++;
            }
        } else {
          Serial.println("Hold and wait duration parameters cannot be lower than or equal to 0");
        }
}



