/*
 * SerialController.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef SERIALCONTROLLER_H_
#define SERIALCONTROLLER_H_

#include <termios.h>
#include <string>

class SerialController {
public:
	SerialController();
	virtual ~SerialController();
	void init(int baudrate,const std::string& port);
	void setDefault(unsigned int baudrate);
	int send(const void* ptr,size_t n);
	int recv(void* ptr,unsigned int n);
	int recvAll(void* ptr,unsigned int n);
	void close();
	void recvClear();
	bool isOpen(){return openFlag;}
	void setTimeout(int t);
protected:
	struct termios oldtio,newtio;
	volatile bool stop;
	int fd;
	bool openFlag;
};

#endif /* SERIALCONTROLLER_H_ */
