#-------------------------------------------------
#
# Project created by QtCreator 2017-07-05T15:29:25
#
#-------------------------------------------------


QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test04
TEMPLATE = app

QMAKE_LIBS+=-L/usr/lib/"nvidia-367" -lGL -lGLU -lX11 -lglut -lfreetype -L/usr/local/cuda-8.0/lib64 \
    -lprotobuf \
    -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -lopencv_detection_based_tracker -lopencv_esm_panorama -lopencv_facedetect -lopencv_imuvstab -lopencv_tegra -lopencv_vstab -lcufft -lnpps -lnppi -lnppc -lcudart -latomic -ltbb -lrt -lpthread -lm -ldl
QMAKE_INCDIR+=/usr/include/freetype2
CONFIG+=c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    mycanvaswidget.cpp \
    EncWorker.cpp \
    PTUCoreTimer.cpp \
    SocketController.cpp \
    SerialController.cpp \
    SystemManagerSet.cpp \
    TextureManager.cpp \
    VertexBufferManager.cpp \
    Obj2dString.cpp \
    pbloader.cpp \
    src_proto/config.pb.cc \
    src_proto/window.pb.cc \
    Obj2dDistribution.cpp

HEADERS  += mainwindow.h \
    mycanvaswidget.h \
    cmdline.h \
    EncWorker.h \
    Lockable.h \
    PTUCoreTimer.h \
    SocketController.h \
    ThreadWorker.h \
    SerialController.h \
    VertexBufferManager.h \
    TextureManager.h \
    SystemManagerSet.h \
    Obj2dString.h \
    pbloader.h \
    src_proto/config.pb.h \
    src_proto/window.pb.h \
    Obj2dDistribution.h

FORMS    += mainwindow.ui

DISTFILES += \
    default.frag \
    default.vert \
    default.frag \
    src_proto/config.proto
