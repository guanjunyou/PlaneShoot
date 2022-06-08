#include "map.h"
#include "config.h"

Map::Map()
{
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    m_scroll_speed = MAP_SCROLL_SPEED;
}
void Map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= 0)
    {
        //重置
        m_map1_posY = -GAME_HEIGHT;
        //往下是正
    }

    //处理第二章图片
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= GAME_HEIGHT)
    {
        //重置
        m_map1_posY = 0;
    }
}
