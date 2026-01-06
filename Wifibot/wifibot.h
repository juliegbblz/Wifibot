#pragma once
#include <thread>
#include <atomic>
#include <cstdint>
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
	bool m_odometry_initialized;

	

	double m_x = 0.0;       
    double m_y = 0.0;          
    double m_theta = 0.0; 

	//unsigned long m_prev_tics_left;
	//unsigned long m_prev_tics_right;
	//unsigned long m_tics_left;
	//unsigned long m_tics_right;

    int32_t m_prev_tics_left = 0;
    int32_t m_prev_tics_right = 0;
	int32_t tics_left;
	int32_t tics_right;
	

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
	double getX() const;
    double getY() const;
    double getTheta() const ;
	void odometry(int32_t tics_l, int32_t tics_r);
	void moveDistance(double distance_m);
	static int32_t readInt32(const uint8_t* buf, int offset);
	


private:	
	void run();
	void receive();
	short crc16(unsigned char*,int);

};