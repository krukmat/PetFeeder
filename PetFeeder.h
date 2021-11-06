//const char* ssid = "MIWIFI_5G_2jJ5_EXT";
const char* ssid = "MIWIFI_2G_2jJ5";
const char* pass = "xvFYmqRv";

const int MOIST_SENSOR = 34;
const int RELAY = 14;

char* mqtt_ip = "ioticos.org";
int mqtt_ip_port = 1883;
char* mqtt_ip_user = "d2uNYOZq2J5uL3T";
char* mqtt_ip_password = "DwqGBXa7LuVlgBG";
char *mqtt_ip_topic = "HPIbCG0C72lcw6g/output";
char *mqtt_ip_topic_subscribe = "HPIbCG0C72lcw6g/input";
int MQTT_RETRYMS = 5000;

char auth[] = "yEWTTtrrde6_IQxbi4L6TkP9bh_lCD0y";
char msg[12];
int readMs = 90000;
int sensorStatus = 0;

