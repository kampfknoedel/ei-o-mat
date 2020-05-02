#ifndef EINGABEFENSTER_H
#define EINGABEFENSTER_H

#include <QWidget>
#include <QtMath>
#include <QDebug>
#include <QMainWindow>
#include <QString>
#include <QTime>

#include "eiertimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Eingabefenster; }
QT_END_NAMESPACE

class Eingabefenster : public QMainWindow
{
    Q_OBJECT
public:
    QDir dir_project;

public:
    Eingabefenster(QWidget *parent = nullptr);
    ~Eingabefenster();

signals:
    void valueChanged(qreal time);
    void TimeChanged(QTime);
    void dirChanged(QString);

private slots:
    void on_ButtonSizeS_clicked();

    void on_ButtonSizeM_clicked();

    void on_ButtonSizeL_clicked();

    void on_ButtonSizeXL_clicked();

    void on_spinBox_textChanged(const QString &arg1);

    void on_spinBoxStarttemp_textChanged(const QString &arg1);

    void calc_time();

    void on_start_Timer_clicked();

    void on_altitude_textChanged(const QString &arg1);

    void on_radioButtonRaumtemperatur_clicked();

    void on_radioButtonKuehlschrank_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_dial_valueChanged(int value);



    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::Eingabefenster *ui;
    Eiertimer* eiertimer;

};
#endif // EINGABEFENSTER_H
