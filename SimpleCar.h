#ifndef SIMPLECAR_H
#define SIMPLECAR_H

#include "OSGBulletIncludes.h"
#include "MultiObject.h"
#include "ResourceManager.h"

enum TormozType
{
    NOW=0,
    SEC,
    COLLIDE,
    NEWER
};

struct Suspension
{
    MultiObject* base;
    MultiObject* whell;
    btHingeConstraint* JoinWhel;
    btGeneric6DofConstraint* JoinShassi;
};

class SimpleCar : public MultiObject
{
    public:
        SimpleCar(btDynamicsWorld* bw, osg::Group* rt );
        virtual ~SimpleCar();
        void InitCar(ResourceManager* RM);
        void SetMassEngine(double arg);
        void SetCarMass(double arg);
        double GetMassEngine();
        double GetCarMass();
        btRigidBody* GetCarKorpusRB();
        void Tormoz();
        TormozType GetTormozType();
	void SetTormozType(TormozType arg);

    protected:

    private:
        MultiObject* Engine;
        MultiObject* Korpus;
        Suspension Susp_TR;
        Suspension Susp_TL;
        Suspension Susp_BR;
        Suspension Susp_BL;
        bool istormoz;
        TormozType tormozT;
};

#endif // SIMPLECAR_H
