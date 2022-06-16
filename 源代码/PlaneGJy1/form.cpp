#include "form.h"
#include "ui_form.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    menu = 0;

    w = NULL;
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QList<QScreen *> list_screen = QGuiApplication::screens();
    QRect rect = list_screen.at(0)->geometry();
    //以上为界面居中

    menu = 1;
    if(w)
    {
        delete w; //如果w 不是空指针 把w的内存释放掉，强制调用w 的析构函数 确保分数写入文件
    }
    w = new MainScene();
    w->move((rect.width() - w->width())/ 2, (rect.height() - w->height()) /2);
    //this->close();
    w->show();  //不是阻塞的
    //delete w;

}





void Form::on_pushButton_3_clicked()
{
    QString str;
    str="1 使用鼠标拖动飞机同时发射子弹 \n 2 子弹击中陨石陨石即爆炸消失，小陨石一击即炸，大陨石需要击中10次才爆炸\n 3 击中小陨石加1分,击中大陨石加10分 \n 4陨石与飞机碰撞游戏结束 \n"
        "【注意事项】 由于程序开发bug , 若点击开始游戏即显示GAME OVER 则再次点击开始游戏 \n"
        "【关于本游戏】 开发者：关竣佑 已在GitHub开源 个人博客：guanjunyou.top \n";
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, "游戏规则", str, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {

    }


}


void Form::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, "警告", "确定要退出？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        this->close();
    }

}
