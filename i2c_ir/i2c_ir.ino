/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */
#include <IRremote.h>
#include <Wire.h>
int RECV_PIN = 5;
int x = 0;
byte kiri = 0;
byte kanan = 0;
byte deff = 0;
int toleh = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;
void(* resetFunc) (void) = 0;
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
    Wire.begin();
    kiri = 0;
    kanan = 0;
    toleh = 0;
}
void loop() {
  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value
  }
//  Serial.println(results.value);
  delay(100);
  if (results.value == 428946)
  {
//    Serial.println("kanan");
    kanan=1;
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write("kanan ");
    Wire.write(kanan);
    Wire.endTransmission();    // stop transmitting
    Serial.println("kanan");
    toleh = 1; //udah toleh kanan
  }
  else if (results.value == 428919)
  {
    kiri = 1;
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write("kiri ");
    Wire.write(kiri);
    Wire.endTransmission();    // stop transmitting
    Serial.println("kiri");
    toleh = 0; //udahb toleh kiri
  }
  if (kiri == 1 && kanan == 1)
  {
    delay(100);
    kiri = 0;
    kanan = 0;
  }
//    Serial.println("udah 1 semua");
//    delay(100);
//    Wire.beginTransmission(9); // transmit to device #9
//    Wire.write("kiri ");
//    Wire.write(deff);
//    Wire.endTransmission();    // stop transmitting
//    Wire.beginTransmission(9); // transmit to device #9
//    Wire.write("kanan ");
//    Wire.write(deff);
//    Wire.endTransmission();    // stop transmitting
//    resetFunc();
//  }
//  else if(kiri == 0 && kanan == 0)
//  {
//    Serial.println("0 semua");
//  }
//  Serial.print(kiri);
//  Serial.print(" ");
//  Serial.println(kanan);
  delay(200);
}
