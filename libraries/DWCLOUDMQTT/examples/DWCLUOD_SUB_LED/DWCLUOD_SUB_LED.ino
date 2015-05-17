/***
 * LED ON  : mosquitto_pub -h 192.168.1.160 -t iot/deaware/led -m "1"
 * LED OFF : mosquitto_pub -h 192.168.1.160 -t iot/deaware/led -m "0"
 *
 *****/

#include <DWCLOUDMQTT.h>

ESP esp(&Serial1, &Serial, 13);

#define WIFI_SSID                  "DD_WIFI"
#define WIFI_PASS                  "deaw1234567890"
#define HOST_IP                    "192.168.1.160"
#define HOST_PORT                  1883

#define LED_PIN                    7

void wifiCb(uint8_t status)
{
  Serial.println("WIFI: Connected");
  esp.mqttConnect(HOST_IP, HOST_PORT);
}

void mqttConnected(uint32_t* args)
{
  Serial.println("MQTT:Connected");
  esp.subscribe("iot/deaware/led");
}

void mqttDisconnected(uint32_t* args)
{
  Serial.println("MQTT:Disconnected");
  esp.mqttConnect(HOST_IP, HOST_PORT);
  Serial.println("MQTT:Reconnect");
}

void mqttPublished(uint32_t* args)
{
  Serial.println("MQTT:Published");
}

void mqttData(uint32_t* args)
{
  mqtt_event_data_t *event_data = (mqtt_event_data_t *)args;
  char topic[16];
  char data[32];
  uint8_t i = 0;

  memcpy(topic, event_data->topic, event_data->topic_length);
  memcpy(data, event_data->data, event_data->data_length);
  topic[event_data->topic_length] = 0;
  data[event_data->data_length] = 0;
  Serial.print("MQTT rcv cmd : ");
  Serial.println(topic);
  
  if(event_data->data_length > 0) {
    switch(data[0]) {
      case '0' :
      digitalWrite(LED_PIN, LOW);
      Serial.print("LED OFF");
      break;
      case '1' :
      digitalWrite(LED_PIN, HIGH);
      Serial.print("LED ON");
      break;
      default :
      break;
    }
  }
  Serial.println();
}

const char clientId[] = "clientId";
const char user[] = "";
const char pass[] = "";


void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(115200);
  Serial.println("Inited");
  
  /* setup event */
  esp.wifiCb.attach(&wifiCb);
  esp.mqttConnected.attach(&mqttConnected);
  esp.mqttDisconnected.attach(&mqttDisconnected);
  esp.mqttPublished.attach(&mqttPublished);
  esp.mqttData.attach(&mqttData);

  /* Init data */
  esp.initMqttClient(clientId, user, pass, 30);
  
  /* wifi connect */
  esp.wifiConnect(WIFI_SSID, WIFI_PASS);
}

void loop() {
  esp.process();
}





