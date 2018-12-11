#ifndef COMMON_H
#define COMMON_H

#include <syslog.h>

constexpr const char* MQTT_ID = "YBServer";
constexpr const char* BROKER_ADDRESS = "localhost";
constexpr int MQTT_PORT = 1883;
constexpr const char* MQTT_SERVER_TOPIC = "yb/server";
constexpr const char* MQTT_STATUS_REQ_TOPIC = "yb/clients/status/request";
constexpr const char* MQTT_STATUS_RESP_TOPIC = "yb/clients/status/response";

#endif // COMMON_H
