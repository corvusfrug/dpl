#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtXml>
#include "modelinfo.h"
#include "model.h"

namespace Ui {

class MainWindow;
}

enum TypeXMLNode
{
    NONE_type=0,
    CAMERA,
    AUTO,
    TARGET
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void SetModel(Model* m);
    ~MainWindow();
public slots:
    void CurrentAutoREDACT(AutoInfo* lastai);
    void CountAutoREDACT(int count);
    void TormozChecked();
    void SendRunModel();
    void PrintResult(std::vector<std::vector<AutoInfo*>> Log);
    void SaveModel();
    void OpenModel();
signals:
    void RunModelSignal(ModelInfo* mi);


private:
    void traverseNode(const QDomNode& node, TypeXMLNode type=TypeXMLNode::NONE_type, int countAuto=0);

    Ui::MainWindow *ui;
    ModelInfo modInfo;
    int CurrentRow;
    Model* model;
    CameraInfo cam;

};

#endif // MAINWINDOW_H
