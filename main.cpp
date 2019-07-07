#include <iostream>

using namespace std;

// abstract class Ksztalt

class Ksztalt
{
public:

    // clean virtual function
    virtual void oblicz_pole() = 0;
};

/* ------------- class Kolo is inheriting from the abstract class Ksztalt ---------------- */

class Kolo :public Ksztalt
{
    float r;

public:

    Kolo(float x)
    {
        r = x;
    }

    // virtual member function does different things for the Kolo class than for the Kwadrat class
    virtual void oblicz_pole()
    {
        cout << "Pole kola: " << 3.14*r*r << endl;
    }
};

/* ------------- class Kwadrat is inheriting from the abstract class Ksztalt ---------------- */

class Kwadrat :public Ksztalt
{
    float a;

public:

    Kwadrat(float x)
    {
        a = x;
    }

    // virtual member function does different things for the Kwadrat class than for the Kolo class
    virtual void oblicz_pole()
    {
        cout << "Pole kwadratu: " << a*a << endl;
    }
};

/* --------------------------------------------- */

// universal function for calling the virtual member functions on the class objects
void obliczenia(Ksztalt *wsk)
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

    // call the function on the last variable in the memory (kw)
    obliczenia(wskaznik);

    // call the function on the object k (reference / address)
    obliczenia(&k);

    return 0;
}
