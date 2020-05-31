#include "user_page.h"
#include "ui_user_page.h"
#include "qmessagebox.h"
#include "QFile"
#include <QDebug>
#include <QPalette>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "copy_paste.h"
#include <QMouseEvent>

extern QSqlDatabase db;

user_page::user_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_page)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //pal.setBrush(QPalette::Background,QBrush(QPixmap(":/img/registration_background.jpg")));
    setPalette(pal);
}

user_page::~user_page()
{
    delete ui;
}

void user_page::on_pushButton_copypaste_clicked()
{
    /*
    QString EXEName_src = ":/exe/copypaste.exe";
    QString EXEName_Dst = "~copypaste.exe";
    QFile EXEFile_src(EXEName_src);
    QFile EXEFile_Dst(EXEName_Dst);
    //对资源里的exe进行重新生成
    if(EXEFile_Dst.open (QIODevice::WriteOnly)){
       if(EXEFile_src.open(QIODevice::ReadOnly)){
       QByteArray tmp = EXEFile_src.readAll();
       EXEFile_Dst.write(tmp);
       }
    }
    EXEFile_Dst.close();
    QString CMD = EXEName_Dst;
    //执行CMD命令
    char* ptr;
    QByteArray ba = CMD.toLocal8Bit(); //支持含中文
    ptr = ba.data();
    system(ptr);

    QFile::remove(EXEName_Dst); //删掉exe文件
    */
    copy shear_plate;

    int result;
    result = shear_plate.get_user_input();
    if(result == -3)        //剪切板内容为文件
    {
        QString addr(shear_plate.user_input);
        QMessageBox::information(this, "提示", "复制文件成功\n");
    }
    else if(result == 0)    //剪切板内容为文本
    {
        QMessageBox::information(this, "提示", "复制剪切板内容成功");
    }
    else if(result == -1)    //复制剪切板内容失败
    {
        QMessageBox::information(this, "提示", "复制剪切板内容失败");
    }
}

void user_page::on_pushButton_personalInfo_clicked()
{
    personalInfo.show();
}

void user_page::on_pushButton_back_clicked()
{
    this->close();
}




void user_page::mousePressEvent(QMouseEvent *event)
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

void user_page::mouseMoveEvent(QMouseEvent *event)
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

void user_page::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}
