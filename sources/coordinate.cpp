#include "headers/coordinate.h"

Coordinate::Coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Coordinate::getX()
{
    return this->x;
}

int Coordinate::getY(){
    return this->y;
}

string Coordinate::getString(){
    string temp = "";
    switch (this->getX()) {
        case 1:
            temp="A/";
            break;
        case 2:
            temp="B/";
            break;
        case 3:
            temp="C/";
            break;
        case 4:
            temp="D/";
            break;
        case 5:
            temp="E/";
            break;
        case 6:
            temp="F/";
            break;
        case 7:
            temp="G/";
            break;
        default:
            temp = "";
    }
    temp.append(to_string(this->getY()));
    return temp;
}
