#include <HardwareSerial.h>

// Khởi tạo Serial2 cho giao tiếp với SIM800L
HardwareSerial SIM800(2);

void setup() {
  // Khởi động serial monitor
  Serial.begin(115200);
  
  // Khởi động Serial2 với baudrate 9600
  SIM800.begin(9600, SERIAL_8N1, 16, 17); // GPIO 16 -> RX, GPIO 17 -> TX
  
  // Đợi để khởi động
  delay(3000);
  
  // Gửi lệnh AT để kiểm tra kết nối với SIM800L
  sendATCommand("AT");
  sendATCommand("AT+CSQ");  // Kiểm tra cường độ tín hiệu
  sendATCommand("AT+CCID"); // Kiểm tra mã thẻ SIM
  sendATCommand("AT+CREG?");// Kiểm tra trạng thái đăng ký mạng
  sendATCommand("ATI");     // Nhận thông tin module
  sendATCommand("AT+CBC");  // Kiểm tra pin
}

void loop() {
  // Liên tục kiểm tra phản hồi từ SIM800L và in ra serial monitor
  updateSerial();
}

void sendATCommand(const char* cmd) {
  SIM800.println(cmd);
  delay(1000);
  updateSerial();
}

void updateSerial() {
  while (SIM800.available()) {
    Serial.write(SIM800.read());
  }
  while (Serial.available()) {
    SIM800.write(Serial.read());
  }
}
