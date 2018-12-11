#include "mqttserver.h"

MQTTServer::MQTTServer(const char *id, const char *host, int port)
    : mosquittopp(id)
{
    int keepalive = 60;
    connect_async(host, port, keepalive);
}

MQTTServer::~MQTTServer()
{

}

void MQTTServer::on_connect(int rc)
{

}

void MQTTServer::on_message(const mosquitto_message *message)
{
    syslog(LOG_DEBUG, "Message received");
    syslog(LOG_DEBUG, "Mid: %d, topic: %s, len: %d", message->mid, message->topic, message->payloadlen);
    syslog(LOG_DEBUG, "Payload: %s", message->payload);
}

void MQTTServer::on_subscribe(int mid, int qos_count, const int *granted_qos)
{

}

int MQTTServer::Publish(const std::string &topic, const std::string &payload)
{
    return publish(nullptr, topic.c_str(), payload.size(), payload.c_str());
}
