#ifndef WLAN_LIB_h
#define WLAN_LIB_h


void setup_WLAN();
void init_com(std::vector<std::pair<String,String>>);
bool is_connected();


class WLAN_PROF
{
    private:
        bool connection_status;
        String ssid;
        String ip;
        String mac;
    public:
        void set_connection_status();
        void set_ssid();
        void set_ip();
        void set_mac();
        bool get_connection_status();
        String get_ssid();
        String get_ip();
        String get_mac();
};
void update_WLAN_PROF();
WLAN_PROF get_WPROF();
void disconnect_WLAN();



#endif