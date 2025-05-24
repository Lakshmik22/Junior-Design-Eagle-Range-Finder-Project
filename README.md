# Junior-Design-Eagle-Range-Finder-Project

This project is a prototype developed as part of a Junior Design course. It integrates several hardware and software components using the **MSP430G2553** microcontroller to demonstrate LED brightness control, ultrasonic distance measurement, and real-time display via an LCD. The system combines sensor data and user input to interactively update display values and outputs.

---

## 🛠 Features

- **LED Blinking and Brightness Control**  
  Uses GPIO to blink an LED and modulates brightness based on potentiometer input.

- **LCD Display**  
  Displays static strings, sensor readings, and duty cycle percentage using a 16x2 LCD connected over I2C.

- **Ultrasonic Sensor Integration**  
  Measures distance in mm and inches using ultrasonic trigger and echo pins, then displays formatted output.

- **Real-Time Duty Cycle Feedback**  
  Uses ADC to read potentiometer voltage and calculate/display a corresponding duty cycle percentage.

---

## 🧰 Hardware Used

- **MSP430G2553 LaunchPad**
- **Ultrasonic Distance Sensor**
- **16x2 I2C LCD Display**
- **Potentiometer**
- **2 LEDs with Resistors**
- **Breadboard and Jumper Wires**
- **MOSFET (for LED switching)**

---

## 🧾 Dependencies

- Code Composer Studio (CCS)
- `Junior_Design.h` – Custom header for hardware setup and display functions
- LCD and ADC libraries included in project

