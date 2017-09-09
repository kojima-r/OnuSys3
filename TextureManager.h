#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glext.h>

#include<fstream>
#include<vector>
#include<string>
#include<ft2build.h>
#include<freetype/freetype.h>
#include<memory>
#include<map>

const static int MAX_NUM_TEXTURE =1024;
class TextureManager;
struct TextureInfo{
    TextureInfo():left_u(0.0),right_u(1.0),top_v(0.0),top_bottom(1.0),adv_x(0),adv_y(0){
    }
    int id;
    std::string name;
    int width;
    int height;
    //
    int pos_x;
    int pos_y;
    int adv_x;
    int adv_y;
    // for GL
    GLuint textureIndex;
    float left_u;
    float right_u;
    float top_v;
    float top_bottom;
    std::vector<GLubyte> data;
    //

    ~TextureInfo();
private:
    void operator=(const TextureInfo&){}
    TextureInfo(const TextureInfo&){}
};
typedef std::shared_ptr<TextureInfo> TextureInfoPtr;
class TextureManager
{
public:
    TextureManager();
    void init();
    TextureInfoPtr loadTexture(const std::string& name);
    TextureInfoPtr getTexture(const std::string& name);
    void loadCharacters(const std::string& name);
private:

    int counter;
    std::map<std::string,TextureInfoPtr> mapNameTextures;
    std::map<int,TextureInfoPtr> mapIdTextures;

    std::vector<GLuint> textureIndex;
    int textureIndexCounter;
    GLuint produceTextureIndex();
    bool releaseTextureIndex(GLuint);

    void drawTexture(std::vector<GLubyte>& data,FT_GlyphSlot& g,
                     int org_pos_y,int org_pos_x,int size_x,int size_y,
                     unsigned int rgb,bool blend);
    void drawCharacter(std::vector<GLubyte>& data,FT_GlyphSlot& g,
                     int org_pos_y,int org_pos_x,int size_x,int size_y,
                     unsigned int rgb,bool blend);
    FT_Library ft;
    FT_Face face;

};

#endif // TEXTUREMANAGER_H
