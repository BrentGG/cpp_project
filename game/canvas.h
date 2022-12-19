#ifndef CANVAS_H
#define CANVAS_H

#include "canvasdrawing.h"

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>

#include <vector>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    void updateCanvas();

    void addDrawing(CanvasDrawing* drawing);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPainter* painter;

    std::vector<CanvasDrawing*> drawings;
};

#endif // CANVAS_H
