#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>
#include<QRect>

class bullet
{
public:
    bullet();

    //更新子弹坐标
    void updatePostion();

    //子弹对象
    QPixmap m_Bullet;

    //子弹坐标
    int m_X;
    int m_Y;
    //子弹移动速度
    int m_Speed;
    //子弹是否闲置
    bool m_Free;
    //子弹矩形边框
    QRect m_Rect;
};

#endif // BULLET_H
