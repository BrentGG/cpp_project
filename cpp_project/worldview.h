#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include <QWidget>
#include <QKeyEvent>

class WorldView : public QWidget
{
    Q_OBJECT
public:
    explicit WorldView(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int x;
    int y;
    int mvmtSpeed;
};

#endif // WORLDVIEW_H
