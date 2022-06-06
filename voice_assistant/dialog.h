#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int proc = 0;
    QString s = "";

private slots:
    void on_pushButton_clicked();
    void application_selection(bool a);
    void choosing_an_action(bool a);
    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;

signals:
    void signal(QString a);
};

#endif // DIALOG_H
