#ifndef CHARACTERDRAWING_H
#define CHARACTERDRAWING_H

#include "canvasdrawing.h"
#include "character.h"

class CharacterDrawing : public CanvasDrawing
{
public:
    CharacterDrawing(Character* model);

    void draw(QPainter* painter) override;

private:
    Character* model;
};

#endif // CHARACTERDRAWING_H
