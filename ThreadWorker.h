/*
 * ThreadWorker.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef THREADWORKER_H_
#define THREADWORKER_H_
#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "Lockable.h"
class ThreadWorker:public Lockable {
public:
	ThreadWorker() :
			m_stoprequested(false), m_running(false) {
	}

	~ThreadWorker() {
	}
	void run() {
		assert(m_running == false);
		m_running = true;
		pthread_create(&m_thread, 0, &ThreadWorker::start_thread, this);
	}
	void stop()
	{
		assert(m_running == true);
		m_running = false;
		m_stoprequested = true;
		pthread_join(m_thread, 0);
	}
	bool isRunning() {
		return m_running;
	}

protected:
	volatile bool m_stoprequested;
	pthread_t m_thread;
	virtual void doWork()=0;
	/*
	void do_work() {
		int iteration = 0;
		while (!m_stoprequested) {
			int value = fibonacci_number(iteration);
			pthread_mutex_lock(&m_mutex);
			m_fibonacci_values.push_back(value);
			pthread_mutex_unlock(&m_mutex); // Note 6
		}
	}
	*/
private:
	volatile bool m_running;
	static void* start_thread(void *obj) {
		reinterpret_cast<ThreadWorker *>(obj)->doWork();
		return NULL;
	}


};

#endif /* THREADWORKER_H_ */
