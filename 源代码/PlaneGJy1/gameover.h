#ifndef GAMEOVER_H
#define GAMEOVER_H
#include<QPixmap>
#include "config.h"

class GameOver
{
public:
    GameOver();

    int m_X ;
    int m_Y ;

    QPixmap m_gameover;
};

#endif // GAMEOVER_H
