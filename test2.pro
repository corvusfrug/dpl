#-------------------------------------------------
#
# Project created by QtCreator 2017-05-02T16:34:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modelinfo.cpp \
    autoinfo.cpp \
    MultiObject.cpp \
    ResourceManager.cpp \
    SimpleCar.cpp \
    SimpleObject.cpp \
    Model.cpp \
    camerainfo.cpp \
    tmp.cpp

HEADERS  += mainwindow.h \
    modelinfo.h \
    autoinfo.h \
    MultiObject.h \
    OSGBulletIncludes.h \
    ResourceManager.h \
    SimpleCar.h \
    SimpleObject.h \
    model.h \
    camerainfo.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/usr/include \
    /usr/include/bullet \
    /usr/local/include

QMAKE_LIBDIR += $$PWD /usr/lib/i386-linux-gnu \
                /usr/lib

LIBS += -losg \
        -losgAnimation \
        -losgDB \
        -losgFX \
        -losgGA \
        -losgManipulator \
        -losgParticle \
        -losgQt \
        -losgPresentation \
        -losgShadow \
        -losgSim \
        -losgTerrain \
        -losgText \
        -losgUI \
        -losgUtil \
        -losgViewer \
        -losgVolume \
        -losgWidget \
        -lBulletCollision \
        -lBulletDynamics \
        -lBulletSoftBody \
        -lLinearMath \
        -lOpenThreads \
        -losgbCollision \
        -losgbDynamics \
        -losgbInteraction \
        -losgwControls \
        -losgwMx \
        -losgwQuery \
        -losgwTools \
        #-losgdb_osgbdynamics \
        #-losgdb_osgobjects \
        #-losgdb_osgwTools \
        #-losgdb_sgb \
        #-losgdb_skeleton

