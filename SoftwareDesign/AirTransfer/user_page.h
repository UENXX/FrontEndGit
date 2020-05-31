#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QWidget>
#include "personal_information.h"

namespace Ui {
class user_page;
}

class user_page : public QWidget
{
    Q_OBJECT

public:
    explicit user_page(QWidget *parent = 0);
    ~user_page();

private slots:
    void on_pushButton_copypaste_clicked();

    void on_pushButton_personalInfo_clicked();

    void on_pushButton_back_clicked();

    //拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::user_page *ui;

    personal_information personalInfo;

    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;
};

#endif // USER_PAGE_H
