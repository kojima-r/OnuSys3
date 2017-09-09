#include "TextureManager.h"
#include <opencv2/opencv.hpp>
using namespace std;

TextureInfo::~TextureInfo(){

}

TextureManager::TextureManager()
{

}
TextureInfoPtr TextureManager::getTexture(const std::string& name){
    auto itr=mapNameTextures.find(name);
    if(itr!=mapNameTextures.end()){
        return itr->second;
    }
    return nullptr;
}
void TextureManager::loadCharacters(const std::string& name){
    std::string str="@a";
    for(auto chr :name){
        str[1]=chr;
        loadTexture(str);
    }
}

void TextureManager::drawTexture(std::vector<GLubyte>& data,FT_GlyphSlot& g,
                                 int org_pos_x,int org_pos_y,int size_y,int size_x,
                                 unsigned int rgb,bool blend){
    bool centering=true;
    int channel=4;
    int h=g->bitmap.rows;
    int w=g->bitmap.width;
    int top=0;
    int start_h=0;
    if(org_pos_y > g->bitmap_top){
        top=org_pos_y-g->bitmap_top;
    }else if(g->bitmap_top>org_pos_y){
        top=0;
        start_h=g->bitmap_top-org_pos_y;
    }
    if(centering){
        org_pos_x=org_pos_x+(size_x-w)/2;
    }
    for(int i=0;(i+start_h<h)&&(i+top<size_y);i++){
        for(int j=0;(j<w)&&(j+g->bitmap_left+org_pos_x<size_x);j++){
            if(j+g->bitmap_left+org_pos_x>=0 && i+top>=0){
                int idx=size_x*(i+top)+j+g->bitmap_left+org_pos_x;
                if(blend){
                    float a1=g->bitmap.buffer[(i+start_h)*w+j];
                    if(a1>0){
                        float a2=data.at(idx*channel+3);
                        float a=a1/(a1+a2);
                        data.at(idx*channel+0)=(1-a)*data.at(idx*channel+0)+a*g->bitmap.buffer[(i+start_h)*w+j];
                        data.at(idx*channel+1)=(1-a)*data.at(idx*channel+1)+a*g->bitmap.buffer[(i+start_h)*w+j];
                        data.at(idx*channel+2)=(1-a)*data.at(idx*channel+2)+a*g->bitmap.buffer[(i+start_h)*w+j];
                        data.at(idx*channel+3)=(1-a)*data.at(idx*channel+3)+a*g->bitmap.buffer[(i+start_h)*w+j];
                    }
                }else{
                    unsigned int x=(g->bitmap.buffer[(i+start_h)*w+j])&0xff;
                    float a1=(float)x;
                    float a2=data.at(idx*channel+3);
                    float a=(a1/0xff);
                    data.at(idx*channel+0)=(unsigned int)((1-a)*data.at(idx*channel+0)+a*((rgb>>16)&0xff));
                    data.at(idx*channel+1)=(unsigned int)((1-a)*data.at(idx*channel+1)+a*((rgb>>8)&0xff));
                    data.at(idx*channel+2)=(unsigned int)((1-a)*data.at(idx*channel+2)+a*((rgb>>0)&0xff));
                    if(a1>a2){
                        data.at(idx*channel+3)=a1;
                    }
                }
            }
        }
    }
}
void TextureManager::drawCharacter(std::vector<GLubyte>& data,FT_GlyphSlot& g,
                                 int x,int y,int size_y,int size_x,
                                 unsigned int rgb,bool blend){
    bool centering=true;
    int h=g->bitmap.rows;
    int w=g->bitmap.width;
    int top=0;
    int channel=4;
    int start_h=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i+y>=0&&i+y<size_y){
                if(j+x>=0&&j+x<size_x){
                    int idx=size_x*(i+y)+j+x;
                    unsigned int alpha=(g->bitmap.buffer[i*w+j])&0xff;
                    float a1=(float)alpha;
                    float a2=data.at(idx*channel+3);
                    float a=(a1/0xff);
                    data.at(idx*channel+0)=(unsigned int)((1-a)*data.at(idx*channel+0)+a*((rgb>>16)&0xff));
                    data.at(idx*channel+1)=(unsigned int)((1-a)*data.at(idx*channel+1)+a*((rgb>>8)&0xff));
                    data.at(idx*channel+2)=(unsigned int)((1-a)*data.at(idx*channel+2)+a*((rgb>>0)&0xff));
                    if(a1>a2){
                        data.at(idx*channel+3)=a1;
                    }
                }
            }
        }
    }
}
TextureInfoPtr TextureManager::loadTexture(const std::string& name){
    TextureInfoPtr ptr=getTexture(name);
    if(ptr){
       return ptr;
    }
    ptr=make_shared<TextureInfo>();
    ptr->name=name;
    ptr->id=counter;
    if(name.at(0)=='@'){// character
        ptr->textureIndex=produceTextureIndex();
        //printf("[LOAD]%s\n",name.c_str());
        int size_x=48;
        int size_y=48;
        int channel=4;
        ptr->data.resize(size_x*size_y*channel,0);
        {
            int font_size_x=48;
            int font_size_y=48;
            unsigned int rgb2=0x000000;
            unsigned int rgb=0xffffffff;

            FT_Set_Pixel_Sizes(face,font_size_x,font_size_y);
            FT_Load_Char(face,name.at(1),FT_LOAD_RENDER);
            FT_GlyphSlot g=face->glyph;
            vector<int> params_x={4,0,2, 2,4,0,4, 0,};
            vector<int> params_y={2,2,4, 0,4,0,0, 4,};
            for(int i=0;i<params_x.size();i++){
                int x=params_x[i];
                int y=params_y[i];
                drawCharacter(ptr->data,g,x,y,size_x,size_y,rgb,false);
            }
            drawCharacter(ptr->data,g,2,2,size_x,size_y,rgb2,false);
            ptr->width=size_x;
            ptr->height=size_y;
            ptr->pos_x=g->bitmap_left+2;
            ptr->pos_y=g->bitmap_top+2;
            ptr->adv_x=(g->advance.x>>6)*((font_size_x+5)*1.0/font_size_x);
            ptr->adv_y=(g->advance.y>>6)*((font_size_x+5)*1.0/font_size_x);

        }
        /*
        {
            int font_size_x=48;
            int font_size_y=48;
            unsigned int rgb2=0x000000;
            unsigned int rgb=0xffffffff;

            FT_Set_Pixel_Sizes(face,font_size_x,font_size_y);
            FT_Load_Char(face,name.at(1),FT_LOAD_RENDER);
            FT_GlyphSlot g=face->glyph;
            int org_pos_x=0;
            int org_pos_y=36;
            vector<int> params_x={2,-2,0, 0,2,-2,2, -2,};
            vector<int> params_y={0, 0,2,-2,2,-2,-2, 2,};
            for(int i=0;i<params_x.size();i++){
                int x=params_x[i];
                int y=params_y[i];
                drawTexture(ptr->data,g,org_pos_x+x,org_pos_y+y,size_x,size_y,rgb,false);
            }
            drawTexture(ptr->data,g,org_pos_x,org_pos_y,size_x,size_y,rgb2,false);

        }*/
        glBindTexture(GL_TEXTURE_2D,ptr->textureIndex);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,size_x,size_y,0,GL_RGBA,GL_UNSIGNED_BYTE,&ptr->data[0]);
    }else if(name=="red"){
        ptr->textureIndex=produceTextureIndex();
        int h=128;
        int w=128;
        int channel=4;
        ptr->data.resize(w*h*channel);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int idx=w*i+j;
                ptr->data.at(idx*channel+0)=0xff;
                ptr->data.at(idx*channel+1)=0x00;
                ptr->data.at(idx*channel+2)=0x00;
                ptr->data.at(idx*channel+3)=0xff;
            }
        }

        glBindTexture(GL_TEXTURE_2D,ptr->textureIndex);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,&ptr->data[0]);
    }else{

        cv::Mat pict=cv::imread(name,cv::IMREAD_UNCHANGED);
        printf("[load]%s (%d,%d)\n",name.c_str(),pict.cols,pict.rows);
        ptr->textureIndex=produceTextureIndex();

        glBindTexture(GL_TEXTURE_2D,ptr->textureIndex);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
        //
        glPixelStorei(GL_UNPACK_ALIGNMENT,(pict.step&3)? 1:4);
        glPixelStorei(GL_UNPACK_ROW_LENGTH,(pict.step/pict.elemSize()));
        if(pict.channels()==4){
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pict.cols,pict.rows,0,GL_BGRA,GL_UNSIGNED_BYTE,pict.ptr());
        }else{
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pict.cols,pict.rows,0,GL_BGR,GL_UNSIGNED_BYTE,pict.ptr());
        }

    }
    counter++;
    mapNameTextures.insert(make_pair(name,ptr));
    mapIdTextures.insert(make_pair(ptr->id,ptr));
    return ptr;
}
GLuint TextureManager::produceTextureIndex(){
    if(textureIndexCounter<MAX_NUM_TEXTURE){
        GLuint r=textureIndex[textureIndexCounter];
        textureIndexCounter++;
        return r;
    }else{
        printf("[ERROR] texture overflow");
    }
}
bool TextureManager::releaseTextureIndex(GLuint index){
    textureIndex[index]=0;
    return true;
}

void TextureManager::init(){
    if(FT_Init_FreeType(&ft)){
        printf("error init freetype");
        //error
        return;
    }

    if(FT_New_Face(ft,"/usr/share/fonts/truetype/freefont/FreeSans.ttf",0,&face)){
        printf("error load ttf");
        //error
        return;
    }
    //
    textureIndex.resize(MAX_NUM_TEXTURE);
    glGenTextures(MAX_NUM_TEXTURE,&textureIndex[0]);
    textureIndexCounter=0;
}
