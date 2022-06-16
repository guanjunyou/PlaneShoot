 #include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include "QIcon"
#include<QPainter>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();
    playGame();
    m_recoder = 0;
    m_boss_recoder = 0;
}

MainScene::~MainScene()
{
   // qDebug()<<"析构\n";
    m_score.write(std::max(m_score.best_score,m_score.score));
    delete ui;
}

void MainScene::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();
    //监听定时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        //敌机出场
       // qDebug()<<"111\n";
        enemyToScene();
        bossToScene();
        //更新游戏元素坐标
        updatePostion();
        //绘制到屏幕中

        update();
        collisionDetection();
    });
}

void MainScene::updatePostion()
{
   // qDebug()<<"0\n"; //这里可以
    m_map.mapPosition();

    //发射子弹
    m_hero.shoot();

    //计算所有非空闲子弹的当前坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_hero.m_bullets[i].m_Free == false)
        {
            m_hero.m_bullets[i].updatePostion();
        }
    }

    //敌机坐标计算
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //qDebug()<<"enemy\n";//这里也可以
        if(m_enemys[i].m_Free==false)
        {
            m_enemys[i].updatePosition();
        }
    }

    //BOSS坐标计算
    for(int i=0;i<BOSS_NUM;i++)
    {
        //qDebug()<<"enemy\n";//这里也可以
        if(m_bosses[i].m_Free==false)
        {
            m_bosses[i].updatePosition();
        }
    }

    //测试
    //temp_bullet.m_Free = false;
    //temp_bullet.updatePostion();

    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();       }
    }

    for(int i=0;i<BOSS_BOMB_NUM;i++)
    {
        if(m_boss_bombs[i].m_Free == false)
        {
            m_boss_bombs[i].updateInfo();       }
    }

    m_score.display();

}

void MainScene::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);

    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);


    QRectF rect(0, 20, 500, 200) ;

   // painter.drawRect(rect);  //为了更直观地看到字体的位置，我们绘制出这个矩形
    QFont font("宋体", 25, QFont::Bold);
    painter.setFont(font);

    painter.setPen(QColor(Qt::red));
    painter.drawText(rect, Qt::AlignHCenter, "当前分数"+QString::number(m_score.score)+"  历史最高分"+QString::number(m_score.best_score));

    //qDebug()<<m_hero.m_life;
    if(m_hero.m_life==0)
        painter.drawPixmap(m_gameover.m_X,m_gameover.m_Y,m_gameover.m_gameover);
    if(m_hero.m_life== 0)
         return;
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_plane);
    //测试代码
    //painter.drawPixmap(temp_bullet.m_X,temp_bullet.m_Y,temp_bullet.m_Bullet);
    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        if(m_hero.m_bullets[i].m_Free == false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }
    //绘制敌机
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //绘制BOSS
    for(int i = 0 ; i< BOSS_NUM;i++)
    {
        if(m_bosses[i].m_Free == false)
        {
            painter.drawPixmap(m_bosses[i].m_X,m_bosses[i].m_Y,m_bosses[i].m_boss);
        }
    }
    //绘制爆炸
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }

    //绘制BOSS爆炸
    for(int i=0;i<BOSS_BOMB_NUM;i++)
    {
        if(m_boss_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_boss_bombs[i].m_X,m_boss_bombs[i].m_Y,m_boss_bombs[i].m_pixArr[m_boss_bombs[i].m_index]);
        }
    }

    if(!m_score.isGameOver)
    {

        QString name = m_score.text;
        QPixmap pix(name);
        //创建绘画对象
        QPainter painter(&pix);
        painter.begin(&pix);
        painter.setPen(Qt::black);
        //设置字体大小.另可以根据画笔改变颜色等属性
        QFont font = painter.font();
        font.setPixelSize(12);//改变字体大小
        font.setFamily("Microsoft YaHei");
        painter.setFont(font);
        //将文字写在图片上，例如是int型的数字123，居中
        painter.drawText(pix.rect(), Qt::AlignCenter, QString::number(123).toStdString().c_str());

    }

}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x() - m_hero.m_Rect.width()*0.5;
    int y=event->y() - m_hero.m_Rect.height()*0.5;

    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=GAME_WIDTH-m_hero.m_Rect.width())
    {
        x=GAME_WIDTH-m_hero.m_Rect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_HEIGHT-m_hero.m_Rect.height())
    {
        y=GAME_HEIGHT-m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

void MainScene::collisionDetection()
{
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            continue;
        }//空闲陨石

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                //qDebug()<<m_score.score;
                if(m_score.isGameOver==false)
                    m_score.score++;
                m_enemys[i].m_Free=true;
                m_hero.m_bullets[j].m_Free=true;
                //以下为爆炸
                for(int k=0;k<BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        m_bombs[k].m_Free = false;
                        m_bombs[k].m_X=m_enemys[i].m_X;
                        m_bombs[k].m_Y=m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }

        //以下为检测陨石与英雄机碰撞
        if(m_enemys[i].m_Rect.intersects(m_hero.m_Rect))
        {
            if(m_hero.m_life > 0)
            {
                m_hero.m_life--;
                m_score.life--;
                //还有命
            }
            else
            {
                m_score.isGameOver = true;
                m_score.life = 0;
                m_hero.m_life = 0;
                m_hero.m_Free = true;

            }
        }
    }
    //qDebug()<<m_hero.m_life<<"\n";

    //以下为boss

    for(int i=0;i<BOSS_NUM;i++)
    {
        if(m_bosses[i].m_Free)
        {
            continue;
        }//空闲陨石

        for(int j=0;j<BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }
            if(m_bosses[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                //qDebug()<<m_score.score;
                m_bosses[i].life--;
                if(m_score.isGameOver==false && m_bosses[i].life == 0)
                    m_score.score+=10; //打中 boss加10分
                if(m_bosses[i].life==0)
                {
                    m_bosses[i].m_Free=true;
                }
                m_hero.m_bullets[j].m_Free=true;
                if(m_bosses[i].life != 0)
                    continue;
                //以下为爆炸
                for(int k=0;k<BOSS_BOMB_NUM;k++)
                {
                    if(m_boss_bombs[k].m_Free)
                    {
                        m_boss_bombs[k].m_Free = false;
                        m_boss_bombs[k].m_X=m_bosses[i].m_X;
                        m_boss_bombs[k].m_Y=m_bosses[i].m_Y;
                        break;
                    }
                }
                m_bosses[i].life=BOSS_LIFE;
            }
        }

        //以下为检测陨石与英雄机碰撞
        if(m_bosses[i].m_Rect.intersects(m_hero.m_Rect))
        {
            if(m_hero.m_life > 0)
            {
                m_hero.m_life--;
                m_score.life--;
                //还有命
            }
            else
            {
                //qDebug()<<"111";
                m_score.isGameOver = true;
                m_score.life = 0;
                m_hero.m_life = 0;
                m_hero.m_Free = true;
                m_score.write(std::max(m_score.best_score,m_score.score));

            }
        }
    }


}

void MainScene::enemyToScene()
{
    //qDebug()<<"111\n";
    m_recoder++;
    if(m_recoder < ENEMY_INTERVAL)
    {
        return;
    }
    m_recoder = 0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == true)
        {
            m_enemys[i].m_Free=false;
            m_enemys[i].m_X=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            //m_enemys[i].m_X=rand();
            m_enemys[i].m_Y=-m_enemys[i].m_Rect.height();
           // qDebug()<<m_enemys[i].m_X<<"\n";
            break;
        }

    }

}

void MainScene::bossToScene()
{
    m_boss_recoder++;
    if(m_boss_recoder < BOSS_INTERVAL)
    {
        return;
    }
    m_boss_recoder = 0;
    for(int i=0;i<BOSS_NUM;i++)
    {
        if(m_bosses[i].m_Free == true)
        {
            m_bosses[i].m_Free=false;
            m_bosses[i].m_X=rand()%(GAME_WIDTH-m_bosses[i].m_Rect.width());
            //m_enemys[i].m_X=rand();
            m_bosses[i].m_Y=-m_bosses[i].m_Rect.height();
           // qDebug()<<m_enemys[i].m_X<<"\n";
            break;
        }

    }
}

