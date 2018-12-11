#ifndef MQTTSERVER_H
#define MQTTSERVER_H

#include <string>
#include <mosquittopp.h>
#include "common.h"

class MQTTServer : public mosqpp::mosquittopp
{
public:
    MQTTServer(const char *id, const char *host, int port);
    ~MQTTServer();

    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);

    int Publish(const std::string &topic, const std::string &payload);
};

#endif // MQTTSERVER_H
