This project is by Sean LaNeave.

I'm going to give a quick overview of the project. The main goal is to create a toy using a buzzer and an LED.

To compile the program, type "make" into the command terminal, and then type "make load" to load the program onto the MSP430.

Once the program is loaded onto the MSP430, the initial state sets up all the buttons to manipulate the buzzer. 
If you press the button on the left side of the MSP430, it will switch the state of the machine, and the red light will turn on, indicating that you have switched states. 
The new state configures all four buttons to manipulate the green LED in different ways.
