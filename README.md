# FansOnMDPE10
Adding three 12V fans on an MDPE10 pellet extruder on a KUKA KR20 R3100

Components:
- ESP32: Main microcontroller to control the fans and receive IR remote signals.
- IR Receiver Module: Receives signals from your remote control and passes them to the ESP32.
- Three 12V Fans: Controlled by PWM signals from the ESP32.
- 12V Power Supply: Powers the fans, with a shared ground connection with the ESP32.
- Fan Driver/Transistor Circuit (for each fan): Required to interface the 3.3V PWM signals from the ESP32 with the 12V fans.

Wiring Connections:
ESP32 to IR Receiver Module:
- Signal Pin (Data Out) of the IR receiver → GPIO 15 on the ESP32.
- VCC (Power) of the IR receiver → 3.3V on the ESP32.
- GND (Ground) of the IR receiver → GND on the ESP32.
  
ESP32 to Fans (PWM Control):
Back Fan:
- Fan driver input → GPIO 5 on the ESP32.
- Fan's power (positive terminal) → 12V from the external power supply.
- Fan's ground (negative terminal) → GND shared with the ESP32 and power supply.
Left Fan:
- Fan driver input → GPIO 18 on the ESP32.
- Fan's power (positive terminal) → 12V from the external power supply.
- Fan's ground (negative terminal) → GND shared with the ESP32 and power supply.
Right Fan:
- Fan driver input → GPIO 19 on the ESP32.
- Fan's power (positive terminal) → 12V from the external power supply.
- Fan's ground (negative terminal) → GND shared with the ESP32 and power supply.
  
12V Power Supply:
- Positive terminal of power supply → Fans' positive terminals.
- Negative terminal of power supply (GND) → Common ground shared by the fans and connected to the ESP32's GND.
