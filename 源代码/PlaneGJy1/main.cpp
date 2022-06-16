#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"
#include "form.h"
#include<QScreen>
#include<QGuiApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册外部的二进制资源文件
    QResource::registerResource(GAME_RES_PATH);
//    Menu.show();
   Form Menu;
   //以下为居中操作
   QList<QScreen *> list_screen = QGuiApplication::screens();
   QRect rect = list_screen.at(0)->geometry();
   Menu.move((rect.width() - Menu.width())/ 2, (rect.height() - Menu.height()) /2);

   Menu.show();

    return a.exec();
}
