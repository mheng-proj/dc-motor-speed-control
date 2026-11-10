# dc-motor-speed-control
It calculates the speed of the motor and adjusts to the wanted speed. I built it to understand if power perfectly correlates with speed.

# Components Used

- Any Arduino/ Arduino-like Model
- Yellow TT Motor
- IR speed sensor
- Code Wheel/Slot disc
- Battery
- Jumper Wires

# How It Works

The Code Wheel/Slot disc is inserted into the white stick that stick out of the Yellow TT Motor. The Code Wheel/Slot disc is then rotated on top of the IR speed sensor as the motor rotates being connected to a battery.

# Challenges Encountered

Problem 1: Speed Change

Issue: The speed change is too slow

Cause: My code only plus 1 and minus 1 to the designated speed that the user inputs.

Solution: Depending on the value of the rpm entered. I entered the different values of pwm using if conditions. The pwm values are correlated with the table.

# Testing and Results

Check Table.jpg

# What I Learned

I was able to understand how different components respond to each other based on feedback systems.

