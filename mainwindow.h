#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modelinfo.h"
#include "model.h"

namespace Ui {
class MainWindow;
}

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
    void SendRunModel();
    void PrintResult(std::vector<std::vector<AutoInfo*>> Log);
signals:
    void RunModelSignal(ModelInfo* mi);


private:
    Ui::MainWindow *ui;
    ModelInfo modInfo;
    int CurrentRow;
    Model* model;
    CameraInfo cam;

};

#endif // MAINWINDOW_H
