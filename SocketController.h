/*
 * SocketController.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef SOCKETCONTROLLER_H_
#define SOCKETCONTROLLER_H_

#include "Lockable.h"
#include <string>

#include <termios.h>
#include <netinet/in.h>
#include <arpa/inet.h>


class SocketController:public Lockable {
public:
	SocketController();
	virtual ~SocketController();
	void connect(const std::string& destination, unsigned short port) ;
    void setAddress(const std::string& destination, unsigned short port) ;
    void close();
	void recvOpening();
	int send(const void* ptr,size_t n);
	int recv(void* ptr,size_t n);
	int recv(void* ptr, size_t n,int sec,int usec);
	bool isConnected(){
		return connected;
	}
	bool listen(unsigned short port);
	bool recvClear();
private:
	int dstSocket;
    struct sockaddr_in targetAddr;
	bool connected;
	struct timeval tv;
};

#endif /* SOCKETCONTROLLER_H_ */
