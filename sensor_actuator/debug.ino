 /*------------------------------------------------------------------------------
 * void printout(void)
 * prints information out on the screen for all BME's
 *----------------------------------------------------------------------------*/
 void serialEvent() {
  String inputString = "";
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
//    Serial.println(inputString);
    delay(2);
  }
  debugBMU(inputString);
 }
 
 /*------------------------------------------------------------------------------
 * void debugBMU(void)
 * does the command that is sent from the debug UART
 *----------------------------------------------------------------------------*/
void debugBMU(String input){ 
  
  if(input.indexOf("pri") >=0){
    testBMU();
  }
  else if(input.indexOf("rOn") >=0){
    relayOn=true; 
    if(uartPrint)Serial.println("Relays On ");
  }
  else if(input.indexOf("rOff") >=0){
    relayOn=false; 
    if(uartPrint)Serial.println("Relays Off ");
  }
  else if(input.indexOf("do1on") >=0){
    extDO1=true; 
    if(uartPrint)Serial.println("external Digatal output 1 On ");
  }
  else if(input.indexOf("do2on") >=0){
    extDO2=true; 
    if(uartPrint)Serial.println("external Digatal output 2 On ");
  }
  else if(input.indexOf("do1of") >=0){
    extDO1=false; 
    if(uartPrint)Serial.println("external Digatal output 1 Off ");
  }
  else if(input.indexOf("do2of") >=0){
    extDO2=false; 
    if(uartPrint)Serial.println("external Digatal output 2  Off ");
  }
  
}
   
/*------------------------------------------------------------------------------
 * void testBMU(void)
 * prints information out on the screen for one BME
 *----------------------------------------------------------------------------*/
 void testBMU(){
  Serial.println("-------------------------------------------------------------------------------------");
  Serial.println("BMU sensors"); 
  Serial.print("Current:"); 
  if (current < 0){
    Serial.print('-');
    Serial.print(-1*current,2);
  }
  else{
    Serial.print(current,2);
  }
  Serial.print(" A\t Voltage:");
  Serial.print(voltage,2);
//  Serial.print(" V\t layerSum:");
//  Serial.print(volSum,2);
  Serial.print(" V\t Pressure:");
  Serial.print(pressure,1);
  Serial.print(" PSIG\t Ext Pressure:");
  Serial.print(pressureExt,1);
  Serial.print(" PSIG\t waterleak: ");
  if(!fwLeak & !bwLeak) Serial.print("no leak");
  else if(!fwLeak & bwLeak) Serial.print("back leak");
  else if(fwLeak & !bwLeak) Serial.print("front leak");
  else if(fwLeak & bwLeak) Serial.print("both leak");
//  Serial.print(" \nFlag: ");
//  Serial.print(flagBMU,HEX);
//  Serial.print(" \t SOC: ");
//  Serial.print(SOC,2);
//  Serial.print(" %\t Vsum: ");
//  Serial.print(volSum,2);
//  Serial.print("V \t minVol: ");
//  Serial.print(minVol,4);
//  Serial.print("V \t maxVol: ");
//  Serial.print(maxVol,4);
//  Serial.print("V \t maxTemp: ");
//  Serial.print(maxTemp,2);
//  Serial.println(" C");
//  Serial.print("Current Mode:\t");
//  switch (modeInfo.currentMode+1) {
//    case 1:
//      Serial.print("STOP");
//      break;
//    case 2:
//      Serial.print("DRIVE");
//      break;
//    case 3:
//      Serial.print("CHARGE");
//      break;
//    case 4:
//      Serial.print("BALANCE");
//      break;
//    default:
//      Serial.print("Somethings Wrong");
//      break;
//  }
  Serial.print(" \t Contactor State: ");
  if(!relay1fb & !relay2fb) Serial.println("Both OFF");
  else if(!relay1fb & relay2fb) Serial.println("Relay 2 ON");
  else if(relay1fb & !relay2fb) Serial.println("Relay 1 ON");
  else if(relay1fb & relay2fb) Serial.println("Both ON");
 }
   
