# Bosch XDK DataLogger

> Author: [Krzysztof Wilczynski](https://www.linkedin.com/in/3sztof/)

## About

Software for Bosch XDK realtime prototyping platform. Written in Eclipse Mita (which directly translates to C project for the freeRTOS platform).

## Functionality

Logs the sensor data: accelerometer X, Y, Z and pressure to a csv file stored on the microSD card. Additionally, the information about the data acquisition cycle number is stored within a binary file (.cycle.xdk) to support continuous writing to a data file (CollectedData.csv) with cycle number persistance between the system reboots.

## Usage

To begin data acquisition:

- Make sure the microSD card (FAT32 data format) is inserted into the XDK
- Power on the XDK
- Wait for the boot sequence to complete (approx. 4 seconds)
- A red diode indicates that the device is not recording data - ready for operation
- To begin data acquisition cycle, press button 1 (with one dot on it)
- A yellow diode indicates that the data acquisition is in progress
- To check the ongoing data acquisition cycle's number (for further data analysis), press button 2 (with two dots on it) - an orange diode will blink with the number of blinks indicating the ongoing data acquisition cycle number
- To gracefully stop the data acquisition cycle, press button 1 again - a yellow diode should turn off and the system returns to inactive (ready) state indicated by the red diode.
- Turn off the XDK and remove the microSD card
- Analyse the data stored in the .csv file (the other file is a system storage for the cycle number, deleting it will reset the cycle number to 1)

System status indication:

- all diodes off:
  - system offline or in initialization phase (wait approx. 4 seconds)
- red diode on:
  - system ready for data acquisition
- yellow diode on:
  - system in the data acquisition mode
- orange diode blinking:
  - the number of blinks indicates the ongoing data acquisition cycle number

## Deployment

Import the DataLogger project folder into the XDK Workbench (version 3.6.0 and above):

- File -> Open Projects from File System...
- Click "Directory" and select the "DataLogger" folder in the popup window and press "OK"
- Click "Finish" in the "Import Projects from File System or Archive" window
- Wait for the import process to complete (it might take a while)

Build and flash the binaries to the XDK device:

- Turn off the XDK
- Plug in the USB cable and connect it to your PC
- Hold the button 1 (with one dot on it) on the XDK and turn it on at the same time
- The XDK should boot into "Bootloader" mode (check it in the "XDK Devices" window in the upper left corner of XDK Workbench)
- Select the project to be built and flashed (click on DataLogger folder in the Project Explorer window)
- Click "Flash" next to your XDK device in the "XDK Devices" window.
- The building process will take quite a while, especially while building the project for the first time, once it is finished, the XDK will reboot into "Application" mode (check it in the "XDK Devices" window in the upper left corner of XDK Workbench)
- It is now safe to disconnect the USB cable, the code was deployed, congrats!

## Dev info

> - XDK Workbench: ver. 3.6.0 (Win10 x64)
> - XDK Version: 1.1.0
