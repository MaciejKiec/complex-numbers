#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp {
private:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
public:
  WyrazenieZesp();
  WyrazenieZesp(const LZespolona & L1, const Operator op, const LZespolona & L2);
  LZespolona Oblicz();
  const LZespolona get_arg1() const;
  const LZespolona get_arg2() const;
  const Operator get_op() const;
  void set_arg1(const LZespolona & L);
  void set_arg2(const LZespolona & L);
  void set_op(const Operator op);
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

std::ostream & operator << (std::ostream & out, const Operator &O);
std::ostream & operator << (std::ostream & out, WyrazenieZesp &W);
std::istream & operator >> (std::istream & in, Operator &Op);
std::istream & operator >> (std::istream & in, WyrazenieZesp &W);
#endif
