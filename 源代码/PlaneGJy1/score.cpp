#include "score.h"
using namespace std;
Score::Score()
{
    m_X = 0;
    m_Y = 0;
    score = 0;
    life = 3;
    isGameOver = false;

    ifstream file;
    file.open(SCORE_PATH,ios::out|ios::binary);
    file>>best_score;
    file.close();
    if(best_score == 32761)
        best_score = 0;
    //cout<<best_score<<endl;
}

void Score::setPosition()
{
    m_X = 0;
    m_Y = 0;
}

void Score::display()
{
    if(isGameOver == true)
        str = "Game Over!";
}

void Score::write(int m_score)
{
    //cout<<"m_score : "<<m_score<<endl;
    ofstream file;
    file.open(SCORE_PATH,ios::out|ios::binary|ios_base::trunc);
    file<<m_score;
    file.close();
}





