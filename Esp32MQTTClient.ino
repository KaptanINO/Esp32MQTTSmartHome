//düzenlenmemeiş kod

#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2
#define DHT11PI 1
#define DHT11P 3// DHT11PIN olarak Dijital 2"yi belirliyoruz.

#include <ESP32Servo.h>
#include <WiFi.h>
#include <PubSubClient.h>

dht11 DHT11;

int chk;
int sicaklik;
int chk2;
int sicaklik2;
int chk3;
int sicaklik3;
char dhtMesaj[3];


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


void setup() {
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

    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {

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

void loop() {

  chk = DHT11.read(DHT11PIN);
  sicaklik = (int)DHT11.temperature;
  if (!client.connected()) {
    reconnect();
  }
  

  
  client.publish("sicaklik", String(sicaklik).c_str());

 chk2 = DHT11.read(DHT11PI);
  sicaklik2 = (int)DHT11.temperature;
  if (!client.connected()) {
    reconnect();
  }
  

  
  client.publish("sicaklik2", String(sicaklik2).c_str());

 chk3 = DHT11.read(DHT11P);
  sicaklik3 = (int)DHT11.temperature;
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  }

  
  client.publish("sicaklik3", String(sicaklik3).c_str());
}


//-----------------------------------------------------------------


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("MQTT Bağlantısı koptu.Yeniden deneniyor...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
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


//-----------------------------------------------------------------

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mesaj esp'ye ulaştı [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    mesaj += (char)payload[i];
  }

  Serial.println();
  Serial.println(mesaj);
  //Salon---------------------------
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
  //YatakOdası---------------------------
  if (mesaj == "Yatakodasiac") {
    digitalWrite(18, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Yatakodasikapa") {
    digitalWrite(18, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  //-------------------------------
  //Mutfak---------------------------
  if (mesaj == "Mutfakac") {
    digitalWrite(20, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Mutfakkapa") {
    digitalWrite(20, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  //Koridor---------------------------
  if (mesaj == "Koridorac") {
    digitalWrite(24, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Koridorkapa") {
    digitalWrite(24, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  //DışKapıIşık---------------------------
  if (mesaj == "Diskapiisikac") {
    digitalWrite(25, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Diskapiisikkapa") {
    digitalWrite(25, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  //Garaj---------------------------
  if (mesaj == "Garajac") {
    digitalWrite(26, HIGH);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "Garajkapa") {
    digitalWrite(26, LOW);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  //--------------------------------
  //P1
  if (mesaj == "") {
    servo1.write(90);
    Serial.println("komut yerine getirildi");
    delay(100);
  }
  if (mesaj == "p1kapa") {
    servo1.write(0);
    Serial.println("komut yerine getirildi");
    delay(100);
  }

  //--------------------------------
  //P3------------------------------
  if (mesaj == "p3ac") {
    servo3.write(90);
    delay(100);
  }
  if (mesaj == "p3kapa") {
    servo3.write(180);
    delay(100);
  }
  //--------------------------------
  //P4
  if (mesaj == "p4ac") {
    servo4.write(90);
    delay(100);
  }


  if (mesaj == "p4kapa") {
    servo4.write(180);
    delay(100);
  }
  //--------------------------------
  //--------------------------------

  mesaj = "";
}
//-----------------------------------------------------------------
