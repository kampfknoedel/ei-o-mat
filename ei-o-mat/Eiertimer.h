#ifndef EIERTIMER_H
#define EIERTIMER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <QSound>
#include <QDir>

//#include "eingabefenster.h"

namespace Ui {
class Eiertimer;
}

class Eiertimer : public QWidget
{
    Q_OBJECT

public:
    QTime *displayTime = new QTime;
    QTime *displayTimeAlt = new QTime;
    QTimer *timer = new QTimer;
    bool buttonStart = true;
    QString dir_alarm;


public:
    explicit Eiertimer(QWidget *parent = nullptr);
    ~Eiertimer();

protected slots:
    void updateTime();

private slots:
    void on_startButton_clicked();
    void receiveTime(QTime time);
    void receiveDir(QString dir);
    void on_resetButton_clicked();

    void on_pushButton_5sec_clicked();

private:
    Ui::Eiertimer *ui;
   // Eingabefenster* eingabefenster;
};

#endif // EIERTIMER_H
