#include "ResourceManager.h"
//#include <QDebug>

ResourceManager::ResourceManager()
{
    init();
}
ResourceManager::~ResourceManager()
{
    dinit();
}
osg::Texture2D* ResourceManager::getTextBeton() {return Beton;}
osg::Texture2D* ResourceManager::getTextWall() {return Wall;}
osg::ref_ptr< osg::Node > ResourceManager::getBox() {return Box;}
osg::ref_ptr< osg::Node > ResourceManager::getBt_Box() {return bt_Box;}
osg::ref_ptr< osg::Node > ResourceManager::getCylinder() {return Cylinder;}
osg::ref_ptr< osg::Node > ResourceManager::getTruck() {return Truck;}
osg::ref_ptr< osg::Node > ResourceManager::getPlatform() {return Platform;}
osg::ref_ptr< osg::Node > ResourceManager::getSuspense_LT_AMDB9() {return Suspense_LT_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getSuspense_LB_AMDB9() {return Suspense_LB_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getSuspense_RT_AMDB9() {return Suspense_RT_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getSuspense_RB_AMDB9() {return Suspense_RB_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getWhell_AMDB9() {return Whell_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getWhell_Collision_AMDB9() {return Whell_Collision_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getShassi_AMDB9() {return Shassi_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getKorpus_AMDB9() {return Korpus_AMDB9;}
osg::ref_ptr< osg::Node > ResourceManager::getKorpus_Collision_AMDB9() {return Korpus_Collision_AMDB9;}
osg::ref_ptr<osg::Node> ResourceManager::getMap_Cross(){return Map_Cross;}
osg::ref_ptr<osg::Node> ResourceManager::getMap_Road(){return Map_Road;}
osg::ref_ptr<osg::Node> ResourceManager::getEngine_AMDB9(){return Engine_AMDB9;}

void ResourceManager::init()
{
    //std::cout << "ERR1!";
    //qDebug() << "ERR1\n";
    std::string fileNameTMP;
    const std::string fileNameC( "Resources/cylinder3.obj" );
    Cylinder = osgDB::readNodeFile( fileNameC );
	if( !Cylinder.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameC << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}
	const std::string fileNameB( "Resources/box.obj" );
    Box = osgDB::readNodeFile( fileNameB );
	if( !Box.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameB << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}

	const std::string fileNameT( "Resources/dumptruck.osg" );
    Truck = osgDB::readNodeFile( fileNameT );
	if( !Truck.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameT << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}
	//texturi
	Beton = new osg::Texture2D;
	const std::string fileNameBe( "Resources/beton.jpg" );
	osg::ref_ptr<osg::Image> im1 = osgDB::readImageFile(fileNameBe);
	Beton->setImage(im1);

	Wall = new osg::Texture2D;
	const std::string fileNameW( "Resources/brick.jpg" );
	osg::ref_ptr<osg::Image> im2 = osgDB::readImageFile(fileNameW);
	Wall->setImage(im2);
    //std::cout << "ERR2!";
    //qDebug() << "ERR2\n";

    const std::string fileNameP( "Resources/platform3.obj" );
    Platform = osgDB::readNodeFile( fileNameP );
	if( !Platform.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	};

	osg::Box* box = new osg::Box( osg::Vec3( 0., 0., 0 ), 0.05, 0.05, 0.05 );
    osg::ShapeDrawable* shape = new osg::ShapeDrawable( box );
    osg::Geode* nd = new osg::Geode();
    nd->addDrawable( shape );
    bt_Box = nd;

    //qDebug() << "AM IN SUSP\n";
    fileNameTMP = "Resources/SuspensionLB_Aston_Martin_DB9.obj";
    Suspense_LB_AMDB9 = osgDB::readNodeFile( fileNameTMP );
    //qDebug() << "PROV\n";
    if( !Suspense_LB_AMDB9.valid() )
	{
        osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
        //qDebug() << "Can't find \"" << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory.\n";
        exit( 0 );
	}
    //qDebug() << "AM IN SUSP2\n";
	fileNameTMP = "Resources/SuspensionRB_Aston_Martin_DB9.obj";
    Suspense_RB_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Suspense_RB_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}

	fileNameTMP = "Resources/SuspensionLT_Aston_Martin_DB9.obj";
    Suspense_LT_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Suspense_LT_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}

	fileNameTMP = "Resources/SuspensionRT_Aston_Martin_DB9.obj";
    Suspense_RT_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Suspense_RT_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
    }
    //qDebug() << "AM IN WHELL\n";
	fileNameTMP = "Resources/Whell_Aston_Martin_DB9.obj";
    Whell_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Whell_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}
    //qDebug() << "AM IN shassi\n";
	fileNameTMP = "Resources/Shassi_Aston_Martin_DB9.obj";
    Shassi_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Shassi_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}

    //qDebug() << "AM IN KORPUS IN\n";
	fileNameTMP = "Resources/Korpus_Aston_Martin_DB9.obj";
    Korpus_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Korpus_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}
    //qDebug() << "AM IN korpus out\n";

	fileNameTMP = "Resources/Whell_Collision_Aston_Martin_DB9.obj";
    Whell_Collision_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Whell_Collision_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}
    //qDebug() << "AM IN COLLISION\n";

	fileNameTMP = "Resources/Korpus_Collision2_Aston_Martin_DB9.obj";
    Korpus_Collision_AMDB9 = osgDB::readNodeFile( fileNameTMP );
	if( !Korpus_Collision_AMDB9.valid() )
	{
		osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
		exit( 0 );
	}

    fileNameTMP = "Resources/Engine_AMDB9.obj";
    Engine_AMDB9 = osgDB::readNodeFile( fileNameTMP );
    if( !Engine_AMDB9.valid() )
    {
        osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
        exit( 0 );
    }

    fileNameTMP = "Resources/map3_grass.obj";
    Map_Cross = osgDB::readNodeFile( fileNameTMP );
    if( !Map_Cross.valid() )
    {
        osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
        exit( 0 );
    }

    fileNameTMP = "Resources/map3_road.obj";
    Map_Road = osgDB::readNodeFile( fileNameTMP );
    if( !Map_Road.valid() )
    {
        osg::notify( osg::FATAL ) << "Can't find \"" << fileNameTMP << "\". Make sure OSG_FILE_PATH includes the OSG sample data directory." << std::endl;
        exit( 0 );
    }
    //std::cout << "err3!\n";
    //qDebug() << "ERR3\n";


}
void ResourceManager::dinit()
{}

