#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

using namespace std;

class Coordinate
{
public:

    Coordinate(int x, int y);

    int getX();

    int getY ();

    string getString();

private:
    int x;
    int y;
};

#endif // COORDINATE_H
