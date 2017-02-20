# vehicle-can-daq
CAN Bus project for automotive racing data acquisition. 

Software:
- Linux OS (Raspbian)
- SocketCAN
- Qt Framework
- C++
- QML
- JavaScript
- HTML5

Hardware:
- Raspberry Pi 3 Model B
- CAN Controller/Interface (MCP2515 Microchip)
- SMPS (Switch Mode Power Supply)
- Highspeed GPS (USB)
- 7" Touchscreen Display 800 × 480 
- DB9 to OBD2 Cable
- Additional wiring, connectors, header pins, terminators, etc.

# Purpose
I wish to provide an effective HUD for the visualization of sensor signals via readouts and gauges with pre-emptive warning indication through an embedded device. In addition, external sensors (GPS) for lap timing in race use.

Racing drivers will be able to effectively and efficiently observe their vehicle’s condition and their driving statistics through an array of sensor/signal outputs with GPS lap timing in real-time.

The device will connect and retrieve data through a common vehicle network, globally adapted in 1996 (CAN bus).

Power, ground, CAN_H, and CAN_L will be retrieved from the OBD2 port (PnP), or from any available wiring if the OBD2 protocol is not supported (CAN support globally adapted in 2008).

# Usefulness
Factory vehicles are not equipped with the tools to most effectively monitor and evaluate vehicle performance in high stress driving situations, such as Road Racing. Racing drivers wish to get the most out of their vehicles and personal driving ability. Fast and accurate depictions of signal data is vital. A high speed GPS unit is paramount to gathering proper lap times. Every tenth of a second is extremely important.

# Getting Started
You will need Qt Creator and the Linux Sockets API: SocketCAN. In additon, you will need to have the supporting hardware and CAN device.

# Need Help?
If you have questions about getting started with vehicle network interfacing through CAN Bus, or anything pertaining to this project, you can reach me at rmfabac047@gmail.com

# Contributions
I'm currently the sole contributor to this project as my Senior Capstone and hobby project, looking forward.
