#include "registration.h"
#include "ui_registration.h"
#include <QMouseEvent>
#include <QPalette>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

extern QSqlDatabase db;

registration::registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/img/registration_background.jpg")));
    ui->pushButton_createID->setStyleSheet("border-radius:4px;background:#005eae;color: #fefefe;");
    ui->pushButton_2->setStyleSheet("border-radius:4px;background:#005eae;color: #fefefe;");
    ui->lineEdit_pwd->setStyleSheet("border-radius:4px;");
    ui->lineEdit_username->setStyleSheet("border-radius:4px;");
    ui->lineEdit_pwd->setFont(QFont("黑体", 11));
    ui->lineEdit_username->setFont(QFont("黑体", 11));
    setPalette(pal);
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_2_clicked()
{
    this->close();
}

void registration::on_pushButton_createID_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString pwd = ui->lineEdit_pwd->text();
    QString id;
    QSqlQuery query(db);
    if(username.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请输入用户名！");
    }
    else if(pwd.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请输入密码！");
    }
    else
    {
        query.exec("SELECT * FROM `user` WHERE user_name = '" + username + "'");
        if(query.next())
        {
            QMessageBox::information(this, "提示", "此用户名已经存在，请重新输入");
            ui->lineEdit_username->clear();
        }
        else
        {
            query.exec("INSERT INTO `id_pwd` SET pwd_hash = '" + pwd + "';");
            query.exec("SELECT LAST_INSERT_ID();");
            query.next();
            id = query.value(0).toString();
            query.exec("INSERT INTO `user` SET user_name = '" + username + "', id = " + id + ";");
            QMessageBox::information(this, "提示", "注册成功！");
            this->close();
        }
    }
}



void registration::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //mouseStartPoint = event->pos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void registration::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

void registration::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}


