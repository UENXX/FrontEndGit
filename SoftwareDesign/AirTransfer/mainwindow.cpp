#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlError"
#include <QMouseEvent>
#include <QPalette>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
QString mid;    //登录商户或用户的id

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectDB(db);      //连接数据库

    //以下为设置界面样式
    QPalette pal = this->palette();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/img/login_blackground.jpg")));
    ui->pushButton_3->setStyleSheet("border-radius:4px;background:#005eae;color: #fefefe;");
    ui->pushButton_2->setStyleSheet("border-radius:4px;background:#005eae;color: #fefefe;");
    ui->pushButton_login->setStyleSheet("border-radius:4px;background:#005eae;color: #fefefe;");
    ui->lineEdit->setStyleSheet("border-radius:4px;");
    ui->lineEdit_2->setStyleSheet("border-radius:4px;");
    ui->radioButton->setStyleSheet("color:#666666;");
    ui->radioButton_2->setStyleSheet("color:#666666;");
    ui->lineEdit->setFont(QFont("黑体", 11));
    ui->lineEdit_2->setFont(QFont("黑体", 11));
    setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    reg.show();
}

bool MainWindow::connectDB(QSqlDatabase db)
{
//连接数据库
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("110505");
    db.setDatabaseName("airtransfer");//使用的数据库
//打开数据库

    if(!db.open())
    {
        QMessageBox::warning(0,"错误",db.lastError().text());
        return false;
    }
    else {
        return true;
    }
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
    QSqlQuery query(db);
    if(username.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请输入用户名！");
        return;
    }
    else if(pwd.isEmpty())
    {
        QMessageBox::warning(this, "警告", "请输入密码！");
        return;
    }

    //普通用户登录
    if(ui->radioButton->isChecked())
    {
        query.exec("SELECT * FROM id_pwd, `user` WHERE `user`.id  = id_pwd.id AND"
                   " `user`.user_name = '" + username + "' AND id_pwd.pwd_hash = '" + pwd + "';");\
        if(query.next())
        {
            query.exec("SELECT id FROM `user` WHERE user_name = '" + username + "';");
            query.next();
            mid = query.value(0).toString();
            this->close();
            //QMessageBox::information(this, "提示", "登录成功！");
            usrp.show();
        }
        else
        {
            QMessageBox::warning(this, "警告", "用户名或密码不正确！");
        }
    }
}



void MainWindow::mousePressEvent(QMouseEvent *event)
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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
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

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}
