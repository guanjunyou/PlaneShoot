#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include"config.h"
#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include<QMessageBox>
#include<QScreen>
#include<QGuiApplication>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    int menu;

    MainScene * w;

private slots:
    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
