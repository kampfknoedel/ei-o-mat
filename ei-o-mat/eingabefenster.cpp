#include "eingabefenster.h"
#include "ui_eingabefenster.h"


#include <QWidget>
#include <QtMath>
#include <QDebug>

Eingabefenster::Eingabefenster(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Eingabefenster)
{
    ui->setupUi(this);
    eiertimer = new Eiertimer;

    const bool connected = connect(this, SIGNAL(TimeChanged(QTime)), eiertimer, SLOT(receiveTime(QTime)));
    qDebug() << "Connection established?" << connected;
    connect(this, SIGNAL(dirChanged(QString)), eiertimer, SLOT(receiveDir(QString)));
    emit on_dial_valueChanged(ui->dial->value());


    QDir dir(QCoreApplication::applicationDirPath());
    dir.cdUp();
    dir.cd("ei-o-mat");
    QStringList filters;
    filters << "*.wav" << "*.WAV";
    dir.setNameFilters(filters);
    QStringList ordnerinhalt;
    ordnerinhalt = dir.entryList();
    ui->comboBox_2->addItems(ordnerinhalt);
    ui->comboBox_2->addItem("kein Sound ausgewählt");
    dir_project=dir;
    emit on_comboBox_2_currentTextChanged(ui->comboBox_2->currentText());
    qDebug() << dir;
    qDebug() << ordnerinhalt;

}

Eingabefenster::~Eingabefenster()
{
    delete ui;
}

void Eingabefenster::calc_time()
{
    qreal L = 0.47311;   // Constante abhängig von Wärmewiderstand und Wärmekapazität von Eigelb und Eiklar
    qreal mass = ui->spinBox->value();
    qreal T_wasser = 100 - (0.003354 * ui->altitude->value());     // Berechung in abhängigkeit von der eingabe höhe über Null
    qreal T_start = ui->spinBoxStarttemp->value();      // Berechung in abhängigkeit der eingabe (Temperatur oder Kühlschrank)
    qreal T_ende = ui->dial->value();       // Berechung in abhängigkeit von Garzustand des Eigelbs

    //qreal Altitude=ui->altitude->value();
    //qDebug() <<Altitude*mass<<endl;
    qreal massehoch23 = qPow(mass, (2.0/3.0));

    qreal time = L*massehoch23 * qLn(0.76*(T_wasser-T_start)/(T_wasser-T_ende));


    qDebug() << "T_wasser" << T_wasser;
    qDebug() << "T_start" << T_start;
    qDebug() << "T_ende" << T_ende;
    qDebug() << "Ln: " << qLn(0.76*(T_wasser-T_start)/(T_wasser-T_ende));
    qDebug() << "Zeit in Minuten" << time;
    //time = 0.06;
    QTime time2(0,0,0);
    QTime time3 = time2.addSecs(time*60);

    QString output;
    output.number(time);

    ui->calculatedTime->display(time3.toString("mm:ss"));
    //ui->label_10->setText(time3.toString("mm:ss"));
    emit valueChanged(time);
    emit TimeChanged(time3);

}


void Eingabefenster::on_ButtonSizeS_clicked()
{
    ui->spinBox->setValue(48);
    calc_time();
}
void Eingabefenster::on_ButtonSizeM_clicked()
{
    ui->spinBox->setValue(58);
}
void Eingabefenster::on_ButtonSizeL_clicked()
{
    ui->spinBox->setValue(68);
}
void Eingabefenster::on_ButtonSizeXL_clicked()
{
    ui->spinBox->setValue(78);
}
void Eingabefenster::on_spinBox_textChanged(const QString &arg1)
{
    ui->ButtonSizeS->setAutoExclusive(false);
    ui->ButtonSizeM->setAutoExclusive(false);
    ui->ButtonSizeL->setAutoExclusive(false);
    ui->ButtonSizeXL->setAutoExclusive(false);
    ui->ButtonSizeS->setChecked(false);
    ui->ButtonSizeM->setChecked(false);
    ui->ButtonSizeL->setChecked(false);
    ui->ButtonSizeXL->setChecked(false);
    ui->ButtonSizeS->setAutoExclusive(true);
    ui->ButtonSizeM->setAutoExclusive(true);
    ui->ButtonSizeL->setAutoExclusive(true);
    ui->ButtonSizeXL->setAutoExclusive(true);

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
    calc_time();
}

void Eingabefenster::on_start_Timer_clicked()
{
    //window();
    //QWidget *w=new Eiertimer;
    emit(calc_time());
    eiertimer->show();
}

void Eingabefenster::on_altitude_textChanged(const QString &arg1)
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


void Eingabefenster::on_radioButtonKuehlschrank_clicked()
{
    ui->spinBoxStarttemp->setValue(7);
}
void Eingabefenster::on_radioButtonRaumtemperatur_clicked()
{
    ui->spinBoxStarttemp->setValue(20);
}
void Eingabefenster::on_spinBoxStarttemp_textChanged(const QString &arg1)
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

void Eingabefenster::on_comboBox_currentIndexChanged(int index)
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

void Eingabefenster::on_dial_valueChanged(int value)
{
    QString string;
    string.setNum(value, 10);
    string.insert(string.length(), QString(" °C"));
    ui->label_targettemp->setText(string);

    calc_time();

}

void Eingabefenster::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    QDir dir_alarm = dir_project;
    emit dirChanged(dir_alarm.filePath(arg1));
    qDebug() << dir_alarm.filePath(arg1);
}
