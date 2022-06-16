#include "boss_bomb.h"

Boss_bomb::Boss_bomb()
{
    //初始化爆炸图片数组
    for(int i = 1 ;i <= BOSS_BOMB_MAX ;i++)
    {
        //字符串拼接，类似  ":/res/bomb-1.png"
        QString str = QString(BOSS_BOMB_PATH).arg(i);
         m_pixArr.push_back(QPixmap(str));
    }

    //初始化坐标
    m_X = 0;
    m_Y = 0;

    //初始化空闲状态
    m_Free = true;

    //当前播放图片下标
    m_index = 0;

    //爆炸间隔记录
    m_recoder = 0;
}

void Boss_bomb::updateInfo()
{
    //空闲状态
    if(m_Free)
    {
        return;
    }

    m_recoder++;
    if(m_recoder < BOSS_BOMB_INTERVAL)
    {
        //记录爆炸间隔未到，直接return，不需要切图
        return;
    }
    //重置记录
    m_recoder = 0;

    //切换爆炸播放图片
    m_index++;
    //注：数组中的下标从0开始，最大是6
    //如果计算的下标大于6，重置为0
    if(m_index > BOSS_BOMB_MAX-1)
    {
        m_index = 0;
        m_Free = true;
    }
}
