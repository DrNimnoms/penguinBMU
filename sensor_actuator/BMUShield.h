/*------------------------------------------------------------------------------
 * BMEShield.h
 * Created by Nima Ghods
 * Data: 5/1/2015
 * setsup the pins, constants, parameters for BMUshielv6.X
 *----------------------------------------------------------------------------*/
 
 //BMU ADC conversion constants
  #define curConst 0.08587        //80/V*3.3V/4095*4.01ohm/3.01ohm  sensor resolution*adc resolution*voltage divider
  #define volConst 0.01244        //(45.3+1.87)/1.87*10Kohm/(6.34Kohm+10Kohm)*3.3V/4095
  #define presConst 0.0019073     //1 kpa/5V/0.018*4.7ohm/3.2ohm*3.3V/4095*0.14503 gpsi/kpa
  #define presConstExt 0.0047218  //15 PSI/16mA/160 ohm*3.3V/4095 d
  #define presOffset 0.3223       //0.04/0.018 kpa * 0.14503 gpsi/kpa
  #define presOffsetExt 3.75      //4mA*160 ohm/3.3V*4096 d*presConstExt psi/d
  #define capConst 0.0000555556   //0.2 sec==>.000055556 hours
  
  
// Arduino due pins in use 
  //Analog input pins
  const int tVolInPin = A7;  // Analog input pin for the total voltage
  const int presInPin = A3;  // Analog pressure sensor pin
  const int presInExtPin = A6;  // Analog pressure sensor pin
  const int curInPin = A4;  // Analog current sensor pin
  const int cur0InPin=A5;   // current sencor referance pin
  //Digital input pins
  const int relay1fbPin = 25;   // negative side relay or relay 1 pin feedback
  const int relay2fbPin = 27;   // positive side relay or realy 2 pin feedback
  const int frontWPin = 22;  //front water leak sensor
  const int backWPin = 23;    // back water leak sensor
  //Digital output pins
  const int relay1Pin = 29;   // negative side relay or relay 1 pin
  const int relay2Pin = 28;   // positive side relay or realy 2 pin
  const int extDO1Pin = 24;   // external Digatal Output 1
  const int extDO2Pin = 26;   // external Digatal Output 2
    
// BMU measurement Variables
  float voltage =0;           // total half-string voltage read from ADC
  float pressure =0;          // pressure sensor reading
  float presOld = 0;          // last pressure value
  float presRate =0;          // filtered pressure rate
  float pressureExt =0;       // external pressure sensor reading
  float presExtOld = 0;          // last external pressure value
  float presExtRate =0;       // filtered external pressure rate
  float cur0 =0;           // offset value read from the LEM sensor
  float current =0;           // value read from the LEM sensor
  boolean fwLeak =0;          // front leak sensor
  boolean bwLeak =0;          // back leak sensor
  boolean relay1fb =0;   // contactor 1 feedback
  boolean relay2fb =0;   // contactor 2 feedback
  
// BMU actuators
  boolean relayOn =false;   // relays 1 nd 2
  boolean extDO1 =false;   // external digatal output 1
  boolean extDO2 =false;   // external digatal output 2

// varables used in getting BMU measurements 
  //Biquad filter struct
  typedef struct{
    float gain;//filter gain
    float b0;  //input k coefficient
    float b1;  //input k-1 coefficient
    float b2;  //input k-2 coefficient
    float a1;  //output k-1 coefficient
    float a2;  //output k-2 coefficient
    float x1;  //filter state
    float x2;  //filter state
  }BiquadType;
  // filter the pressure rates
  BiquadType biPresrate;     //filter for on board pressure sensor
  BiquadType biPresrateExt;  //filter for external pressure sensor
  
  
