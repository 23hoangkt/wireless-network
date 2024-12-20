////#include <WiFi.h>
////#include <PubSubClient.h>
////
////#define wifi_ssid "P510"
////#define wifi_password "12345678q"
////#define mqtt_server "192.168.1.16"  // Địa chỉ của MQTT broker
////
////WiFiClient espClient;
////PubSubClient client(espClient);
////
////// Các topic cần subscribe
////#define humidity_topic "sensor/DHT11/humidity"
////#define temperature_celsius_topic "sensor/DHT11/temperature_celsius"
////#define temperature_fahrenheit_topic "sensor/DHT11/temperature_fahrenheit"
////
////void setup() {
////  Serial.begin(115200);
////  setup_wifi();
////  client.setServer(mqtt_server, 1883);
////  client.setCallback(mqtt_callback); // Đăng ký hàm callback khi nhận dữ liệu
////}
////
////void setup_wifi() {
////  delay(10);
////  // Kết nối WiFi
////  Serial.println();
////  Serial.print("Connecting to ");
////  Serial.println(wifi_ssid);
////
////  WiFi.begin(wifi_ssid, wifi_password);
////
////  while (WiFi.status() != WL_CONNECTED) {
////    delay(500);
////    Serial.print(".");
////  }
////
////  Serial.println("");
////  Serial.println("WiFi connected");
////  Serial.println("IP address: ");
////  Serial.println(WiFi.localIP());
////}
////
////void reconnect() {
////  while (!client.connected()) {
////    Serial.print("Attempting MQTT connection...");
////    if (client.connect("ESP32Subscriber")) {
////      Serial.println("connected");
////      // Đăng ký vào các topic
////      client.subscribe(humidity_topic);
////      client.subscribe(temperature_celsius_topic);
////      client.subscribe(temperature_fahrenheit_topic);
////    } else {
////      Serial.print("failed, rc=");
////      Serial.print(client.state());
////      Serial.println(" try again in 5 seconds");
////      delay(5000);
////    }
////  }
////}
////
////void mqtt_callback(char* topic, byte* payload, unsigned int length) {
////  Serial.print("Message arrived [");
////  Serial.print(topic);
////  Serial.print("] ");
////  String message = "";
////  
////  for (int i = 0; i < length; i++) {
////    message += (char)payload[i];
////  }
////  Serial.println(message);
////
////  // Xử lý dữ liệu tùy theo topic
////  if (String(topic) == humidity_topic) {
////    Serial.print("Humidity: ");
////    Serial.println(message);
////  } else if (String(topic) == temperature_celsius_topic) {
////    Serial.print("Temperature (Celsius): ");
////    Serial.println(message);
////  } else if (String(topic) == temperature_fahrenheit_topic) {
////    Serial.print("Temperature (Fahrenheit): ");
////    Serial.println(message);
////  }
////}
////
////void loop() {
////  if (!client.connected()) {
////    reconnect();
////  }
////  client.loop();
////}
//
//
//
//
//
//#include <Wire.h>
//#include <WiFi.h>
//#include <PubSubClient.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
//
//#define SCREEN_WIDTH 128
//#define SCREEN_HEIGHT 64
//#define OLED_RESET -1
//
//#define wifi_ssid "HoangKT"
//#define wifi_password "modiemoi1"
//#define mqtt_server "192.168.138.195"  // Địa chỉ của MQTT broker
//
//WiFiClient espClient;
//PubSubClient client(espClient);
//
//// Các topic cần subscribe
//#define humidity_topic "sensor/DHT11/humidity"
//#define temperature_celsius_topic "sensor/DHT11/temperature_celsius"
//#define temperature_fahrenheit_topic "sensor/DHT11/temperature_fahrenheit"
//
//// Khai báo màn hình OLED
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//
//void setup() {
//  Serial.begin(115200);
//  setup_wifi();
//  client.setServer(mqtt_server, 1883);
//  client.setCallback(mqtt_callback); // Đăng ký hàm callback khi nhận dữ liệu
//
//  // Khởi tạo màn hình OLED
//  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
//    Serial.println(F("Không thể khởi tạo màn hình OLED!"));
//    while (true);
//  }
//  display.clearDisplay();
//  display.setTextSize(1);      
//  display.setTextColor(SSD1306_WHITE);  
//  display.setCursor(0, 0);     
//  display.print(F("Connecting WiFi..."));
//  display.display();
//}
//
//void setup_wifi() {
//  delay(10);
//  // Kết nối WiFi
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(wifi_ssid);
//
//  WiFi.begin(wifi_ssid, wifi_password);
//
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//}
//
//void reconnect() {
//  while (!client.connected()) {
//    Serial.print("Attempting MQTT connection...");
//    if (client.connect("ESP32Subscriber")) {
//      Serial.println("connected");
//      // Đăng ký vào các topic
//      client.subscribe(humidity_topic);
//      client.subscribe(temperature_celsius_topic);
//      client.subscribe(temperature_fahrenheit_topic);
//    } else {
//      Serial.print("failed, rc=");
//      Serial.print(client.state());
//      Serial.println(" try again in 5 seconds");
//      delay(5000);
//    }
//  }
//}
//
//void mqtt_callback(char* topic, byte* payload, unsigned int length) {
//  Serial.print("Message arrived [");
//  Serial.print(topic);
//  Serial.print("] ");
//  String message = "";
//  
//  for (int i = 0; i < length; i++) {
//    message += (char)payload[i];
//  }
//  Serial.println(message);
//
//  // Hiển thị dữ liệu lên màn hình SSD1306
//  display.clearDisplay(); // Xóa màn hình trước khi in mới
//  display.setCursor(0, 0);
//
//  // Xử lý dữ liệu tùy theo topic và in ra màn hình
//  if (String(topic) == humidity_topic) {
//    display.print("Humidity: ");
//    display.println(message);
//  } else if (String(topic) == temperature_celsius_topic) {
//    display.print("Temp (C): ");
//    display.println(message);
//  } else if (String(topic) == temperature_fahrenheit_topic) {
//    display.print("Temp (F): ");
//    display.println(message);
//  }
//
//  display.display(); // Cập nhật màn hình
//}
//
//void loop() {
//  if (!client.connected()) {
//    reconnect();
//  }
//  client.loop();
//}













#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define wifi_ssid "HoangKT"
#define wifi_password "modiemoi1"
#define mqtt_server "192.168.138.195"  // MQTT broker

WiFiClient espClient;
PubSubClient client(espClient);

// MQTT Topics
#define humidity_topic "sensor/DHT11/humidity"
#define temperature_celsius_topic "sensor/DHT11/temperature_celsius"
#define temperature_fahrenheit_topic "sensor/DHT11/temperature_fahrenheit"
#define flame_sensor_topic "sensor/FIRE/flame"
#define mq2_gas_sensor_topic "sensor/GAS/mq2_gas"

// SIM Module
#define SIM_TX 17
#define SIM_RX 16
#include <HardwareSerial.h>
// #define simSerial Serial2
HardwareSerial sim800(2); // Sử dụng UART2: TX = GPIO 17, RX = GPIO 16

// OLED Display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
String lastTopic = "";
String lastMessage = "";

// Giá trị hiển thị trên màn hình
String humidity = "0 %";
String tempC = "0.0 C";
String tempF = "0.0 F";
String flame = "No flame";
String gas = "No gas";

void setup() {
  Serial.begin(115200);
  sim800.begin(115200, SERIAL_8N1, SIM_RX, SIM_TX);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqtt_callback);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed!"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Connecting WiFi..."));
  display.display();
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);
  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Subscriber")) {
      Serial.println("connected");
      client.subscribe(humidity_topic);
      client.subscribe(temperature_celsius_topic);
      client.subscribe(temperature_fahrenheit_topic);
      client.subscribe(flame_sensor_topic);
      client.subscribe(mq2_gas_sensor_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


// Hàm hiển thị dữ liệu lên màn hình OLED
void displayData() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Humid: ");
  display.println(humidity);

  display.setCursor(0, 12);
  display.print("Temp(C): ");
  display.println(tempC);

  display.setCursor(0, 24);
  display.print("Temp(F): ");
  display.println(tempF);

  display.setCursor(0, 36);
  display.print("Fire: ");
  display.println(flame);

  display.setCursor(0, 48);
  display.print("Gas: ");
  display.println(gas);

  display.display();
}

// Hàm xử lý dữ liệu MQTT (bao gồm cả phần gửi tin nhắn)
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == humidity_topic) {
    humidity = message + " %";
    Serial.println("Humidity:");
    Serial.println(message);
  }
  if (String(topic) == temperature_celsius_topic) {
    tempC = message + " C";
    Serial.println("Temp (C):");
    Serial.println(message);
  }
  if (String(topic) == temperature_fahrenheit_topic) {
    tempF = message + " F";
    Serial.println("Temp (F):");
    Serial.println(message);
  }
  if (String(topic) == flame_sensor_topic) {
    flame = message;
    Serial.println("NO FIRE!!!");
    if (message == "Flame detected") {
      send_sms("0974039288", "ALERT: Flame detected at your location!");
      Serial.println("FIRE!!!");
    }
  }
  if (String(topic) == mq2_gas_sensor_topic) {
    gas = message;
    Serial.println("NO GAS!!!");
    if (message == "GAS detected") {
      send_sms("0974039288", "ALERT: Gas leaked at your location!");
      Serial.println("GAS!!!");
    }
  }

  displayData(); // Cập nhật hiển thị khi có dữ liệu mới
}
void waitForResponse() {
  unsigned long startTime = millis();
  while (millis() - startTime < 50000) { // Chờ tối đa 5 giây
    if (sim800.available()) {
      String response = sim800.readString();
      Serial.println("Phản hồi từ module: " + response);
      if (response.indexOf("OK") != -1 || response.indexOf(">") != -1) {
        return; // Nếu nhận được OK hoặc dấu nhắc ">", thoát hàm
      }
    }
  }
  Serial.println("Không nhận được phản hồi từ module.");
}
void send_sms(const char* number, const char* text) {
  sim800.println("AT"); // Kiểm tra kết nối với module
  delay(1000);
  waitForResponse();

  sim800.println("AT+CMGF=1"); // Chế độ tin nhắn văn bản
  delay(1000);
  waitForResponse();

  sim800.print("AT+CMGS=\""); // Bắt đầu gửi tin nhắn
  sim800.print(number);
  sim800.println("\"");
  delay(1000);
  waitForResponse();

  sim800.print(text); // Nội dung tin nhắn
  delay(1000);
  sim800.write(26); // Ký tự kết thúc tin nhắn (Ctrl+Z)
  delay(5000);

  Serial.println("Tin nhắn đã được gửi!");
}

unsigned long previousMillis = 0;
const long interval = 100;  // Thời gian chờ giữa các lần cập nhật


void loop() {
  unsigned long currentMillis = millis();

  // Nếu không kết nối MQTT, thực hiện kết nối lại
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Chỉ thực hiện công việc cập nhật sau mỗi khoảng thời gian nhất định
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Cập nhật thời gian mới nhất

    // Cập nhật màn hình OLED, kiểm tra và hiển thị dữ liệu
    displayData();
  }

  // Các tác vụ khác có thể thực hiện ở đây mà không bị trì hoãn
}
