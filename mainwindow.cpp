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
