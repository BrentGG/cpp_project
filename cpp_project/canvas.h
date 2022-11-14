#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QKeyEvent>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int x;
    int y;
    int mvmtSpeed;

private slots:
    void updateView();
};

#endif // CANVAS_H
