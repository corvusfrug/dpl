#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "OSGBulletIncludes.h"
class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();
    osg::Texture2D* getTextBeton();
    osg::Texture2D* getTextWall();
    osg::ref_ptr< osg::Node > getBox();
    osg::ref_ptr< osg::Node > getBt_Box();
    osg::ref_ptr< osg::Node > getCylinder();
    osg::ref_ptr< osg::Node > getTruck();
    osg::ref_ptr< osg::Node > getPlatform();
    osg::ref_ptr< osg::Node > getSuspense_LT_AMDB9();
    osg::ref_ptr< osg::Node > getSuspense_LB_AMDB9();
    osg::ref_ptr< osg::Node > getSuspense_RT_AMDB9();
    osg::ref_ptr< osg::Node > getSuspense_RB_AMDB9();
    osg::ref_ptr< osg::Node > getWhell_AMDB9();
    osg::ref_ptr< osg::Node > getWhell_Collision_AMDB9();
    osg::ref_ptr< osg::Node > getShassi_AMDB9();
    osg::ref_ptr< osg::Node > getKorpus_AMDB9();
    osg::ref_ptr< osg::Node > getKorpus_Collision_AMDB9();
    osg::ref_ptr< osg::Node > getEngine_AMDB9();
    osg::ref_ptr< osg::Node > getMap_Cross();
    osg::ref_ptr< osg::Node > getMap_Road();
private:
    void init();
    void dinit();
    osg::Texture2D* Beton;
    osg::Texture2D* Wall;
    osg::ref_ptr< osg::Node > Box;
    osg::ref_ptr< osg::Node > bt_Box;
    osg::ref_ptr< osg::Node > Cylinder;
    osg::ref_ptr< osg::Node > Truck;
    osg::ref_ptr< osg::Node > Platform;
    osg::ref_ptr< osg::Node > Suspense_LT_AMDB9;
    osg::ref_ptr< osg::Node > Suspense_LB_AMDB9;
    osg::ref_ptr< osg::Node > Suspense_RT_AMDB9;
    osg::ref_ptr< osg::Node > Suspense_RB_AMDB9;
    osg::ref_ptr< osg::Node > Whell_AMDB9;
    osg::ref_ptr< osg::Node > Whell_Collision_AMDB9;
    osg::ref_ptr< osg::Node > Shassi_AMDB9;
    osg::ref_ptr< osg::Node > Korpus_AMDB9;
    osg::ref_ptr< osg::Node > Korpus_Collision_AMDB9;
    osg::ref_ptr< osg::Node > Engine_AMDB9;
    osg::ref_ptr< osg::Node > Map_Cross;
    osg::ref_ptr< osg::Node > Map_Road;
};


#endif // RESOURCEMANAGER_H
