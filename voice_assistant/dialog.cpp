#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_4->setVisible(false);
    ui->pushButton_4->setVisible(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::application_selection(bool b)
{
    bool a = b;
    ui->label->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton->move(310, 80);

    ui->pushButton_2->setVisible(a);
    ui->pushButton_3->setVisible(a);
    ui->lineEdit_2->setVisible(a);
    ui->label_2->setVisible(a);
    ui->label_3->setVisible(a);
    ui->comboBox->setVisible(a);
}
void Dialog::choosing_an_action(bool b)
{
    bool a = b;
    ui->lineEdit_3->setVisible(a);
    ui->comboBox_2->setVisible(a);
    ui->label_5->setVisible(a);
    ui->label_4->setVisible(a);
    ui->pushButton_4->setVisible(a);
    ui->pushButton->move(230, 90);
}

void Dialog::on_pushButton_clicked()
{
    if (proc == 0) {
        application_selection(true);
        s = ui->lineEdit->text();
        ++proc;
    } else {
        if (proc <= 15) {
            application_selection(false);
            choosing_an_action(true);
            ++proc;
        } else {
            ui->pushButton->setVisible(false);
        }
    }
}


void Dialog::on_pushButton_4_clicked()
{
    emit signal(s);
    close();
}
