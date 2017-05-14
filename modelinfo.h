#ifndef MODELINFO_H
#define MODELINFO_H

#include <vector>
#include "autoinfo.h"
#include "camerainfo.h"

#include <QDebug>

class ModelInfo: public QObject
{
    Q_OBJECT
public:
    ModelInfo();
    CameraInfo* GetCamInfo();

public slots:
    void SetCount(int arg);
    void SetGravity(double arg);
    void SetFriction(double arg);
    void SetFrequency(double arg);
    void SetCurrentAuto(int arg);

    std::string ToString();

    int GetCount();
    double GetGravity();
    btVector3 GetVGravity();
    double GetFriction();
    double GetFrequency();
    double GetFrequencyTime();
    AutoInfo* GetCurrentAuto();
    std::vector<AutoInfo*> GetAllAutoInfo();
    int GetCurrentAutoNum();

    void SetPosCamX(double arg);
    void SetPosCamY(double arg);
    void SetPosCamZ(double arg);

    void SetTargCamX(double arg);
    void SetTargCamY(double arg);
    void SetTargCamZ(double arg);

signals:
    void SwitchCurrentAuto(AutoInfo* ai);
    void SwitchCountAuto(int count);

private:
    int countAuto;
    std::vector<AutoInfo*> autoInfos;
    AutoInfo* currentAutoInfo;
    int currentAutoInfoNum;
    double gravity;
    btVector3 vGravity;
    double friction;
    double frequency;
    CameraInfo* cam;

};

#endif // MODELINFO_H
