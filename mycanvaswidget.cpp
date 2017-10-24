
#define GLFW_NO_GLU
#define GL_GLEXT_PROTOTYPES

#include "mycanvaswidget.h"
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glext.h>

#include<fstream>
#include<vector>
#include<string>
#include<ft2build.h>
#include<freetype/freetype.h>

#include "TextureManager.h"

MyCanvasWidget::MyCanvasWidget()
{

}


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

    // シェーダを作ります。
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // ファイルから頂点シェーダのコードを読み込みます。
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }

    // ファイルからフラグメントシェーダを読み込みます。
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // 頂点シェーダをコンパイルします。
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    printf("shader : %s\n", VertexSourcePointer);

    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // 頂点シェーダをチェックします。
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

    // フラグメントシェーダをコンパイルします。
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // フラグメントシェーダをチェックします。
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%sn", &FragmentShaderErrorMessage[0]);

    // プログラムをリンクします。
    fprintf(stdout, "Linking programn");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // プログラムをチェックします。
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( std::max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%sn", &ProgramErrorMessage[0]);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}

MyCanvasWidget::MyCanvasWidget(QWidget*& q):QOpenGLWidget(q){

}

GLuint programID;

void MyCanvasWidget::initializeGL(){
    glClearColor(0.1,0.1,0.1,1.0);
    pbLoader.loadConfig("config.txt");
    //pbLoader.saveConfig("config.txt");
    int dist_num=pbLoader.config.labels_size();
    // read texture
    managers.textureManager.init();

    managers.textureManager.loadTexture("@a");

    managers.textureManager.loadTexture("@b");

    managers.textureManager.loadTexture("@x");
    managers.textureManager.loadCharacters("abcdefghijklmnopqrstuvwxyz");
    managers.textureManager.loadCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    managers.textureManager.loadCharacters("0123456789");
    managers.textureManager.loadTexture("red");
    managers.textureManager.loadTexture("/home/nvidia/Qt/test04/back.jpg");


    managers.vertexBufferManager.init();
    {
        std::string name="back";
        auto ptr=managers.vertexBufferManager.buildBuffer(name);
        std::vector<GLfloat> buf={
            -1.0f, -1.0f, 0.0f, 0.0f,1.0f,
            1.0f, -1.0f, 0.0f,  1.0f,1.0f,
            1.0f,  1.0f, 0.0f,  1.0f,0.0f,
             -1.0f, 1.0f, 0.0f, 0.0f,0.0f,
        };

        int n=4;
        int offset=0;
        ptr->buffer=buf;
        // position
        ptr->attr.push_back(VBAttribute(0, 3, sizeof(GL_FLOAT)*5, 0));
        // uv
        ptr->attr.push_back(VBAttribute(1, 2, sizeof(GL_FLOAT)*5, 0+sizeof(GL_FLOAT)*3));
        managers.vertexBufferManager.setBuffer(name);
    }
    {

        Obj2dDistribution* obj =new Obj2dDistribution(&managers);
        obj->init(dist_num);
        objs_dist.push_back(obj);
    }

    for(auto& l :pbLoader.config.labels()){
        Obj2dString* obj =new Obj2dString(&managers,l);
        obj->init();
        objs.push_back(obj);
    }

    programID = LoadShaders( "default.vert", "default.frag");
    glBindAttribLocation(programID,0,"qt_Vertex");
    glBindAttribLocation(programID,1,"qt_cood");

    //
    //
    enc=new EncWorker(dist_num);
    sock=new SocketController();
    sock->connect("127.0.0.1",1113);
    sock->setAddress("127.0.0.1",1112);

    enc->init(sock);
    enc->run();
    vertexBufferGraphData=new GLfloat[2*8*5];
    // timer
    timer.start(16,this);

}

void MyCanvasWidget::timerEvent(QTimerEvent* e){

    //
    for(auto& o:objs_dist){
        o->update(enc);
    }
    //
    this->update();
}

void MyCanvasWidget::resizeGL(int w, int h){
    glViewport(0,0,w,h);
    this->adjustSize();
}

void MyCanvasWidget::paintGL(){
    //glClear(GL_COLOR_BUFFER_BIT);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //
    glUseProgram(programID);
    //
    // バッファ
    //
    {
        std::string name="back";
        managers.vertexBufferManager.setBuffer(name);
        managers.vertexBufferManager.enableBuffer(name);
        GLuint textureIndex;
        textureIndex=managers.textureManager.getTexture("/home/nvidia/Qt/test04/back.jpg")->textureIndex;
        glBindTexture(GL_TEXTURE_2D,textureIndex);
        glDrawArrays(GL_POLYGON, 0, 4); // 0-3 =>
    }

    //
    for(auto& o:objs){
        o->render();
    }
    for(auto& o:objs_dist){
        o->render();
    }
    //
    glDisableVertexAttribArray(0);

    //glFlush();

}

