import time
import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import Adafruit_ADS1x15


# MQTT network configuration
mqttServer = "MQTT_Broker_IP_Address"  # Replace with MQTT broker IP address
mqttPort = 1883  # Default MQTT port
mqttTopic = "sound"


# GPIO configuration
led_pin = 18  # GPIO pin number used for the LED
GPIO.setmode(GPIO.BCM) 
GPIO.setup(led_pin, GPIO.OUT) # Setup the led pin as output
GPIO.output(led_pin, GPIO.LOW)  # Turn off the LED at startup


# MQTT client configuration
client = mqtt.Client()


# MQTT client connection
def on_connect(client, userdata, flags, rc):
    client.subscribe(mqttTopic)


def on_message(client, userdata, msg):
    pass  # this function empty cause we don't receive MQTT messages


# MQTT client publishing function 
def publish_message(msg):
    client.publish(mqttTopic, msg)


client.on_connect = on_connect
#client.on_message = on_message


client.connect(mqttServer, mqttPort, 60)
client.loop_start()


def read_sound_level():
    adc = Adafruit_ADS1x15.ADS1115()
    gain = 1  # Gain factor (1x)
    sound_level = adc.read_adc(0, gain=gain) * (3300.0 / 32767.0)  # Read analog value in Hz and convert to mV
    return sound_level


threshold = 300  # Crying threshold in Hz
blink_duration = 1  # Duration in seconds during which the LED will blink


def blink_led():
    start_time = time.time()
    end_time = start_time + blink_duration
    while time.time() < end_time:
        GPIO.output(led_pin, GPIO.HIGH)  # Turn on the LED
        time.sleep(0.5)  # LED on time
        GPIO.output(led_pin, GPIO.LOW)  # Turn off the LED
        time.sleep(0.5)  # LED off time


try:
    while True:
        sound_level = read_sound_level()  # Get the sound level
        if sound_level > threshold:  # Check if sound level exceeds the threshold
            blink_led()  # Blink the LED
            publish_message("Sound Detected!")  # Publish an MQTT message
        time.sleep(1)  # Wait for 1 second
except KeyboardInterrupt:
    client.loop_stop()
    client.disconnect()
    GPIO.cleanup()  # Clean up used GPIOs