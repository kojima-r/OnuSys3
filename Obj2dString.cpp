#include "Obj2dString.h"
#include <math.h>

Obj2dString::Obj2dString(SystemManagerSet* managers,const protocol::Obj2dString& params)
{
    this->managers=managers;
    this->params=params;
}

void Obj2dString::init(){
    auto ptr=managers->vertexBufferManager.buildBuffer(params.name());
    std::vector<GLfloat> buf;

    ptr->buffer=buf;
    // position
    ptr->attr.push_back(VBAttribute(0, 3, sizeof(GL_FLOAT)*5, 0));
    // uv
    ptr->attr.push_back(VBAttribute(1, 2, sizeof(GL_FLOAT)*5, 0+sizeof(GL_FLOAT)*3));
    //vertexBufferManager.setBuffer("text");

}


void Obj2dString::render(){
    VertexBufferManager& vertexBufferManager=managers->vertexBufferManager;
    TextureManager& textureManager=managers->textureManager;

    auto vbptr=vertexBufferManager.getBuffer(params.name());
    std::string str="@a";
    const std::string& text=params.text();
    std::vector<float> template_box={
        0.0f, 0.0f, 0.0f, 0.0f,1.0f,
            1.0f, 0.0f, 0.0f,  1.0f,1.0f,
            1.0f,  1.0f, 0.0f,  1.0f,0.0f,
             0.0f, 1.0f, 0.0f, 0.0f,0.0f};
    {
        std::vector<GLfloat>& buf=vbptr->buffer;
        buf.resize(5*4*text.size(),0);
        double next_pos_x=0;
        double next_pos_y=0;
        for(int i=0;i<text.size();i++){
            int step=5*4;
            for(int j=0;j<step;j++){
                buf[i*step+j]=template_box[j];
            }
            str[1]=text[i];
            TextureInfoPtr ptr=textureManager.getTexture(str);
            if(!ptr){
                //("[ERROR] unknown character:"+str);
                return;
            }
            double scale=1.0;
            double pix_scale=1.0/460.0*scale;
            double w=ptr->width*pix_scale;
            double h=ptr->height*pix_scale;
            double temp_x=ptr->pos_x*pix_scale;
            double temp_y=(ptr->pos_y*pix_scale);
            double adv_x=ptr->adv_x*pix_scale;
            double adv_y=ptr->adv_y*pix_scale;
            double pos_x=next_pos_x+temp_x;
            double pos_y=next_pos_y+temp_y;
            buf[i*step+5*0+0]*=w;
            buf[i*step+5*0+0]+=pos_x;
            buf[i*step+5*0+1]*=h;
            buf[i*step+5*0+1]+=pos_y;
            buf[i*step+5*1+0]*=w;
            buf[i*step+5*1+0]+=pos_x;
            buf[i*step+5*1+1]*=h;
            buf[i*step+5*1+1]+=pos_y;
            buf[i*step+5*2+0]*=w;
            buf[i*step+5*2+0]+=pos_x;
            buf[i*step+5*2+1]*=h;
            buf[i*step+5*2+1]+=pos_y;
            buf[i*step+5*3+0]*=w;
            buf[i*step+5*3+0]+=pos_x;
            buf[i*step+5*3+1]*=h;
            buf[i*step+5*3+1]+=pos_y;
            next_pos_x+=adv_x;
            next_pos_y+=adv_y;
            double rad=params.rad();
            {
                double x=buf[i*step+5*0+0];
                double y=buf[i*step+5*0+1];
                buf[i*step+5*0+0]=x*cos(rad)-y*sin(rad);
                buf[i*step+5*0+1]=x*sin(rad)+y*cos(rad);
            }
            {
                double x=buf[i*step+5*1+0];
                double y=buf[i*step+5*1+1];
                buf[i*step+5*1+0]=x*cos(rad)-y*sin(rad);
                buf[i*step+5*1+1]=x*sin(rad)+y*cos(rad);
            }
            {
                double x=buf[i*step+5*2+0];
                double y=buf[i*step+5*2+1];
                buf[i*step+5*2+0]=x*cos(rad)-y*sin(rad);
                buf[i*step+5*2+1]=x*sin(rad)+y*cos(rad);
            }
            {
                double x=buf[i*step+5*3+0];
                double y=buf[i*step+5*3+1];
                buf[i*step+5*3+0]=x*cos(rad)-y*sin(rad);
                buf[i*step+5*3+1]=x*sin(rad)+y*cos(rad);
            }

            double x=params.x();
            double y=params.y();
            buf[i*step+5*0+0]+=x;
            buf[i*step+5*0+1]+=y;
            buf[i*step+5*1+0]+=x;
            buf[i*step+5*1+1]+=y;
            buf[i*step+5*2+0]+=x;
            buf[i*step+5*2+1]+=y;
            buf[i*step+5*3+0]+=x;
            buf[i*step+5*3+1]+=y;
        }

    }
    vertexBufferManager.setBuffer(params.name());
    vertexBufferManager.enableBuffer(params.name());
    //
    for(int i=0;i<text.size();i++){
        str[1]=text[i];
        GLuint textureIndex=textureManager.getTexture(str)->textureIndex;
        glBindTexture(GL_TEXTURE_2D,textureIndex);
        glDrawArrays(GL_POLYGON, 4*i, 4);
    }

}
