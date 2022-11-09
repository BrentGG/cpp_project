#ifndef TETRISSCREEN_H
#define TETRISSCREEN_H

#include <QWidget>
#include <QKeyEvent>

class TetrisScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TetrisScreen(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int x;
    int y;
    int mvmtSpeed;
};

#endif // TETRISSCREEN_H
