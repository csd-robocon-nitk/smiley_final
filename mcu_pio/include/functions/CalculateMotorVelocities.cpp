// Sign matrix for our smiley bot special case (omni drive made differential drive)
// TODO: Sit with bot and fix sign matrix
float sign_matrix[4][3] = {
    { 1.0,   1.0,  1.0},   // Motor 1 (Front-Left)
    { 1.0,   1.0,  1.0},   // Motor 2 (Front-Right)
    { 1.0,  -1.0,  1.0},   // Motor 3 (Back-Left)
    { 1.0,  -1.0,  1.0}    // Motor 4 (Back-Right)
};

// Convert vx, vy, vw to individual motor PWM values
Pwm calculateMotorVelocities(Velocity vel) {
    Pwm motors;
    
    // Create velocity vector [vx, vy, w]
    float velocity_vector[3][1] = {
        {vel.vx},
        {vel.vy},
        {vel.vw}
    };

    // Result matrix for motor velocities
    float motor_velocity_matrix[4][1];

    // Matrix multiplication: motor_velocity_matrix = sign_matrix × velocity_vector
    for (int i = 0; i < 4; i++) {
        motor_velocity_matrix[i][0] = 0;
        for (int j = 0; j < 3; j++)
            motor_velocity_matrix[i][0] += sign_matrix[i][j] * velocity_vector[j][0];
    }

    // Store calculated velocities in struct
    motors.m1 = motor_velocity_matrix[0][0];
    motors.m2 = motor_velocity_matrix[1][0];
    motors.m3 = motor_velocity_matrix[2][0];
    motors.m4 = motor_velocity_matrix[3][0];
    
    return motors;
}