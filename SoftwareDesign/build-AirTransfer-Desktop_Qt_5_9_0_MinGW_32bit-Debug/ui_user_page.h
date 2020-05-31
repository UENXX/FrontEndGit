/********************************************************************************
** Form generated from reading UI file 'user_page.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_PAGE_H
#define UI_USER_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_page
{
public:
    QPushButton *pushButton_copypaste;
    QPushButton *pushButton_personalInfo;
    QPushButton *pushButton_back;
    QLabel *label;
    QTableView *tableView;
    QPushButton *pushButton_upload;
    QPushButton *pushButton_download;

    void setupUi(QWidget *user_page)
    {
        if (user_page->objectName().isEmpty())
            user_page->setObjectName(QStringLiteral("user_page"));
        user_page->resize(602, 500);
        pushButton_copypaste = new QPushButton(user_page);
        pushButton_copypaste->setObjectName(QStringLiteral("pushButton_copypaste"));
        pushButton_copypaste->setGeometry(QRect(310, 90, 81, 31));
        pushButton_personalInfo = new QPushButton(user_page);
        pushButton_personalInfo->setObjectName(QStringLiteral("pushButton_personalInfo"));
        pushButton_personalInfo->setGeometry(QRect(450, 90, 91, 31));
        pushButton_back = new QPushButton(user_page);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setGeometry(QRect(470, 430, 75, 23));
        label = new QLabel(user_page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 71, 21));
        tableView = new QTableView(user_page);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 90, 251, 251));
        pushButton_upload = new QPushButton(user_page);
        pushButton_upload->setObjectName(QStringLiteral("pushButton_upload"));
        pushButton_upload->setGeometry(QRect(30, 380, 75, 23));
        pushButton_download = new QPushButton(user_page);
        pushButton_download->setObjectName(QStringLiteral("pushButton_download"));
        pushButton_download->setGeometry(QRect(140, 380, 75, 23));

        retranslateUi(user_page);

        QMetaObject::connectSlotsByName(user_page);
    } // setupUi

    void retranslateUi(QWidget *user_page)
    {
        user_page->setWindowTitle(QApplication::translate("user_page", "Form", Q_NULLPTR));
        pushButton_copypaste->setText(QApplication::translate("user_page", "\345\244\215\345\210\266\345\211\252\345\210\207\346\235\277", Q_NULLPTR));
        pushButton_personalInfo->setText(QApplication::translate("user_page", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", Q_NULLPTR));
        pushButton_back->setText(QApplication::translate("user_page", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QApplication::translate("user_page", "\344\270\252\344\272\272\346\226\207\344\273\266\344\274\240\350\276\223", Q_NULLPTR));
        pushButton_upload->setText(QApplication::translate("user_page", "\344\270\212\344\274\240", Q_NULLPTR));
        pushButton_download->setText(QApplication::translate("user_page", "\344\270\213\350\275\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class user_page: public Ui_user_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_PAGE_H
