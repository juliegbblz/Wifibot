#pragma once
#include <thread>
#include <atomic>
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

	long m_prev_tics_left;
	long m_prev_tics_right;
	unsigned long r_tics_left;
	unsigned long r_tics_right;
	long m_tics_left;
	long m_tics_right;
	

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
	void odometry(long tics_l,long tics_r);
	void moveDistance(double distance_m);
	


private:	
	void run();
	void receive();
	short crc16(unsigned char*,int);

};