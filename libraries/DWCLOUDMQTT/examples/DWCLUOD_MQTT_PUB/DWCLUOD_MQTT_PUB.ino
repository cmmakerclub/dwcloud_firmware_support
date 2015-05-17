#include <DWCLOUDMQTT.h>

ESP esp(&Serial1, &Serial, 13);

#define WIFI_SSID                  "DD_WIFI"
#define WIFI_PASS                  "deaw1234567890"
#define HOST_IP                    "192.168.1.160"
#define HOST_PORT                  1883
#define MQTT_TOPIC                 "t/temp"

void wifiCb(uint8_t status)
{
  Serial.println("WIFI: Connected");
  esp.mqttConnect(HOST_IP, HOST_PORT);
}

void mqttConnected(uint32_t* args)
{
  Serial.println("MQTT:Connected");
  //esp.subscribe("t/temp");
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
  Serial.print("Received, topic:");
  Serial.print(topic);
  Serial.print(", Length:");
  Serial.print(event_data->data_length);
  Serial.print(", data:");
  
  for (i=0; i<event_data->data_length; i++) {
    Serial.write(data[i]);
  }
  Serial.println();
}

const char clientId[] = "clientId";
const char user[] = "";
const char pass[] = "";

void setup() {
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

uint32_t count = 0;

void loop() {
  esp.process();
  count = count + 1;
  if(count > 10) {
    esp.publish(MQTT_TOPIC, "test", strlen("test"), 0, 0);
    Serial.print("Publish !!");
    count = 0;
  }
}





