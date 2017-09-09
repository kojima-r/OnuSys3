/*
 * SocketController.cpp
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "SocketController.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>


SocketController::SocketController() :
		dstSocket(0),connected(false) {
}

SocketController::~SocketController() {
}
int SocketController::send(const void* ptr, size_t n) {
    ::sendto(dstSocket, ptr, n, 0,(struct sockaddr *)&targetAddr,sizeof(targetAddr));
	return n;
}
int SocketController::recv(void* ptr, size_t n,int sec,int usec) {
	// 10 sec
	tv.tv_sec = sec;
	tv.tv_usec =usec;
	fd_set fds,readfds;
	FD_ZERO(&readfds);
	FD_SET(dstSocket, &readfds);
	memcpy(&fds, &readfds, sizeof(fd_set));
	n = select(1, &fds, NULL, NULL, &tv);
	if (n == 0) {
		//タイムアウト
		return 0;
	}
	int r = ::recv(dstSocket, ptr, n, 0);
	return r;
}
int SocketController::recv(void* ptr, size_t n) {
	// 10 sec
	tv.tv_sec = 0;
	tv.tv_usec = 100000;
	int r = ::recv(dstSocket, ptr, n, 0);
	return r;
}

void SocketController::setAddress(const std::string& destination,
        unsigned short port) {
    // sockaddr_in 構造体
    memset(&targetAddr, 0, sizeof(targetAddr));
    targetAddr.sin_port = htons(port);
    targetAddr.sin_family = AF_INET;
    targetAddr.sin_addr.s_addr = inet_addr(destination.c_str());

}

void SocketController::connect(const std::string& destination,
		unsigned short port) {
	// sockaddr_in 構造体
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(destination.c_str());
	// ソケット生成
    dstSocket = socket(AF_INET, SOCK_DGRAM, 0);
    // 接続
    printf("listen port: %d \n", port);

    if (bind(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr)) != 0) {
        perror("bind");
        connected = false;
        return;
    }
    connected = true;
}

void SocketController::close() {
	::close(dstSocket);
	connected = false;
}

#define MAXFRAMELEN 65536
bool SocketController::recvClear() {
	int i;
	char buf[MAXFRAMELEN];
	int buflen = sizeof(buf);
	{
		i = ::recv(dstSocket, buf, buflen, MSG_DONTWAIT);
		if (i < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)) {
			//printf("%s\n", strerror(errno));
			return false;
		}
	}
	return true;
}
