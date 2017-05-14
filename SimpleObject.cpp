#include "SimpleObject.h"
//#include "ResourceManager.h"

//ResourceManager* RM = new ResourceManager();

SimpleObject::SimpleObject(btDynamicsWorld* bw, osg::Group* rt )
{
    this->bw = bw;
    root = rt;
    ready = false;
}
//osg::MatrixTransform* SimpleObject::initbody()
void SimpleObject::Init(osg::ref_ptr< osg::Node > NodeModel,
                     osg::ref_ptr< osg::Node > CollisionModel,
                     short group,
                     short mask,
                     bool Visible)
{
    if(ready) return;
    //osg::notify( osg::WARN ) << "ERR1" ;
	/*const std::string fileName( "cylinder3.obj" );
    osg::ref_ptr< osg::Node > nodeDB = osgDB::readNodeFile( fileName );
	if( !nodeDB.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileName << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}*/

    if( ( node = dynamic_cast< osg::MatrixTransform * >( NodeModel.get() ) ) == NULL )
    {
        node = new osg::MatrixTransform;
        node->addChild( NodeModel.get() );
        nodeCollision = new osg::MatrixTransform;
        nodeCollision->addChild( CollisionModel.get() );
    }

    /*  osgBullet code */
    motion = new osgbDynamics::MotionState;
    motion->setTransform( node.get() );
    btCollisionShape * collision = osgbCollision::btConvexTriMeshCollisionShapeFromOSG( nodeCollision.get() );
    // Create an OSG representation of the Bullet shape and attach it.
    // This is mainly for debugging.
    osg::Node* debugNode = osgbCollision::osgNodeFromBtCollisionShape( collision );
    node->addChild( debugNode );

    // Set debug node state.
    //std::cout << "ERR1!";
    osg::StateSet* state = debugNode->getOrCreateStateSet();
    osg::PolygonMode* pm = new osg::PolygonMode( osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::POINT);
    state->setAttributeAndModes( pm );
    osg::PolygonOffset* po = new osg::PolygonOffset( -1, -1 );
    state->setAttributeAndModes( po );
    state->setMode( GL_LIGHTING, osg::StateAttribute::OFF );

    /*  BULLET CODE */
    btTransform bodyTransform;
    bodyTransform.setIdentity();
    bodyTransform.setOrigin( btVector3( 0, 0, 0 ) );
    motion->setWorldTransform( bodyTransform );

    btScalar _mass( 1.0 );
    this->mass = 1.0;
    btVector3 inertia;
    collision->calculateLocalInertia( _mass, inertia );
    btRigidBody::btRigidBodyConstructionInfo rbinfo( _mass, motion, collision, inertia );
    body = new btRigidBody( rbinfo );
    NullVelosities();
    bw->addRigidBody( body, group, mask );

    // kick thing around from time to time.
    //node->setUpdateCallback( new GliderUpdateCallback( body ) );

//return( node.release() );
    if(Visible)
        root->addChild(node.release() );
    ready = true;
}
void SimpleObject::SetPos(btVector3 v)
{
    btTransform trans=GetRigitBodyTransform();
    //startTransform.setIdentity();
    trans.setOrigin(v);
    //startTransform.setRotation(btQuaternion(0,0,0,1));
    body->setWorldTransform(trans);
    //motion->setWorldTransform( bodyTransform );

    NullVelosities();

    //body->setLinearVelocity(btVector3(-10, -10, 0));
}
btRigidBody* SimpleObject::GetRigitBody()
{
    return body;
};
btTransform  SimpleObject::GetRigitBodyTransform()
{
    return body->getWorldTransform();
};
void SimpleObject::SetLVelosity(btVector3 v)
{
    body->setLinearVelocity( v );
}
void SimpleObject::SetMass(double mass)
{
    btVector3 inertia;
    body->getCollisionShape()->calculateLocalInertia(mass,inertia);
    body->setMassProps(mass,inertia);
    this->mass=mass;
}
void SimpleObject::SetRot(btVector3 v)
{
    btTransform transform = body->getWorldTransform();
    //body->getMotionState()->getWorldTransform(transform);
    //btVector3 pos = transform.getOrigin();

    //transform.setIdentity();
    //transform.setOrigin(pos);
    transform.setRotation(btQuaternion(v.x(),v.y(),v.z()));

    //startTransform.setIdentity();
    //startTransform.setOrigin(v);
    //motion->setTransform(node.get());
    //startTransform.setRotation(btQuaternion(0,0,1,0));
    //body->setCenterOfMassTransform(startTransform);
    body->setWorldTransform(transform);
    //motion->setWorldTransform( startTransform );
    //body->getMotionState()->setWorldTransform(startTransform);
    NullVelosities();
    //body->setLinearVelocity(btVector3(-10, -10, 0));
    /*
    // create the quaternion from yaw, pitch and roll
btQuaternion qNewOrientation;
qNewOrientation.setEuler(yaw, pitch, roll);
// get body's transform and change only its orientation, keep its position
btTransform transBody;
transBody->getMotionState()->getWorldTransform(bt);
// pass the quaternion to the transform
transBody.setRotation(qNewOrientation);
// pass the transform to the rigid body
body->setCenterOfMassTransform(transBody);

    */
}
void SimpleObject::TranslateAnVector(btVector3 v)
{
    btTransform trans=GetRigitBodyTransform();

    btVector3 posit = trans.getOrigin();
    posit+=v;

    trans.setOrigin(posit);

    body->setWorldTransform(trans);

    NullVelosities();
}
void SimpleObject::NullVelosities()
{
    body->setLinearVelocity(btVector3(0,0,0));
    body->setAngularVelocity(btVector3(0,0,0));
};
btVector3 SimpleObject::GetPos()
{
    return body->getWorldTransform().getOrigin();
}
double SimpleObject::GetMass()
{
    return mass;
}
double SimpleObject::GetRotZ()
{
    return body->getWorldTransform().getRotation().getAngle();

}
btTransform SimpleObject::GetTransform()
{
    return body->getWorldTransform();
}
double D2R(double Degree)
{
    static const double PI = 3.1415926535897932384626433832795;
    return Degree*PI/180.0;
}
double R2D(double Radian)
{
    static const double PI = 3.1415926535897932384626433832795;
    return Radian/(PI/180.0);
}
btVector3 EilerByQuat(btTransform q)
{
    btScalar* smatr;
    q.getOpenGLMatrix(smatr);
    double matr[4][4];
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            matr[i][j] = *(smatr + j*4 +i);

    double Y = - std::asin(matr[0][2]);
    double C = cos(Y);
    Y*= R2D(1.0);
    double rotx,roty,X,Z;
    if(std::fabs(C)>0.0005)
    {
        rotx=matr[2][2]/C;
        roty=matr[1][2]/C;
        X=std::atan2(roty,rotx)*R2D(1.0);
        rotx=matr[0][0]/C;
        roty=matr[0][1]/C;
        Z=std::atan2(roty,rotx)*R2D(1.0);
    } else
    {
        X=0;
        rotx=(double)matr[1][1];
        roty=-(double)matr[1][0];
        Z=std::atan2(roty,rotx)*R2D(1.0);
    };
    if(X<0) X+=360.0;
    if(Y<0) Y+=360.0;
    if(Z<0) Z+=360.0;
    return btVector3(X,Y,Z);
    /*double ysqr = q.y() * q.y();

    // X, roll, Крен
    double t0 = +2.0 * (q.w()*q.x() + q.y()*q.z());
    double t1 = +1.0 - 2.0 * (q.x() * q.x() + ysqr);
    double roll = std::atan2(t0,t1);

    // Y, pitch, Тангаж
    double t2 = +2.0 * (q.w()*q.y() - q.z()*q.x());
    t2 = (t2>1.0)? 1.0 : t2;
    t2 = (t2<-1.0)? -1.0 : t2;
    double pitch = std::asin(t2);

    // Z, yaw, Рысканье
    double t3 = +2.0 * (q.w()*q.z() + q.x()*q.y());
    double t4 = +1.0 - 2.0 * (ysqr + q.z()*q.z());
    double yaw = std::atan2(t3,t4);

    return btVector3(yaw,pitch,roll);*/
}
void SimpleObject::SetFriction(double arg)
{
    body->setFriction(arg);
}
double SimpleObject::GetFriction(){return body->getFriction(); }

