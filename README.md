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

Joystick is an input device. It consists of two potentiometers and a push button. The potentiometers indicate in whitch direction is the joystick being pushed. this device has five pins. three of whitch are inputs to Arduino, while the remaining two supply voltage (5 V) and ground. The graphic below shows the X and Y directions and also gives an indication of how the outputs will respond when the joystick is pushed in various directions.

![joystick](https://user-images.githubusercontent.com/99388270/205435527-94b1b353-9a05-48d7-9741-ecba4a571a7a.png)

**Digilent PmodCLP LCD module**

LCD is an electronic device which is used for display any ASCII text. Our screen size is 16x2 characters. This module has 18 pins. 8 pins are used for data transfer. 3 pins, whitch are internally conected,  supply voltage (5 V). 3 pins supply ground. These are also internally conected. And last 4 pins are for Register select, R/W, R/W enable and optional back-light enable.



## Software description

Put flowchats of your algorithm(s). Write descriptive text of your libraries and source files. Put direct links to these files in `src` or `lib` folders.

## Video

Insert a link to a short video with your practical implementation example (1-3 minutes, e.g. on YouTube).

## References

1. Write your text here.
2. ...
