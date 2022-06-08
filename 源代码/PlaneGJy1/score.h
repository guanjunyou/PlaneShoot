#ifndef SCORE_H
#define SCORE_H
#include <QPixmap>
#include<QRect>
#include"config.h"
#include<QString>
#include<qfont.h>
#include<QFontMetrics>

class Score
{
public:
    Score();
    int score;
    int life;
    bool isGameOver;

    void setPosition();

    void display();

    int m_X;
    int m_Y;

    QString str;

    QString text = "5";
};

#endif // SCORE_H
