#ifndef PERSONAL_INFORMATION_H
#define PERSONAL_INFORMATION_H

#include <QWidget>

namespace Ui {
class personal_information;
}

class personal_information : public QWidget
{
    Q_OBJECT

public:
    explicit personal_information(QWidget *parent = 0);
    ~personal_information();

private:
    Ui::personal_information *ui;
};

#endif // PERSONAL_INFORMATION_H
