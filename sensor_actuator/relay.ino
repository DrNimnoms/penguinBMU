/*------------------------------------------------------------------------------
 * void setContactors(void))
 * sets the contactors on or off
 *----------------------------------------------------------------------------*/
void setRelays(){
  if(relayOn) setRelayOn(); 
  else setRelayOff();
  if(extDO1) digitalWrite(extDO1Pin, HIGH);
  else digitalWrite(extDO1Pin, LOW);
  if(extDO2) digitalWrite(extDO2Pin, HIGH);
  else digitalWrite(extDO2Pin, LOW);
}
/*------------------------------------------------------------------------------
 * void relayOn(void))
 * turns both relays on with 1 sec delay between
 *----------------------------------------------------------------------------*/
void setRelayOn(void){
  digitalWrite(relay1Pin, HIGH);
  if(relayCounter<5) relayCounter++;
  else digitalWrite(relay2Pin, HIGH);
}

/*------------------------------------------------------------------------------
 * void relayOff(void))
 * turns both relays off and sets currentOffset
 *----------------------------------------------------------------------------*/
void setRelayOff(void){
  digitalWrite(relay1Pin, LOW);
  digitalWrite(relay2Pin, LOW);
  relayCounter=0;
}
