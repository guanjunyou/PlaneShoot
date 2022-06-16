// h文件
#ifndef TESTLABEL_H
#define TESTLABEL_H

#include <QWidget>
#include <QPalette>
#include <QFont>
#include <QGraphicsBlurEffect>

namespace Ui {
class TestLabel;
}

class TestLabel : public QWidget
{
    Q_OBJECT

public:
    explicit TestLabel(QWidget *parent = 0);
    ~TestLabel();

    void setText(const QString& text);
    void setAlignment(Qt::Alignment align);
    void setTextColor(QColor color);
    void setWidgetBackColor(QColor color);
    void setWidgetRound(int r);
    void setLabelBackColor(QColor color);
    void setFontSize(int size);
    void setWidgetEffect(QColor color);

protected:
    void paintEvent(QPaintEvent* e);

private:
    Ui::TestLabel *ui;
    QPalette _palette; // 文字颜色
    QFont _font;
    QGraphicsDropShadowEffect _effect;
    int _round; // 圆角半经
    QColor _backColor; // 控件背景颜色
};

#endif // TESTLABEL_H

