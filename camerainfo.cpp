#include "camerainfo.h"

CameraInfo::CameraInfo()
{
    pos = btVector3(0,-10,10);
    target = btVector3(0,0,0);
}

double CameraInfo::GetPosX(){return pos.x();}
double CameraInfo::GetPosY(){return pos.y();}
double CameraInfo::GetPosZ(){return pos.z();}
btVector3 CameraInfo::GetPos(){return pos;}

void CameraInfo::SetPosX(double arg)
{
    pos = btVector3(arg,pos.y(),pos.z());
}
void CameraInfo::SetPosY(double arg)
{
    pos = btVector3(pos.x(),arg,pos.z());
}
void CameraInfo::SetPosZ(double arg)
{
    pos = btVector3(pos.x(),pos.y(),arg);
}

double CameraInfo::GetTargX(){return target.x();}
double CameraInfo::GetTargY(){return target.y();}
double CameraInfo::GetTargZ(){return target.z();}
btVector3 CameraInfo::GetTarg(){return target;}

void CameraInfo::SetTargX(double arg)
{
    target = btVector3(arg,target.y(),target.z());
}
void CameraInfo::SetTargY(double arg)
{
    target = btVector3(target.x(),arg,target.z());
}
void CameraInfo::SetTargZ(double arg)
{
    target = btVector3(target.x(),target.y(),arg);
}
