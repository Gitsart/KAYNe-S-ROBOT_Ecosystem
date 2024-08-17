#include <WiFi.h>
#define LED 13
#define LED1 2
const char* ssid = "Vaishak M";
const char* pass = "03101997";


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode (LED, OUTPUT);
  pinMode (LED1, OUTPUT);
  Serial.begin (115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  /* xTaskCreatePinnedToCore (
     loop2,     // Function to implement the task
     "loop2",   // Name of the task
     1000,      // Stack size in bytes
     NULL,      // Task input parameter
     0,         // Priority of the task
     NULL,      // Task handle.
     0          // Core where the task should run );*/
  xTaskCreatePinnedToCore(loop2, "loop2", 1000, NULL, 1, NULL, 0);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite (LED1, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay (1000);  // wait for a second
  digitalWrite (LED1, LOW); // turn the LED off by making the voltage LOW
  delay (1000);  // wait for a second
  Serial.print("CORE:"); Serial.println(xPortGetCoreID());
}

// the loop2 function also runs forver but as a parallel task
void loop2 (void* pvParameters) {
  while (WiFi.status() == WL_CONNECTED) {
    digitalWrite (LED, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay (100);  // wait for a second
    digitalWrite (LED, LOW); // turn the LED off by making the voltage LOW
    delay (100);

    Serial.print("WiFiCore"); Serial.println(xPortGetCoreID());

  }
}
