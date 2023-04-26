#include "Manager.h"
#include "Miasto.h"
#include <iostream>


    Manager::Manager()
    {

    }

    void Manager::Menu()
    {
        menu:
        int wybor;
        std::cout << "Jesli chcesz wczytac plik wpisz 1, jesli losowac mieszkancow wpisz 2" << std::endl;
        std::cin >> wybor;
        switch (wybor)
        {
            case 1:
            {
                Wczytywanie();
            }break;
            case 2:
            {
                PodawanieDanych();
            }break;
            default:
            {
                std::cout << "Zly typ danych" << std::endl;
                goto menu;
            }
        }
    }

    void Manager::Wczytywanie()
    {
        int lata;
        int piksele;
        float zasiegMieszkanca;
        float rozmiarMapy;
        std::cout << "Podaj liczbe lat" << std::endl;
        std::cin >> lata;
        std::cout << "Podaj ilosc pikseli" << std::endl;
        std::cin >> piksele;
        std::cout << "Podaj rozmiar mapy" << std::endl;
        std::cin >> rozmiarMapy;
        std::cout << "Podaj zasieg mieszkanca" << std::endl;
        std::cin >> zasiegMieszkanca;
        Miasto miasto(rozmiarMapy, zasiegMieszkanca);
        miasto.wczytajMiasto();
        for (int i = 0; i < lata; ++i)
        {
            miasto.narysuj(piksele, "rok" + std::to_string(i) + ".ppm");
            miasto.ewoluuj();
        }
    }

    void Manager::PodawanieDanych()
    {
        float liczbaMieszkancow;
        float procenty;
        float rozmiarMapy;
        int lata;
        float zasiegMieszkanca;
        int piksele;
        std::cout << "Podaj liczbe mieszkancow" << std::endl;
        std::cin >> liczbaMieszkancow;
        std::cout << "Podaj procent zielonych" << std::endl;
        std::cin >> procenty;
        std::cout << "Podaj rozmiar mapy" << std::endl;
        std::cin >> rozmiarMapy;
        std::cout << "Podaj liczbe lat" << std::endl;
        std::cin >> lata;
        std::cout << "Podaj zasieg mieszkanca" << std::endl;
        std::cin >> zasiegMieszkanca;
        std::cout << "Podaj ilosc pikseli" << std::endl;
        std::cin >> piksele;

        Miasto miasto(liczbaMieszkancow, procenty, rozmiarMapy, zasiegMieszkanca);
        miasto.zaludnij();
        for (int i = 0; i < lata; ++i)
        {
            miasto.narysuj(piksele, "rok" + std::to_string(i) + ".ppm");
            miasto.ewoluuj();
        }
    }