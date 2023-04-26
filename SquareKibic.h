#include "Kibic.h"
#ifndef PROJEKT2_SQUAREKIBIC_H
#define PROJEKT2_SQUAREKIBIC_H


class SquareKibic : Kibic{
public:
    SquareKibic();
    SquareKibic(float size, float percent);
    SquareKibic(float pozycjaX, float pozycjaY, bool zielony);

    virtual float dystansDoKibica(Kibic kibic) override;
};


#endif //PROJEKT2_SQUAREKIBIC_H
