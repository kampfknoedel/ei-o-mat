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
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::calc_time()
{
    qreal L = 0.47311;   // Constante abhängig von Wärmewiderstand und Wärmekapazität von Eigelb und Eiklar
    qreal mass = ui->spinBox->value();
    qreal T_wasser = 0;     // Berechung in abhängigkeit von der eingabe hähe über Null
    qreal T_start = 0;      // Berechung in abhängigkeit der eingabe (Temperatur oder Kühlschrank)
    qreal T_ende = 0;       // Berechung in abhängigkeit von Garzustand des Eigelbs
    qreal Altitude=ui->altitude->value();
    qDebug() <<Altitude*mass<<endl;

    qreal time = L*qPow(mass, (2/3)) * qLn(0.76*(T_wasser-T_start)/(T_wasser-T_ende));
    QString output;
    output.number(time);
    ui->label->setText(output);
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

}

