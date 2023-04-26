#include "SquareKibic.h"
#include <cmath>
#include <iostream>

SquareKibic::SquareKibic():Kibic(){}

SquareKibic::SquareKibic(float size, float percent):Kibic(size, percent){}

SquareKibic::SquareKibic(float pozycjaX, float pozycjaY, bool zielony):Kibic(pozycjaX, pozycjaY, zielony){}

float SquareKibic::dystansDoKibica(Kibic kibic)
{
    std::cout << "Square" << std::endl;
    float odlegloscX = abs((xPosition-kibic.pozycjaX()));
    float odlegloscY = abs((yPosition-kibic.pozycjaY()));
    if(odlegloscX > odlegloscY) return odlegloscX;
    else return odlegloscY;
}