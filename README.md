# Deaf-friendly-baby-monitor
This is an IOT project in which we implemented the idea of a deaf-friendly baby monitor using micro-controllers such as Raspberry Pi 4, Arduino Nano and ESP8266 adding to that a variety of electronic components.

# Project description

Deaf parents usually struggle in our society to be totally independent in terms of their children’s care, especially at early ages. Deaf or hard-hearing parents struggle to watch their babies at night since at that age they tend to wake up a lot and cry, a sign that can not alert a deaf or hard-hearing parent. The objective of our project is to create a tool that might help deaf and hard-hearing people to gain a little more autonomy in terms of child
care: by creating a deaf-friendly baby monitor, that consists of two systems: a **monitor** as a hearing device put near the babies’ cribs for example, that captures their crying sounds, and a **smart bracelet** that should
be worn by the parents or the caretakers of the child on their wrists. When a crying sound is captured by the monitor, a signal is sent to the bracelet which produces a vibration to alert its wearer.


# Operating Process
Our monitor is designed to be put in a 1 meter diameter space away from the target. As the crying sound of a baby is generally between **300 Hz** and **600 Hz**, we defined a threshold of **300 Hz** that should be exceeded in order for the monitor to send an alarming signal to the bracelet. Once the alert transmitted, the bracelet starts vibrating until stopped or the duration exceeds 30 seconds. The figure below resumes the general process of our system.

![schema_global(1)](https://github.com/FerielAmel/Deaf-friendly-baby-monitor/assets/107730108/084ba45e-3cbb-464a-8106-524e5a61012f)


In order to create the wanted effect, we needed to find an efficient way to connect our components as the communication between the monitor and the bracelet had to be in real-time, quick and reliable. For that, we choose to connect the two systems by Wi-Fi over the **MQTT** protocol.
The monitor hosts the **MQTT** broker to which the sound sensor module publishes on a topic named **"Sound"**.
In order to reduce the number of publications, we programmed the publication to be carried out only if the sound’s frequency exceeds 300 Hz.
Our bracelet being the subscriber to the **"Sound"** topic, it gathers the alarms and alerts the wearer of the bracelet of the situation.
As we choose the Arduino Nano to be the bracelet’s micro-controller, we had to add a Wi-Fi module (ESP8266) to it in order to get access to the broker. The Wi-Fi module is set to communicate with the Arduino micro-controller using the **UART** protocol.
The following diagram summarizes the global communication process and means used in our product.

![comm (2)](https://github.com/FerielAmel/Deaf-friendly-baby-monitor/assets/107730108/ebafb280-2cb9-4c32-a88f-3135c29e88bb)


## Electronic Schemes

Now that all of the components have been listed, the global working process of our product known and the communication protocols discovered, we can finally address the matter of the wiring of our different components. You can see below both the circuit in the monitor and the one in the smart bracelet.

### Monitor circuit

![raspb](https://github.com/FerielAmel/Deaf-friendly-baby-monitor/assets/107730108/242e7f7a-5e15-4c13-81c0-e9878e05123e)


### Bracelet circuit
![Arduino_sketch](https://github.com/FerielAmel/Deaf-friendly-baby-monitor/assets/107730108/febb60d9-f008-4cc3-b819-f41e8ab56382)

## Code + Inventory of materials 
Both the code and list of inventory can be found in the following attached files:
1. **Raspberry.py**: Contains the python code of the Raspberry Pi 4 which is the monitor's micro-controller.
2. **ArduinoNano.ino**: Contains the C/C++ code of the Arduino Nano which is the bracelet's micro-controller.
3. **ESP8266.ino**: Contains the C/C++ code of the ESP8266 which is the micro-controller that will connect the bracelet to the WiFi.
4. **Project_Report.pdf**: Contains the exhaustive list of all the product's components, their hardware wiring and the software programming of the systems + the potential prospects we consider for our product.

