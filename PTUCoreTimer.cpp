/*
 * PTUCoreTimer.cpp
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#include "PTUCoreTimer.h"
#include <stdio.h>
#include <sys/time.h>

PTUCoreTimer::PTUCoreTimer() {
	// TODO Auto-generated constructor stub

}

PTUCoreTimer::~PTUCoreTimer() {
	// TODO Auto-generated destructor stub
}

CoreTime PTUCoreTimer::getTime(){
	struct timeval t0;
	gettimeofday(&t0, NULL);
	t0.tv_usec;
	return t0;
}
long PTUCoreTimer::diffMs(const CoreTime& t0,const CoreTime& t1){
	long d_sec=t0.tv_sec-t1.tv_sec;
	long d_usec=t0.tv_usec-t1.tv_usec;
	return d_sec*1000+d_usec/1000;
}
CoreTimeUs PTUCoreTimer::diff(const CoreTime& t0,const CoreTime& t1){
	long d_sec=t0.tv_sec-t1.tv_sec;
	long d_usec=t0.tv_usec-t1.tv_usec;
	return d_sec*1000*1000+d_usec;
}
void PTUCoreTimer::addMs(CoreTime& t0,long msec){
	t0.tv_sec+=msec/1000;
	t0.tv_usec+=(msec%1000)*1000;
	if(t0.tv_usec>1000000){
		t0.tv_usec-=1000000;
		t0.tv_sec+=1;
	}
}
