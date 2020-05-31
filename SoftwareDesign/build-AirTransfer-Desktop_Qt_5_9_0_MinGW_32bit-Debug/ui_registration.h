/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_pwd;
    QPushButton *pushButton_createID;
    QPushButton *pushButton_2;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName(QStringLiteral("registration"));
        registration->resize(424, 326);
        lineEdit_username = new QLineEdit(registration);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(90, 180, 241, 31));
        lineEdit_pwd = new QLineEdit(registration);
        lineEdit_pwd->setObjectName(QStringLiteral("lineEdit_pwd"));
        lineEdit_pwd->setGeometry(QRect(90, 230, 241, 31));
        pushButton_createID = new QPushButton(registration);
        pushButton_createID->setObjectName(QStringLiteral("pushButton_createID"));
        pushButton_createID->setGeometry(QRect(90, 280, 91, 31));
        pushButton_2 = new QPushButton(registration);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 280, 91, 31));

        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QApplication::translate("registration", "Form", Q_NULLPTR));
        lineEdit_username->setPlaceholderText(QApplication::translate("registration", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        lineEdit_pwd->setPlaceholderText(QApplication::translate("registration", "\345\257\206\347\240\201", Q_NULLPTR));
        pushButton_createID->setText(QApplication::translate("registration", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("registration", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
