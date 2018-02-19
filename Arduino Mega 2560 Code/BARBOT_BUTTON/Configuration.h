#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define maestroSerial SERIAL_PORT_HARDWARE_OPEN

// Stepper driver
#define X_INTERFACE_TYPE 1 // Stepper motor interface type
#define X_STEP_PIN 26 // Stepper driver step pin
#define X_DIR_PIN 28 // Stepper driver dir pin

// Stepper motor
#define X_PARK_SPEED 150 // Parking speed
#define X_HOME_SPEED 700 // Homing speed
#define X_MAX_SPEED 1000 // The maximum speed in steps per second the X axis accelerate up to
#define X_ACCELERATION 3000 // Acceleration/deceleration rate in steps per second per second
#define X_MAX_POS -4995 // The maximum position for the X axis

// Stepper driver
#define Z_INTERFACE_TYPE 1 // Stepper motor interface type
#define Z_STEP_PIN 36 // Stepper driver step pin
#define Z_DIR_PIN 34 // Stepper driver dir pin

// Stepper motor
#define Z_PARK_SPEED 150 // Parking speed
#define Z_HOME_SPEED 700 // Homing speed
#define Z_MAX_SPEED 1000 // The maximum speed in steps per second the Z axis accelerate up to
#define Z_ACCELERATION 3000 // Acceleration/deceleration rate in steps per second per second
#define Z_MAX_POS -3000 // The maximum position for the Z axis

/*
  Hold delay time in Z max  = 2250 -  HOLD_DELAY_IN_Z_MAX  

  EX: looking 1 second delay:
   1000 = 2250 - 1250 <<<<=== hold delay in z max should be setted as 1250   
*/
#define HOLD_DELAY_IN_Z_MAX 2250 // max value is 2250



// Servo motor
#define SERVO_MAX_POS 0 // Servo hold position
#define SERVO_MIN_POS 90 // Servo normal position
#define SERVO_RAISE_SPEED 30 // The speed of the servo when travelling from the normal to the hold position
#define SERVO_RELEASE_SPEED 0 // The speed of the servo when travelling from the hold to the normal position

// Endstop
#define X_ENDSTOP_PIN 3 // Endstop pin
#define Z_ENDSTOP_PIN 2 // Endstop pin


// Other
#define TOTAL_ACTIONS 30 // Total number of actions
#define DELAY_BETWEEN_INGREDIENTS 600 // Time duration to wait before travelling to the next ingredient

#endif



