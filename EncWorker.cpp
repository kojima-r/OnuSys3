/*
 * EncWorker.cpp
 *
 *  Created on: 2013/10/22
 *      Author: susrobo
 */

#include "EncWorker.h"
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(const string &str, char delim){
	vector<string> res;
	size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos){
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

EncWorker::EncWorker(int dist_num):dist_num(dist_num){
}

EncWorker::~EncWorker() {
	// TODO Auto-generated destructor stub
}

void EncWorker::addData(DistData& data){
	lock();
    PTUCoreTimer::getTime();
    dataList.push_back(data);
	while(dataList.size()>bufferSize){
		dataList.pop_front();
	}
	unlock();
}
bool EncWorker::getLatestData(DistData& data){
    lock();
	if(dataList.empty()){
		unlock();
		return false;
	}
    data=dataList.back();
	unlock();
	return true;
}

DistData EncWorker::getLatestData(){
    lock();
    if(dataList.empty()){
        unlock();
        return DistData(dist_num,0);
    }
    DistData data=dataList.back();
    unlock();
    return data;
}

CoreTime EncWorker::update(){
    DistData rd(dist_num,0.0);
    CoreTime recvTime;
    if (sock->isConnected()) {
        while(1){
            recvTime = PTUCoreTimer::getTime();
            int r = sock->recv(&rd.data[0],sizeof(float)*dist_num);
            if(r>0) {

                //
                this->addData(rd);
                //
                break;
            }
        }
    }
    return recvTime;
}
void EncWorker::doWork() {
	while (!m_stoprequested) {
		CoreTime startTime = PTUCoreTimer::getTime();
		CoreTime recvTime =update();
		CoreTime endTime = PTUCoreTimer::getTime();
		CoreTimeUs endLoopTime = PTUCoreTimer::diff(endTime,startTime);
		if(logEnable){
            DistData dd;
            getLatestData(dd);
			CoreTimeUs recvLoopTime = PTUCoreTimer::diff(recvTime,startTime);
            //cout<<recvLoopTime<<","<<endLoopTime<<endl;
		}
		long stime = (10000 - endLoopTime);
		//usleep待ち
		if (stime > 0) {
			usleep(stime);
		}


	}
}
