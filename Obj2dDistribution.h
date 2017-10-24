#ifndef OBJJ2DDISTRIBUTION_H
#define OBJJ2DDISTRIBUTION_H

#include"SystemManagerSet.h"
#include"Lockable.h"
class EncWorker;

struct DistData{
    std::vector<float> data;
    DistData(int n,float a){
        data.resize(n,a);
    }
    DistData(){
    }
};

class Obj2dDistribution
{
public:
    Obj2dDistribution(SystemManagerSet* managers);
    void init(int dist_num);
    void render();
    void update(EncWorker * worker);

    SystemManagerSet* managers;
    Lockable distDataLock;
    DistData distData;
    int dist_num;
    float gain;
    float base_value;
    float r0;
    float r1;
    float v0;
};

#endif // OBJJ2DDISTRIBUTION_H
