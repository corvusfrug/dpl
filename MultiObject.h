#ifndef MULTIOBJECT_H
#define MULTIOBJECT_H

#include "OSGBulletIncludes.h"
#include "SimpleObject.h"
enum TypeOfConstraint
{
    STATIC_JOIN=0,
    HINGE_CONSTR
};

class MultiObject;
struct MONode
{
    MultiObject* mo;
    btVector3 pos;  //local pos in parent CS
    btVector3 rot;  //local Yaw/Pitch/Roll in parent CS
    btVector3 rotParent;  //local Yaw/Pitch/Roll  parent CS
    btTypedConstraint* constraint;
    btVector3 pivotBase;
    btVector3 pivotMO;
    btVector3 axisBase;
    btVector3 axisMO;
    TypeOfConstraint ConstrType;
    MONode();
    MONode(
            btDynamicsWorld* bw,
            MultiObject* mo,
            MultiObject* base,
            btVector3 pivotMO,
            btVector3 pivotBase,
            btVector3 axisMO,
            btVector3 axisBase,
            TypeOfConstraint type=TypeOfConstraint::STATIC_JOIN
          );
};

class MultiObject : public SimpleObject
{
public:
    MultiObject(btDynamicsWorld* bw, osg::Group* rt);
    ~MultiObject();
    void SetPos(btVector3 v);
    void TranslateAnVector(btVector3 v);
    void SetRot(btVector3 v);
    //void SetMass(double mass);
    virtual void SetLVelosity(btVector3 v);
    void NullVelosities();
    void AddMO(MONode nobject);

protected:

        std::vector<MONode> MObjects;

};

btVector3 Q2E(btQuaternion q);

#endif // MULTIOBJECT_H
