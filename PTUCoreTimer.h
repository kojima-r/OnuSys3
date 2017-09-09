/*
 * PTUCoreTimer.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef PTUCORETIMER_H_
#define PTUCORETIMER_H_
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct timeval CoreTime;
typedef long CoreTimeMs;
typedef unsigned long CoreTimeUs;

class PTUCoreTimer {
public:
	PTUCoreTimer();
	virtual ~PTUCoreTimer();
	static CoreTime getTime();
	static void addMs(CoreTime& t0,CoreTimeMs msec);
	static CoreTimeMs diffMs(const CoreTime& t0,const CoreTime& t1);
	static CoreTimeUs diff(const CoreTime& t0,const CoreTime& t1);
};

#endif /* PTUCORETIMER_H_ */
