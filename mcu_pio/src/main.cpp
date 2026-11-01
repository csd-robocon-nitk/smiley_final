#include "include_all.hpp"

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);
sensors_event_t event;

void setup() {
  Serial.begin(115200);
  Wire.setSDA(Sda);
  Wire.setSCL(Scl);
  Wire.begin();
  delay(10);

  // Start encoders
  initEncoders();

  // Start bno
  if(!bno.begin()) while(1); // Set a better debug mechanism for this later
  bno.setExtCrystalUse(true);

  for(int i = 0; i < 10; i++) bno.getEvent(&event);
  bnoreading.refer_angle = event.orientation.x;

  // The BTS7960 objects are constructed globally, before the Arduino core
  // finishes startup. Reconfigure their PWM pins here so they are definitely
  // outputs before the first setSpeed() call.
  pinMode(M1_LPWM, OUTPUT);
  pinMode(M1_RPWM, OUTPUT);
  pinMode(M2_LPWM, OUTPUT);
  pinMode(M2_RPWM, OUTPUT);
  pinMode(M3_LPWM, OUTPUT);
  pinMode(M3_RPWM, OUTPUT);
  pinMode(M4_LPWM, OUTPUT);
  pinMode(M4_RPWM, OUTPUT);
}

void loop() {
  std::vector<uint8_t> payload;
  do {
    payload = receive_data();
    if(!payload.empty()) store_data(payload);
  } while(!payload.empty());

  //Calculate motor velocities from vx, vy, vw and actuate motors
  Pwm PwmVals = calculateMotorVelocities(velocity);
  setMotorSpeeds(PwmVals);

  bno.getEvent(&event);
  bnoreading.current_angle = event.orientation.x;

  delay(10);
  t1.spin();
}
