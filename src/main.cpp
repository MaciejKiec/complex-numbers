#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
#include <limits>

using namespace std;




int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu test;
  statystyka statystyka;

  if (!test.InicjalizujTest(argv[1])) return 1;
  if(test.OtworzPlik()==false){
    cout << "Nie udało się otworzyć pliku z pytaniami!" << endl;
    return 1;
  }
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
  

  LZespolona temp;
  WyrazenieZesp WyrZ_PytanieTestowe;
  statystyka.Inicjalizuj();

  while (test.PobierzPytanie(WyrZ_PytanieTestowe)) {
    cout << WyrZ_PytanieTestowe<< endl;
     int counter = 3;
      do{
      cin >> temp;
      if(cin.good()) counter=0;
      if (cin.fail()){
        counter--;
        cout << "Błąd! Podane liczby muszą być postaci: (a+bi)" << endl;
        cout << "Pozostało prób: " << counter << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      }while(counter > 0);
    if (WyrZ_PytanieTestowe.Oblicz() == temp){
      cout << "Poprawna odpowiedź!" << endl;
      statystyka.DodajDobre();
    }else{
      cout << "Odpowiedź niepoprawna!" << endl;
      statystyka.DodajZle();
    }
  }

  test.ZamknijPlik();


  cout << endl;
  cout << "Koniec testu" << endl;
  statystyka.WyswietlWynik();
  cout << endl; 
  
}
