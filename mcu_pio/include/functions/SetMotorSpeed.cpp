//Using the MDLib
void setMotorSpeeds(Pwm pwm) {
    motor1.setSpeed(pwm.m1);
    motor2.setSpeed(pwm.m2);
    motor3.setSpeed(pwm.m3);
    motor4.setSpeed(pwm.m4);
}

// Set motor speeds using PWM values
// Motors 1 & 4: Use DIR + PWM pins
// Motors 2 & 3: Use LPWM + RPWM pins (H-bridge)
// void setMotorSpeeds(Pwm pwm) {
//     int v11 = constrain(pwm.m1, -255, 255);
//     int v22 = constrain(pwm.m2, -255, 255);
//     int v33 = constrain(pwm.m3, -255, 255);
//     int v44 = constrain(pwm.m4, -255, 255);

//     // Motor 1 (LPWM + RPWM)
//     if (pwm.m1 < 0) {
//         analogWrite(M1_LPWM, 0);
//         analogWrite(M1_RPWM, abs(v11));
//     } else if (pwm.m1 > 0) {
//         analogWrite(M1_LPWM, abs(v11));
//         analogWrite(M1_RPWM, 0);
//     } else {
//         analogWrite(M1_RPWM, 0);
//         analogWrite(M1_LPWM, 0);
//     }
  
//     // Motor 2 (LPWM + RPWM)
//     if (pwm.m2 < 0) {
//         analogWrite(M2_LPWM, 0);
//         analogWrite(M2_RPWM, abs(v22));
//     } else if (pwm.m2 > 0) {
//         analogWrite(M2_LPWM, abs(v22));
//         analogWrite(M2_RPWM, 0);
//     } else {
//         analogWrite(M2_RPWM, 0);
//         analogWrite(M2_LPWM, 0);
//     }
  
//     // Motor 3 (LPWM + RPWM)
//     if (pwm.m3 < 0) {
//         digitalWrite(M3_LPWM, 0);
//         analogWrite(M3_RPWM, abs(v33));
//     } else if (pwm.m3 > 0) {
//         analogWrite(M3_LPWM, abs(v33));
//         analogWrite(M3_RPWM, 0);
//     } else {
//         analogWrite(M3_LPWM, 0);
//         analogWrite(M3_RPWM, 0);
//     }
  
//     // Motor 4 (LPWM + RPWM)
//     if (pwm.m4 < 0) {
//         analogWrite(M4_LPWM, 0);
//         analogWrite(M4_RPWM, abs(v44));
//     } else if (pwm.m4 > 0) {
//         analogWrite(M4_LPWM, abs(v44));
//         analogWrite(M4_RPWM, 0);
//     } else {
//         analogWrite(M4_RPWM, 0);
//         analogWrite(M4_LPWM, 0);
//     }
// }