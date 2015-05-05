/*------------------------------------------------------------------------------
 * initalize.ino
 * Created by Nima Ghods
 * Data: 5/1/2015
 * contains all initialization functions for sensor_actuator.ino
 *----------------------------------------------------------------------------*/
 
 /*------------------------------------------------------------------------------
 * void allInital(void)
 * calls all initialization fuctions in initalize.ino
 *----------------------------------------------------------------------------*/
 void allInital(void){
   debugInital();
   digitalInital();
   analogInital();
 }
 
 
 /*------------------------------------------------------------------------------
 * void debugInital(void)
 * initializes the debug parameters
 *----------------------------------------------------------------------------*/
 void debugInital(void){
   Serial.begin(9600);           // set up Serial library at 9600 bps
   Serial.println("Initalizing BMU "); 
 }
 
 
 /*------------------------------------------------------------------------------
 * void digitalInital(void)
 * initializes the digitalpins as inputs and outputs
 *----------------------------------------------------------------------------*/
 void digitalInital(void){
   
   //************************ BMU setup *************************// 
    pinMode(relay1Pin, OUTPUT); //pin selected to control
    digitalWrite(relay1Pin, LOW);
    pinMode(relay2Pin, OUTPUT); //pin selected to control
    digitalWrite(relay2Pin, LOW); 
    pinMode(extDO1Pin, OUTPUT); //pin selected to control
    digitalWrite(extDO1Pin, LOW);
    pinMode(extDO2Pin, OUTPUT); //pin selected to control
    digitalWrite(extDO2Pin, LOW);    
    
    pinMode(frontWPin, INPUT);      // set pin to input
    digitalWrite(frontWPin, HIGH);  // turn on pullup resistors
    pinMode(backWPin, INPUT);       // set pin to input
    digitalWrite(backWPin, HIGH);  // turn on pullup resistors
    pinMode(relay1fbPin, INPUT);      // set pin to input
    digitalWrite(relay1fbPin, HIGH);  // turn on pullup resistors
    pinMode(relay2fbPin, INPUT);       // set pin to input
    digitalWrite(relay2fbPin, HIGH);  // turn on pullup resistors
 }
 
 /*------------------------------------------------------------------------------
 * void analogInital(void)
 * initializes the analog sensors
 *----------------------------------------------------------------------------*/
 void analogInital(void){
   
   analogReadResolution(12); // set ADC to 12 bit resalution
   
   // set the old pressure values for the rate calculation
   presOld=avgADC(presInPin,3)*presConst-presOffset;  // read pressure from on board sensor
   presExtOld=avgADC(presInExtPin,3)*presConstExt-presOffsetExt;   //get external pressure
  
   // [b, a] = butter(2,.16*2/5) in Matlab
  // second order butterworthcutoff freq at 0.16 normalized nyquist freq, sampling 5hz
  biPresrate.gain=1;//filter gain
  biPresrate.b0 = 0.0088;         //input k coefficient
  biPresrate.b1 = 0.0177;        //input k-1 coefficient
  biPresrate.b2 = 0.0088;         //input k-2 coefficient
  biPresrate.a1 = -1.7172;        //output k-1 coefficient
  biPresrate.a2 = 0.7525;         //output k-2 coefficient
  biPresrate.x1 = 0;              //filter state
  biPresrate.x2 = biPresrate.x1;    //filter state
   
  biPresrateExt.gain=1;//filter gain
  biPresrateExt.b0 = 0.0088;              //input k coefficient
  biPresrateExt.b1 = 0.0177;              //input k-1 coefficient
  biPresrateExt.b2 = 0.0088;                //input k-2 coefficient
  biPresrateExt.a1 = -1.7172;                //output k-1 coefficient
  biPresrateExt.a2 = 0.7525;                //output k-2 coefficient
  biPresrateExt.x1 = 0;            //filter state
  biPresrateExt.x2 = biPresrateExt.x1;    //filter state
  
   
 }
   
