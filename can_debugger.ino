#include <SPI.h>
#include <mcp2515.h>

//I am not using Interrup pin "default-D2" , dont connect.
#define CAN_CS_PIN 10
#define SERIAL_BAUD 115200

// Change this if your MCP2515 module crystal is 16 MHz , mine is 8 mhz.
#define MCP_CLOCK MCP_8MHZ

// Change this if the car CAN is not 500 kbps (you need to know which Can bus are you )
//                                            Comfort is often in Can B using 250 or less .
#define CAN_SPEED CAN_500KBPS

MCP2515 mcp2515(CAN_CS_PIN);
struct can_frame rxFrame;

void printHexByte(uint8_t v) {
  if (v < 0x10) Serial.print('0');
  Serial.print(v, HEX);
}

void printHexId(uint32_t id) {
  Serial.print(id, HEX);
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  SPI.begin();

  while (mcp2515.reset() != MCP2515::ERROR_OK) {
    delay(100);
  }

  while (mcp2515.setBitrate(CAN_SPEED, MCP_CLOCK) != MCP2515::ERROR_OK) {
    delay(100);
  }

  while (mcp2515.setNormalMode() != MCP2515::ERROR_OK) {
    delay(100);
  }
}

void loop() {
  if (mcp2515.readMessage(&rxFrame) == MCP2515::ERROR_OK) {
    uint32_t canId;

    if (rxFrame.can_id & CAN_EFF_FLAG) {
      canId = rxFrame.can_id & CAN_EFF_MASK;
    } else {
      canId = rxFrame.can_id & CAN_SFF_MASK;
    }

    printHexId(canId);
    Serial.print(',');
    Serial.print(rxFrame.can_dlc);

    for (uint8_t i = 0; i < 8; i++) {
      Serial.print(',');
      if (i < rxFrame.can_dlc) {
        printHexByte(rxFrame.data[i]);
      } else {
        Serial.print("00");
      }
    }

    Serial.println();
  }
}