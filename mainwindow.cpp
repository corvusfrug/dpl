#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //modInfo.PrintTest();
    //model = m;
    //ResourceManager* rm = new ResourceManager();
    //modInfo.PrintTest();


    //ui->tab_5->setVisible(false);
    ui->tab_5->setEnabled(false);

    QWidget* ftab = ui->tab_6;
    ui->tabWidget_2->clear();
    ui->tabWidget_2->addTab(ftab,QString("Моделирование"));

    //ui->tab_5->setHidden(false);

    CurrentRow=0;
    ui->SB_NumAutos->setValue(modInfo.GetCount());
    ui->SB_Gravity->setValue(modInfo.GetGravity());
    ui->SB_Friction->setValue(modInfo.GetFriction());
    for(int i = 0; i<modInfo.GetCount(); ++i)
    {
        ui->ListAuto->addItem(QString("Автомобиль ")+QString().setNum(i+1));
    };
    ui->ListAuto->setCurrentRow(0);
    AutoInfo* tmp = modInfo.GetCurrentAuto();
    ui->SB_Mass->setValue(tmp->GetMass());
    ui->SB_Mass_Engine->setValue(tmp->GetMassEngine());
    ui->SB_Speed->setValue(tmp->GetLVelosityForward());
    ui->SP_Pos_X->setValue(tmp->GetPosX());
    ui->SP_Pos_Y->setValue(tmp->GetPosY());
    ui->SP_Pos_Z->setValue(tmp->GetPosZ());
    ui->SP_Azimut->setValue(tmp->GetRotZ());
    ui->dial_Azimut->setValue(tmp->GetRotZ());

    QObject::connect(ui->dial_Azimut, SIGNAL(valueChanged(int)), ui->SP_Azimut, SLOT(setValue(int)));
    QObject::connect(ui->SP_Azimut, SIGNAL(valueChanged(int)), ui->dial_Azimut, SLOT(setValue(int)));

    QObject::connect(&modInfo, SIGNAL(SwitchCountAuto(int)), this, SLOT(CountAutoREDACT(int)));
    QObject::connect(&modInfo, SIGNAL(SwitchCurrentAuto(AutoInfo*)), this, SLOT(CurrentAutoREDACT(AutoInfo*)));

    QObject::connect(ui->BTN_Run_Model, SIGNAL(clicked()), this, SLOT(SendRunModel()));
    //QObject::connect(this, SIGNAL(RunModelSignal(ModelInfo*)), model, SLOT(initModel(ModelInfo*)));

    QObject::connect(ui->SB_NumAutos, SIGNAL(valueChanged(int)), &modInfo, SLOT(SetCount(int)));
    QObject::connect(ui->SB_Friction, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetFriction(double)));
    QObject::connect(ui->SB_Gravity, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetGravity(double)));
    QObject::connect(ui->SB_Frequency, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetFrequency(double)));

    //CameraInfo* ctmp = modInfo.GetCamInfo();
    QObject::connect(ui->SP_Pos_Cam_X, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetPosCamX(double)));
    QObject::connect(ui->SP_Pos_Cam_Y, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetPosCamY(double)));
    QObject::connect(ui->SP_Pos_Cam_Z, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetPosCamZ(double)));
    QObject::connect(ui->SP_Pos_Cam_Target_X, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetTargCamX(double)));
    QObject::connect(ui->SP_Pos_Cam_Target_Y, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetTargCamY(double)));
    QObject::connect(ui->SP_Pos_Cam_Target_Z, SIGNAL(valueChanged(double)), &modInfo, SLOT(SetTargCamZ(double)));

    QObject::connect(ui->ListAuto, SIGNAL(currentRowChanged(int)), &modInfo, SLOT(SetCurrentAuto(int)));


    QObject::connect(ui->SB_Mass, SIGNAL(valueChanged(int)), tmp, SLOT(SetMass(int)));
    QObject::connect(ui->SB_Mass_Engine, SIGNAL(valueChanged(int)), tmp, SLOT(SetMassEngine(int)));

    QObject::connect(ui->SP_Azimut, SIGNAL(valueChanged(int)), tmp, SLOT(SetRot(int)));
    QObject::connect(ui->dial_Azimut, SIGNAL(valueChanged(int)), tmp, SLOT(SetRot(int)));

    QObject::connect(ui->SP_Pos_X, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosX(double)));
    QObject::connect(ui->SP_Pos_Y, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosY(double)));
    QObject::connect(ui->SP_Pos_Z, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosZ(double)));

    QObject::connect(ui->SB_Speed, SIGNAL(valueChanged(double)), tmp, SLOT(SetLVelosity(double)));

    // Блокировка колес
    QObject::connect(ui->RB_block_1s, SIGNAL(clicked()), this, SLOT(TormozChecked()));
    QObject::connect(ui->RB_block_now, SIGNAL(clicked()), this, SLOT(TormozChecked()));
    QObject::connect(ui->RB_block_collide, SIGNAL(clicked()), this, SLOT(TormozChecked()));
    QObject::connect(ui->RB_block_never, SIGNAL(clicked()), this, SLOT(TormozChecked()));

    //  Сохранение и загрузка модели
    QObject::connect(ui->BTN_Save_model, SIGNAL(clicked()), this, SLOT(SaveModel()));
    QObject::connect(ui->BTN_Open_model, SIGNAL(clicked()), this, SLOT(OpenModel()));

}

void MainWindow::SetModel(Model* m)
{
    model = m;
    QObject::connect(this, SIGNAL(RunModelSignal(ModelInfo*)), model, SLOT(initModel(ModelInfo*)));

    QObject::connect(model, SIGNAL(SendAutoInfo(std::vector<std::vector<AutoInfo*>>)), this,
                     SLOT(PrintResult(std::vector<std::vector<AutoInfo *> >)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CurrentAutoREDACT(AutoInfo* lastai)
{
    QObject::disconnect(ui->SB_Mass, SIGNAL(valueChanged(int)), lastai, SLOT(SetMass(int)));
    QObject::disconnect(ui->SB_Mass_Engine, SIGNAL(valueChanged(int)), lastai, SLOT(SetMassEngine(int)));

    QObject::disconnect(ui->SP_Azimut, SIGNAL(valueChanged(int)), lastai, SLOT(SetRot(int)));
    QObject::disconnect(ui->dial_Azimut, SIGNAL(valueChanged(int)), lastai, SLOT(SetRot(int)));

    QObject::disconnect(ui->SP_Pos_X, SIGNAL(valueChanged(double)), lastai, SLOT(SetPosX(double)));
    QObject::disconnect(ui->SP_Pos_Y, SIGNAL(valueChanged(double)), lastai, SLOT(SetPosY(double)));
    QObject::disconnect(ui->SP_Pos_Z, SIGNAL(valueChanged(double)), lastai, SLOT(SetPosZ(double)));

    QObject::disconnect(ui->SB_Speed, SIGNAL(valueChanged(double)), lastai, SLOT(SetLVelosity(double)));


    AutoInfo* tmp = modInfo.GetCurrentAuto();

    QObject::connect(ui->SB_Mass, SIGNAL(valueChanged(int)), tmp, SLOT(SetMass(int)));
    QObject::connect(ui->SB_Mass_Engine, SIGNAL(valueChanged(int)), tmp, SLOT(SetMassEngine(int)));

    QObject::connect(ui->SP_Azimut, SIGNAL(valueChanged(int)), tmp, SLOT(SetRot(int)));
    QObject::connect(ui->dial_Azimut, SIGNAL(valueChanged(int)), tmp, SLOT(SetRot(int)));

    QObject::connect(ui->SP_Pos_X, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosX(double)));
    QObject::connect(ui->SP_Pos_Y, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosY(double)));
    QObject::connect(ui->SP_Pos_Z, SIGNAL(valueChanged(double)), tmp, SLOT(SetPosZ(double)));

    QObject::connect(ui->SB_Speed, SIGNAL(valueChanged(double)), tmp, SLOT(SetLVelosity(double)));

    ui->SB_Mass->setValue(tmp->GetMass());
    ui->SB_Mass_Engine->setValue(tmp->GetMassEngine());
    ui->SB_Speed->setValue(tmp->GetLVelosityForward());
    ui->SP_Pos_X->setValue(tmp->GetPosX());
    ui->SP_Pos_Y->setValue(tmp->GetPosY());
    ui->SP_Pos_Z->setValue(tmp->GetPosZ());
    ui->SP_Azimut->setValue(tmp->GetRotZ());
    //ui->dial_Azimut->setValue(tmp->GetRotZ());

    if(tmp->GetTormozType()==TormozType::NOW)
        ui->RB_block_now->setChecked(true);

    if(tmp->GetTormozType()==TormozType::SEC)
        ui->RB_block_1s->setChecked(true);

    if(tmp->GetTormozType()==TormozType::COLLIDE)
        ui->RB_block_collide->setChecked(true);

    if(tmp->GetTormozType()==TormozType::NEWER)
        ui->RB_block_never->setChecked(true);
}

void MainWindow::CountAutoREDACT(int count)
{
    //ui->ListAuto->currentItem();
    ui->ListAuto->clear();
    for(int i = 0; i<count; ++i)
    {
        ui->ListAuto->addItem(QString("Автомобиль ")+QString().setNum(i+1));
    };
    //ui->ListAuto->fi
    ui->ListAuto->setCurrentRow(modInfo.GetCurrentAutoNum());
}

void MainWindow::TormozChecked()
{
    if(ui->RB_block_now->isChecked())
        modInfo.GetCurrentAuto()->SetTormozType(TormozType::NOW);

    if(ui->RB_block_1s->isChecked())
        modInfo.GetCurrentAuto()->SetTormozType(TormozType::SEC);

    if(ui->RB_block_collide->isChecked())
        modInfo.GetCurrentAuto()->SetTormozType(TormozType::COLLIDE);

    if(ui->RB_block_never->isChecked())
        modInfo.GetCurrentAuto()->SetTormozType(TormozType::NEWER);
}

void MainWindow::SendRunModel()
{
    //modInfo.PrintTest();
    emit RunModelSignal(&modInfo);
}

void MainWindow::PrintResult(std::vector<std::vector<AutoInfo *> > Log)
{
    //ui->tab_5->setVisible(true);
    ui->tab_5->setEnabled(true);
    //ui->tab_5->setHidden(true);
    QWidget* ftab = ui->tab_6;
    ui->tabWidget_2->clear();
    ui->tabWidget_2->addTab(ftab,QString("Моделирование"));

    ui->lab_res_mod_data->setText(QDateTime::currentDateTime().toString());
    ui->lab_res_mod_count->setText(QString::number(modInfo.GetCount()));
    ui->lab_res_mod_grav->setText(QString::number(modInfo.GetGravity()));
    ui->lab_res_mod_fric->setText(QString::number(modInfo.GetFriction()));
    ui->lab_res_mod_time->setText(QString::number(modInfo.GetFrequencyTime()*Log[0].size()));
    ui->lab_res_mod_freq->setText(QString::number(modInfo.GetFrequency()));


    for(int i=0; i< Log.size();++i)
    {
        QWidget* tab = new QWidget(ui->tabWidget_2);
        ui->tabWidget_2->addTab(tab,QString("Автомобиль ")+QString().setNum(i+1));

        QLabel* lab = new QLabel(tab);
        lab->setText(QString("Масса корпуса"));
        lab->setGeometry(QRect(10,10,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(170,10,71,16));
        lab->setText(QString().setNum(Log[i][0]->GetMass()));

        lab = new QLabel(tab);
        lab->setText(QString("Масса двигателя"));
        lab->setGeometry(QRect(10,30,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(170,30,71,16));
        lab->setText(QString().setNum(Log[i][0]->GetMassEngine()));

        lab = new QLabel(tab);
        lab->setText(QString("Общая масса"));
        lab->setGeometry(QRect(10,50,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(170,50,71,16));
        lab->setText(QString().setNum(Log[i][0]->GetMass()+Log[i][0]->GetMassEngine()));

        lab = new QLabel(tab);
        lab->setText(QString("Начальная скорость"));
        lab->setGeometry(QRect(10,70,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(170,70,261,16));
        lab->setText(QString().setNum(Log[i][0]->GetLVelosityForward()));

        lab = new QLabel(tab);
        lab->setText(QString("Начальная позиция"));
        lab->setGeometry(QRect(250,10,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(410,10,221,16));
        lab->setText(
                        QString("(")+
                        QString().setNum(Log[i][0]->GetPosX()) +
                        QString(", ") +
                        QString().setNum(Log[i][0]->GetPosY()) +
                        QString(", ") +
                        QString().setNum(Log[i][0]->GetPosZ()) +
                        QString(")")
                    );

        lab = new QLabel(tab);
        lab->setText(QString("Начальный азимут"));
        lab->setGeometry(QRect(250,30,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(410,30,221,16));
        lab->setText(QString().setNum(Log[i][0]->GetRotZ()));

        lab = new QLabel(tab);
        lab->setText(QString("Конечная позиция"));
        lab->setGeometry(QRect(250,50,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(410,50,221,16));
        lab->setText(
                        QString("(")+
                        QString().setNum(Log[i][Log[i].size()-1]->GetPosX()) +
                        QString(", ") +
                        QString().setNum(Log[i][Log[i].size()-1]->GetPosY()) +
                        QString(", ") +
                        QString().setNum(Log[i][Log[i].size()-1]->GetPosZ()) +
                        QString(")")
                    );

        lab = new QLabel(tab);
        lab->setText(QString("Конечный азимут"));
        lab->setGeometry(QRect(250,70,141,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(410,70,221,16));
        lab->setText(QString().setNum(Log[i][Log[i].size()-1]->GetRotZ()));

        lab = new QLabel(tab);
        lab->setText(QString("Время первого столкновения"));
        lab->setGeometry(QRect(10,100,201,16));

        lab = new QLabel(tab);
        lab->setGeometry(QRect(210,100,141,16));
        AutoInfo* Crash = NULL;
        int nomCrash=0;
        for(int j=0;j<Log[i].size();++j)
            if(Log[i][j]->GetBam())
            {
                Crash=Log[i][j];
                nomCrash=j;
            }
        if(Crash==NULL)
            lab->setText(QString("Не сталкивался"));
        else
            lab->setText(QString().setNum(modInfo.GetFrequencyTime()*nomCrash));

        lab = new QLabel(tab);
        lab->setText(QString("Блокировка колес"));
        lab->setGeometry(QRect(340,100,201,16));

        lab = new QLabel(tab);
        //lab->setText(QString("Блокировка колес:"));
        lab->setGeometry(QRect(470,100,201,16));
        switch(Log[i][0]->GetTormozType())
        {
        case TormozType::NEWER:
            lab->setText(QString("Никогда"));
            break;
        case TormozType::SEC:
            lab->setText(QString("Через 5 секунд"));
            break;
        case TormozType::NOW:
            lab->setText(QString("Сразу"));
            break;
        case TormozType::COLLIDE:
            lab->setText(QString("После столкновения"));
            break;
        };

        lab = new QLabel(tab);
        lab->setText(QString("Весь лог"));
        lab->setGeometry(QRect(10,120,201,16));

        QTextBrowser* browser = new QTextBrowser(tab);
        browser->setGeometry(10,140,621,291);

        QString text;
        for(int j=0;j<Log[i].size();++j)
        {
            if(Log[i][j]->GetBam()) text += QString("!!! Столкновение !!! ");
            text += QString("Время: ") += QString().setNum(modInfo.GetFrequencyTime()*j)
                 += QString(" | ") += QString("Позиция: ") += QString("(")+=
                                                QString().setNum(Log[i][j]->GetPosX()) +=
                                                QString(", ") +=
                                                QString().setNum(Log[i][j]->GetPosY()) +=
                                                QString(", ") +=
                                                QString().setNum(Log[i][j]->GetPosZ()) +=
                                                QString(")\n");
            text += QString("Азимут: ")  += QString().setNum(Log[i][j]->GetRotZ()) += QString(" | ") += QString("Скорость: ")
                 += QString().setNum(Log[i][j]->GetLVelosityForward()) += QString("\n");
            text += QString("####################################\n");
        }
        browser->setText(text);
    }
}

void MainWindow::SaveModel()
{

    //QFileDialog* opdlg = new QFileDialog();
    QString str = QFileDialog::getSaveFileName(this, "Сохранить модель...", "NewModel", "*.gmod ; *.Gmod ; *.GMOD");
    //qDebug() << str << "\n";

    // создание хмл
    QDomDocument doc("Model");
    QDomElement element = doc.createElement("ModelInfo");
    doc.appendChild(element);

    QDomElement countAuto = doc.createElement("countAuto");
    QDomText countAutoVal = doc.createTextNode(QString().setNum(modInfo.GetCount()));
    countAuto.appendChild(countAutoVal);
    element.appendChild(countAuto);

    QDomElement gravity = doc.createElement("gravity");
    QDomText gravityVal = doc.createTextNode(QString().setNum(modInfo.GetGravity()));
    gravity.appendChild(gravityVal);
    element.appendChild(gravity);

    QDomElement friction = doc.createElement("friction");
    QDomText frictionVal = doc.createTextNode(QString().setNum(modInfo.GetFriction()));
    friction.appendChild(frictionVal);
    element.appendChild(friction);

    QDomElement frequency = doc.createElement("frequency");
    QDomText frequencyVal = doc.createTextNode(QString().setNum(modInfo.GetFrequency()));
    frequency.appendChild(frequencyVal);
    element.appendChild(frequency);

    // Запишем камеру
    CameraInfo* cam = modInfo.GetCamInfo();
    QDomElement Camera = doc.createElement("CameraInfo");

    QDomElement CamPos = doc.createElement("pos");

    QDomElement posCamX = doc.createElement("X");
    QDomText posCamXVal = doc.createTextNode(QString().setNum(cam->GetPosX()));
    posCamX.appendChild(posCamXVal);
    CamPos.appendChild(posCamX);

    QDomElement posCamY = doc.createElement("Y");
    QDomText posCamYVal = doc.createTextNode(QString().setNum(cam->GetPosY()));
    posCamY.appendChild(posCamYVal);
    CamPos.appendChild(posCamY);

    QDomElement posCamZ = doc.createElement("Z");
    QDomText posCamZVal = doc.createTextNode(QString().setNum(cam->GetPosZ()));
    posCamZ.appendChild(posCamZVal);
    CamPos.appendChild(posCamZ);

    Camera.appendChild(CamPos);

    QDomElement CamTarg = doc.createElement("target");

    QDomElement posCamTargX = doc.createElement("X");
    QDomText posCamTargXVal = doc.createTextNode(QString().setNum(cam->GetTargX()));
    posCamTargX.appendChild(posCamTargXVal);
    CamTarg.appendChild(posCamTargX);

    QDomElement posCamTargY = doc.createElement("Y");
    QDomText posCamTargYVal = doc.createTextNode(QString().setNum(cam->GetTargY()));
    posCamTargY.appendChild(posCamTargYVal);
    CamTarg.appendChild(posCamTargY);

    QDomElement posCamTargZ = doc.createElement("Z");
    QDomText posCamTargZVal = doc.createTextNode(QString().setNum(cam->GetTargZ()));
    posCamTargZ.appendChild(posCamTargZVal);
    CamTarg.appendChild(posCamTargZ);

    Camera.appendChild(CamTarg);

    element.appendChild(Camera);


    // Запишем все автомобили
    QDomElement Autos = doc.createElement("AutoInfos");

    std::vector<AutoInfo*> autos = modInfo.GetAllAutoInfo();
    for(int i = 0; i < autos.size(); ++i)
    {
        QDomElement Auto = doc.createElement("AutoInfo");
        QDomAttr atr = doc.createAttribute("name");
        atr.setValue(QString("Автомобиль ")+QString().setNum(i+1));
        Auto.setAttributeNode(atr);

        QDomElement mass = doc.createElement("mass");
        QDomText massVal = doc.createTextNode(QString().setNum(autos[i]->GetMass()));
        mass.appendChild(massVal);
        Auto.appendChild(mass);

        QDomElement massEngine = doc.createElement("massEngine");
        QDomText massEngineVal = doc.createTextNode(QString().setNum(autos[i]->GetMassEngine()));
        massEngine.appendChild(massEngineVal);
        Auto.appendChild(massEngine);

        QDomElement azimut = doc.createElement("azimut");
        QDomText azimutVal = doc.createTextNode(QString().setNum(autos[i]->GetRotZ()));
        azimut.appendChild(azimutVal);
        Auto.appendChild(azimut);

        QDomElement velosity = doc.createElement("velosity");
        QDomText velosityVal = doc.createTextNode(QString().setNum(autos[i]->GetLVelosityForward()));
        velosity.appendChild(velosityVal);
        Auto.appendChild(velosity);

        QDomElement tormozT = doc.createElement("tormozT");

        QDomText tormozTVal;
        switch(autos[i]->GetTormozType())
        {
            case TormozType::NEWER:
            tormozTVal = doc.createTextNode(QString("NEWER"));
            break;
            case TormozType::SEC:
            tormozTVal = doc.createTextNode(QString("SEC"));
            break;
            case TormozType::NOW:
            tormozTVal = doc.createTextNode(QString("NOW"));
            break;
            case TormozType::COLLIDE:
            tormozTVal = doc.createTextNode(QString("COLLIDE"));
            break;
        }
        tormozT.appendChild(tormozTVal);
        Auto.appendChild(tormozT);

        QDomElement pos = doc.createElement("pos");

        QDomElement posX = doc.createElement("X");
        QDomText posXVal = doc.createTextNode(QString().setNum(autos[i]->GetPosX()));
        posX.appendChild(posXVal);
        pos.appendChild(posX);

        QDomElement posY = doc.createElement("Y");
        QDomText posYVal = doc.createTextNode(QString().setNum(autos[i]->GetPosY()));
        posY.appendChild(posYVal);
        pos.appendChild(posY);

        QDomElement posZ = doc.createElement("Z");
        QDomText posZVal = doc.createTextNode(QString().setNum(autos[i]->GetPosZ()));
        posZ.appendChild(posZVal);
        pos.appendChild(posZ);

        Auto.appendChild(pos);

        Autos.appendChild(Auto);
    }
    element.appendChild(Autos);

    //Запись
    if(!(str.toLower()).endsWith(".gmod"))
        str.append(".gmod");
    QFile file(str);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << doc.toString();
        file.close();
    };
    QMessageBox::information(0, "Сохранение модели","Модель\n" + str + "\nСохранена!");
    QStringList strl = str.split('/');
    this->setWindowTitle(strl.back());

}

void MainWindow::OpenModel()
{
    QString str = QFileDialog::getOpenFileName(this, "Открыть модель...", "", "*.gmod *.Gmod *.GMOD *.gMOD *.GMod");
    QDomDocument doc;
    //ModelInfo modinf;
    QFile file(str);
    if(file.open(QIODevice::ReadOnly))
    {
        if(doc.setContent(&file))
        {
            QDomElement element = doc.documentElement();
            traverseNode(element, TypeXMLNode::NONE_type, -1);
        }
        file.close();
    }
    CurrentAutoREDACT(modInfo.GetCurrentAuto());
    QMessageBox::information(0, "Открытие модели","Модель\n" + str + "\nЗагружена!");
    QStringList strl = str.split('/');
    this->setWindowTitle(strl.back());
}


void MainWindow::traverseNode(const QDomNode& node, TypeXMLNode type, int countAuto)
{
    static int currentAutoInd=-1;
    if(countAuto==-1) currentAutoInd = countAuto;
    static TypeXMLNode currType=type;
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if(domNode.isElement())
        {
            QDomElement element = domNode.toElement();
            if(!element.isNull())
            {
                if(element.tagName() == "countAuto")
                {
                    int tmp = element.text().toInt();
                    if(tmp>0)
                    {
                        modInfo.SetCount(tmp);
                        ui->SB_NumAutos->setValue(modInfo.GetCount());
                    }
                }
                if(element.tagName() == "gravity")
                {
                    double tmp = element.text().toDouble();
                    //if(tmp > 0)
                    {
                        modInfo.SetGravity(tmp);
                        ui->SB_Gravity->setValue(modInfo.GetGravity());
                    }
                }
                if(element.tagName() == "friction")
                {
                    double tmp = element.text().toDouble();
                    if(tmp>0)
                    {
                        modInfo.SetFriction(tmp);
                        ui->SB_Friction->setValue(modInfo.GetFriction());
                    }
                }
                if(element.tagName() == "frequency")
                {
                    double tmp = element.text().toDouble();
                    if(tmp>0 && tmp < 10)
                    {
                        modInfo.SetFrequency(tmp);
                        ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
                if(element.tagName() == "CameraInfo")
                {
                    currType=TypeXMLNode::CAMERA;//traverseNode(domNode,TypeXMLNode::CAMERA);
                }
                if(element.tagName() == "AutoInfo")
                {
                    currentAutoInd++;
                    currType=TypeXMLNode::AUTO;//traverseNode(domNode,TypeXMLNode::AUTO);
                }
                if(element.tagName() == "target")
                {
                    currType=TypeXMLNode::TARGET;//traverseNode(domNode,TypeXMLNode::TARGET);
                }
                if(element.tagName() == "X")
                {
                    if(type==TypeXMLNode::CAMERA)
                    {
                        modInfo.GetCamInfo()->SetPosX(element.text().toDouble());
                        ui->SP_Pos_Cam_X->setValue(modInfo.GetCamInfo()->GetPosX());
                    }
                    if(type==TypeXMLNode::TARGET)
                    {
                        modInfo.GetCamInfo()->SetTargX(element.text().toDouble());
                        ui->SP_Pos_Cam_Target_X->setValue(modInfo.GetCamInfo()->GetTargX());
                    }
                    if(type==TypeXMLNode::AUTO)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetPosX(element.text().toDouble());
                        //CurrentAutoREDACT(modInfo.GetCurrentAuto());
                    }
                }
                if(element.tagName() == "Y")
                {
                    if(type==TypeXMLNode::CAMERA)
                    {
                        modInfo.GetCamInfo()->SetPosY(element.text().toDouble());
                        ui->SP_Pos_Cam_Y->setValue(modInfo.GetCamInfo()->GetPosY());
                    }
                    if(type==TypeXMLNode::TARGET)
                    {
                        modInfo.GetCamInfo()->SetTargY(element.text().toDouble());
                        ui->SP_Pos_Cam_Target_Y->setValue(modInfo.GetCamInfo()->GetTargY());
                    }
                    if(type==TypeXMLNode::AUTO)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetPosY(element.text().toDouble());
                        //CurrentAutoREDACT(modInfo.GetCurrentAuto());
                    }
                }
                if(element.tagName() == "Z")
                {
                    if(type==TypeXMLNode::CAMERA)
                    {
                        modInfo.GetCamInfo()->SetPosZ(element.text().toDouble());
                        ui->SP_Pos_Cam_Z->setValue(modInfo.GetCamInfo()->GetPosZ());
                    }
                    if(type==TypeXMLNode::TARGET)
                    {
                        modInfo.GetCamInfo()->SetTargZ(element.text().toDouble());
                        ui->SP_Pos_Cam_Target_Z->setValue(modInfo.GetCamInfo()->GetTargZ());
                    }
                    if(type==TypeXMLNode::AUTO)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetPosZ(element.text().toDouble());
                        //CurrentAutoREDACT(modInfo.GetCurrentAuto());
                    }
                }
                if(element.tagName() == "mass")
                {
                    double tmp = element.text().toInt();
                    if(tmp>0)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetMass(tmp);
                        //ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
                if(element.tagName() == "massEngine")
                {
                    double tmp = element.text().toInt();
                    if(tmp>0)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetMassEngine(tmp);
                        //ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
                if(element.tagName() == "velosity")
                {
                    double tmp = element.text().toDouble();
                    //if(tmp>0)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetLVelosity(tmp);
                        //ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
                if(element.tagName() == "azimut")
                {
                    double tmp = element.text().toInt();
                    if(tmp>=-179 && tmp<=180)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetRot(tmp);
                        //ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
                if(element.tagName() == "tormozT")
                {
                    QString tmp = element.text();
                    TormozType tmp2=TormozType::COLLIDE;
                    if(tmp=="NEWER") tmp2 = TormozType::NEWER;
                    if(tmp=="NOW") tmp2 = TormozType::NOW;
                    if(tmp=="SEC") tmp2 = TormozType::SEC;
                    //if(tmp>=-179 && tmp<=180)
                    {
                        (modInfo.GetAllAutoInfo())[currentAutoInd]->SetTormozType(tmp2);
                        //ui->SB_Frequency->setValue(modInfo.GetFrequency());
                    }
                }
            }
        }
        traverseNode(domNode, currType);
        currType=type;
        domNode=domNode.nextSibling();
    }
}
