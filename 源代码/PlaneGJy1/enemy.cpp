#include "enemy.h"
#include<iostream>

Enemy::Enemy()
{
    m_enemy.load(ENEMY_PATH);
    int m_X=0;
    int m_Y=0;

    m_Free = true;

    m_Speed = ENEMY_SPEED;

    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);

}

void Enemy::updatePosition()
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
