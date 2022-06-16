#ifndef SCORE_H
#define SCORE_H
#include <QPixmap>
#include<QRect>
#include"config.h"
#include<QString>
#include<qfont.h>
#include<QFontMetrics>
#include<fstream>
#include<istream>
#include<iostream>

class Score
{
public:
    Score();
    int score;
    int best_score;//历史最高分数
    int life;
    bool isGameOver;

    void setPosition();

    void display();

    void write(int m_score);

    int m_X;
    int m_Y;

    QString str;

    QString text = "5";

};

#endif // SCORE_H
