/*MultiObject* tmp = new MultiObject(bulletWorld, root);
tmp->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9());
tmp->SetPos(btVector3(0,0,2));
tmp->SetRot(btVector3(0,D2R(0),D2R(0)));

MultiObject* tmp2 = new MultiObject(bulletWorld, root);
tmp2->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9());
tmp2->SetPos(btVector3(0,0,5));
tmp2->SetRot(btVector3(0,D2R(0),D2R(0)));
//tmp2->SetLVelosity(btVector3(0,-5,0));*/

/*SimpleObject* t1 = new SimpleObject(bulletWorld, root);
t1->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::WHELL, CollisionGroups::ALL);
t1->SetPos(btVector3(0,0,1));

SimpleObject* t2 = new SimpleObject(bulletWorld, root);
t2->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::KORPUS, CollisionGroups::ALL & ~CollisionGroups::WHELL);
t2->SetPos(btVector3(0,0,2));*/


/*SimpleCar* car1 = new SimpleCar(bulletWorld,root);
car1->Init(RM->getShassi_AMDB9());
car1->SetMass(1);
car1->InitCar(RM);
car1->SetPos(btVector3(-0,0,3));
car1->SetRot(btVector3(0,0,0));*/
//car1->SetLVelosity

///
/*SimpleCar* car2 = new SimpleCar(bulletWorld,root);
car2->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
car2->InitCar(RM);
//car2->SetMass(1300);
car2->SetPos(btVector3(-1.2,0,3));
///
car2->SetRot(btVector3(0,0,D2R(0)));

SimpleCar* car1 = new SimpleCar(bulletWorld,root);
car1->Init(RM->getShassi_AMDB9(),RM->getShassi_AMDB9());
car1->InitCar(RM);
//car2->SetMass(1300);
car1->SetPos(btVector3(-50,50,3));
///
car1->SetRot(btVector3(0,0,D2R(-90)));*/
/*MultiObject* test = new MultiObject(bulletWorld, root);
test->Init(RM->getPlatform());
test->SetPos(btVector3(0,0,1));
test->SetRot(btVector3(0,0,D2R(30)));*/

//car1->SetPos(btVector3(0,0,5));

/*MultiObject* base = new MultiObject(bulletWorld, root);
base->Init(RM->getBt_Box(),true);
base->SetPos(btVector3(0,0,2));
base->SetMass(0.5);

MultiObject* ktl = new MultiObject(bulletWorld, root);
ktl->Init(RM->getWhell_AMDB9());
ktl->SetPos(btVector3(-1,0,1));
///
btVector3 vec = Q2E(ktl->GetRigitBodyTransform().getRotation());
std::cout << "KTL: (" << vec.x() << ", " << vec.y() << ", " << vec.z() << ")\n";
///
//ktl->SetRot(btVector3(0,0,D2R(90)));
ktl->SetMass(1);

MultiObject* ktr = new MultiObject(bulletWorld, root);
ktr->Init(RM->getWhell_AMDB9());
ktr->SetPos(btVector3(1,0,1));
ktr->SetRot(btVector3(0,0,D2R(180)));
ktr->SetMass(1);

btHingeConstraint* hinge = new btHingeConstraint(
                                                  *base->GetRigitBody(),
                                                  *ktl->GetRigitBody(),
                                                  btVector3(0,0,-1), // pivot A
                                                  btVector3(1,0,0), // pivot B
                                                  btVector3(-1,0,0), // axis A
                                                  btVector3(-1,0,0), // axis B
                                                  true);
bulletWorld->addConstraint(hinge,true);

btHingeConstraint* hinge2 = new btHingeConstraint(
                                                  *base->GetRigitBody(),
                                                  *ktr->GetRigitBody(),
                                                  btVector3(0,0,-1), // pivot A
                                                  btVector3(1,0,0), // pivot B
                                                  btVector3(1,0,0), // axis A
                                                  btVector3(-1,0,0), // axis B
                                                  true);
bulletWorld->addConstraint(hinge2,true);

MONode JoinInfo;  // узел связи, инфа о нем
JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
JoinInfo.mo = ktl; // что хотим подсоединяем
JoinInfo.pos = btVector3(-1,0,-1);
JoinInfo.rot = btVector3(0,0,D2R(0));
JoinInfo.rotParent = btVector3(0,0,0);
JoinInfo.pivotBase = btVector3(0,0,-1);
JoinInfo.pivotMO = btVector3(1,0,0);
JoinInfo.axisBase = btVector3(-1,0,0);
JoinInfo.axisMO = btVector3(1,0,0);
JoinInfo.constraint = hinge;

base->AddMO(JoinInfo);

//MONode JoinInfo2;  // узел связи, инфа о нем
JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
JoinInfo.mo = ktr; // что хотим подсоединяем
JoinInfo.pos = btVector3(1,0,-1);
JoinInfo.rot = btVector3(0,0,D2R(180));
JoinInfo.rotParent = btVector3(0,0,0);
JoinInfo.pivotBase = btVector3(0,0,-1);
JoinInfo.pivotMO = btVector3(1,0,0);
JoinInfo.axisBase = btVector3(-1,0,0);
JoinInfo.axisMO = btVector3(1,0,0);
JoinInfo.constraint = hinge2;

base->AddMO(JoinInfo);*/


//base->SetPos(btVector3(0,0,5));
//base->SetRot(btVector3(D2R(90),0,0));




/*SimpleObject* platform = new SimpleObject(bulletWorld, root);
platform->Init(RM->getPlatform());
platform->SetPos(btVector3(0,0,3));
platform->SetRot(btVector3(0,0,D2R(90)));*/

/*base->SetPos(btVector3(-2,2,3));
ktl->SetPos(btVector3(-3,2,2));

btTransform tA, tB;
tA.setIdentity();
tB.setIdentity();
//tB = base->GetRigitBodyTransform();
tA.setOrigin(btVector3(2,2,0)); // local in A
tB.setOrigin(btVector3(1,0,0)); //local in B

/*btGeneric6DofConstraint * Join1 = new btGeneric6DofConstraint(
                        *platform->GetRigitBody(),
                        *base->GetRigitBody(),
                        tA,
                        tB,
                        true);

Join1->setAxis(
    btVector3(0,1,0),
    btVector3(1,0,0));

Join1->setLinearLowerLimit(btVector3(0,0,0));
Join1->setLinearUpperLimit(btVector3(0,0,0));
Join1->setAngularLowerLimit(btVector3(0,0,0));
Join1->setAngularUpperLimit(btVector3(0,0,0));*/

/*btRotationalLimitMotor* m=Join1->getRotationalLimitMotor();
m->m_limitSoftness = 1.0;
Join1->set*/

//bulletWorld->addConstraint(Join1,true);

/* \cond */
/*class ShakeManipulator : public osgGA::GUIEventHandler
{
public:
    ShakeManipulator( osgbDynamics::MotionState* motion, osg::Camera* Cam)
      : _motion( motion )
    {
        this->Cam = Cam;
    }

    bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& )
    {
        switch( ea.getEventType() )
        {
            case osgGA::GUIEventAdapter::KEYUP:
            {
                if (ea.getKey()==osgGA::GUIEventAdapter::KEY_D ||
                    ea.getKey()==osgGA::GUIEventAdapter::KEY_Right)
                {
                    osg::Vec3d eye, center, up;
                    Cam->getViewMatrixAsLookAt(eye, center, up);
                    std::cout << eye.x() << " " << eye.y() << " " << eye.z() << "\n";
                    std::cout << center.x() << " " << center.y() << " " << center.z() << "\n";
                    eye =
                        eye +
                        Cam->getViewMatrix() * osg::Vec3d(1.,0.,0.);
                    center =
                        center +
                        Cam->getViewMatrix() * osg::Vec3d(1.,0.,0.);
                    std::cout << eye.x() << " " << eye.y() << " " << eye.z() << "\n";
                    std::cout << center.x() << " " << center.y() << " " << center.z() << "\n";
                    /*up =
                        up +
                        Cam->getViewMatrix() * osg::Vec3d(1,0,0);*/

                    //Cam->setViewMatrixAsLookAt(eye, center, up);
                    //btTransform transBT;
                    //trans
                    //osg::Matrixd transOSG = Cam->getViewMatrix();
                    //transOSG = transOSG.translate(0,0,0);
                    //Cam->setViewMatrix(transOSG);
                    //_motion->setWorldTransform( trans );


                   // return true;
                //}

               // return false;
           // }

            /*case osgGA::GUIEventAdapter::PUSH:
            {
                _lastX = ea.getXnormalized();
                _lastY = ea.getYnormalized();

                btTransform world;
                _motion->getWorldTransform( world );
                btVector3 o = world.getOrigin();
                o[ 2 ] = 0.25;
                world.setOrigin( o );
                _motion->setWorldTransform( world );

                return true;
            }
            case osgGA::GUIEventAdapter::DRAG:
            {
                btVector3 move;
                move[ 0 ] = _lastX - ea.getXnormalized();
                move[ 1 ] = ea.getYnormalized() - _lastY;
                move[ 2 ] = 0.;
                move *= 10.;
                btTransform moveTrans; moveTrans.setIdentity();
                moveTrans.setOrigin( move );
                btTransform world;
                _motion->getWorldTransform( world );
                btTransform netTrans = moveTrans * world;
                btVector3 o = netTrans.getOrigin();
                o[ 2 ] = 0.;
                netTrans.setOrigin( o );

                _motion->setWorldTransform( netTrans );

                _lastX = ea.getXnormalized();
                _lastY = ea.getYnormalized();

                return true;
            }*/
           // default:
           // break;
        //}
       // return false;
   // }//

/*protected:
    osg::Camera* Cam;
    osgbDynamics::MotionState* _motion;
    float _lastX, _lastY;
};
 //endcond*/

/*void setTransform( btRigidBody * body, const btVector3 & position, const btQuaternion & rotation )
{
    // Матрица транформации
    btTransform transform;
    transform.setIdentity();

    // Заполним матрицу
    transform.setOrigin(position);
    transform.setRotation(rotation);

    // Применим матрицу к телу
    body->setWorldTransform(transform);

    // Важный этап: обнулим линейную и угловую скорости
    body->setLinearVelocity(btVector3(0, 0, 0));
    body->setAngularVelocity(btVector3(0, 0, 0));
}
*/

/*osg::MatrixTransform*  makeDie( btDynamicsWorld* bw )
{
    osg::MatrixTransform* root = new osg::MatrixTransform;
    //const std::string fileName( "dice.osg" );
    // создание драваблов
    osg::Box *shape = new osg::Box(osg::Vec3(0,0,1),3); // Примитив

    osg::ShapeDrawable *drawable = new osg::ShapeDrawable(shape);

    //drawable->setColor( osg::Vec4( 50., 50., 50., 1. ) );

    osg::Geode *node = new osg::Geode;
    //osg::Node* node;// = osgDB::readNodeFile( fileName );
    node->addDrawable(drawable);
    /*if( node == NULL )
    {
        osg::notify( osg::FATAL ) << "Can't find \"" << fileName << "\". Make sure OSG_FILE_PATH includes the osgBullet data directory." << std::endl;
        exit( 0 );
    }*//*
    root->addChild( node );

    btCollisionShape* cs = osgbCollision::btBoxCollisionShapeFromOSG( node );

    osg::ref_ptr< osgbDynamics::CreationRecord > cr = new osgbDynamics::CreationRecord;
    cr->_sceneGraph = root;
    cr->_shapeType = BOX_SHAPE_PROXYTYPE;
    cr->_mass = 1.f;
    cr->_restitution = 1.f;
    btRigidBody* body = osgbDynamics::createRigidBody( cr.get(), cs );
    bw->addRigidBody( body );
    ///
    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setOrigin(btVector3(0,0,10));
    startTransform.setRotation(btQuaternion(0,0,0,1));
    body->setWorldTransform(startTransform);

    //body->setLinearVelocity(btVector3(-10, -10, 0));

    return( root );
}*/
