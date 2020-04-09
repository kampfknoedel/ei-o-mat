#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <QStringBuilder>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);

    QPushButton *neuerknopf = new QPushButton("Test", this);
    neuerknopf->setGeometry(20, 120, 50, 30);
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));


    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(CalcWeightInGramm(S));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CalcWeightInGramm(QString *Eggsize)
{
    QString comp = "S";
    if (Eggsize == comp){      //Eggsize "S" entspricht ca. 48g
        ui->InputWeight->setText(tr("48 g"));

    }
    comp = "M";
    if (Eggsize == comp){      //Eggsize "M" entspricht ca. 58g
        return 58;
    }
    comp = "L";
    if (Eggsize == comp){      //Eggsize "L" entspricht ca. 68g
        return 68;
    }
    comp = "XL";
    if (Eggsize == comp){      //Eggsize "XL" entspricht ca. 78g
        return 78;
    }

    else
        return 0;
}

QString MainWindow::CalcSize(int Weight)
{
    if (43 <= Weight && Weight < 53){
        return "S";
    }
    if (53 <= Weight && Weight < 63){
        return "M";
    }
    if (63 <= Weight && Weight < 73){
        return "L";
    }
    if (73 <= Weight && Weight < 83){
        return "XL";
    }
    else {
        return "error";
    }
}
int tBoilInSec (int Eggsize, )
