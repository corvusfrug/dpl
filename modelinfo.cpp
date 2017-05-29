#include "modelinfo.h"

ModelInfo::ModelInfo()
{
    countAuto = 1;
    autoInfos.push_back(new AutoInfo());
    currentAutoInfo = autoInfos[0];
    currentAutoInfoNum = 0;
    gravity = -9.81;
    vGravity = btVector3(0,0,gravity);
    friction = 1.0;
    frequency = 1.0;
    cam = new CameraInfo();
}

CameraInfo *ModelInfo::GetCamInfo()
{
    return cam;
}
std::string ModelInfo::ToString()
{
    std::string result = "";

    std::cout << "countAuto: " << countAuto << "\n";
    std::cout << "gravity: " << gravity << "\n";
    std::cout << "friction: " << friction << "\n";
    std::cout << "Start Pos:\n";
    for(unsigned int i=0; i<autoInfos.size(); ++i)
    {
        std::cout << "Auto: " << i+1 << ":\n";
        autoInfos[i]->ToString();
    }
    return result;
}

void ModelInfo::SetCount(int arg)
{
    if(arg>=countAuto)
    {
        while(countAuto<arg)
        {
            countAuto++;
            autoInfos.push_back(new AutoInfo());
        };
    } else
    {
        AutoInfo* last = currentAutoInfo;
        currentAutoInfo = autoInfos[0];
        currentAutoInfoNum=0;
        emit SwitchCurrentAuto(last);

        while(countAuto>arg)
        {
            countAuto--;
            autoInfos.pop_back();
        }
        currentAutoInfo = autoInfos[0];
        currentAutoInfoNum=0;
    }
    emit SwitchCountAuto(countAuto);
}
void ModelInfo::SetGravity(double arg)
{
    gravity=arg;
    vGravity = btVector3(0,0,arg);
}

void ModelInfo::SetFriction(double arg)
{
    friction = arg;
}

void ModelInfo::SetFrequency(double arg)
{
    frequency = arg;
}

void ModelInfo::SetCurrentAuto(int arg)
{
    AutoInfo* last = currentAutoInfo;
    if(arg < (unsigned int)autoInfos.size() && arg >=0)
    {
        currentAutoInfo = autoInfos[arg];
        currentAutoInfoNum=arg;
    };

    emit SwitchCurrentAuto(last);
}

int ModelInfo::GetCount(){return countAuto;}
double ModelInfo::GetGravity(){return gravity;}
btVector3 ModelInfo::GetVGravity(){return vGravity;}
double ModelInfo::GetFriction(){return friction;}

double ModelInfo::GetFrequency(){return frequency;}

double ModelInfo::GetFrequencyTime(){return 1.0/frequency;}

AutoInfo* ModelInfo::GetCurrentAuto(){return currentAutoInfo;}

std::vector<AutoInfo *> ModelInfo::GetAllAutoInfo(){return autoInfos;}
int ModelInfo::GetCurrentAutoNum(){return currentAutoInfoNum;}

void ModelInfo::SetPosCamX(double arg){cam->SetPosX(arg);}
void ModelInfo::SetPosCamY(double arg){cam->SetPosY(arg);}
void ModelInfo::SetPosCamZ(double arg){cam->SetPosZ(arg);}

void ModelInfo::SetTargCamX(double arg){cam->SetTargX(arg);}
void ModelInfo::SetTargCamY(double arg){cam->SetTargY(arg);}
void ModelInfo::SetTargCamZ(double arg){cam->SetTargZ(arg);}
