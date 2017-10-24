#include "Obj2dDistribution.h"
#include "EncWorker.h"


Obj2dDistribution::Obj2dDistribution(SystemManagerSet* managers)
{
    this->managers=managers;
    gain=2.0;
    r0=-0.9f;
    r1=0.8f;
    v0=-0.1f;
    base_value=0.01;
}

void Obj2dDistribution::init(int dist_num){
    std::string name="test";

    this->dist_num=dist_num;
    auto ptr=managers->vertexBufferManager.buildBuffer(name);
    std::vector<GLfloat> buf={
        -1.0f, -1.0f, 0.0f, 0.0f,0.0f,
        1.0f, -1.0f, 0.0f,  0.0f,1.0f,
        1.0f,  1.0f, 0.0f,  1.0f,1.0f,
         -1.0f, 1.0f, 0.0f, 1.0f,0.0f,

         -0.5f, -0.5f, 0.0f, 0.0f,0.0f,
         0.5f, -0.5f, 0.0f,  0.0f,1.0f,
         0.5f,  0.5f, 0.0f,  1.0f,1.0f,
          -0.5f, 0.5f, 0.0f, 1.0f,0.0f,

         -0.9f, -0.1f, 0.0f, 0.0f,0.0f,
         -0.9f, 0.1f, 0.0f,  0.0f,1.0f,
         0.0f, -0.1f, 0.0f,  0.5f,1.0f,
         0.0f,  0.0f, 0.0f,  0.5f,0.0f,
         0.9f, -0.1f, 0.0f,  1.0f,1.0f,
         0.9f,  0.1f, 0.0f,  1.0f,0.0f,
    };

    int n=dist_num*2;
    int offset=4+4;
    buf.resize(5*(offset+n),0);

    ptr->buffer=buf;
    // position
    ptr->attr.push_back(VBAttribute(0, 3, sizeof(GL_FLOAT)*5, 0));
    // uv
    ptr->attr.push_back(VBAttribute(1, 2, sizeof(GL_FLOAT)*5, 0+sizeof(GL_FLOAT)*3));
    managers->vertexBufferManager.setBuffer(name);

    {
        std::string name2="test2";
        auto ptr=managers->vertexBufferManager.buildBuffer(name2);
        std::vector<GLfloat> buf;
        buf.resize(5*(4*dist_num),0);
        ptr->buffer=buf;
        // position
        ptr->attr.push_back(VBAttribute(0, 3, sizeof(GL_FLOAT)*5, 0));
        // uv
        ptr->attr.push_back(VBAttribute(1, 2, sizeof(GL_FLOAT)*5, 0+sizeof(GL_FLOAT)*3));
        managers->vertexBufferManager.setBuffer(name2);
    }

}
void Obj2dDistribution::update(EncWorker * worker){

    printf("==\n");
    distDataLock.lock();
    distData=worker->getLatestData();
    printf("<%d>",distData.data.size());
    for(int j=0;j<3;j++){
        printf("[%f]",distData.data[j]);
    }
    distDataLock.unlock();
}

void Obj2dDistribution::render(){
    std::string name="test";

    distData.data.resize(dist_num);
    static int cnt=0;
    int n=dist_num*2;

    auto ptr=managers->vertexBufferManager.getBuffer(name);
    {
        int offset=4+4;
        distDataLock.lock();
        std::vector<GLfloat>& buf=ptr->buffer;
        cnt++;
        for(int i=0;i<n;i++){
            int j=(i/2);
            float r=j*1.0f/((n/2)-1);

            float v1=v0+base_value+distData.data[j]*gain;

            buf[5*(offset+i)+0]=r*(r1-r0)+r0;
            if(i%2==0){
                buf[5*(offset+i)+1]=v0;
                buf[5*(offset+i)+4]=0.0f;
            }else{
                buf[5*(offset+i)+1]=v1;
                buf[5*(offset+i)+4]=1.0f;
            }
            buf[5*(offset+i)+2]=0.0f;
            buf[5*(offset+i)+3]=r;

        }
        distDataLock.unlock();
    }
    managers->vertexBufferManager.setBuffer(name);
    // 最初の属性バッファ：頂点
    managers->vertexBufferManager.enableBuffer(name);

    //
    GLuint textureIndex=managers->textureManager.getTexture("red")->textureIndex;
    glBindTexture(GL_TEXTURE_2D,textureIndex);
    glDrawArrays(GL_TRIANGLE_STRIP, 8, n); //
    {
        std::string name2="test2";
        auto ptr=managers->vertexBufferManager.getBuffer(name2);
        std::vector<GLfloat>& buf=ptr->buffer;
        for(int j=0;j<dist_num;j++){
            float r=j*1.0f/(dist_num-1);
            float dr=0.002;
            float dv=0.01;

            buf[5*4*j + 5*0 + 0]=r*(r1-r0)+r0;
            buf[5*4*j + 5*0 + 1]=v0;
            buf[5*4*j + 5*0 + 2]=0;
            buf[5*4*j + 5*0 + 3]=0;
            buf[5*4*j + 5*0 + 4]=0;

            buf[5*4*j + 5*1 + 0]=r*(r1-r0)+r0;
            buf[5*4*j + 5*1 + 1]=v0-dv;
            buf[5*4*j + 5*1 + 2]=0;
            buf[5*4*j + 5*1 + 3]=0;
            buf[5*4*j + 5*1 + 4]=1;

            buf[5*4*j + 5*2 + 0]=r*(r1-r0)+r0+dr;
            buf[5*4*j + 5*2 + 1]=v0;
            buf[5*4*j + 5*2 + 2]=0;
            buf[5*4*j + 5*2 + 3]=1;
            buf[5*4*j + 5*2 + 4]=0;

            buf[5*4*j + 5*3 + 0]=r*(r1-r0)+r0+dr;
            buf[5*4*j + 5*3 + 1]=v0-dv;
            buf[5*4*j + 5*3 + 2]=0;
            buf[5*4*j + 5*3 + 3]=1;
            buf[5*4*j + 5*3 + 4]=1;

        }
        managers->vertexBufferManager.setBuffer(name2);
        managers->vertexBufferManager.enableBuffer(name2);
        GLuint textureIndex;
        textureIndex=managers->textureManager.getTexture("red")->textureIndex;
        glBindTexture(GL_TEXTURE_2D,textureIndex);
        for(int j=0;j<dist_num;j++){
            glDrawArrays(GL_POLYGON, j*4, 4); // 0-3 =>
        }
    }

}
