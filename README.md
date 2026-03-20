**Agrobot Sensor System**

**Overview**

This project simulates the electronics subsystem of an IoT-based agricultural robot using the Wokwi online simulator. It integrates multiple environmental and soil sensors with an ESP32 microcontroller to monitor soil health parameters and support automated irrigation logic.

The repository contains all simulation files, circuit setup, and firmware used for testing sensor interfacing and control workflows in a virtual environment.

System Architecture

**Sensors Used**

* Soil Moisture Sensor — soil water content
* pH Sensor — soil acidity/alkalinity
* NPK Sensor — soil nutrient levels
* DHT22 Sensor — digital temperature and humidity sensor

**Controller**

* ESP32 (ADC-based data acquisition + control logic)

**Simulation Platform**

* Wokwi IoT Simulator

---

## Features

* Multi-sensor data acquisition using ESP32 ADC and digital pins
* Real-time sensor value monitoring via serial output
* Threshold-based irrigation control logic
* Modular firmware structure for easy sensor expansion
* Fully virtual prototyping (no physical hardware required)



## How to Run the Simulation

1. Upload the provided project files.
2. Start the simulation.
3. Use virtual controls to vary sensor inputs.
4. Open the Serial Monitor to observe sensor readings.
5. Verify irrigation/control responses based on thresholds.

---

##  What Was Tested

* Correct sensor signal acquisition
* ADC reading accuracy
* Data sampling and serial logging
* Control logic trigger conditions
* End-to-end embedded workflow in simulation

## Application

Designed as part of an agricultural robotics system for:

* Soil health monitoring
* Precision irrigation
* Smart farming automation
* Weed Detection


## Future Improvements

* Physical hardware prototype
* Cloud data logging (MQTT/IoT platform)
* Mobile/Web dashboard
* Advanced data analytics



