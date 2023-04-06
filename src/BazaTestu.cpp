#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"
#include <fstream>
#include <limits>

using namespace std;


  bool BazaTestu::OtworzPlik(){
    plik_z_pyt.open(str,std::fstream::in);
    if (plik_z_pyt){
      return true;
    }else{
      return false;
    }
  }

  bool BazaTestu::PobierzPytanie(WyrazenieZesp & W){
    plik_z_pyt >> W;
    while(!plik_z_pyt.good() && !plik_z_pyt.eof()){
      cerr << "Nie udało się odczytać pytania!" << endl;
      plik_z_pyt.clear();
      plik_z_pyt.ignore(numeric_limits<streamsize>::max(), '\n');
      plik_z_pyt >> W;
    }
    if(plik_z_pyt.good()!=true) return false;
   return true;
  }

  void BazaTestu::ZamknijPlik(){
    plik_z_pyt.close();
  }

  bool BazaTestu::InicjalizujTest(const char *PoziomTestu){
    if(!strcmp(PoziomTestu,"latwy")){
      str="test_latwy.dat";
      return true;
    }
    if(!strcmp(PoziomTestu,"trudny")){
      str="test_trudny.dat";
      return true;
    }

    cerr << "Otwarcie testu nie powiodło się" << endl;
    return false;
  }