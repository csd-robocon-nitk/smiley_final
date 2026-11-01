#include "include_all.hpp"

// x4 encoder reader, gives 4 times PPR

static int8_t lookup_table[16] = {
    0, -1,  1,  0,
    1,  0,  0, -1,
   -1,  0,  0,  1,
    0,  1, -1,  0
};

volatile uint8_t pre_X_state = 0;
volatile uint8_t pre_Y_state = 0;

// ISR for X axis encoder
void readEncoderX() {
    // Read state of channel A and B together as a two bit number
    uint8_t curr = (digitalRead(XENC_A) << 1) | digitalRead(XENC_B);   
    // Check transition btw previous and current state as a 4 bit number - PREVA PREVB CURRA CURRB
    uint8_t idx = (pre_X_state << 2) | curr; 

    encx += lookup_table[idx];
    pre_X_state = curr;
}

// ISR for Y axis encoder
void readEncoderY() {
    uint8_t curr = (digitalRead(YENC_A) << 1) | digitalRead(YENC_B);
    uint8_t idx = (pre_Y_state << 2) | curr;

    ency += lookup_table[idx];
    pre_Y_state = curr;
}

// Initialize encoder pins and attach interrupts
void initEncoders() {
    pinMode(XENC_A, INPUT_PULLUP);
    pinMode(XENC_B, INPUT_PULLUP);
    pinMode(YENC_A, INPUT_PULLUP);
    pinMode(YENC_B, INPUT_PULLUP);

    // Capture initial state of channels
    pre_X_state = (digitalRead(XENC_A) << 1) | digitalRead(XENC_B);
    pre_Y_state = (digitalRead(YENC_A) << 1) | digitalRead(YENC_B);

    attachInterrupt(digitalPinToInterrupt(XENC_A), readEncoderX, CHANGE);
    attachInterrupt(digitalPinToInterrupt(XENC_B), readEncoderX, CHANGE);
    attachInterrupt(digitalPinToInterrupt(YENC_A), readEncoderY, CHANGE);
    attachInterrupt(digitalPinToInterrupt(YENC_B), readEncoderY, CHANGE);
}