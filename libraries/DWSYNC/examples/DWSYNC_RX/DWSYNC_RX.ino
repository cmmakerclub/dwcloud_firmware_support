#include <dwsync.h>

#define LED_CMD        0x01

DW_SYNC sync(&Serial);

void led_handler(DWSYN_PRTCL args)
{
  if (args->data[0]) {
    digitalWrite(16, HIGH);
  } else {
    digitalWrite(16, LOW);
  }
}

void sync_rd_cb(DWSYN_PRTCL args)
{
  switch (args->cmd) {
    case LED_CMD:
      led_handler(args);
      break;
    default:
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  sync.read_cb.attach(sync_rd_cb);
}

void loop() {
  // put your main code here, to run repeatedly:
  sync.process();
}
