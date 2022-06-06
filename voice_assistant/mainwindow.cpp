#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QObject"
#include "QSysInfo"
#include "QTextCodec"


MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    }
void MainWindow::getInfo() {
    QByteArray a = process->readAll();
    QString u2 = QString::fromLocal8Bit(a);
    ui->textEdit->setText(ui->textEdit->toPlainText() + u2);
}

void MainWindow::on_pushButton_13_clicked()
{
    dialog = new Dialog;
    dialog->show();

    connect(dialog, &Dialog::signal, this, &MainWindow::slot);

    dialog->setModal(true);
    dialog->exec();
}

void MainWindow::slot(QString a)
{
    ui->pushButton_10->setText(a);
    ui->pushButton->setText("Окончание");
    ui->pushButton_4->setText("Погода");
    ui->pushButton_7->setText("Музыка");

}

void MainWindow::on_pushButton_2_clicked()
{
    dialog = new Dialog;
    dialog->show();

    connect(dialog, &Dialog::signal, this, &MainWindow::slot);

    dialog->setModal(true);
    dialog->exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    //информация о погоде
    information = new Information;
    information->show();

    connect(this, &MainWindow::signali, information, &Information::sloti);
    emit signali("Данный шаблон узнаёт информацию о\nпогоде.", false);
    information->setModal(true);
}


void MainWindow::on_pushButton_10_clicked()
{

}

void MainWindow::voice()
{
    process = new QProcess();

    QObject::connect(process, QProcess::readyRead, this, &MainWindow::getInfo);

    QObject::connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                     [=](int exitCode, QProcess::ExitStatus /*exitStatus*/){
    qDebug()<< "process exited with code " << exitCode;
    process->deleteLater();
    });
    process->setWorkingDirectory("C:/Users/Student/Desktop/VoiceAssist/PyVoice/puvoiceut/");
    process->start("C:/Users/Student/Desktop/VoiceAssist/PyVoice/venv/puvoiceut/Scripts/Activate.ps1");
    process->start("C:/Users/Student/Desktop/VoiceAssist/PyVoice/venv/puvoiceut/Scripts/python", QStringList() << "C:/Users/Student/Desktop/VoiceAssist/PyVoice/puvoiceut/main.py");
}


void MainWindow::on_pushButton_20_clicked()
{
    if (start_voice == false) {
        voice();
        ui->pushButton_20->setText("Микрофон включен");
        start_voice = true;
    } else {
        ui->pushButton_20->setText("Микрофон выключен");
        start_voice = false;
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    information = new Information;
    information->show();

    connect(this, &MainWindow::signali, information, &Information::sloti);
    emit signali("Данный шаблон узнаёт\nинформацию о погоде\nчерез сервис:", true);
    information->setModal(true);
}
