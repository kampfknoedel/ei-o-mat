#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

//Testkommentar für GitHub

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);

    QPushButton *neuerknopf = new QPushButton("Test", this);
    neuerknopf->setGeometry(20, 120, 50, 30);
    connect(neuerknopf, SIGNAL(clicked()), qApp, SLOT(quit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

