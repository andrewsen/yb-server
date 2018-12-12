#include <iostream>
#include <chrono>
#include <thread>
#include "mqttserver.h"

using namespace std;

int main(int argc, char* argv[])
{
    openlog ("YB-MQTT-Server", LOG_PERROR | LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);
    mosqpp::lib_init();

    MQTTServer *ybServer = new MQTTServer(MQTT_ID, BROKER_ADDRESS, MQTT_PORT);
    syslog(LOG_DEBUG, "YB MQTT Server created. Version %s", GIT_TAG);

    int rc = 1;
    while(rc)
    {
        rc = ybServer->loop_start();
        syslog(LOG_DEBUG, "Loop started with rc=%d", rc);
        if (rc) {
            syslog(LOG_DEBUG, "Reconnect");
            ybServer->reconnect_async();
        }
        else {
            ybServer->subscribe(nullptr, MQTT_SERVER_TOPIC);
            ybServer->subscribe(nullptr, MQTT_STATUS_RESP_TOPIC);
            syslog(LOG_DEBUG, "Subscribed to topics '%s', '%s'", MQTT_SERVER_TOPIC, MQTT_STATUS_RESP_TOPIC);
        }
    }

    while(true)
    {
        std::this_thread::sleep_for(60s);
        syslog(LOG_DEBUG, "Requesting status");
        ybServer->Publish(MQTT_STATUS_REQ_TOPIC, "{\"type\": \"request\"}");
    }

    mosqpp::lib_cleanup();

    return 0;
}
