#pragma once
#include <thread>
#include "order.h"
#include "socket.h"

#define LOOP_TIME 200
#define PORT 15020 //adresse ip 192.168.1.106

class Wifibot {
private:
	Order m_order;
	std::thread* m_p_thread;
	std::thread* m_p_thread_recv;
	bool m_stop;
	Socket_TCP m_socket;
	char m_output_buf[9];
	unsigned char trame_crc[6];
	unsigned char ir_left;
	unsigned char ir_right;
	char data_robot[21];
	std::atomic<bool> m_obstacle;
	float m_dist_left;
	float m_dist_right;
	

public:
	Wifibot();
	~Wifibot();
	void stop();
	void speed_up();
	void speed_down();
	void turn(int direction);
	void rotate(int direction);
	void connect(std::string ip);
	void disconnect();
	int getBattery();
	float convertVoltage(unsigned char ir);
	


private:	
	void run();
	void receive();
	short crc16(unsigned char*,int);

};