#include "personal_information.h"
#include "ui_personal_information.h"

personal_information::personal_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personal_information)
{
    ui->setupUi(this);
}

personal_information::~personal_information()
{
    delete ui;
}
