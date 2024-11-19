# stepperSMI
Taking an input from serial monitor from the user to operate stepper's speed,no. of revolution and direction
# Arduino Stepper Motor Controller
This project is an Arduino-based stepper motor controller that takes commands over the serial port to move a stepper motor. The program allows you to control the direction, number of revolutions, and speed of the motor.

# Features
Direction Control: Move the motor up or down based on serial input.
Speed Adjustment: Change the delay between steps to adjust motor speed.
Revolution Control: Specify how many revolutions the motor should complete.
How It Works
The Arduino listens for serial input in this format:
10up100

10: Number of revolutions (e.g., 10 revolutions).
up: Direction of movement (up for forward, dn for reverse).
100: Delay in microseconds between steps (smaller values = faster speed).
Based on the input, the program calculates the total number of steps (steps = steps_per_revolution * revolutions) and moves the motor accordingly.

The direction pin is set based on the up or dn command.

# Hardware Setup
Connect your stepper motor's driver to the Arduino pins as follows:

Step Pin: Pin 6
Direction Pin: Pin 5
Ensure the motor driver and Arduino share the same ground.

# Code Overview
The main parts of the code include:

Setup (setup() function): Initializes serial communication and sets up pin modes for stepPin and dirPin.
Loop (loop() function): Continuously checks for new serial data, parses the command, and moves the motor based on the input.
Key Variables
stepPin: Controls the stepping of the motor.
dirPin: Sets the direction (forward or reverse).
step_mode: Number of steps per revolution (default is 3200 for a 16-microstep driver).
Sample Input
Here’s an example input you can send via the Arduino Serial Monitor:
5up200

This moves the motor 5 revolutions in the up direction with a delay of 200 microseconds per step.
How to Use
Connect your Arduino to a computer and upload the code.
Open the Serial Monitor (set to 9600 baud).
Enter commands in the specified format and hit send.
Watch your stepper motor come to life!
Notes
Ensure your power supply can handle the current requirements of the stepper motor.
If you’re using a different stepper motor driver, adjust the step_mode variable accordingly.
Input validation is minimal, so make sure your commands are formatted correctly.
