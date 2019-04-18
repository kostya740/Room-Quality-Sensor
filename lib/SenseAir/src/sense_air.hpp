#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>

void s8_setup(SoftwareSerial& swSer);
void myread(SoftwareSerial& swSer, int n);
uint16_t ModRTU_CRC(byte* buf, int len);
uint16_t readco2(SoftwareSerial& swSer);
