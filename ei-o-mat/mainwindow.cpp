#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Eiertimer.h"
#include <QWidget>
#include <QtMath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(MainWindow::TimeChanged,SIGNAL(TimeChanged(QTime)),Eiertimer,SLOT(receiveTime(QTime)));
    connect()
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::calc_time()
{
    qreal L = 0.47311;   // Constante abhängig von Wärmewiderstand und Wärmekapazität von Eigelb und Eiklar
    qreal mass = ui->spinBox->value();
    qreal T_wasser = 100 - (0.003354 * ui->altitude->value());     // Berechung in abhängigkeit von der eingabe höhe über Null
    qreal T_start = ui->spinBoxStarttemp->value();      // Berechung in abhängigkeit der eingabe (Temperatur oder Kühlschrank)
    qreal T_ende = ui->dial->value();       // Berechung in abhängigkeit von Garzustand des Eigelbs

    //qreal Altitude=ui->altitude->value();
    //qDebug() <<Altitude*mass<<endl;
    qreal massehoch23 = qPow(mass, (2/3));
    qreal time = L*massehoch23 * qLn(0.76*(T_wasser-T_start)/(T_wasser-T_ende));
    time = 305;
    QTime time2(0,0,0);
    QTime time3 = time2.addSecs(time);

    QString output;
    output.number(time);

    ui->calculatedTime->display(time);
    qreal i = ui->label_10->

    ui->label_10->setText(time3.toString("mm:ss"));

    emit valueChanged(time);

}


void MainWindow::on_ButtonSizeS_clicked()
{
    ui->spinBox->setValue(48);
    calc_time();
}
void MainWindow::on_ButtonSizeM_clicked()
{
    ui->spinBox->setValue(58);
}
void MainWindow::on_ButtonSizeL_clicked()
{
    ui->spinBox->setValue(68);
}
void MainWindow::on_ButtonSizeXL_clicked()
{
    ui->spinBox->setValue(78);
}
void MainWindow::on_ButtonSizeOstrich_clicked()
{
    ui->spinBox->setValue(1500);
}
void MainWindow::on_spinBox_textChanged(const QString &arg1)
{
    ui->ButtonSizeS->setAutoExclusive(false);
    ui->ButtonSizeM->setAutoExclusive(false);
    ui->ButtonSizeL->setAutoExclusive(false);
    ui->ButtonSizeXL->setAutoExclusive(false);
    ui->ButtonSizeOstrich->setAutoExclusive(false);
    ui->ButtonSizeS->setChecked(false);
    ui->ButtonSizeM->setChecked(false);
    ui->ButtonSizeL->setChecked(false);
    ui->ButtonSizeXL->setChecked(false);
    ui->ButtonSizeOstrich->setChecked(false);
    ui->ButtonSizeS->setAutoExclusive(true);
    ui->ButtonSizeM->setAutoExclusive(true);
    ui->ButtonSizeL->setAutoExclusive(true);
    ui->ButtonSizeXL->setAutoExclusive(true);
    ui->ButtonSizeOstrich->setAutoExclusive(true);

    int i = ui->spinBox->value();

    if ((43 <= i) && (i < 53)){
        ui->ButtonSizeS->setChecked(true);
    }
    if ((53 <= i) && (i < 63)){
        ui->ButtonSizeM->setChecked(true);
    }
    if ((63 <= i) && (i < 73)){
        ui->ButtonSizeL->setChecked(true);
    }
    if ((73 <= i) && (i < 83)){
        ui->ButtonSizeXL->setChecked(true);
    }
    if ((1300 <= i) && (i < 1900)){
        ui->ButtonSizeOstrich->setChecked(true);
    }
    calc_time();
}

void MainWindow::on_start_Timer_clicked()
{
    //window();
    QWidget *w=new Eiertimer;
    Eiertimer *neuesFester = new Eiertimer(w);
    w->show();
}

void MainWindow::on_altitude_textChanged(const QString &arg1)
{
    int i = ui->altitude->value();
    ui->comboBox->setCurrentIndex(3);
    if (i==115)
    {
        ui->comboBox->setCurrentIndex(0);
    }
    if (i==250)
    {
        ui->comboBox->setCurrentIndex(1);
    }
    if (i==2960)
    {
        ui->comboBox->setCurrentIndex(2);
    }
    calc_time();
}


void MainWindow::on_radioButtonKuehlschrank_clicked()
{
    ui->spinBoxStarttemp->setValue(7);
}
void MainWindow::on_radioButtonRaumtemperatur_clicked()
{
    ui->spinBoxStarttemp->setValue(20);
}
void MainWindow::on_spinBoxStarttemp_textChanged(const QString &arg1)
{
    ui->radioButtonRaumtemperatur->setAutoExclusive(false);
    ui->radioButtonKuehlschrank->setAutoExclusive(false);
    ui->radioButtonRaumtemperatur->setChecked(false);
    ui->radioButtonKuehlschrank->setChecked(false);
    ui->radioButtonRaumtemperatur->setAutoExclusive(true);
    ui->radioButtonKuehlschrank->setAutoExclusive(true);


    int i = ui->spinBoxStarttemp->value();

    if (i == 20){
        ui->radioButtonRaumtemperatur->setChecked(true);
    }
    if (i == 7){
        ui->radioButtonKuehlschrank->setChecked(true);
    }
    calc_time();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0) // Karlsruhe
    {
        ui->altitude->setValue(115);
    }
    if (index == 1) // Stuttgart
    {
        ui->altitude->setValue(250);
    }
    if (index == 2) // Zugspitze
    {
        ui->altitude->setValue(2960);
    }
    if (index == 3) // Benutzerdefiniert
    {

    }
    calc_time();
}

void MainWindow::on_dial_valueChanged(int value)
{
    calc_time();
}
