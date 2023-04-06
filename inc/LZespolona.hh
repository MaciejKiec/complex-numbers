#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>


class LZespolona {
private:
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
public:
  LZespolona(double _re, double _im);
  LZespolona();
  double modul() const;
  LZespolona  sprzezenie() const;
  LZespolona  operator + (const LZespolona & N2) const;
  LZespolona  operator - (const LZespolona & N2) const;
  LZespolona  operator * (const LZespolona & N2) const;
  LZespolona  operator / (const LZespolona & N2) const;
  LZespolona  operator / (const double & N2) const;
  bool operator == (const LZespolona & N2) const;
  bool operator != (const LZespolona & N2) const;
  const double & get_re() const;
  const double & get_im() const;
  void set_re(double _re);
  void set_im(double _im);
};

std::ostream& operator << (std::ostream& out, LZespolona Skl1); 
std::istream& operator >> (std::istream& in, LZespolona & Skl1);



#endif
