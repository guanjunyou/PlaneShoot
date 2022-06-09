#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include"map.h"
#include"heroplane.h"
#include<QMouseEvent>
#include <QTimer>
#include"bullet.h"
#include"enemy.h"
#include<ctime>
#include"bomb.h"
#include"score.h"
#include <QApplication>
#include <QLabel>
#include"gameover.h"
#include"boss.h"
#include"boss_bomb.h"
#include<fstream>
#include<istream>
#include<cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
     void  initScene();

     //计分类
     Score m_score;

     //启动游戏
     void playGame();

     //更新所有游戏中的坐标
     void updatePostion();

     //绘制到游戏中  函数名称不能改
     void paintEvent(QPaintEvent * event);

     //鼠标移动事件
     void mouseMoveEvent(QMouseEvent * event);

     //碰撞检测
     void collisionDetection();

     //敌机出场
     void enemyToScene();

     //敌机数组
     Enemy m_enemys[ENEMY_NUM];

     //BOSS出场
     void bossToScene();

     //BOSS数组
     Boss m_bosses[BOSS_NUM];

     //敌机出场间隔记录
     int m_recoder;
     int m_boss_recoder;

     //地图对象
     Map m_map;

     //定时器
     QTimer m_Timer;

     //飞机
     HeroPlane m_hero;

     //测试
    // bullet temp_bullet;

     //爆炸数组
     bomb m_bombs[BOMB_NUM];

     Boss_bomb m_boss_bombs[BOSS_BOMB_NUM];


    GameOver m_gameover;



private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
