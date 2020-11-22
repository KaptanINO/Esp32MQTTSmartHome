#include <ESP32Servo.h>
#include <WiFi.h>
#include <PubSubClient.h>



Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
int servo1Pin = 2;
int servo2Pin = 4;
int servo3Pin = 5;
int servo4Pin = 12;
int servo5Pin = 19;
int servo6Pin = 21;
int servo7Pin = 23;
int minUs = 500;
int maxUs = 2400;

const char* ssid = "MFA183";
const char* password =  "08102007mfa";
const char* mqttServer = "m24.cloudmqtt.com";
const int mqttPort = 13791;
const char* mqttUser = "oeefondp";
const char* mqttPassword = "UoKQL28Lxqon";

String mesaj = "";
WiFiClient espClient;
PubSubClient client(espClient);


void setup() 
      {
  pinMode(13, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  Serial.begin(115200);



  servo1.setPeriodHertz(50);      // Standard 50hz servo
  servo2.setPeriodHertz(50);      // Standard 50hz servo
  servo3.setPeriodHertz(50);      // Standard 50hz servo
  servo4.setPeriodHertz(50);
  servo5.setPeriodHertz(50);
  servo6.setPeriodHertz(50);
  servo7.setPeriodHertz(50);

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("WİFİ AĞINA BAĞLANIYOR");
  }

  Serial.println("Wifi ağına bağlanıldı");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {
    Serial.println("MQTT Sunucusuna Bağlanıyor...");

    if (client.connect("ESP32client", mqttUser, mqttPassword )) {

      Serial.println("MQTT Sunucusuna bağlanıldı!");

    } else {

      Serial.print("Bağlantı Başarısız Oldu. ");
      Serial.print(client.state());
      delay(2000);

    }
  }

  client.publish("espdenpcye", "Hello from ESP32");
  client.subscribe("pcdenespye");
  servo1.attach(servo1Pin, minUs, maxUs);
  servo2.attach(servo2Pin, minUs, maxUs);
  servo3.attach(servo3Pin, minUs, maxUs);
  servo4.attach(servo4Pin, minUs, maxUs);
  servo5.attach(servo5Pin, minUs, maxUs);
  servo6.attach(servo6Pin, minUs, maxUs);
  servo7.attach(servo7Pin, minUs, maxUs);
 }
 void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mesaj esp'ye ulaştı [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    mesaj += (char)payload[i];
  }
}

void loop() {

}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("MQTT Bağlantısı koptu.Yeniden deneniyor...");
    // Attempt to connect
    if (client.connect("espClient")) {
      Serial.println("Bağlandı..");
      // Once connected, publish an announcement...
      client.publish("espdenpcye", "hello world");
      // ... and resubscribe
      client.subscribe("pcdenespye");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}






 
  if (mesaj == "Salonac") {
    digitalWrite(16, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Salonkapa") {
    digitalWrite(16, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }



  mesaj = "";
}
