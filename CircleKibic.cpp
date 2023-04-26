#include "CircleKibic.h"
#include <cmath>
#include <iostream>

CircleKibic::CircleKibic():Kibic(){}

CircleKibic::CircleKibic(float size, float percent):Kibic(size, percent){}

CircleKibic::CircleKibic(float pozycjaX, float pozycjaY, bool zielony):Kibic(pozycjaX, pozycjaY, zielony){}

float CircleKibic::dystansDoKibica(Kibic kibic)
{
    std::cout << "Circle" << std::endl;
    float kwadratRoznicyX = pow((xPosition-kibic.pozycjaX()),2);
    float kwadratRoznicyY = pow((yPosition-kibic.pozycjaY()),2);
    float dystans = sqrt(kwadratRoznicyX+kwadratRoznicyY);
    return dystans;
}