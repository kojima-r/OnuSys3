#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <GL/gl.h>
#include<EncWorker.h>
#include<SocketController.h>
#include<pbloader.h>

int main(int argc, char *argv[])
{
    printf("version:%s\n",glGetString(GL_VERSION));
    QApplication a(argc, argv);
    MainWindow w;

    PBLoader pbloader;
    pbloader.loadWindow("window.txt");
    //pbloader.window.set_fullscreen(false);
    //pbloader.saveWindow("window.txt");

    if(pbloader.window.fullscreen()){
        w.showFullScreen();
    }else{
        w.show();
    }
    //

    return a.exec();
}
