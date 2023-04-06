#include "Statystyka.hh"

void statystyka::WyswietlWynik(){
    float wynik =(poprawne*100)/(poprawne+niepoprawne);

    std::cout << "Uzyskany wynik:" << std::endl;
    std::cout << "Poprawne odpowiedzi: " << poprawne << std::endl;
    std::cout << "Błędne odpowiedzi: " << niepoprawne << std::endl;
    std::cout << "Uzyskany wynik w procentach: " << wynik << "%" << std::endl;
}

void statystyka::DodajDobre(){
    poprawne++;
}

void statystyka::DodajZle(){
    niepoprawne++;
}

void statystyka::Inicjalizuj(){
    poprawne = 0;
    niepoprawne = 0;
}