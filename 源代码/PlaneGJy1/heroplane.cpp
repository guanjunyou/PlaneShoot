#include "heroplane.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机图片
    m_plane.load(HERO_PATH);
    //初始化飞机的坐标
    m_X = (GAME_WIDTH - m_plane.width())*0.5;
    m_Y = (GAME_HEIGHT - m_plane.height());

    //初始化矩形边框
    m_Rect.setWidth(m_plane.width());
    m_Rect.setHeight(m_plane.height());

    //初始化发射间隔记录
    m_recoder = 0;

    m_life = 3;

    m_Free = false;
}

void HeroPlane::shoot()
{
    //发射子弹函数
    m_recoder++;
    if(m_recoder < BULLET_INTERVAL)
        return;
    //达到发射间隔
    m_recoder = 0;
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_bullets[i].m_Free == true)
        {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X+55;
            m_bullets[i].m_Y = m_Y;
            break;//只发一发
        }
    }
}

void HeroPlane::setPosition(int x,int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}
