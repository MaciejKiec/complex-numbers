#include "LZespolona.hh"
const double epsilon = 0.00000000001;



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (const LZespolona & N2) const{
  LZespolona  Wynik;

  Wynik.re = re + N2.re;
  Wynik.im = im + N2.im;
  return Wynik;
}
LZespolona LZespolona::operator - (const LZespolona & N2) const{
  LZespolona  Wynik;

  Wynik.re = re - N2.re;
  Wynik.im = im - N2.im;
  return Wynik;
}
LZespolona LZespolona::operator * (const LZespolona & N2) const{
  LZespolona  Wynik;

  Wynik.re = re*N2.re-im*N2.im;
  Wynik.im = re*N2.im+im*N2.re;
  return Wynik;
}
LZespolona LZespolona::operator / (const LZespolona & N2) const{
  LZespolona Wynik;

  Wynik = (*this) * N2.sprzezenie()/(N2.modul()*N2.modul());

  return Wynik;
}

LZespolona LZespolona::operator / (const double & l2) const{
  LZespolona wynik;

  wynik.re = re/l2;
  wynik.im = im/l2;

  return wynik;
}

double  LZespolona::modul() const{
  double wynik;

  wynik = sqrt(pow(re,2)+pow(im,2));
  return wynik;
}

LZespolona  LZespolona::sprzezenie() const{
  LZespolona  wynik;
  wynik.re = re;
  wynik.im = -im;
  return wynik;
}

std::ostream& operator << (std::ostream& out, LZespolona Skl1){

  out << "(" << Skl1.get_re() << std::showpos << Skl1.get_im() << std::noshowpos << "i)";

  return out;
}

LZespolona::LZespolona(double _re, double _im): re(_re), im(_im){}
LZespolona::LZespolona(): re(0), im(0){}

const double & LZespolona::get_re() const{
  return re;
}

const double & LZespolona::get_im() const{
  return im;
}

void LZespolona::set_re(double _re){
  re = _re;
}

void LZespolona::set_im(double _im){
  im = _im;
}

std::istream& operator >> (std::istream& in, LZespolona & Skl1){
  char temp;
  double re,im;

  in >> temp;
  if (temp != '('){
    in.setstate(std::ios::failbit);
     return in;
  }
  in >> re;
  Skl1.set_re(re);
  in >> im;
  Skl1.set_im(im);
  in >> temp;
  if (temp != 'i'){
    in.setstate(std::ios::failbit);
     return in;
  }
  in >> temp;
   if (temp != ')'){
    in.setstate(std::ios::failbit);
     return in;
  }

return in;
}

bool LZespolona::operator == (const LZespolona & N2) const{
  if ((std::abs(re-N2.re)) < epsilon && (std::abs(im-N2.im)) < epsilon){
    return true;
  }else{
    return false;
  }
}

bool LZespolona::operator != (const LZespolona & N2) const{
  return !(*this == N2);
}
