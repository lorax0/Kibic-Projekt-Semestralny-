#include <vector>

#ifndef PROJEKT2_KIBIC_H
#define PROJEKT2_KIBIC_H


class Kibic{
protected:
    float xPosition;
    float yPosition;
    bool isGreen;
public:
    Kibic();
    Kibic(float size, float percent);
    Kibic(float pozycjaX, float pozycjaY, bool zielony);

    float randomowyFloat();
    void przeprowadzka(int size, int odlegloscPoruszania);
    int zadowolenie(std::vector<Kibic> kibice, int zasiegZadowolenia);
    virtual float dystansDoKibica(Kibic kibic);
    float pozycjaX();
    float pozycjaY();
    bool jestZielony();
    bool sojusznik(bool jestZielony);
};


#endif //PROJEKT2_KIBIC_H
