#include "boss.h"

Boss::Boss()
{
    m_boss.load(BOSS_PATH);
    int m_X=0;
    int m_Y=0;

    m_Free = true;

    life = BOSS_LIFE;

    m_Speed = BOSS_SPEED;

    m_Rect.setWidth(m_boss.width());
    m_Rect.setHeight(m_boss.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Boss::updatePosition()
{
    //std::cout<<"222"<<std::endl;
    if(m_Free == true)
    {
        return;
    }
    m_Y+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);
    if(m_Y >= GAME_HEIGHT)
    {
        m_Free = true;
    }
}
