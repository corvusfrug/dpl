/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * osgBullet is (C) Copyright 2009-2012 by Kenneth Mark Bryden
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


#include "model.h"




//#include <QDebug>

void Model::initModel(ModelInfo* info)
{
    infomodel = info;
    RunModel();
}
Model::Model()
{
    //qDebug() << "MODEL CONSTRUCT IN\n";
    RM = new ResourceManager();
    //qDebug() << "MODEL CONSTRUCT  OUT\n";
}

void CrachNearCallback(btBroadphasePair& collisionPair,
                       btCollisionDispatcher& dispatcher,
                       const btDispatcherInfo& dispatcherInfo);

btDynamicsWorld* Model::initPhysics()
{
    btDefaultCollisionConfiguration * collisionConfiguration = new btDefaultCollisionConfiguration();
    //btCollisionDispatcher * dispatcher = new btCollisionDispatcher( collisionConfiguration );
    MyDispatcher* dispatcher = new MyDispatcher(collisionConfiguration);
    dispatcher->SetModel(this);

    btConstraintSolver * solver = new btSequentialImpulseConstraintSolver;

    btVector3 worldAabbMin( -10000, -10000, -10000 );
    btVector3 worldAabbMax( 10000, 10000, 10000 );
    btBroadphaseInterface * inter = new btAxisSweep3( worldAabbMin, worldAabbMax, 1000 );

    btDynamicsWorld * dynamicsWorld = new btDiscreteDynamicsWorld( dispatcher, inter, solver, collisionConfiguration );

    dynamicsWorld->setGravity( btVector3( 0, 0, infomodel->GetGravity() ) );

    // Итераций решателя столкновений
    btContactSolverInfo& info = dynamicsWorld->getSolverInfo();
    info.m_numIterations = 20;

    // Регистрируем собственный обработчик
   // dispatcher->setNearCallback(CrachNearCallback);

    return( dynamicsWorld );
}






osg::Geode* Model::osgBox( const osg::Vec3& center, const osg::Vec3& halfLengths )
{
    osg::Vec3 l( halfLengths * 2. );
    osg::Box* box = new osg::Box( center, l.x(), l.y(), l.z() );
    osg::ShapeDrawable* shape = new osg::ShapeDrawable( box );
    shape->setColor( osg::Vec4( 1., 1., 1., 1. ) );
    osg::Geode* geode = new osg::Geode();
    geode->addDrawable( shape );
    return( geode );
}




int Model::RunModel()
{
    btDynamicsWorld* bulletWorld = initPhysics();
    osg::Group* root = new osg::Group;
    //root->
    //osg::MatrixTransform* nullTransform = new osg::MatrixTransform;
    //root->addChild(nullTransform);

    SimpleObject* map = new SimpleObject(bulletWorld,root);
    map->Init(RM->getMap_Cross(),
              RM->getMap_Cross(),
              CollisionGroups::WORLD,
              CollisionGroups::ALL,
              true);
    map->SetPos(btVector3(0,0,0));
    map->SetMass(0.0);
    //map->GetRigitBody()->setCollisionFlags( map->GetRigitBody()->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT );
    //map->GetRigitBody()->setActivationState( DISABLE_DEACTIVATION );

    SimpleObject* road = new SimpleObject(bulletWorld,root);
    road->Init(RM->getMap_Road(),
              RM->getMap_Road(),
              CollisionGroups::WORLD,
              CollisionGroups::ALL,
              true);
    road->SetPos(btVector3(0,0,0.0));
    road->SetMass(0.0);
    //road->GetRigitBody()->setCollisionFlags( road->GetRigitBody()->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT );
    //road->GetRigitBody()->setActivationState( DISABLE_DEACTIVATION );
    //std::cout << "Frict: " << road->GetFriction() << "\n";
    map->SetFriction(infomodel->GetFriction());
    road->SetFriction(infomodel->GetFriction());


    /*std::vector<AutoInfo*> infocars(infomodel->GetAllAutoInfo());
    std::vector<SimpleCar*> cars;
    for(int i = 0; i < infocars.size(); ++i)
    {
        cars.push_back(new SimpleCar(bulletWorld,root));
        cars[i]->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
        cars[i]->InitCar(RM);
        cars[i]->SetPos(infocars[i]->GetPos());
        cars[i]->SetRot(infocars[i]->GetRot());
        cars[i]->SetMass(infocars[i]->GetMass());
        //cars[i]->SetMassEngine(infocars[i]->GetMassEngine());
        cars[i]->SetLVelosity(infocars[i]->GetLVelosity());



            /*ar2->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
                            car2->InitCar(RM);
                            //car2->SetMass(1300);
                            car2->SetPos(btVector3(-1.2,0,3));
                            ///
                            car2->SetRot(btVector3(0,0,D2R(0)));*/
     //}*/

        /*osg::MatrixTransform* shakeBox = new osg::MatrixTransform;





        btCompoundShape* cs = new btCompoundShape;
        { // floor -Z (far back of the shake cube)

            //osg::Box* box = new osg::Box( osg::Vec3( 0., 0., -0.5), 2000, 2000, 1 );
            //osg::ShapeDrawable* shape = new osg::ShapeDrawable( box );
            //shape->setColor( osg::Vec4( 1., 1., 1., 1. ) );
            //osg::Geode* geode = new osg::Geode();
            //geode->addDrawable( shape );
            osg::ref_ptr< osg::MatrixTransform > node = new osg::MatrixTransform;
            node->addChild( RM->getMap_Cross().get() );
            osg::ref_ptr< osg::MatrixTransform > nodeCollision = new osg::MatrixTransform;
            nodeCollision->addChild( RM->getMap_Cross().get() );

            //tEXTURES

            //osg::ref_ptr<osg::StateSet> ss = geode->getOrCreateStateSet();
            //ss->setTextureAttributeAndModes(0,RM->getTextBeton(),osg::StateAttribute::ON);
            //geode->setStateSet(ss);
            //osg::ref_ptr<osg::TexGen> tg(new osg::)
            //Textures end
            //osg::Vec3 halfLengths( xDim*.5, yDim*.5, thick*.5 );
            //osg::Vec3 center( 0., 0., zDim*.5 );
            shakeBox->addChild(node);
            //btBoxShape* box = new btBoxShape( osgbCollision::asBtVector3( halfLengths ) );
            ///
            btCollisionShape* css = osgbCollision::btBoxCollisionShapeFromOSG( nodeCollision );
            ///
            btTransform trans; trans.setIdentity();
            trans.setOrigin( osgbCollision::asBtVector3( osg::

            Vec3( 0., 0., -0.6 ) ) );
            cs->addChildShape( trans, css );

            ///
            osg::Matrix mat;
            mat.setTrans(osg::Vec3( 0., 0., -0.6 ));
            node->setMatrix(mat);
            ///

        }

        // END: Create environment boxes

        osgbDynamics::MotionState * shakeMotion = new osgbDynamics::MotionState();
        shakeMotion->setTransform( shakeBox );

        btScalar mass( 0.0 );
        btVector3 inertia( 0, 0, 0 );
        btRigidBody::btRigidBodyConstructionInfo rb( mass, shakeMotion, cs, inertia );
        btRigidBody* shakeBody = new btRigidBody( rb );
        shakeBody->setCollisionFlags( shakeBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT );
        shakeBody->setActivationState( DISABLE_DEACTIVATION );
        bulletWorld->addRigidBody( shakeBody, CollisionGroups::WORLD, CollisionGroups::ALL );

        root->addChild( shakeBox );*/

        osgViewer::Viewer viewer;
        viewer.setUpViewInWindow( 150, 150, 1024, 768 );
        viewer.setSceneData( root );

        //viewer

        /// CAMERA!!!!!
        CameraInfo* caminfo = infomodel->GetCamInfo();
        osg::Camera* Cam =viewer.getCamera();
        Cam->setViewMatrixAsLookAt(
            osg::Vec3(caminfo->GetPosX(),
                      caminfo->GetPosY(),
                      caminfo->GetPosZ()),
            osg::Vec3(caminfo->GetTargX(),
                      caminfo->GetTargY(),
                      caminfo->GetTargZ()),
            osg::Vec3( 0, 0, 1 ) );
        Cam->setProjectionMatrixAsPerspective( 40., 1., 1., 50. );
    //
        //viewer.setCameraManipulator(new osgGA::TrackballManipulator());
        //viewer.getCameraManipulator()->setHomePosition(osg::Vec3( 0, -5, 1),
                    //osg::Vec3( 0, 0, 5 ), osg::Vec3( 0, 0, 1 ));
    //    osg::Matrixd tmp;
        //tmp = tmp.lookAt(osg::Vec3( 0, -30, 20),
                 //   osg::Vec3( 0, 0, 5 ), osg::Vec3( 0, 0, 1 ));
                   // tmp.

        //viewer.getCameraManipulator()->setByMatrix(tmp);

        //Cam->setViewMatrixAsLookAt(
            //osg::Vec3( 0, -5, 1), osg::Vec3( 0, 0, 0 ), osg::Vec3( 0, 0, 1 ) );

    //viewer.addEventHandler( new ShakeManipulator( shakeMotion, Cam ) );
        //osg::Vec3d eye, center, up;
        //Center.x
        //osgGA::CameraManipulator* cm = new osgGA::CameraManipulator(Center);


        ////////////////////////////////////////
       /* SimpleCar* tmp = new SimpleCar(bulletWorld, root);
        tmp->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
        tmp->InitCar(RM);
        tmp->SetPos(btVector3(3,6,1));
        tmp->SetRot(btVector3(0,0,0));
        tmp->SetMass(1);*/

        std::vector<AutoInfo*> infocars(infomodel->GetAllAutoInfo());

            for(unsigned int i = 0; i < infocars.size(); ++i)
            {
                cars.push_back(new SimpleCar(bulletWorld,root));
                cars[i]->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
                cars[i]->InitCar(RM);
                cars[i]->SetPos(infocars[i]->GetPos());
                cars[i]->SetRot(infocars[i]->GetRot());
                cars[i]->SetCarMass(infocars[i]->GetMass());
                cars[i]->SetMassEngine(infocars[i]->GetMassEngine());
                cars[i]->SetLVelosity(infocars[i]->GetLVelosity());



                    /*ar2->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
                                    car2->InitCar(RM);
                                    //car2->SetMass(1300);
                                    car2->SetPos(btVector3(-1.2,0,3));
                                    ///
                                    car2->SetRot(btVector3(0,0,D2R(0)));*/
             }


        //Log
        for(unsigned int i = 0; i < cars.size(); ++i)
        {
            std::vector<AutoInfo*> tmp;
            tmp.push_back(infocars[i]);
            Log.push_back(tmp);
        }

        viewer.realize();
        double prevSimTime = 0.;
        ///
        //bool onetime1 = true;
        //bool onetime2 = true;
        //bool onetime3 = true;
        ///
        double stopTime = 0;
        double logTime = 0;
        bool allCarsStop = false;
        bam = false;

        while( !viewer.done() )
        {

            const double currSimTime = viewer.getFrameStamp()->getSimulationTime();
            double elapsed( currSimTime - prevSimTime );
            if( viewer.getFrameStamp()->getFrameNumber() < 3 )
                elapsed = 1./60.;
            //osg::notify( osg::ALWAYS ) << elapsed / 3. << ", " << 1./180. << std::endl;
            bulletWorld->stepSimulation( elapsed, 4, elapsed/4. );
            prevSimTime = currSimTime;

            if(!allCarsStop)
            {
                allCarsStop= true;
                for(unsigned int i=0;i<cars.size();++i)
                {
                    if(cars[i]->GetRigitBody()->getLinearVelocity().length() > btVector3(0.01, 0.01, 0.01).length() ||
                       cars[i]->GetRigitBody()->getAngularVelocity().length() > btVector3(0.01, 0.01, 0.01).length())
                       {
                            allCarsStop = false;
                            break;
                       }
                        //stopTime = currSimTime;
                }
                stopTime = currSimTime;
            }

            if(allCarsStop && currSimTime-stopTime>5) break;

            if(currSimTime - logTime >infomodel->GetFrequencyTime())
            {
                for(unsigned int i = 0; i < cars.size(); ++i)
                {
                    Log[i].push_back(new AutoInfo(cars[i], currSimTime, bam));
                };
                if(bam) bam=false;

                logTime = currSimTime;
            }
            /*if(onetime1 && currSimTime>55)
            {
                //car1->SetPos(btVector3(0,0,3));
                //car1->SetRot(btVector3(0,0,D2R(45)));

               // base->setr
                onetime1 = false;
            }*/
           /* if(onetime2 && currSimTime>5)
            {
                //base->SetRot(btVector3(D2R(90),D2R(0),D2R(0)));
                //base->SetPos(btVector3(0,0,5));
                //car2->SetLVelosity(btVector3(0,-1,0));
                car1->SetLVelosity(btVector3(50,0,0));
                //car2->SetRot(btVector3(0,0,D2R(180)));

                onetime2 = false;
            }
            if(onetime3 && currSimTime>5.05)
            {
                //base->SetPos(btVector3(0,0,5));
                //car2->SetLVelosity(btVector3(0,-2,0));
                car2->SetLVelosity(btVector3(0,50,0));

                onetime3 = false;
            }*/

            viewer.frame();
            //bam = false;
        }
        ///
        //for(int i = 0; i < Log.size(); ++i)
           // for(int j = 0; j < Log[i].size(); ++j)
               // {
                    //Log[Log.size()-1]
                    //[Log[Log.size()-1].size()-1]->ToString();
               // }

        // LOG
        emit SendAutoInfo(Log);

        for(unsigned int i = 0; i < cars.size(); ++i)
        {
            delete cars[i];
            for(unsigned int j = 1; j < Log[i].size(); ++j)
                delete Log[i][j];
            Log[i].clear();
        }
        cars.clear();
        Log.clear();
        //delete
        //delete KTR;
        //delete KBR;
        //delete KTL;
        //delete KBL;
        //delete platform;
        //delete shakeBox;
        //delete base;
        //delete ktl;
        //delete ktr;
        //delete cs;
       // delete shakeMotion;
        //delete shakeBox;
        //delete shakeBody;
        delete bulletWorld;
        //root-
        //delete root;

        return( 0 );

    /** \page diceexample The Mandatory Dice Example
    No physics-based project would be complete without a dice example. Use the
    left mouse button to chake the dice shaker.
    */
}
SimpleCar* Model::FindCarByRB(btRigidBody* arg)
{
    for(unsigned int i = 0; i<cars.size(); ++i)
        if(cars[i]->GetCarKorpusRB() == arg)
            return cars[i];
    return NULL;
}

void CrachNearCallback(btBroadphasePair& collisionPair,
                       btCollisionDispatcher& dispatcher,
                       const btDispatcherInfo& dispatcherInfo)
{
static bool flag = false;
    // MY LOGIC HERE
    //bool flag1=false, flag2=false;
    //SimpleCar* body1=NULL,body2=NULL;
    short int body1 = collisionPair.m_pProxy0->m_collisionFilterGroup;
    short int body2 = collisionPair.m_pProxy1->m_collisionFilterGroup;
    if(!flag && body1==CollisionGroups::KORPUS && body2==CollisionGroups::KORPUS)
    {
        flag = true;
        std::cout << "BAM!!! ";
    }
    // MY LOGIC END
    dispatcher.defaultNearCallback(collisionPair,dispatcher,dispatcherInfo);
}

bool MyDispatcher::needsResponse(const btCollisionObject* body0,
                                const btCollisionObject* body1)
{
    static bool flag = false;
    btRigidBody* b0 = (btRigidBody*)body0;
    btRigidBody* b1 = (btRigidBody*)body1;
    //body0->getCollision
    SimpleCar* car1 = NULL;
    SimpleCar* car2 = NULL;
    car1 = model->FindCarByRB(b0);
    car2 = model->FindCarByRB(b1);
    if(car1!=NULL && car2 != NULL)
        if(!flag)
        {
            flag = true;
            std::cout << "BAM!!!\n";
            model->SetBam(true);
            car1->Tormoz();
            car2->Tormoz();
        }

    return btCollisionDispatcher::needsResponse(body0, body1);

}

MyDispatcher::MyDispatcher(btDefaultCollisionConfiguration* collisionConfiguration)
:btCollisionDispatcher( collisionConfiguration )
{
}
void MyDispatcher::SetModel(Model* model)
{
    this->model = model;
}
