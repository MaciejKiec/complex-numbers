#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include "LZespolona.hh"

class statystyka{
private:
    int poprawne;
    int niepoprawne;
public:

    void WyswietlWynik();
    void DodajDobre();
    void DodajZle();
    void Inicjalizuj();

};



#endif