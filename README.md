# IoT Home Automation Project

## Project Overview
This project focuses on building an IoT-based home automation system using the ESP8266 microcontroller. The system integrates sensors and actuators to automate home appliances, monitor environmental conditions, and enhance safety. The Blynk platform is utilized for seamless remote control and monitoring.

## Components Used
1. **ESP8266**: The core microcontroller for Wi-Fi connectivity and control.
2. **Relay Module**: To control appliances like lights, fans, and other devices.
3. **DHT11 Sensor**: For temperature and humidity monitoring.
4. **MQ2 Sensor**: For detecting gas leaks.
5. **Blynk Platform**: For creating a user-friendly mobile app interface.

## Features
- **Appliance Control**: Remotely control lights, fans, and other appliances via the Blynk app.
- **Environmental Monitoring**: Real-time display of temperature and humidity using the DHT11 sensor.
- **Safety Alerts**: Gas leak detection using the MQ2 sensor, with alerts sent to the user's smartphone.
- **Real-Time Data**: Data visualization on the Blynk dashboard for better insights.

## Circuit Diagram
The circuit involves connecting the ESP8266 with the following components:
- Relay module connected to GPIO pins to control appliances.
- DHT11 sensor connected to a digital pin for environmental data.
- MQ2 sensor connected to an analog or digital pin for gas detection.

## Software Requirements
1. **Arduino IDE**: For programming the ESP8266.
2. **Blynk Library**: For integrating with the Blynk platform.
3. **Wi-Fi Network**: For ESP8266 connectivity.

## Steps to Implement
1. **Hardware Setup**:
   - Connect the relay module, DHT11 sensor, and MQ2 sensor to the ESP8266 as per the circuit diagram.
2. **Blynk Configuration**:
   - Create a new project in the Blynk app and note the authentication token.
   - Add widgets for buttons, gauges, and notifications as needed.
3. **Programming the ESP8266**:
   - Install the required libraries in the Arduino IDE (ESP8266, Blynk, DHT, etc.).
   - Write the code to:
     - Connect to Wi-Fi.
     - Read data from sensors.
     - Control the relay module.
     - Send data to the Blynk app.
4. **Upload and Test**:
   - Upload the code to the ESP8266.
   - Test the system for appliance control, environmental monitoring, and safety alerts.

## Applications
- Smart home automation.
- Real-time environmental monitoring.
- Gas leak detection for enhanced safety.
