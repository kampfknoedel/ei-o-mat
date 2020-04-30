#include "eiertimer.h"
#include "ui_eiertimer.h"


Eiertimer::Eiertimer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Eiertimer)
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->setSingleShot(true);

    //const bool connected = connect(eingabefenster, &Eingabefenster::TimeChanged, this, &Eiertimer::receiveTime);

    //qDebug() << "Connection established?" << connected;
}

Eiertimer::~Eiertimer()
{
    delete ui;
}

void Eiertimer::on_startButton_clicked()
{
    if(buttonStart == true)
    {
        buttonStart = false;
        ui->startButton->setText("Stop");
      //  ui->timeEdit->setEnabled(false);
      //  *displayTime = ui->timeEdit->time();
        ui->calculatedTime->display(displayTime->toString("mm:ss"));
        timer->start(1000);
    }
    else
    {
        buttonStart = true;
        ui->startButton->setText("Start");
     //   ui->timeEdit->setEnabled(true);
   //     ui->timeEdit->setTime(*displayTime);
        timer->stop();
    }
}

void Eiertimer::updateTime()
{
    QTime newTime = displayTime->addSecs(-1);
    displayTime->setHMS(newTime.hour(),newTime.minute(),newTime.second());
    ui->calculatedTime->display(displayTime->toString("mm:ss"));
    if(displayTime->hour() != 0 ||
            displayTime->minute() != 0 ||
            displayTime->second() != 0)
    {
        timer->start(1000);
    }
    else
    {
        buttonStart = true;
        ui->startButton->setText("Start");
        timer->stop();
    }
}
void Eiertimer::receiveTime(QTime time)
{
    //ui->timeEdit->setTime(time);
    *displayTime = time;
    *displayTimeAlt = time;
    ui->calculatedTime->display(displayTime->toString("mm:ss"));
}

void Eiertimer::on_resetButton_clicked()
{
    timer->stop();
    *displayTime = *displayTimeAlt;
    ui->startButton->setText("Start");
    ui->calculatedTime->display(displayTime->toString("mm:ss"));
    buttonStart = true;

}
