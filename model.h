#ifndef MODEL_H
#define MODEL_H

#include "OSGBulletIncludes.h"

//#include "SimpleObject.h"
//#include "MultiObject.h"
#include "ResourceManager.h"
#include "SimpleCar.h"
#include "modelinfo.h"
#include <QObject>

class Model : public QObject
{
    Q_OBJECT
public:
    Model();
    ModelInfo* infomodel;
    btDynamicsWorld* initPhysics();
    osg::Geode* osgBox( const osg::Vec3& center, const osg::Vec3& halfLengths );
    ResourceManager* RM;
    osg::Camera* Cam;
    int RunModel();
    SimpleCar* FindCarByRB(btRigidBody* arg);
    /*void CrachNearCallback(btBroadphasePair& collisionPair,
                       btCollisionDispatcher& dispatcher,
                       btDispatcherInfo& dispatcherInfo);*/
    inline bool GetBam(){return bam;}
    inline void SetBam(bool arg){bam=arg;}

public slots:
    void initModel(ModelInfo* info);
signals:
    void SendAutoInfo(std::vector<std::vector<AutoInfo*>>);
private:
    std::vector<SimpleCar*> cars;
    std::vector<std::vector<AutoInfo*>> Log;
    bool bam;
};

// Свой диспетчер
class MyDispatcher: public btCollisionDispatcher
{
public:
    MyDispatcher(btDefaultCollisionConfiguration*);
    void SetModel(Model* model);
    bool needsResponse(const btCollisionObject* body0,
                                const btCollisionObject* body1);
private:
    Model* model;
};

#endif // MODEL_H
