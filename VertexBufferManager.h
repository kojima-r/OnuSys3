#ifndef VERTEXBUFFERMANAGER_H
#define VERTEXBUFFERMANAGER_H
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glext.h>

#include<fstream>
#include<vector>
#include<string>
#include<memory>
#include<map>

#define NUM_VERTEX_BUFFER 1024
struct VBAttribute{
    int id;
    int size;
    size_t stride;//sizeof(GL_FLOAT)*5
    size_t offset;//(void*)(0+sizeof(GL_FLOAT)*3)
    VBAttribute(){
    }
    VBAttribute(int id, int size, size_t stride, size_t offset)
        :id(id), size(size), stride(stride), offset(offset){
    }
};

struct VBInfo{
    int id;
    std::string name;
    std::vector<VBAttribute> attr;
    // for GL
    GLuint vertexBufferIndex;
    std::vector<GLfloat> buffer;
};

typedef std::shared_ptr<VBInfo> VBInfoPtr;


class VertexBufferManager
{
public:
    VertexBufferManager();
    void init();
    VBInfoPtr getBuffer(const std::string& name);
    VBInfoPtr buildBuffer(const std::string& name);
    bool setBuffer(const std::string& name);
    bool enableBuffer(const std::string& name);

private:
    int counter;
    std::map<std::string,VBInfoPtr> mapNameBuffer;
    std::map<int,VBInfoPtr> mapIdBuffer;

    std::vector<GLuint> vertexbuffers;
    int bufferIndexCounter;
    GLuint produceBufferIndex();

};

#endif // VERTEXBUFFERMANAGER_H
