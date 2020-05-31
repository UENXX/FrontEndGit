/********************************************************************************
** Form generated from reading UI file 'personal_information.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAL_INFORMATION_H
#define UI_PERSONAL_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personal_information
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *personal_information)
    {
        if (personal_information->objectName().isEmpty())
            personal_information->setObjectName(QStringLiteral("personal_information"));
        personal_information->resize(378, 393);
        label = new QLabel(personal_information);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 110, 54, 12));
        lineEdit = new QLineEdit(personal_information);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 110, 113, 20));
        label_2 = new QLabel(personal_information);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 160, 54, 12));
        lineEdit_2 = new QLineEdit(personal_information);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 160, 113, 20));
        label_3 = new QLabel(personal_information);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 210, 54, 12));
        lineEdit_3 = new QLineEdit(personal_information);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 210, 113, 20));

        retranslateUi(personal_information);

        QMetaObject::connectSlotsByName(personal_information);
    } // setupUi

    void retranslateUi(QWidget *personal_information)
    {
        personal_information->setWindowTitle(QApplication::translate("personal_information", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("personal_information", "\345\216\237\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("personal_information", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("personal_information", "\344\277\256\346\224\271\345\244\264\345\203\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class personal_information: public Ui_personal_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAL_INFORMATION_H
