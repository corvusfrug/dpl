#include "SimpleCar.h"

SimpleCar::SimpleCar(btDynamicsWorld* bw, osg::Group* rt )
 :MultiObject(bw,rt)
{
    //ctor
}

SimpleCar::~SimpleCar()
{
    //dtor
}

void SimpleCar::InitCar(ResourceManager* RM)
{
    if(!ready)
    {
        std::cout << "Car mast be initialize.\n";
        return;
    }

    MultiObject* base_TR = new MultiObject(bw,root); // Подвеска передняя правая
    base_TR->Init(RM->getBt_Box(),RM->getBt_Box(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_TR.base = base_TR;

    MultiObject* base_TL = new MultiObject(bw,root); // Подвеска передняя левая
    base_TL->Init(RM->getBt_Box(),RM->getBt_Box(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_TL.base = base_TL;

    MultiObject* base_BR = new MultiObject(bw,root); // Подвеска задняя правая
    base_BR->Init(RM->getBt_Box(),RM->getBt_Box(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_BR.base = base_BR;

    MultiObject* base_BL = new MultiObject(bw,root); // Подвеска задняя левая
    base_BL->Init(RM->getBt_Box(),RM->getBt_Box(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_BL.base = base_BL;


    MultiObject* Koleso_TR = new MultiObject(bw,root); // Колесо переднее правое
    Koleso_TR->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_TR.whell = Koleso_TR;

    MultiObject* Koleso_TL = new MultiObject(bw,root); // Колесо переднее левое
    Koleso_TL->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_TL.whell = Koleso_TL;

    MultiObject* Koleso_BR = new MultiObject(bw,root); // Колесо заднее правое
    Koleso_BR->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_BR.whell = Koleso_BR;

    MultiObject* Koleso_BL = new MultiObject(bw,root); // Колесо заднее левое
    Koleso_BL->Init(RM->getWhell_AMDB9(), RM->getWhell_Collision_AMDB9(), CollisionGroups::WHELL, CollisionGroups::ALL);
    Susp_BL.whell = Koleso_BL;

    // Запоминаем текущие координаты
    btVector3 OldPos = GetRigitBodyTransform().getOrigin();
    // распологаем Основу
    SetPos(btVector3(0,0,0)); //База
    SetRot(btVector3(0,0,D2R(0))); //База

    // Создание передней правой подвески
    {
        // Сперва распологаем базу
        base_TR->SetPos(btVector3(0,0,0));
        base_TR->SetMass(1);

        // Теперь колесо
        Koleso_TR->SetPos(btVector3(0.35,0,0));
        Koleso_TR->SetRot(btVector3(0,0,D2R(180)));
        Koleso_TR->SetMass(1);

        // Создаем "Связь" подвеска - колесо
        btHingeConstraint* hinge = new btHingeConstraint(
                                                          *base_TR->GetRigitBody(),
                                                          *Koleso_TR->GetRigitBody(),
                                                          btVector3(0.35,0,0), // pivot A
                                                          btVector3(0,0,0), // pivot B
                                                          btVector3(1,0,0), // axis A
                                                          btVector3(-1,0,0), // axis B
                                                          true);
        bw->addConstraint(hinge,true);
        Susp_TR.JoinWhel=hinge;


        //Регестрируем "зависимость" колеса от подвески
        MONode JoinInfo;  // узел связи, инфа о нем
        JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
        JoinInfo.mo = Koleso_TR;                // что хотим подсоединяем (МО)
        JoinInfo.pos = btVector3(0.35,0,0);      // Координаты присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rotParent = btVector3(0,0,0);  // Начальный поворот того МО к которому присоединяемся
        JoinInfo.pivotBase = btVector3(0.35,0,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo.axisMO = btVector3(1,0,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo.constraint = hinge;        // Соединение

        base_TR->AddMO(JoinInfo); // прикрепляем подузел

        //Теперь присоединяем подвеску к корпусу
        // Сперва создаем соединение

        //base_TR->SetPos(btVector3(0,0,5));

        // распологаем  подвеску
        //SetPos(btVector3(0,0,0)); //База
        //SetRot(btVector3(0,0,D2R(90))); //База
        //base_TR->SetRot(btVector3(0,0,D2R(0))); // Подвеска (база и колесо)
        base_TR->SetPos(btVector3(0.5,1.4,0)); // Подвеска (база и колесо)
        //ktl->SetPos(btVector3(-3,2,2));

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(0.5,1.4,0)); // Пивот local относительно базы
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно подвески (коорд подвеска == коорд базы подвески)

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *base_TR->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(1,0,0),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно подвески

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));

        Susp_TR.JoinShassi=Join;
        ///
            //Join->getRotationalLimitMotor()
        ///

        bw->addConstraint(Join,true);

        // Теперь Регестрируем "зависимость" подвески от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = base_TR;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(0.5,1.4,0);      // Координаты присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rot = btVector3(0,0,D2R(0));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(0.5,1.4,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo2.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел
    }
    // Создание передней левой подвески
    {
        // Сперва распологаем базу
        base_TL->SetPos(btVector3(0,0,0));
        base_TL->SetMass(1);

        // Теперь колесо
        Koleso_TL->SetPos(btVector3(0.35,0,0));
        Koleso_TL->SetRot(btVector3(0,0,D2R(180)));
        Koleso_TL->SetMass(1);

        // Создаем "Связь" подвеска - колесо
        btHingeConstraint* hinge = new btHingeConstraint(
                                                          *base_TL->GetRigitBody(),
                                                          *Koleso_TL->GetRigitBody(),
                                                          btVector3(0.35,0,0), // pivot A
                                                          btVector3(0,0,0), // pivot B
                                                          btVector3(1,0,0), // axis A
                                                          btVector3(-1,0,0), // axis B
                                                          true);
        bw->addConstraint(hinge,true);
        Susp_TL.JoinWhel = hinge;

        //Регестрируем "зависимость" колеса от подвески
        MONode JoinInfo;  // узел связи, инфа о нем
        JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
        JoinInfo.mo = Koleso_TL;                // что хотим подсоединяем (МО)
        JoinInfo.pos = btVector3(0.35,0,0);      // Координаты присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rotParent = btVector3(0,0,0);  // Начальный поворот того МО к которому присоединяемся
        JoinInfo.pivotBase = btVector3(0.35,0,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo.axisMO = btVector3(1,0,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo.constraint = hinge;        // Соединение

        base_TL->AddMO(JoinInfo); // прикрепляем подузел


        //Теперь присоединяем подвеску к корпусу
        // Сперва создаем соединение

        // распологаем Основу, потом подвеску
        //SetPos(btVector3(0,0,0)); //База
        //SetRot(btVector3(0,0,D2R(90))); //База
        base_TL->SetPos(btVector3(-0.5,1.4,0)); // Подвеска (база и колесо)
        base_TL->SetRot(btVector3(0,0,D2R(180)));
        //ktl->SetPos(btVector3(-3,2,2));

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(-0.5,1.4,0)); // Пивот local относительно базы
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно подвески (коорд подвеска == коорд базы подвески)

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *base_TL->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(-1,0,0),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно подвески

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));

        bw->addConstraint(Join,true);
        Susp_TL.JoinShassi = Join;

        // Теперь Регестрируем "зависимость" подвески от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = base_TL;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(-0.5,1.4,0);      // Координаты присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(-0.5,1.4,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo2.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(-1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел
    }
    // Создание задней правой подвески
    {
        // Сперва распологаем базу
        base_BR->SetPos(btVector3(0,0,0));
        base_BR->SetMass(1);

        // Теперь колесо
        Koleso_BR->SetPos(btVector3(0.35,0,0));
        Koleso_BR->SetRot(btVector3(0,0,D2R(180)));
        Koleso_BR->SetMass(1);

        // Создаем "Связь" подвеска - колесо
        btHingeConstraint* hinge = new btHingeConstraint(
                                                          *base_BR->GetRigitBody(),
                                                          *Koleso_BR->GetRigitBody(),
                                                          btVector3(0.35,0,0), // pivot A
                                                          btVector3(0,0,0), // pivot B
                                                          btVector3(1,0,0), // axis A
                                                          btVector3(-1,0,0), // axis B
                                                          true);
        bw->addConstraint(hinge,true);
        Susp_BR.JoinWhel = hinge;

        //Регестрируем "зависимость" колеса от подвески
        MONode JoinInfo;  // узел связи, инфа о нем
        JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
        JoinInfo.mo = Koleso_BR;                // что хотим подсоединяем (МО)
        JoinInfo.pos = btVector3(0.35,0,0);      // Координаты присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rotParent = btVector3(0,0,0);  // Начальный поворот того МО к которому присоединяемся
        JoinInfo.pivotBase = btVector3(0.35,0,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo.axisMO = btVector3(1,0,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo.constraint = hinge;        // Соединение

        base_BR->AddMO(JoinInfo); // прикрепляем подузел


        //Теперь присоединяем подвеску к корпусу
        // Сперва создаем соединение

        // распологаем  подвеску
        //SetPos(btVector3(0,0,0)); //База
        //SetRot(btVector3(0,0,D2R(90))); //База
        base_BR->SetRot(btVector3(0,0,D2R(0))); // Подвеска (база и колесо)
        base_BR->SetPos(btVector3(0.5,-1.35,0)); // Подвеска (база и колесо)
        //ktl->SetPos(btVector3(-3,2,2));

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(0.5,-1.35,0)); // Пивот local относительно базы
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно подвески (коорд подвеска == коорд базы подвески)

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *base_BR->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(1,0,0),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно подвески

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));

        bw->addConstraint(Join,true);
        Susp_BR.JoinShassi = Join;

        // Теперь Регестрируем "зависимость" подвески от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = base_BR;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(0.5,-1.35,0);      // Координаты присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rot = btVector3(0,0,D2R(0));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(0.5,-1.35,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo2.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел
    }
     // Создание задней левой подвески
    {
        // Сперва распологаем базу
        base_BL->SetPos(btVector3(0,0,0));
        base_BL->SetMass(1);

        // Теперь колесо
        Koleso_BL->SetPos(btVector3(0.35,0,0));
        Koleso_BL->SetRot(btVector3(0,0,D2R(180)));
        Koleso_BL->SetMass(1);

        // Создаем "Связь" подвеска - колесо
        btHingeConstraint* hinge = new btHingeConstraint(
                                                          *base_BL->GetRigitBody(),
                                                          *Koleso_BL->GetRigitBody(),
                                                          btVector3(0.35,0,0), // pivot A
                                                          btVector3(0,0,0), // pivot B
                                                          btVector3(1,0,0), // axis A
                                                          btVector3(-1,0,0), // axis B
                                                          true);
        bw->addConstraint(hinge,true);
        Susp_BL.JoinWhel = hinge;

        //Регестрируем "зависимость" колеса от подвески
        MONode JoinInfo;  // узел связи, инфа о нем
        JoinInfo.ConstrType = TypeOfConstraint::HINGE_CONSTR; // тип соединения
        JoinInfo.mo = Koleso_BL;                // что хотим подсоединяем (МО)
        JoinInfo.pos = btVector3(0.35,0,0);      // Координаты присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительнотого к которому присоединяемся
        JoinInfo.rotParent = btVector3(0,0,0);  // Начальный поворот того МО к которому присоединяемся
        JoinInfo.pivotBase = btVector3(0.35,0,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo.axisBase = btVector3(1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo.axisMO = btVector3(1,0,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo.constraint = hinge;        // Соединение

        base_BL->AddMO(JoinInfo); // прикрепляем подузел

        //Теперь присоединяем подвеску к корпусу
        // Сперва создаем соединение

        // распологаем  подвеску
        //SetPos(btVector3(0,0,0)); //База
        //SetRot(btVector3(0,0,D2R(90))); //База

        base_BL->SetPos(btVector3(-0.5,-1.35,0)); // Подвеска (база и колесо)
        base_BL->SetRot(btVector3(0,0,D2R(180)));
        //ktl->SetPos(btVector3(-3,2,2));

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(-0.5,-1.35,0)); // Пивот local относительно базы
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно подвески (коорд подвеска == коорд базы подвески)

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *base_BL->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(-1,0,0),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно подвески

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));

        bw->addConstraint(Join,true);
        Susp_BL.JoinShassi = Join;

        // Теперь Регестрируем "зависимость" подвески от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = base_BL;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(-0.5,-1.35,0);      // Координаты присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rot = btVector3(0,0,D2R(180));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(-0.5,-1.35,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo2.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(-1,0,0);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел
    }
    //SetPos(btVector3(100,100,0));

    //Теперь прикрутим кузов
    {
        Korpus = new MultiObject(bw,root);
        Korpus->Init(RM->getKorpus_AMDB9(),RM->getKorpus_Collision_AMDB9(), CollisionGroups::KORPUS, CollisionGroups::ALL & ~CollisionGroups::WHELL);

        // Разместим корпус
        Korpus->SetPos(btVector3(0,0,-0.35));//-0,35

        // Создадим связь корпус - подвеска

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(0,0,-0.35)); // Пивот local относительно базы //-0.35
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно корауса

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *Korpus->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(0,0,1),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно корпуса

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));



        bw->addConstraint(Join,true);

        // Теперь Регестрируем "зависимость" корпуса от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = Korpus;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(0,0,-0.35);      // Координаты присоединяемого МО относительно того к которому присоединяемся //-0.35
        JoinInfo2.rot = btVector3(0,0,D2R(0));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(0,0,-0.35); // Пивот относительно МультиОбъекта к которому присоединяемся //-0.35
        JoinInfo2.pivotMO = btVector3(0,0,0);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(0,0,1);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел

        //Korpus->GetRigitBody()->

    }
    //Теперь прикрутим Мотор
    {
        Engine = new MultiObject(bw,root);
        Engine->Init(RM->getEngine_AMDB9(),RM->getEngine_AMDB9(), CollisionGroups::ENGINE, CollisionGroups::NONE);

        // Разместим Мотор
        Engine->SetPos(btVector3(0,1,0.1));

        // Создадим связь корпус - подвеска

        btTransform tA, tB;
        tA.setIdentity();
        tB.setIdentity();
        tA.setOrigin(btVector3(0,1,0.1)); // Пивот local относительно базы
        tB.setOrigin(btVector3(0,0,0)); // Пивот local относительно корауса

        btGeneric6DofConstraint * Join = new btGeneric6DofConstraint(
                                *body,
                                *Engine->GetRigitBody(),
                                tA,
                                tB,
                                true);

        Join->setAxis(
            btVector3(0,0,1),  // ось вращения (соединения) относительно базы
            btVector3(0,1,0)); // ось вращения (соединения) относительно корпуса

        Join->setLinearLowerLimit(btVector3(0,0,0)); // полностью окраничиваем все вращения
        Join->setLinearUpperLimit(btVector3(0,0,0));
        Join->setAngularLowerLimit(btVector3(0,0,0));
        Join->setAngularUpperLimit(btVector3(0,0,0));

        bw->addConstraint(Join,true);

        // Теперь Регестрируем "зависимость" двигла от базы
        MONode JoinInfo2;  // узел связи, инфа о нем
        JoinInfo2.ConstrType = TypeOfConstraint::STATIC_JOIN; // тип соединения
        JoinInfo2.mo = Engine;                // что хотим подсоединяем (МО)
        JoinInfo2.pos = btVector3(0,1,0.1);      // Координаты присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rot = btVector3(0,0,D2R(0));  // Поворот присоединяемого МО относительно того к которому присоединяемся
        JoinInfo2.rotParent = btVector3(0,0,D2R(0));  // Начальный поворот того МО к которому присоединяемся
        JoinInfo2.pivotBase = btVector3(0,0,0); // Пивот относительно МультиОбъекта к которому присоединяемся
        JoinInfo2.pivotMO = btVector3(0,1,0.1);   // Пивот относительно МультиОбъекта который присоединяем
        JoinInfo2.axisBase = btVector3(0,0,1);  // Ось вращения соединения относительно МО к которому присоединяемся
        JoinInfo2.axisMO = btVector3(0,1,0);     // Ось вращения соединения относительно МО который присоединяем
        JoinInfo2.constraint = Join;        // Соединение

        AddMO(JoinInfo2); // прикрепляем подузел

        //Korpus->GetRigitBody()->

    }

    SetPos(OldPos);
}

void SimpleCar::SetMassEngine(double arg)
{
    if(!ready) return;
    Engine->SetMass(arg);
}
void SimpleCar::SetCarMass(double arg)
{
    double countPart = 10.0;
    if(!ready) return;

    this->SetMass(arg/countPart);
    Korpus->SetMass(arg/countPart);

    Susp_TR.base->SetMass(arg/countPart);
    Susp_TR.whell->SetMass(arg/countPart);

    Susp_TL.base->SetMass(arg/countPart);
    Susp_TL.whell->SetMass(arg/countPart);

    Susp_BR.base->SetMass(arg/countPart);
    Susp_BR.whell->SetMass(arg/countPart);

    Susp_BL.base->SetMass(arg/countPart);
    Susp_BL.whell->SetMass(arg/countPart);
}
btRigidBody* SimpleCar::GetCarKorpusRB()
{
    return Korpus->GetRigitBody();
}
void SimpleCar::Tormoz()
{
    Susp_TL.JoinWhel->setLimit(Susp_TL.JoinWhel->getHingeAngle(),Susp_TL.JoinWhel->getHingeAngle());
    Susp_TR.JoinWhel->setLimit(Susp_TR.JoinWhel->getHingeAngle(),Susp_TR.JoinWhel->getHingeAngle());
    Susp_BL.JoinWhel->setLimit(Susp_BL.JoinWhel->getHingeAngle(),Susp_BL.JoinWhel->getHingeAngle());
    Susp_BR.JoinWhel->setLimit(Susp_BR.JoinWhel->getHingeAngle(),Susp_BR.JoinWhel->getHingeAngle());
}
double SimpleCar::GetMassEngine()
{
    return Engine->GetMass();
}
double SimpleCar::GetCarMass()
{
    return this->GetMass()*10.0;
}
