# Security Locker using Atmega32

Hi there, this is a simple locker made using the **ATMEGA32** microcontroller, a project me and my team made as a graduation project for the Embedded Systems course by ITI Egypt on September 10th 2023.
The project is well organized, both for code and hardware design.
![Protues Design](PROTUES\design.BMP)

## How to use
You will need Proteus 8 or later to run the simulation, and make sure you install a [bluetooth library](https://www.theengineeringprojects.com/2016/03/bluetooth-library-for-proteus.html) for Proteus as well as installing [Eltima virtual Serial Port](https://www.eltima.com/products/vspdxp/). Run the **Virtual Serial Port Driver** and create a pair between 2 ports (COM1 and COM2 by default) then run the simulation in Proteus. You will be asked to set a password at first, then you can use all the functionalities of the safe.

## Features
* Easy to use interface.
* The ability to store a 4-digit pin.
* The password is stored on the internal storage of the MCU for extra security.
* Include a security alarm to deal with thiefs.
* The state of the locker is sent via bluetooth to the owner.

---
## This project was done by a team of 4:
1. Pierre Emad
2. Mahmoud Hossam
3. Hassan Sherif
4. Ibrahim Ayman
