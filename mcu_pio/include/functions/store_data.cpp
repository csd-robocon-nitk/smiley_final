// takes raw byte array, matches the interface and parses the data
void store_data(std::vector<uint8_t> payload) {
    if (!payload.empty()) {
        // find id
        uint8_t id = payload[0];
        // Parse Velocity commands from ROS (main drive)
        if (id == VELOCITY) velocity = parse_struct<Velocity>(payload);
    }
}