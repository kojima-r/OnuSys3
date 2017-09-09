#ifndef OBJ2DSTRING_H
#define OBJ2DSTRING_H

#include<string>
#include"SystemManagerSet.h"
#include"src_proto/config.pb.h"
class Obj2dString
{
public:
    Obj2dString(SystemManagerSet* managers,const protocol::Obj2dString& params);
    void init();
    void render();
    SystemManagerSet* managers;
    protocol::Obj2dString params;
/*
    std::string name;
    std::string text;
    double x;
    double y;
    double rad;*/
};

#endif // OBJ2DSTRING_H
