# dc-motor-speed-control
It calculates the speed of a motor and adjusts it to reach the desired speed. I built this project to understand whether electrical power and motor speed are perfectly correlated.

# Components Used

- Any Arduino/ Arduino-like Model
- Yellow TT Motor
- IR speed sensor
- Code Wheel/Slot disc
- Battery
- Jumper Wires

# How It Works

The Code Wheel / Slotted Disc is attached to the white shaft sticking out of the Yellow TT Motor. As the motor rotates, the disc spins above the IR speed sensor, which detects the slots and generates signals.

The Arduino uses these signals to calculate the motor's RPM. It then compares the measured RPM with the desired speed and adjusts the PWM input to regulate the motor.

# Challenges Encountered

Problem 1: Slow Speed Adjustment

Issue: The motor took too long to reach the desired speed.

Cause: My initial code only increased or decreased the PWM value by one unit at a time.

Solution: Depending on the desired RPM entered by the user, I used if conditions to assign different PWM values. These PWM values are correlated with the results in the table.

# Testing and Results

Check Table.jpg

# What I Learned
I was able to understand how different components respond to each other in a feedback control system. I also learned how PWM affects motor speed and how RPM measurements can be used to regulate it.

