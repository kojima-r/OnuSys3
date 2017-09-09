/*
 * Lockable.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef LOCKABLE_H_
#define LOCKABLE_H_
#include <pthread.h>
#include <unistd.h>

class Lockable {
public:
	Lockable() {
		pthread_mutex_init(&m_mutex, 0);
	}

	virtual ~Lockable() {
		pthread_mutex_destroy(&m_mutex);
	}
	void lock() {
		pthread_mutex_lock(&m_mutex);
	}
	void unlock() {
		pthread_mutex_unlock(&m_mutex);
	}

protected:
	pthread_mutex_t m_mutex;
};

#endif /* LOCKABLE_H_ */
