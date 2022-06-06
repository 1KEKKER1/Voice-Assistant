#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();
    QString s = "";

private:
    Ui::Information *ui;
public slots:
    void sloti(QString a, bool b);
};

#endif // INFORMATION_H
