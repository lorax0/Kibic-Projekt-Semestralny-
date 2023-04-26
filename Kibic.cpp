#include "Kibic.h"
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <iostream>

    float xPosition;
    float yPosition;
    bool isGreen;

    Kibic::Kibic()
    {

    }

    Kibic::Kibic(float size, float percent)
    {
        xPosition = randomowyFloat()*size;
        yPosition = randomowyFloat()*size;
        isGreen = randomowyFloat() <= percent;
    }

    Kibic::Kibic(float pozycjaX, float pozycjaY, bool zielony)
    {
        xPosition = pozycjaX;
        yPosition = pozycjaY;
        isGreen = zielony;
    }

    float Kibic::randomowyFloat()
    {
        return (float)(rand()) / (float)(RAND_MAX);
    }

    void Kibic::przeprowadzka(int size, int odlegloscPoruszania)
    {
        float kierunek = randomowyFloat()*2*M_PI;
        xPosition += cos(kierunek)*odlegloscPoruszania;
        yPosition += sin(kierunek)*odlegloscPoruszania;
        if(xPosition>size)
        {
            xPosition-=size;
        }
        if(yPosition>size)
        {
            yPosition-=size;
        }
    }

    int Kibic::zadowolenie(std::vector<Kibic> kibice, int zasiegZadowolenia)
    {
        int zadowolenie = 0;
        for(Kibic kibic : kibice)
        {
            if(kibic.pozycjaX()==xPosition &&kibic.pozycjaY()==yPosition) continue;
            if(dystansDoKibica(kibic)>zasiegZadowolenia) continue;
            if(kibic.sojusznik(isGreen))
            {
                ++zadowolenie;
                continue;
            }
            --zadowolenie;
        }
        return zadowolenie;
    }

    float Kibic::dystansDoKibica(Kibic kibic)
    {
        std::cout << "zle" << std::endl;
        return 0;
    }

    float Kibic::pozycjaX() { return xPosition ;}

    float Kibic::pozycjaY() { return yPosition ;}

    bool Kibic::jestZielony() { return isGreen ;}

    bool Kibic::sojusznik(bool jestZielony)
    {
        bool jestSojusznikiem = jestZielony == isGreen;
        return jestSojusznikiem;
    }