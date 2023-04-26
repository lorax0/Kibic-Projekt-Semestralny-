#include <iostream>
#include <ctime>
#include <memory>
#include <vector>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include "Kibic.h"

#ifndef PROJEKT2_MIASTO_H
#define PROJEKT2_MIASTO_H


class Miasto {
private:
    std::vector<Kibic> kibice;
    int personsAmount;
    float percent;
    float range;
    int size;
public:
    Miasto();
    Miasto(int ludzie, float procenty, int rozmiar, float zasiegMieszkanca);
    Miasto(int rozmiar, float zasiegMieszkanca);

    void zaludnij();
    void ewoluuj();
    void narysuj(int pixels, std::string name);
    void wczytajMiasto();
    std::string nazwaKlubu();
    bool jestKibicNaPozycji(int xPosition, int yPosition, int pixels);
    Kibic kibicNaPozycji(float xPosition, float yPosition, int pixels);
    float dystansDoKibica(float xPosition, float yPosition, Kibic kibic, int pixels);
    float meanZadowolenie();
};


#endif //PROJEKT2_MIASTO_H
