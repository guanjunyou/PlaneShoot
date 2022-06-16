#ifndef ENEMY_H
#define ENEMY_H
#include "config.h"
#include<QPixmap>
#include<ctime>

class Enemy
{
public:
    Enemy();

    void updatePosition();

    QPixmap m_enemy;

    int m_X;
    int m_Y;

    QRect m_Rect;

    bool m_Free;

    int m_Speed;
};

#endif // ENEMY_H
