#ifndef COORDS_H
#define COORDS_H

/**
 * @brief A small container class for storing an x and y coordinate. Made this because I did not like the alternative of using vector, pair or tuple.
 */
class Coords
{
public:
    Coords(unsigned int x, unsigned int y) : xCoord(x), yCoord(y) {}

    unsigned int x() { return xCoord; } // not getX() because this method will be used a lot and x() seems clearer.
    unsigned int y() { return yCoord; } // not getY() because this method will be used a lot and y() seems clearer.

    void setX(unsigned int x) { xCoord = x; }
    void setY(unsigned int y) { yCoord = y; }

    void addX(int x) { xCoord += x; }
    void addY(int y) { yCoord += y; }

private:
    unsigned int xCoord;
    unsigned int yCoord;
};

#endif // COORDS_H
