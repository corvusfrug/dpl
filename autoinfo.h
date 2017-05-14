#ifndef AUTOINFO_H
#define AUTOINFO_H

#include <btBulletDynamicsCommon.h>
#include "SimpleCar.h"
#include <QObject>

class AutoInfo : public QObject
{
    Q_OBJECT
public:
    AutoInfo();
    AutoInfo(SimpleCar* arg, double curTime=0.0, bool bam=false);
public slots:
    void SetPos(double x, double y, double z);
    void SetPosX(double arg);
    void SetPosY(double arg);
    void SetPosZ(double arg);
    void SetRot(int x);
    void SetMass(int x);
    void SetMassEngine(int x);
    void SetLVelosity(double x);

    void SetTransform(btTransform arg);
    btTransform GetTrnsform();

    btVector3 GetPos();
    double GetPosX();
    double GetPosY();
    double GetPosZ();
    std::string ToString();

    btVector3 GetRot();
    int GetRotZ();

    btVector3 GetLVelosity();
    double GetLVelosityForward();

    int GetMass();
    int GetMassEngine();

    double GetTime();
    void SetTime(double arg);

    bool GetBam();
    void SetBam(bool arg);

private:
    btVector3 pos;
    btVector3 rot;
    int mass;
    int massEngine;
    int azimut;
    btVector3 lVelosity;
    double velosity;
    btTransform transform;
    double time;
    bool bam;

};

#endif // AUTOINFO_H
