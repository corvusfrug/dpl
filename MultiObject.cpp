#include "MultiObject.h"

MONode::MONode()
{
    mo=NULL;
    ConstrType=TypeOfConstraint::STATIC_JOIN;
};

MONode::MONode(
            btDynamicsWorld* bw,
            MultiObject* mo,
            MultiObject* base,
            btVector3 pivotMO,
            btVector3 pivotBase,
            btVector3 axisMO,
            btVector3 axisBase,
            TypeOfConstraint type
          )
{
    this->mo=mo;
    this->pivotBase=pivotBase;
    this->pivotMO=pivotMO;
    this->axisMO=axisMO;
    this->axisBase=axisBase;
    ConstrType=type;
    pos = mo->GetRigitBodyTransform().getOrigin() - base->GetRigitBodyTransform().getOrigin();
    //  Вытаскиваем углы эйлера из кватерниона
    btQuaternion q = mo->GetRigitBodyTransform().getRotation();

    rot = Q2E(q);

    switch(type)
    {
    case TypeOfConstraint::HINGE_CONSTR:
        constraint = new btHingeConstraint(
                      *base->GetRigitBody(),
                      *mo->GetRigitBody(),
                      pivotBase, // pivot Base
                      pivotMO,      // pivot Multi Object
                      axisBase,  // axis Base
                      axisMO,    // axis Multi Object
                      true);
        bw->addConstraint(constraint,true);
    break;
    case TypeOfConstraint::STATIC_JOIN:
    default:
        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();

        tA.setOrigin(pivotBase); // local in base
        tB.setOrigin(pivotMO);   //local in MO

        constraint = new btGeneric6DofConstraint(
                            *base->GetRigitBody(),
                            *mo->GetRigitBody(),
                            tA,
                            tB,
                            true);

        ((btGeneric6DofConstraint*)constraint)->setAxis(axisBase,axisMO);

        ((btGeneric6DofConstraint*)constraint)->setLinearLowerLimit(btVector3(0,0,0));
        ((btGeneric6DofConstraint*)constraint)->setLinearUpperLimit(btVector3(0,0,0));
        ((btGeneric6DofConstraint*)constraint)->setAngularLowerLimit(btVector3(0,0,0));
        ((btGeneric6DofConstraint*)constraint)->setAngularUpperLimit(btVector3(0,0,0));

        bw->addConstraint(constraint,true);
    break;
    }
    //base->addSO(this);

};

MultiObject::MultiObject(btDynamicsWorld* bw, osg::Group* rt)
    :SimpleObject(bw,rt)
{
    //ctor
}

MultiObject::~MultiObject()
{
    //dtor
}
void MultiObject::SetPos(btVector3 v)
{
    SimpleObject::SetPos(v);

    for(unsigned int i=0;i<MObjects.size();++i)
    {
        MObjects[i].mo->SetPos(GetRigitBodyTransform()*MObjects[i].pos);
    }
    NullVelosities();
}
void MultiObject::TranslateAnVector(btVector3 v)
{
    SimpleObject::TranslateAnVector(v);
    for(unsigned int i=0;i<MObjects.size();++i)
        MObjects[i].mo->TranslateAnVector(v);
}
 /**@brief Коментарий под своей функцией*/
void MultiObject::SetRot(btVector3 v)
{
    SimpleObject::SetRot(v);

    btTransform trans = GetRigitBodyTransform();
    for(unsigned int i=0;i<MObjects.size();++i)
    {
        btVector3 npos = trans * MObjects[i].pos;
        btVector3 nrot = (v-MObjects[i].rotParent) + MObjects[i].rot;
        MObjects[i].mo->SetPos(npos);
        MObjects[i].mo->SetRot(nrot);
    }
    NullVelosities();
}

void MultiObject::SetLVelosity(btVector3 v)
{
    SimpleObject::SetLVelosity(v);
     for(unsigned int i=0;i<MObjects.size();++i)
        MObjects[i].mo->SetLVelosity(v);
}
void MultiObject::NullVelosities()
{
    SimpleObject::NullVelosities();
    for(unsigned int i=0;i<MObjects.size();++i)
        MObjects[i].mo->NullVelosities();
}
void MultiObject::AddMO(MONode nobject)
{
    MObjects.push_back(nobject);
}
btVector3 Q2E(btQuaternion q)
{
    btVector3 i(1,0,0); //орты
    btVector3 j(0,1,0);
    btVector3 k(0,0,1);

    double x = 0;//std::acos((q*i)*i);
    double y = 0;//std::acos((q*j)*j);
    double z = 0;//std::acos((q*k)*k);

    return btVector3(x,y,z);
}
