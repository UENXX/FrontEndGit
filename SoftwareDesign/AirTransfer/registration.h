#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>


namespace Ui {
class registration;
}

class registration : public QWidget
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = 0);
    ~registration();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_createID_clicked();

    //拖拽窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::registration *ui;

    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

};

#endif // REGISTRATION_H
