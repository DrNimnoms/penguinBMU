/*------------------------------------------------------------------------------
 * BME.h
 * Created by Nima Ghods
 * Data: 5/1/2015
 * setsup miscellaneous parameters for running BMU v6.X
 *----------------------------------------------------------------------------*/
 
 // debug
 boolean uartPrint= true;

 
 //time constants
  #define ONEHOUR 36000000 //in milliseconds
  #define TWOMINUTES 120000  // in milliseconds
  #define ONEMINUTE 60000  // in milliseconds
  #define THIRTYSECONDS 30000 //in milliseconds
  #define TENSECONDS 10000 //in milliseconds
  #define FIVESECONDS 5000 //in milliseconds
  #define THREESECOND 3000   // in milliseconds
  #define ONESECOND 1000   // in milliseconds
  #define FIVEHZ 200   // in milliseconds
  #define DT 0.2     // loop time in sec
// timeres
  Metro looptimer = Metro(FIVEHZ); 

// relay counter  
  int relayCounter=0;  // a counter to saprate the relays turning on 
  
  
// varables used in getting BMU measurements 
  //a coutner to address the intermittent leak seonsors 
//  int fwLeakCount=0;
//  int bwLeakCount=0;

  

