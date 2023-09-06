//arduino Mqtt client library 
#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
//WIFI CREDENTIALS
char WIFI_NAME[] = "Moulik";   
char WIFI_PASSWORD[] = "012345678"; 
//OUR ULTRASONIC SENSOR PIN
const int TRIGERING_PIN = 4;
const int ENCHO_PIN = 5;
//VARIABLES
float TIME_DURATION, DISTANCE;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

//MQTTT CREDENTIALS
const char broker[] = "mqtt-dashboard.com";
int port = 1883;
const char topic[] = "mm-wave";
const long interval = 1000;
unsigned long previousMillis = 0;
//COUNT
int count = 0;

void setup() {
  
  pinMode(TRIGERING_PIN, OUTPUT );
  pinMode(ENCHO_PIN, INPUT );
  Serial.begin(9600);
  while (!Serial) {
   
    ;
  }

  Serial.print("Attempting to connect to  WIFI_NAME: ");
  Serial.println(WIFI_NAME);
  while (WiFi.begin(WIFI_NAME, WIFI_PASSWORD) != WL_CONNECTED) {
    
    Serial.print(".");
    delay(5000);
  }

  Serial.println("CONNECVTED TO NETWORK");
  Serial.println();

  Serial.print("TRYING CONNECTIING THE MQTT BROKER ");
  Serial.println(broker);


  if (!mqttClient.connect(broker, port)) {
    Serial.print("CONNECTION FAILED ERROR CODE: ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("CONNECTED TO THE MQTT BROKER");
  Serial.println();
}

void loop() {
  
  mqttClient.poll();
  unsigned long MILLIS_CURRENTLY = millis();

  if (MILLIS_CURRENTLY - previousMillis >= interval) {
    previousMillis = MILLIS_CURRENTLY;

   
    digitalWrite(TRIGERING_PIN, LOW);
    delayMicroseconds(3);
    digitalWrite(TRIGERING_PIN, HIGH);
    delayMicroseconds(12);
    digitalWrite(TRIGERING_PIN, LOW);

    TIME_DURATION= pulseIn(ENCHO_PIN, HIGH);
   DISTANCE= (TIME_DURATION* 0.0343) / 2;

    Serial.print("PALM_DISTANCE ");
    Serial.println(DISTANCE);

  
    if (DISTANCE < 12) {
      mqttClient.beginMessage(topic);
      mqttClient.print(" WAVE IS DETECTED");
      mqttClient.print("PALM_DISTANCE ");
      mqttClient.print(DISTANCE);
      mqttClient.endMessage();
      delay(1000);
    }

    Serial.println();

    count++;
  }
}
