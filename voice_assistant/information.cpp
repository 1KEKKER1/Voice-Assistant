#include "information.h"
#include "ui_information.h"


Information::Information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
}

Information::~Information()
{
    delete ui;
}

void Information::sloti(QString a, bool b)
{
        s = a;
        ui->label->setText(ui->label->text() + s);
        ui->comboBox->setVisible(b);
}
