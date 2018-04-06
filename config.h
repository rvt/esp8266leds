#include "setup.h"

// #define DEVICE_MODEL                           "LC01"
// #define DEVICE_MODEL                           "LC02"
// #define DEVICE_MODEL                           "LC03"
// #define DEVICE_MODEL                           "LC04"
// #define DEVICE_MODEL                           "LC08"
// #define DEVICE_MODEL                           "LC09"
// #define DEVICE_MODEL                           "LC10"
// #define DEVICE_MODEL                           "LC11"

#ifndef DEVICE_MODEL
#define DEVICE_MODEL                           "LC01"
#endif

#ifndef RGB || RGBW || RGBWW
#define RGB
#endif

// #define IR_REMOTE
// #define RF_REMOTE
// Base code from remote control that will be added to the key code
#ifndef REMOTE_CODE
#define REMOTE_CODE                            0x000000
#endif

// Wi-Fi
#ifndef WIFI_SSID
#define WIFI_SSID                              ""
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD                          ""
#endif

// TLS support, make sure to edit the fingerprint and the MQTT broker IP address if
// you are not using CloudMQTT
// #define TLS
// #define TLS_FINGERPRINT                     "A5 02 FF 13 99 9F 8B 39 8E F1 83 4F 11 23 65 0B 32 36 FC 07"

// MQTT server settings
#ifndef MQTT_SERVER
#define MQTT_SERVER                            "127.0.0.1"
#endif

#ifndef MQTT_PORT
#define MQTT_PORT                              1883
#endif

#ifndef MQTT_USER
#define MQTT_USER                              ""
#endif

#ifndef MQTT_PASS
#define MQTT_PASS                              ""
#endif

// How often we are updating the mqtt state in ms
#ifndef MQTT_STATE_UPDATE_DELAY
#define MQTT_STATE_UPDATE_DELAY                       5000
#endif

// MQTT topics : RGBW/00FF1234
#define MQTT_TOPIC_PREFIX_TEMPLATE             "%s/%s"

// Last Will and Testament topic : RGBW/00FF1234/lastwill
#define MQTT_LASTWILL_TOPIC_TEMPLATE           "%s/lastwill"

#define MQTT_SUBSCRIBER_TOPIC_TEMPLATE         "%s/#"

#define MQTT_STATE_STATE_TOPIC_TEMPLATE        "/state/state"
#define MQTT_STATE_TOPIC_TEMPLATE              "/state"

#define MQTT_REMOTE_STATE_TOPIC                "/remote/state"
#define MQTT_REMOTE_TOPIC                      "/remote"

#define MQTT_COLOR_STATE_TOPIC                 "/color/state"
#define MQTT_COLOR_TOPIC                       "/color"

#define MQTT_FILTER_STATE_TOPIC                "/filter/state"
#define MQTT_FILTER_TOPIC                      "/filter"

#define MQTT_EFFECT_TOPIC                      "/effect"

#define MQTT_STORE_TOPIC                       "/store"
#define MQTT_RESTART_TOPIC                     "/restart"


// Enable Home Assistant MQTT discovery support.
#define HOME_ASSISTANT_MQTT_DISCOVERY
#ifndef HOME_ASSISTANT_MQTT_DISCOVERY_PREFIX
#define HOME_ASSISTANT_MQTT_DISCOVERY_PREFIX   "homeassistant"
#endif

// Base hostname, used for the MQTT Client ID and OTA hostname
#ifndef HOSTNAME_TEMPLATE
#define HOSTNAME_TEMPLATE                       "ARILUX%s"
#endif

// Enable console output via telnet OR SERIAL
// #define DEBUG_TELNET
// #define DEBUG_SERIAL

// When set we will pause for any OTA messages before we startup, no commands are handled in this time
// #define PAUSE_FOR_OTA

#define FILTER                      "filter"
#define FNAME                       "name"
#define FILTER_NONE                 "none"
#define FILTER_FADING               "fading"
#define FALPHA                      "alpha"
#define FILTER_FADING_ALPHA         0.04

// Command to set base address of the remote control
#define REMOTECMD              "remote"

// When received, force storage in eeprom (don´t call this unless you have to)
#define STORECMD              "store"

#define RESTARTCMD                  "restart"

#define EFFECT                  "effect"
#define ENAME                  "name"
#define EFFECT_NONE             "none"
#define EFFECT_FLASH            "flash"
#define EFFECT_FADE             "fade"
#define EFFECT_RAINBOW             "rainbow"
#define TWIDTH                      "width"
#define TNAME                       "name"
#define TDURATION                   "duration"

#define STATE                       "state"
#define SON                         "ON"
#define SOFF                        "OFF"

#define BRIGHTNESS_INCREASE     5
#define BRIGHTNESS_DECREASE     -5

#ifndef EEPROM_COMMIT_WAIT_DELAY
// Number of milli seconds to wait untill we commit to EEPROM
#define EEPROM_COMMIT_WAIT_DELAY       300000
#endif
#ifndef EEPROM_COMMIT_BOUNCE_DELAY
// Number of ms we wait untill we store to prevent storing to eeprom to many times
#define EEPROM_COMMIT_BOUNCE_DELAY       5000
#endif
