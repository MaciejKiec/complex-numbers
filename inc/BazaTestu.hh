#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"
#include <fstream>
#include <string>


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
class BazaTestu {
public:
  std::fstream plik_z_pyt;
  std::string str;
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */

public:
  bool OtworzPlik();
  bool PobierzPytanie(WyrazenieZesp & W);
  void ZamknijPlik();
  bool InicjalizujTest(const char *PoziomTestu);

};

#endif
