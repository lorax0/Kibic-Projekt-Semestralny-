#include "Miasto.h"
#include "CircleKibic.h"
#include "SquareKibic.h"
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>

    std::vector<Kibic> kibice;
    int personsAmount;
    float percent;
    float range;
    int size;
    int personSize = 9;

    Miasto::Miasto()
    {

    }

    Miasto::Miasto(int ludzie, float procenty, int rozmiar, float zasiegMieszkanca)
    {
        personsAmount = ludzie;
        percent = procenty;
        size = rozmiar;
        range = zasiegMieszkanca;
    }

    Miasto::Miasto(int rozmiar, float zasiegMieszkanca)
    {
        size = rozmiar;
        range = zasiegMieszkanca;
    }

    void Miasto::zaludnij()
    {
        kibice.clear();
        for (int i = 0; i < personsAmount; ++i)
        {
            Kibic *kibic = new CircleKibic(size, percent);
            kibice.push_back(*kibic);
        }
        std::cout << "Srednie zadowolenie mieszkanca jest rowne" + std::to_string(meanZadowolenie()) << std::endl;
    }

    void Miasto::ewoluuj()
    {
        for (int i = 0; i < kibice.size(); ++i)
        {
            int zadowolenieKibica = kibice.at(i).zadowolenie(kibice, range);
            if(zadowolenieKibica<0)
            {
                kibice.at(i).przeprowadzka(size, range);
            }
        }
    }

    void Miasto::narysuj(int pixels, std::string name)
    {
        std::ofstream output(name);
        if(output.is_open())
        {
            output << "P3" << std::endl;
            output << pixels << ' ';
            output << pixels << std::endl;
            output << 255 << std::endl;

            for (int i = 0; i < pixels; ++i)
            {
                for (int j = 0; j < pixels; ++j)
                {
                    bool jestKibic = jestKibicNaPozycji(i, j, pixels);
                    if(!jestKibic)
                    {
                        output << "0 0 0" << std::endl;
                    }
                    else
                    {
                        Kibic kibic = kibicNaPozycji(i, j, pixels);
                        bool jestZielony = kibic.jestZielony();
                        if(jestZielony)
                        {
                            output << "0 255 0" << std::endl;
                        }
                        else
                        {
                            output << "255 0 0" << std::endl;
                        }
                    }
                }
            }
            output.close();
        }
        std::cout << "Srednie zadowolenie mieszkanca jest rowne" + std::to_string(meanZadowolenie()) << std::endl;

        // funkcja, która tworzy plik (tekstowy) w formacie PPM (rozszerzenie .ppm) – obrazek
        //stanu miasta o rozdzielczości M×M, na którym będą zaznaczeni kibice w postaci kropek o promieniu
        // R pikseli o odpowiednim kolorze: zielonym (kibice Legii) lub czerwonym (kibice Polonii).
    }

    void Miasto::wczytajMiasto()
    {
        std::string nazwaPliku;
        std::cout << "Podaj nazwe pliku" << std::endl;
        std::cin >> nazwaPliku;

        std::ifstream plik(nazwaPliku);
        kibice.clear();
        while(!plik.eof())
        {
            float pozycjaX=-1, pozycjaY=-1;
            std::string klub="";
            plik >> pozycjaX;
            plik >> pozycjaY;
            plik >> klub;

            if(pozycjaX==-1 || pozycjaY ==-1||klub=="")
            {
                std::cout << "Niepelne dane w pliku" << std::endl;
                exit(0);
            }

            if(pozycjaX  > size || pozycjaY > size)
            {
                std::cout << "Bledne pozycje w pliku" << std::endl;
                exit(0);
            }
            if(klub != "Legia" && klub != "Polonia")
            {
                std::cout << "Bledna nazwa klubu:" + klub << std::endl;

                std::string nazwa = nazwaKlubu();
                if(nazwa =="") continue;
                klub = nazwa;
            }

            kibice.emplace_back(pozycjaX, pozycjaY, klub=="Legia");
        }

    }

    std::string Miasto::nazwaKlubu()
    {
        wybor:
        int wybor;
        std::cout << "Jesli chcesz przypisac kibica do Legii wybierz 1, jesli do Polonii wybierz 2, jesli pominac tego kibica wybierz 3, jesli zakonczyc program wybierz 4" << std::endl;
        std::cin >> wybor;

        switch (wybor)
        {
            case 1:
            {
                return "Legia";
            }break;
            case 2:
            {
                return "Polonia";
            }break;
            case 3:
            {
                return "";
            }break;
            case 4:
            {
                std::cout << "Koniec programu wybrano 4" << std::endl;
                exit(0);
            }break;
            default:
            {
                std::cout << "Zly typ danych" << std::endl;
                goto wybor;
            }
        }

    }

    bool Miasto::jestKibicNaPozycji(int xPosition, int yPosition, int pixels)
    {
        for (Kibic kibic : kibice)
        {
            if(dystansDoKibica(xPosition, yPosition, kibic, pixels)<=personSize) return true;
        }
        return false;
    }

    Kibic Miasto::kibicNaPozycji(float xPosition, float yPosition, int pixels)
    {
        for (Kibic kibic : kibice)
        {
            if(dystansDoKibica(xPosition, yPosition, kibic, pixels)<=personSize) return kibic;
        }
    }

    float Miasto::dystansDoKibica(float xPosition, float yPosition, Kibic kibic, int pixels)
    {
        float kwadratRoznicyX = pow((xPosition-(int)((kibic.pozycjaX()/(float)size)*(float)pixels)),2);
        float kwadratRoznicyY = pow((yPosition-(int)((kibic.pozycjaY()/(float)size)*(float)pixels)),2);
        float dystans = sqrt(kwadratRoznicyX+kwadratRoznicyY);
        return dystans;
    }

    float Miasto::meanZadowolenie()
    {
        float zadowolenie = 0;
        for(auto kibic : kibice)
        {
            zadowolenie+= kibic.zadowolenie(kibice, range);
        }
        return (zadowolenie/kibice.size());
    }