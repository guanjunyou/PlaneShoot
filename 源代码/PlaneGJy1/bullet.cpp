#include "bullet.h"

bullet::bullet()
{
    m_Bullet.load(BULLET_PATH);

    m_X=GAME_WIDTH*0.5 - m_Bullet.width()*0.5;
    m_Y = GAME_HEIGHT;

    m_Free = true;

    m_Speed = BULLET_SPEED;

    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void bullet::updatePostion()
{
    if(m_Free)
    {
        return;
    }
   m_Y-=m_Speed;//子弹向上移动
   m_Rect.moveTo(m_X,m_Y);

   if(m_Y<=-m_Rect.height()) //到了上界
   {
       m_Free = true;
   }
}
