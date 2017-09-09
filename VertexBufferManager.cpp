#define GLFW_NO_GLU
#define GL_GLEXT_PROTOTYPES

#include "VertexBufferManager.h"
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glext.h>

using namespace std;

VertexBufferManager::VertexBufferManager()
{

}

VBInfoPtr VertexBufferManager::getBuffer(const std::string& name){
    auto itr=mapNameBuffer.find(name);
    if(itr!=mapNameBuffer.end()){
        return itr->second;
    }
    return nullptr;
}

VBInfoPtr VertexBufferManager::buildBuffer(const std::string& name){
    VBInfoPtr ptr=getBuffer(name);
    if(ptr){
       return ptr;
    }
    ptr=make_shared<VBInfo>();
    ptr->name=name;
    ptr->id=counter;
    ptr->vertexBufferIndex=this->produceBufferIndex();

    counter++;
    mapNameBuffer.insert(make_pair(name,ptr));
    mapIdBuffer.insert(make_pair(ptr->id,ptr));

    return ptr;
}

bool VertexBufferManager::setBuffer(const std::string& name){
    VBInfoPtr ptr=getBuffer(name);
    if(ptr){
        glBindBuffer(GL_ARRAY_BUFFER, ptr->vertexBufferIndex);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*ptr->buffer.size(),
                     &(ptr->buffer[0]), GL_STATIC_DRAW);
        return true;
    }
    return false;
}
bool VertexBufferManager::enableBuffer(const std::string& name){
    VBInfoPtr ptr=getBuffer(name);
    if(ptr){
        glBindBuffer(GL_ARRAY_BUFFER, ptr->vertexBufferIndex);
        for(VBAttribute& a:ptr->attr){
            glEnableVertexAttribArray(a.id);
            glVertexAttribPointer(
               a.id,
               a.size,
               GL_FLOAT,
               GL_FALSE,
               a.stride,
               (void*)(a.offset)            // 配列バッファオフセット
            );
        }
        return true;
    }
    return false;
}

GLuint VertexBufferManager::produceBufferIndex(){
    GLuint r=vertexbuffers[bufferIndexCounter];
    bufferIndexCounter++;
    return r;
}

void VertexBufferManager::init(){
    vertexbuffers.resize(NUM_VERTEX_BUFFER);
    glGenBuffers(NUM_VERTEX_BUFFER, &vertexbuffers[0]);

    bufferIndexCounter=0;
}
