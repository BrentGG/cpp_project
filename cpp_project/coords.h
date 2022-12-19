#ifndef COORDS_H
#define COORDS_H

/**
 * @brief A small container class for storing an x and y coordinate. Made this because I did not like the alternative of using vector, pair or tuple.
 */
class Coords
{
public:
    Coords(unsigned short int x, unsigned short int y) : xCoord(x), yCoord(y) {}

    unsigned short int x() { return xCoord; } // not getX() because this method will be used a lot and x() seems clearer.
    unsigned short int y() { return yCoord; } // not getY() because this method will be used a lot and y() seems clearer.

    void setX(unsigned int x) { xCoord = x; }
    void setY(unsigned int y) { yCoord = y; }

    void addX(short int x) { xCoord += x; }
    void addY(short int y) { yCoord += y; }

private:
    unsigned short int xCoord;
    unsigned short int yCoord;
};

#endif // COORDS_H
