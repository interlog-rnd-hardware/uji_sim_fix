// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
//    Serial.print(c);         // print the character
    sir += c;
  }
      
  int x = Wire.read();    // receive byte as an integer
  sirr = sir + x;
//  Serial.println(sirr);
  if(sirr.startsWith("kiri") /*&& tolkanan == 1*/)
  {
//    Serial.println("ini kiri");
    kiri = "1";
    digitalWrite(right,HIGH);
    digitalWrite(left,LOW);    
    tolkanan = 0;    
    digitalWrite(kamera,HIGH);    
  }
//    kiri = getValue(sirr,' ',1);
//    Serial.print("kiri : ");
//    Serial.println(kiri);
  else if(sirr.startsWith("kanan") /* && detecttrack == 1*/)
  {
    kanan = "1";
    digitalWrite(right,LOW);
    digitalWrite(left,HIGH);        
    tolkanan = 1;    
  }
//    kanan = getValue(sirr,' ',1);
//    Serial.print("kanan : ");
//    Serial.println(kanan);
 sir ="";
}
