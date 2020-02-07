
     /*    Arduino Long Range Wireless Communication using HC-12
                          Example 01
       by Dejan Nedelkovski, www.HowToMechatronics.com
    */
    String s;
//    #define setpin 12
    #include <SoftwareSerial.h>
    SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
    void setup() {
      Serial.begin(9600);      
      // Serial port to computer
      HC12.begin(9600);               // Serial port to HC12
//      pinMode(setpin,OUTPUT);
//      digitalWrite(setpin,HIGH);
    }
    void loop() {
      while (HC12.available()) {        // If HC-12 has data
      Serial.write(HC12.read());      // Send the data to Serial monitor
//        char c = HC12.read();
//        s += c;
      }
      while (Serial.available()) {      // If Serial monitor has data
        HC12.write(Serial.read());      // Send that data to HC-12
      }
//      HC12.println("<m_1~100078~0~0~0,0,0,0~12.6~12.3>");
      Serial.println();
      delay(150);
      s = "";
    }
