#include <iostream>

using namespace std;

class Ksztalt
{
public:
    virtual void oblicz_pole() = 0;     // czysta funkcja wirtualna
};
///////////////////////////////////

class Kolo :public Ksztalt
{
    float r;
public:
    Kolo(float x)
    {
        r = x;
    }
    virtual void oblicz_pole()
    {
        cout << "Pole kola: " << 3.14*r*r << endl;
    }
};

class Kwadrat :public Ksztalt
{
    float a;
public:
    Kwadrat(float x)
    {
        a = x;
    }
    virtual void oblicz_pole()
    {
        cout << "Pole kwadratu: " << a*a << endl;
    }
};

//////////////////////////////

void obliczenia(Ksztalt *wsk)   // uniwersalna funkcja
{
    wsk -> oblicz_pole();
}

int main()
{
    Kolo k(1);
    Kwadrat kw(2);

    Ksztalt *wskaznik;

    wskaznik = &k;
    wskaznik -> oblicz_pole();

    wskaznik = &kw;
    wskaznik -> oblicz_pole();

    obliczenia(wskaznik);   // z ostatniej zmiennej w pamieci (kw)

    obliczenia(&k);     // z obiektu k

    return 0;
}
