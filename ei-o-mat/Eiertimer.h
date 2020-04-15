#ifndef EIERTIMER_H
#define EIERTIMER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

namespace Ui {
class Eiertimer;
}

class Eiertimer : public QMainWindow
{
    Q_OBJECT

public:
    QTime *displayTime = new QTime;
    QTimer *timer = new QTimer;
    bool buttonStart = true;

public:
    explicit Eiertimer(QWidget *parent = 0);
    ~Eiertimer();


protected slots:
    void updateTime();

private slots:
    void on_startButton_clicked();

private:
    Ui::Eiertimer *ui;
};

#endif // EIERTIMER_H
