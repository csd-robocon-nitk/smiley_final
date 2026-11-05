from robot_interfaces.msg import Velocity, BnoReading, Encoder
from blitz import Blitz

blitz_interfaces = {str : Blitz}

# Blitz interfaces for communication btw rpi and pico (mcu_pio)
# To mcu: Velocity
# From mcu: Encoder, BnoReading
blitz_interfaces = {

    "BnoReading": Blitz(
        topic="/bno",
        msg_id=1,
        struct_fmt="ff",
        fields=["current_angle","refer_angle"],
        ros_msg=BnoReading,
        from_mcu=True
    ),

    "Encoder": Blitz(
        topic="/encoder",
        msg_id=2,
        struct_fmt="hh",
        fields=["enc_x", "enc_y"],
        ros_msg=Encoder,
        from_mcu=True
    ),

    "Velocity": Blitz(
        topic="/cmd_vel",
        msg_id=5,
        struct_fmt="fff",
        fields=["vx", "vy", "vw"],
        ros_msg=Velocity,
        from_mcu=False
    ),
}
