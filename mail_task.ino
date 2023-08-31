//library 
#include <WiFiNINA.h>
//credetials to access the wifi network
char WIFINAME[] = "Nord"; //enter your wifi name
char WIFI_PASS[] = "12345678900"; //enter your wifi password
//cliwnt object
WiFiClient client;
//hostname , websitelink
char   HOST_NAME[] = "maker.ifttt.com";
//wifipathe to which data must be sent this contain the webhook event name along, with key to send the data
String PATH_NAME = "/trigger/email_to_me/with/key/fKsf7Mh8Re2PNyWCQIK5iQoSvjnCa1epfNBFvUe_wbA";

void setup() {
  //wifi is external object to which we call the begin function which contain the wifi name and the password with which all the credentials are sent
  WiFi.begin(WIFINAME, WIFI_PASS);
  //serial begin to communicate between the laptop and the arduino
  Serial.begin(9600);
  while (!Serial) ;
//to check weather that arduino nano is connected with wifi or not 
//Wl_connected show wetather that our arduino is connected to wifi as wifi.status is used to give this 
//if not then connection failed is printed
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Connection to WiFi failed");
  }
}

void loop() {
//sensor dat is take in the form of analog read 
float LIGHT_INTENSITY_VALUE = analogRead(A0);

//THIS IS THE CERTAIN CHART AND BASED ON THIS VALUES WILL BE PRINTED AND THE MESSAGE WILL BE MAILED
  if (LIGHT_INTENSITY_VALUE < 100) 
  {
    FORMAT_WEBHOOK_FUNCTION_CONNECTION(- Very bright, float LIGHT_INTENSITY_VALUE)
  } else if (LIGHT_INTENSITY_VALUE < 200) 
  {
    FORMAT_WEBHOOK_FUNCTION_CONNECTION("it is bright - ",LIGHT_INTENSITY_VALUE);
  } else if (LIGHT_INTENSITY_VALUE < 500)
  {
   FORMAT_WEBHOOK_FUNCTION_CONNECTION("it is light - ",LIGHT_INTENSITY_VALUE);

  } else if (LIGHT_INTENSITY_VALUE < 800) 
  {
   FORMAT_WEBHOOK_FUNCTION_CONNECTION("Dim ---",LIGHT_INTENSITY_VALUE);
  } else 
  {
    FORMAT_WEBHOOK_FUNCTION_CONNECTION("it is dark - ",LIGHT_INTENSITY_VALUE);
  }

  delay(5000); // Delay for a few seconds before taking the next reading
}

//THIS IS THE FUCNTIONN TO RESPONSE TO THE MAIL SENDING
//IT TAKE TWO PARAMETERS MESSAGE AND LIGHTINTENSITY VALUES
//THESRE ARE FURTHER STORED IN QUERRY STRING AS ALL THESE ARE CONVERTED TO STRING FORMAT
//AFTER THAT WEBSITE NAME IS USED ALONG WITH THE SERVER NAME
//HOST NAME WHICH IS IFTTT AND THE 80 IS THE PORT NUMBER

void FORMAT_WEBHOOK_FUNCTION_CONNECTION(String message, float LIGHT_INTENSITY_VALUE) {
  String queryString = "?value1=" + message + "&value2=" + String(LIGHT_INTENSITY_VALUE);
//if connected then execution else server failed
  if (client.connect(HOST_NAME, 80)) {
    client.print("GET " + PATH_NAME + queryString + " HTTP/1.1\r\n");
    client.print("Host: " + String(HOST_NAME) + "\r\n");
    client.print("Connection: close\r\n");
    client.print("\r\n");
    Serial.println(message + "Voltage: " + String(LIGHT_INTENSITY_VALUE));
    Serial.println("Email sent");
  } else {
    Serial.println("Connection to server failed");
  }

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
  }
//delay for 5 seconds
  delay(5000);
}
