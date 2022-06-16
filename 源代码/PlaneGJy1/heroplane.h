#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include<QRect>
#include"config.h"
#include"bullet.h"
class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x,int y);

    QPixmap m_plane;

    //飞机坐标
    int m_X;
    int m_Y;
    //飞机矩形边框

    QRect m_Rect;

    //弹匣
    bullet m_bullets[BULLET_NUM];
    //发射间隔记录
    int m_recoder;

    //英雄机的生命值 初始化为3 有三条命
    int m_life;

    int m_Free;

};

#endif // HEROPLANE_H
