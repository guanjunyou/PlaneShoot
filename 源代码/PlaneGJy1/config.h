#ifndef CONFIG_H
#define CONFIG_H

/**********  游戏配置数据 **********/
#define GAME_WIDTH  812  //宽度
#define GAME_HEIGHT 768  //高度
#define GAME_TITLE "陨石撞飞机" //标题
#define GAME_RES_PATH  "./plane.rcc" //rcc文件路径
#define GAME_ICON  ":/res/app.ico"
#define GAME_RATE 10//定时器刷新时间间隔 毫秒

/**********  地图配置数据 **********/

#define MAP_PATH ":/res/img_bg_level_6.jpg" //地图路径
#define MAP_SCROLL_SPEED 2;

/**********  飞机配置数据 **********/
#define HERO_PATH ":/res/hero2.png"

/**********  子弹配置数据 **********/
#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 10  //子弹移动速度 5
#define BULLET_NUM 30   //弹匣中子弹总数
#define BULLET_INTERVAL 10 //发射子弹时间间隔 20

/**********  陨石配置数据 **********/
#define ENEMY_PATH  ":/res/img-plane_9.png"  //陨石资源图片
#define ENEMY_SPEED 3  //陨石移动速度  5
#define ENEMY_NUM   20  //陨石总数量
#define ENEMY_INTERVAL  30  //陨石出场时间间隔

#define BOMB_PATH  ":/res/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7     //爆炸图片最大索引
#define BOMB_INTERVAL 20   //爆炸切图时间间隔

/**********  BOSS配置数据 **********/
#define BOSS_PATH  ":/res/img-enemy_1.png"  //陨石资源图片
#define BOSS_SPEED 2  //陨石移动速度  5
#define BOSS_NUM   10  //陨石总数量
#define BOSS_INTERVAL  170  //陨石出场时间间隔

#define BOSS_BOMB_PATH  ":/res/boss-bomb-%1.png"   //爆炸资源图片
#define BOSS_BOMB_NUM  20     //爆炸数量
#define BOSS_BOMB_MAX  3     //爆炸图片最大索引

#define BOSS_BOMB_INTERVAL 15   //爆炸切图时间间隔


#define BOSS_LIFE 10


/**********  计分栏配置数据 **********/
#define SCORE_WIDTH 100
#define SCORE_HEIGHT 100
#define SCORE_PATH "score.txt"

/**********  GAME OVER **********/
//#define SCORE_WIDTH 100
//#define SCORE_HEIGHT 100
#define GAMEOVER_PATH ":/res/img-gameover.jpg"   //子弹图片路径
#endif // CONFIG_H
