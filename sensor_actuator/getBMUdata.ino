/*------------------------------------------------------------------------------
 * void getBMUData(void)
 * Measures and calculates data on a half string level 
 *-----------------------------------------------------------------------------*/
 void getBMUData(void){
   
  voltage=avgADC(tVolInPin,3)*volConst;          // read voltage value
  fwLeak=!digitalRead(frontWPin);             // read front leak sensor
  bwLeak=!digitalRead(backWPin);              //read back leak sensor
  presOld = pressure;             // last pressure value
  pressure=avgADC(presInPin,3)*presConst-presOffset;  // read pressure from on board sensor
  presRate=(pressure-presOld)*DT;          //calculate pressure rate
  presRate= biquadFilter(biPresrate,presRate);      // get filtered pressure rate
  presExtOld = pressureExt;                     // last pressure value
  pressureExt=avgADC(presInExtPin,3)*presConstExt-presOffsetExt;   //get external pressure
  presExtRate=(pressureExt-presExtOld)*DT;       //calculate externalpressure rate
  presExtRate= biquadFilter(biPresrateExt, presExtRate); // get filtered external pressure rate
  cur0=avgADC(cur0InPin,3);             //read current offset from LEM sensor
  relay1fb=!digitalRead(relay1fbPin);     // read feedback from relay 1
  relay2fb=!digitalRead(relay2fbPin);    // read feedback from relay 2
  current=(avgADC(curInPin,3)-cur0)*curConst;     //read current sensor
 }
 
  /*------------------------------------------------------------------------------
 * int biquadFilter(BiquadType biPram,float input)
 * applies Biquad filter to the input
 * returns the filtered value
 *-----------------------------------------------------------------------------*/
 float biquadFilter(BiquadType biPram, float input){
    // Apply Filter
    float x = biPram.gain*input - biPram.a1*biPram.x1 - biPram.a2*biPram.x2;
    float out = biPram.b0*x + biPram.b1*biPram.x1 + biPram.b2*biPram.x2;
    // Update states
    biPram.x2 = biPram.x1;
    biPram.x1 = x;
    return out;
 }
 
  /*------------------------------------------------------------------------------
 * int avgADC(int adcPin,int n)
 * average the ADC measurement 2^n times
 * returns the average
 *-----------------------------------------------------------------------------*/
 int avgADC(int adcPin,int n){
  long tempo=0;
  for(int i=0;i<(1<<n);i++){
    tempo+=analogRead(adcPin);
    delay(1);
  }
  tempo=tempo>>n;
  return (int)tempo;
 }
