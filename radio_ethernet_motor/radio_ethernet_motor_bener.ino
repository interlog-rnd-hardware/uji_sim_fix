/*
  Web client
  This sketch connects to a website (http://www.google.com)
  using an Arduino Wiznet Ethernet shield.
  Circuit:
   Ethernet shield attached to pins 10, 11, 12, 13
  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe, based on work by Adrian McEwen
*/

#include <SPI.h>
#include <Ethernet.h>
#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3); // HC-12 TX Pin, HC-12 RX Pin

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
//char server[] = "172.20.17.254";    // name address for Google (using DNS)
char server[] = "www.korlantas.id";    // name address for Google (using DNS)
const char* phpinsert = " /motor.php";
const char* phpselect = " /selectmotor.php";
const int port   = 80;

String nocones;
String statuss;
String tegangan;
String datamotor, datanya;
String respon, respon1, respon2, respon3, respon4, respon5, finish, belok, s, sub;
int panjang, panjang1, panjang2, panjang3, panjang4, panjang5;
bool m1, m2, m3, m4, mm1, mm2, mm3, mm4, m5, rc, bkanan, bkiri;
char cc[2];

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);
IPAddress myDns(192, 168, 0, 1);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

// Variables to measure the speed
unsigned long beginMicros, endMicros;
unsigned long byteCount = 0;
bool printWebData = true;  // set to false for better speed measurement

void setup() {
  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  HC12.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(100);
  Serial.print("connecting to ");
  Serial.print(server);
  Serial.println("...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.print("connected to ");
    Serial.println(client.remoteIP());
    // Make a HTTP request:
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  beginMicros = micros();
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  int len = client.available();
  if (len) {
    byte buffer[250];
    char c[250];
    if (len > 250) len = 250;
    client.read(c, 250);
    if (printWebData) {
      //      Serial.write(c, 246); // show in the serial monitor (slows some boards)
      String data = String(c[250]);
      String datakirim = data.substring(246, 247);
      //      Serial.println(data);
      Serial.write(c[246]);
      char cdatakirim[2];
      datakirim.toCharArray(cdatakirim, 2);
      HC12.write(c[246]);
    }
    byteCount = byteCount + len;
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    endMicros = micros();
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    Serial.print("Received ");
    Serial.print(byteCount);
    Serial.print(" bytes in ");
    float seconds = (float)(endMicros - beginMicros) / 1000000.0;
    Serial.print(seconds, 4);
    float rate = (float)byteCount / seconds / 1000.0;
    Serial.print(", rate = ");
    Serial.print(rate);
    Serial.print(" kbytes/second");
    Serial.println();
  }

  // do nothing forevermore:
  while (HC12.available())
  {
    char mot = HC12.read();
    datamotor += mot;
  }
  //      Serial.println(datamotor);
  //
if (datamotor.startsWith("<"))
{
  if (datamotor.length() > 20)
  {
    if (client.connect(server, 80))
    {
      int indexx = datamotor.indexOf('<');
      int respon = datamotor.indexOf('>', indexx);
      datanya = datamotor.substring(indexx + 1, respon);
      Serial.println(datanya);
      Serial.print("connected to ");
      Serial.println(client.remoteIP());
      // Make a HTTP request:
      String url;
      url += phpinsert;
      url += "?motor=";
      url += datanya;

      client.print("GET"); // /chiller.php?mood=najib_ganteng
      client.print(url);
      client.println(" HTTP/1.1");
      client.println("Host: korlantas.id");
      client.println("Connection: close");
      client.println();
      Serial.println(url);
    }
    len = client.available();
    //   if (len) {
    //    byte buffer[250];
    //     char c[250];
    //    if (len > 250) len = 250;
    ////    client.read(c, 250);
    //    if (printWebData) {
    ////      Serial.write(c, 246); // show in the serial monitor (slows some boards)
    //      String data = String(c[249,250]);
    //      String datakirim = data.substring(246,247);
    //      Serial.write(c[246]);
    //      HC12.write(c[246]);
    ////      HC12.println(datakirim);
    //    }
    //    byteCount = byteCount + len;
      }
      
    datamotor = "";
    //    datanya="";
    delay(100);
  }

}
