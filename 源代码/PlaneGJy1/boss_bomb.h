#ifndef BOSS_BOMB_H
#define BOSS_BOMB_H
#include<QPixmap>
#include"config.h"

class Boss_bomb
{
public:
    Boss_bomb();

    void updateInfo();


    QVector<QPixmap> m_pixArr;

    int m_X;
    int m_Y;

    bool m_Free;

    int m_recoder;//爆炸切图时间间隔

    int m_index;//爆炸加载图片下
};

#endif // BOSS_BOMB_H
