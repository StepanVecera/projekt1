# Project 1

Application of analog joy-stick (2 ADC channels, 1 push button), rotary encoder, and Digilent PmodCLP LCD module.

## Instructions

The goal of the project is cooperation in pairs, further study of the topic, design of own solutions, implementation, creation of project documentation and presentation of results. The division of roles and tasks within the team is up to their members.

* Students work on a project in the labs during the 10th and 11th weeks of the semester.

* Through the BUT e-learning, students submit a link to the GitHub repository, which contains the complete project in PlatfomIO and a descriptive README file. The submission deadline is the day before the next laboratory, i.e. in 2 weeks.

* The source code for the AVR must be written in C and/or Assembly and must be implementable on Arduino Uno board using toolchains from the semester, ie PlatformIO and not the Arduino-style. No other development tools are allowed.

## Recommended GitHub repository structure

   ```c
   YOUR_PROJECT        // PlatfomIO project
   ├── include         // Included files
   ├── lib             // Libraries
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   ├── platformio.ini  // Project Configuration File
   └── README.md       // Report of this project
   ```

## Recommended README.md file structure

### Team members

*  Šimon Buchta (coding, )
*  Štěpán Večeřa (coding, )

## Hardware description
**joystick**

Joystick is an input device. It consists of two potentiometers and a push button. The potentiometers indicate in whitch direction is the joystick being pushed. this device has five pins. three of whitch are inputs to Arduino, while the remaining two supply voltage (5 V) and ground. The graphic below shows the X and Y directions and also gives an indication of how the outputs will respond when the joystick is pushed in various directions. In our project, we use joystick to move around LCD screen.

![joystick](https://user-images.githubusercontent.com/99388270/205435527-94b1b353-9a05-48d7-9741-ecba4a571a7a.png)

**Digilent PmodCLP LCD module**

LCD is an electronic device which is used for display any ASCII text. Our screen size is 16x2 characters. This module has 18 pins. 8 pins are used for data transfer. 3 pins, whitch are internally conected,  supply voltage (5 V). 3 pins supply ground. These are also internally conected. And last 4 pins are for Register select, R/W, R/W enable and optional back-light enable. We can use PmodCLP reference manual [4](https://digilent.com/reference/_media/pmod:pmod:pmodCLP_rm.pdf) to locate these pins. In our project, we use this module to display text.

**Rotary encoder**
A rotary encoder is a type of position sensor that converts the angular position (rotation) of a knob into an output signal that is used to determine which direction the knob is being turned. Rotary encoders are the modern digital equivalent of potentiometers. There are five pins on our module. Voltage supply pin (5 V), ground pin, SW pin,  witch is switch output, CLK and  DT pins. The last two mentioned pins are the important pins, whitch we use to determine direction of rotation and also by how many positions we moved the encoder. The explenation of how rotary encoder works is in reference [5](https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/)


## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. [Arduino pinout](https://docs.arduino.cc/static/6ec5e4c2a6c0e9e46389d4f6dc924073/2f891/Pinout-UNOrev3_latest.png)
2. [ATmega 328 Datasheet](https://www.microchip.com/en-us/product/ATmega328p)
3. [Joystick](https://components101.com/sites/default/files/component_datasheet/Joystick%20Module.pdf)
4. [PmodCLP reference manual](https://digilent.com/reference/_media/pmod:pmod:pmodCLP_rm.pdf)
5. [Rotary encoder](https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/)
