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

signals:
    void valueChanged(qreal boilingtime);

private slots:
    void on_ButtonSizeS_clicked();

    void on_ButtonSizeM_clicked();

    void on_ButtonSizeL_clicked();

    void on_ButtonSizeXL_clicked();

    void on_spinBox_textChanged(const QString &arg1);

    void on_ButtonSizeOstrich_clicked();

    void calc_time();

    void on_start_Timer_clicked();

    void on_calculatedTime_overflow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


