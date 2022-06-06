#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<dialog.h>
#include<information.h>
#include<QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QProcess* process;
    bool start_voice = false;
private slots:
    void on_pushButton_13_clicked();
    void getInfo();
    void on_pushButton_2_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void voice();

    void on_pushButton_20_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    Information *information;


signals:
    void signali(QString a, bool b);

public slots:
    void slot(QString a);
};
#endif // MAINWINDOW_H
