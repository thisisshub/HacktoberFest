#include <ESP8266WiFi.h>
const char* ssid     = "Your WiFi SSID";
const char* password = "Your Password";

void setup() 
{
   Serial.begin(115200);
   Serial.println("Starting...");

   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) 
   {
      delay(250);
      Serial.print(".");
   }

   Serial.println("WiFi connected");  
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
}

void loop() 
{
}
