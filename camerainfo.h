#ifndef CAMERAINFO_H
#define CAMERAINFO_H

#include <btBulletDynamicsCommon.h>
#include <QObject>
#include "autoinfo.h"

class CameraInfo: public QObject
{
    Q_OBJECT
public:
    CameraInfo();
public slots:
    double GetPosX();
    double GetPosY();
    double GetPosZ();
    btVector3 GetPos();

    void SetPosX(double arg);
    void SetPosY(double arg);
    void SetPosZ(double arg);

    double GetTargX();
    double GetTargY();
    double GetTargZ();
    btVector3 GetTarg();

    void SetTargX(double arg);
    void SetTargY(double arg);
    void SetTargZ(double arg);
private:
    btVector3 pos;
    btVector3 target;
};

#endif // CAMERAINFO_H
