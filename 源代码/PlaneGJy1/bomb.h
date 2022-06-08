#ifndef BOMB_H
#define BOMB_H
#include"config.h"
#include<QPixmap>
#include<QVector>


class bomb
{
public:
    bomb();

    void updateInfo();

    QVector<QPixmap> m_pixArr;

    int m_X;
    int m_Y;

    bool m_Free;

    int m_recoder;//爆炸切图时间间隔

    int m_index;//爆炸加载图片下
};

#endif // BOMB_H
