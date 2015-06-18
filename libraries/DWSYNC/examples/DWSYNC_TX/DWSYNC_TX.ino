#include <dwsync.h>

#define PEROID         1000
#define PEROID2        3000

#define LED_CMD        0x01

/* Use Serial1 as ESP8266 communication. */
DW_SYNC sync(&Serial1);

void sync_rd_cb(DWSYN_PRTCL args)
{
  DWSYN_PRTCL dw = (DWSYN_PRTCL)args;
  switch (dw->cmd) {
    case LED_CMD:
      /* Do nothing. */
      break;
    default:
      break;
  }
}

void setup() {
  // put your setup code here, to run once:
  /* Use Serial as debug output. */
  Serial.begin(115200);
  Serial.println("Inited");
  
  /* Use Serial1 as ESP8266 communication. */
  Serial1.begin(115200);
  
  sync.read_cb.attach(sync_rd_cb);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint32_t prev;
  static uint8_t led_stat = 0;
  uint32_t now;
  
  now = millis();
  
  if (now - prev >= PEROID) {
    prev = now;
    sync.send(LED_CMD, &led_stat, 1);
    led_stat = !led_stat;
  }

  sync.process();
}
