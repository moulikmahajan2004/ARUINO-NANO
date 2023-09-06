//arduino mqtt library
#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
//WIFI VREDENTIALS
char WIFI_NAME[] = "Moulik";     
char WIFI_PASSWORD[] = "12345678"; 
//LED PIN
int BULUB_PIN = 6;  

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

//MQTT CREDENTIALS
const char BROKER_LINK[] = "mqtt-dashboard.com";  
int PORT_NO = 1883;                              
const char TOPIC[] = "mm/wave";           

void setup() {
  Serial.begin(9600);
  pinMode(BULUB_PIN, OUTPUT);
  while (!Serial) {
    
  }

  Serial.print("TRYING TO CONNECT THE WIFI_NAME: ");
  Serial.println(WIFI_NAME);

  while (WiFi.begin(WIFI_NAME, WIFI_PASSWORD) != WL_CONNECTED) {
    Serial.print(".");
    delay(5000);
  }

  Serial.println("CONNECTED TO THE NETWORK");
  Serial.println();

  Serial.print("TRYING TO COOENCT THE MQTT BROKER LINK: ");
  Serial.println(BROKER_LINK);

 
  if (!mqttClient.connect(BROKER_LINK, PORT_NO)) {
    Serial.print("CONNECTION FAILED MQTT BROKER: ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("CONNECTED MQTT BROKER_LINK!");
  Serial.println();

  Serial.print("SUBSCRIBING TOPIC: ");
  Serial.println(TOPIC);
  Serial.println();


  mqttClient.subscribe(TOPIC);

  Serial.print("Waiting for messages on TOPIC: ");
  Serial.println(TOPIC);
  Serial.println();
}

void loop() {
  int messageSize = mqttClient.parseMessage();
  if (messageSize) {
    Serial.print("Received a message with TOPIC '");
    Serial.print(mqttClient.messageTOPIC());
    Serial.print("', length ");
    Serial.print(messageSize);
    Serial.println(" bytes:");

    // Print the received message
    while (mqttClient.available()) {
      Serial.print((char)mqttClient.read());
    }
    Serial.println();

    // Toggle the BULUB_PIN to indicate a message was received
    digitalWrite(BULUB_PIN, HIGH);
    delay(200);
    digitalWrite(BULUB_PIN, LOW);
    delay(200);
    digitalWrite(BULUB_PIN, HIGH);
    delay(200);
    digitalWrite(BULUB_PIN, LOW);
    delay(200);
    digitalWrite(BULUB_PIN, HIGH);
    delay(200);
    digitalWrite(BULUB_PIN, LOW);
    delay(200);

    Serial.println();
  }
}