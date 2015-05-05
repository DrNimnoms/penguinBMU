/*------------------------------------------------------------------------------
 * sensor_actuator.ino
 * Created by Nima Ghods
 * Data: 5/1/2015
 * made to test the inputs and outouts of BMUshielv6.X
 *----------------------------------------------------------------------------*/

//included headers
#include "Arduino.h"
#include <Metro.h>    //Include Metro library for keeping time intervals
#include "BMU.h"           //all BMU variables
#include "BMUShield.h"     //all BMU variables

void setup() {
  allInital();
}

void loop() {
  if (looptimer.check() == 1) { // check if the metro has passed its interval 
    
    getBMUData();
    
    setRelays();
    
  }
}
