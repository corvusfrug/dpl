#include "mainwindow.h"
#include <QApplication>
#include "modelinfo.h"
#include "model.h"

int main(int argc, char *argv[])
{
    //ResourceManager* man = new ResourceManager();
    Model* model = new Model();
    qDebug() << "READY Load Model\n";
    QApplication a(argc, argv);
    //qDebug() << "EROR2!!!\n";
    //ResourceManager* man = new ResourceManager();
    MainWindow w;
    //qDebug() << "EROR3!!!\n";
    w.SetModel(model);
    //qDebug() << "EROR4!!!\n";
    w.show();
    //qDebug() << "ERROR5!!!\n";

    return a.exec();
}
