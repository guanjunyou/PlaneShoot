#include "score.h"

Score::Score()
{
    m_X = 0;
    m_Y = 0;
    score = 0;
    life = 3;
    isGameOver = false;
}

void Score::setPosition()
{
    m_X = 0;
    m_Y = 0;
}

void Score::display()
{
    if(isGameOver == true)
        str = "Game Over!";
}



