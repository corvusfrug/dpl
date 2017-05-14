#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "OSGBulletIncludes.h"
enum CollisionGroups
{
    NONE = 0,
    WORLD = 1 << 0,
    WHELL = 1 << 1,
    KORPUS = 1 << 2,
    ENGINE = 1 << 3,
    ALL = WORLD | WHELL | KORPUS
};

class SimpleObject
{
public:
    SimpleObject(btDynamicsWorld* bw, osg::Group* rt );
    void Init(osg::ref_ptr< osg::Node > NodeModel, osg::ref_ptr< osg::Node > ColisionModel, short group=WORLD, short mask=ALL, bool Visible=true);
    virtual void SetPos(btVector3 v);
    virtual void TranslateAnVector(btVector3 v);
    virtual void SetRot(btVector3 v);
    //void SetRot(btVector3 v);
    void SetMass(double mass);
    double GetMass();
    virtual void SetLVelosity(btVector3 v);
    virtual void NullVelosities();
    btRigidBody* GetRigitBody();
    btTransform  GetRigitBodyTransform();
    btVector3 GetPos();
    double GetRotZ();
    void SetFriction(double arg);
    double GetFriction();
    btTransform GetTransform();

    //osg::MatrixTransform* initbody();
protected:
    bool ready;
    double mass;
    // Оболочка
    //osg::MatrixTransform* LocalRoot;
    // Заготовка (обертка дравабла)
    //osg::Box *shape;
    // Дравабл
    //osg::ShapeDrawable *drawable;
    // Вместилище дравабла
    osg::ref_ptr< osg::MatrixTransform > node;
    osg::ref_ptr< osg::MatrixTransform > nodeCollision;
    // Тело по физике
    btRigidBody* body;
    // xtо бы эт о ни было
    osgbDynamics::MotionState * motion;

    btDynamicsWorld* bw;
    osg::Group *root;

};

// Angle in Degrees to angle in Radians
double D2R(double Degree);
double R2D(double Radian);
//btVector3 EilerByQuat(btTransform q);

#endif // SIMPLEOBJECT_H
