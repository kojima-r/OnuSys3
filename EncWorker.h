/*
 * EncWorker.h
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#ifndef ENCWORKER_H_
#define ENCWORKER_H_
#include "ThreadWorker.h"
#include "SocketController.h"
#include "SerialController.h"
#include <string>
#include <list>
#include <vector>
#include "PTUCoreTimer.h"
#include "Obj2dDistribution.h"

//static const int NUM_DIST=37;



class EncWorker :public ThreadWorker{
public:
    EncWorker(int dist_num);
	virtual ~EncWorker();
    void init(SocketController* sock){
		this->sock=sock;
	};
	void doWork();
    void addData(DistData& data);
    bool getLatestData(DistData& data);
    DistData getLatestData();
    bool logEnable;
private:
    int dist_num;
	SocketController* sock;
    CoreTime update();
    std::list<DistData> dataList;
	size_t bufferSize;
};

#endif /* ENCWORKER_H_ */
