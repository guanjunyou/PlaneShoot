#ifndef BOSS_H
#define BOSS_H
#include<QPixmap>
#include"config.h"

class Boss
{
public:
    Boss();

    void updatePosition();

    QPixmap m_boss;

    int m_X;
    int m_Y;

    QRect m_Rect;

    bool m_Free;

    int m_Speed;

    int life ;
};

#endif // BOSS_H
