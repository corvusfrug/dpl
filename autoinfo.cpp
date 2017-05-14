#include "autoinfo.h"
#include <string>

AutoInfo::AutoInfo()
{

    pos = btVector3(0,0,0);
    rot = btVector3(0,0,0);
    mass = 1;
    massEngine = 1;
    azimut = 0;
    lVelosity = btVector3(0,0,0);
    velosity = 0;
    time = 0;
    bam = false;
}
AutoInfo::AutoInfo(SimpleCar* arg, double curTime, bool bam)
{
    pos = arg->GetPos();
    rot = btVector3(0,0,arg->GetRotZ());
    mass = (int)arg->GetCarMass();
    massEngine = (int)arg->GetMassEngine();
    azimut = R2D(arg->GetRotZ());
    lVelosity = arg->GetRigitBody()->getLinearVelocity();
    velosity = lVelosity.length();
    time = curTime;
    this->bam=bam;
}

void AutoInfo::SetPos(double x, double y, double z)
{
    pos = btVector3(x,y,z);
}

void AutoInfo::SetPosX(double arg)
{
    pos = btVector3(arg,pos.y(),pos.z());
}
void AutoInfo::SetPosY(double arg)
{
    pos = btVector3(pos.x(),arg,pos.z());
}
void AutoInfo::SetPosZ(double arg)
{
    pos = btVector3(pos.x(),pos.y(),arg);
}
void AutoInfo::SetRot(int x)
{
    azimut = x;
    rot = btVector3(0,0,D2R(-azimut));
    SetLVelosity(GetLVelosityForward());
}
void AutoInfo::SetMass(int x)
{
    mass = x;
}
void AutoInfo::SetMassEngine(int x)
{
    massEngine = x;
}
void AutoInfo::SetLVelosity(double x)
{
    btTransform trans;
    trans.setIdentity();
    trans.setRotation(btQuaternion(rot.x(), rot.y(), rot.z()));
    btVector3 azim(0,1,0);
    azim = trans * azim;
    lVelosity = azim * (x*1000/3600);
    velosity = x;
}

btVector3 AutoInfo::GetPos() {return pos;}
double AutoInfo::GetPosX()   {return pos.x();}
double AutoInfo::GetPosY()   {return pos.y();}
double AutoInfo::GetPosZ()   {return pos.z();}

btVector3 AutoInfo::GetRot() {return rot;}
int AutoInfo::GetRotZ()   {return azimut;}

btVector3 AutoInfo::GetLVelosity() {return lVelosity;}
double AutoInfo::GetLVelosityForward(){return velosity;}

int AutoInfo::GetMass(){return mass;}
int AutoInfo::GetMassEngine(){return massEngine;}

double AutoInfo::GetTime(){return time;}

void AutoInfo::SetTime(double arg)
{
    time = arg;
}

bool AutoInfo::GetBam(){return bam;}

void AutoInfo::SetBam(bool arg)
{
    bam = arg;
}

void AutoInfo::SetTransform(btTransform arg) {transform=arg;}

btTransform AutoInfo::GetTrnsform(){return transform;}

std::string AutoInfo::ToString()
{
    std::string result = "";
        std::cout << "   pos: "  << this->GetPosX() <<  " ";
        std::cout << this->GetPosY() << " ";
        std::cout << this->GetPosZ();
        std::cout << "\n";
        std::cout << "   rot(azimut): " << this->GetRotZ();
        std::cout << "\n";
        std::cout << "   velosity: " << this->GetLVelosityForward() << "\n";
        std::cout << "   mass: " << this->GetMass() << "\n";
        std::cout << "   mass engine: " << this->GetMassEngine() << "\n";
        return result;
}
