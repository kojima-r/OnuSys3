#ifndef MYCANVASWIDGET_H
#define MYCANVASWIDGET_H
#include<QOpenGLWidget>
#include"EncWorker.h"
#include "SystemManagerSet.h"

#include "Obj2dString.h"
#include "Obj2dDistribution.h"
#include<pbloader.h>
#include<QBasicTimer>

class MyCanvasWidget : public QOpenGLWidget
{
public:
    MyCanvasWidget();
    MyCanvasWidget(QWidget *&q);
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    SystemManagerSet managers;
    PBLoader pbLoader;

    EncWorker* enc;
    SocketController* sock;
    GLfloat* vertexBufferGraphData;
    QBasicTimer timer;

    std::vector<Obj2dDistribution*> objs_dist;
    std::vector<Obj2dString*> objs;
protected:
    void timerEvent(QTimerEvent* e);
};

#endif // MYCANVASWIDGET_H
