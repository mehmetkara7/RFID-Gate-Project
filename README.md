# RFID-Gate--Project
This project aims to create a security gate using Arduino and RFID (Radio-Frequency Identification) technology. The project identifies authorized RFID cards and opens a gate through a servo motor. It also detects unauthorized entries and provides an alert.

## Requirements

To build and run this project, you will need the following components:
- Arduino board
- RC522 RFID module
- Servo motor
- Buzzer (for audible alerts)
- Authorized RFID cards

## Circuit Diagram

You can view the project's circuit diagram:![rfid_project_bb](https://github.com/mehmetkara7/RFID-Gate--Project/assets/76877886/a9e06515-939a-40ed-a8fd-2f1cab1630d7)


## Usage

To run the project, upload the code using the Arduino IDE. Add your authorized RFID cards to the `ID` and `ID1` arrays. When recognized, the gate will open. An alert will be triggered if an unauthorized card is used.
