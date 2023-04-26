#include "Kibic.h"
#ifndef PROJEKT2_CIRCLEKIBIC_H
#define PROJEKT2_CIRCLEKIBIC_H


class CircleKibic : public Kibic{
public:
    CircleKibic();
    CircleKibic(float size, float percent);
    CircleKibic(float pozycjaX, float pozycjaY, bool zielony);

    float dystansDoKibica(Kibic kibic);

};


#endif //PROJEKT2_CIRCLEKIBIC_H
