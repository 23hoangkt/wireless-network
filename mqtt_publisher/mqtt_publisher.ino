//#include "DHT.h"
//#define DHTPIN 4     // Digital pin connected to the DHT sensor
//// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
//// Pin 15 can work but DHT must be disconnected during program upload.
//// Uncomment whatever type you're using!
////#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
////#define DHTTYPE DHT21   // DHT 21 (AM2301)
//// Connect pin 1 (on the left) of the sensor to +5V
//// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
//// to 3.3V instead of 5V!
//// Connect pin 2 of the sensor to whatever your DHTPIN is
//// Connect pin 4 (on the right) of the sensor to GROUND
//// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
//// Initialize DHT sensor.
//// Note that older versions of this library took an optional third parameter to
//// tweak the timings for faster processors.  This parameter is no longer needed
//// as the current DHT reading algorithm adjusts itself to work on faster procs.
//DHT dht(DHTPIN, DHTTYPE);
//void setup() {
//  Serial.begin(115200);
//  Serial.println(F("DHTxx test!"));
//  dht.begin();
//}
//void loop() {
//  // Wait a few seconds between measurements.
//  delay(2000);
//  // Reading temperature or humidity takes about 250 milliseconds!
//  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//  float h = dht.readHumidity();
//  // Read temperature as Celsius (the default)
//  float t = dht.readTemperature();
//  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = dht.readTemperature(true);
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t) || isnan(f)) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }
//  // Compute heat index in Fahrenheit (the default)
//  float hif = dht.computeHeatIndex(f, h);
//  // Compute heat index in Celsius (isFahreheit = false)
//  float hic = dht.computeHeatIndex(t, h, false);
//  Serial.print(F("Humidity: "));
//  Serial.print(h);
//  Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
//}



 
 
#include <WiFi.h>            /* WiFi library for ESP32 */
#include <Wire.h>
#include <PubSubClient.h>
#include "DHT.h"             /* DHT11 sensor library */

#define DHTPIN 4
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define wifi_ssid "HoangKT"
#define wifi_password "modiemoi1"
#define mqtt_server "192.168.138.195"

#define humidity_topic "sensor/DHT11/humidity"
#define temperature_celsius_topic "sensor/DHT11/temperature_celsius"
#define temperature_fahrenheit_topic "sensor/DHT11/temperature_fahrenheit"

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  // dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");

  if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void loop() {

      if (!client.connected()) {
        reconnect();
      }
      client.loop();

      // Wait a few seconds between measurements.
      delay(2000);

      // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
      float h = dht.readHumidity();
      // Read temperature as Celsius (the default)
      float t = dht.readTemperature();
      // Read temperature as Fahrenheit (isFahrenheit = true)
      float f = dht.readTemperature(true);

      // Check if any reads failed and exit early (to try again).
      if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
      }

      // Compute heat index in Fahrenheit (the default)
      float hif = dht.computeHeatIndex(f, h);
      // Compute heat index in Celsius (isFahreheit = false)
      float hic = dht.computeHeatIndex(t, h, false);
      Serial.print("Humidity: ");
      Serial.print(h);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(t);
      Serial.print(" *C ");
      Serial.print(f);
      Serial.print(" *F\t");
      Serial.print("Heat index: ");
      Serial.print(hic);
      Serial.print(" *C ");
      Serial.print(hif);
      Serial.println(" *F");

      Serial.print("Temperature in Celsius:");
      Serial.println(String(t).c_str());
      client.publish(temperature_celsius_topic, String(t).c_str(), true);

      Serial.print("Temperature in Fahrenheit:");
      Serial.println(String(f).c_str());
      client.publish(temperature_fahrenheit_topic, String(f).c_str(), true);

      Serial.print("Humidity:");
      Serial.println(String(h).c_str());
      client.publish(humidity_topic, String(h).c_str(), true);

}
