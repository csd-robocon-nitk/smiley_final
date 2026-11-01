#include "../include_all.hpp"

void timer_cb(){
    // Only send change in encoder ticks
    Encoder encoder;
    noInterrupts();
    encoder.enc_x = encx;
    encoder.enc_y = ency;
    encx = 0;
    ency = 0;
    interrupts();
    
    send_data(pack_data<BnoReading>(bnoreading, BNOREADING));
    send_data(pack_data<Encoder>(encoder, ENCODER));
}

BlitzTimer t1(timer_cb, 50);