#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void CalcWeightInGramm(QString *Eggsize);
    QString CalcSize(int Weight);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


