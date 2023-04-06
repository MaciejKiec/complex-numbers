#include "WyrazenieZesp.hh"

LZespolona WyrazenieZesp::Oblicz(){
    LZespolona wynik;
    switch (Op)
    {
    case Op_Dodaj:
        wynik = Arg1 + Arg2;
    break;
    case Op_Odejmij:
        wynik = Arg1 - Arg2;
    break;
    case Op_Mnoz:
        wynik = Arg1 * Arg2;
    break;
    case Op_Dziel:
        wynik = Arg1 / Arg2;
    break;
    }

    return wynik;

}
WyrazenieZesp::WyrazenieZesp(const LZespolona & L1, const Operator op, const LZespolona & L2): Arg1(L1), Op(op), Arg2(L2) {}
WyrazenieZesp::WyrazenieZesp(): Arg1(), Op(Op_Dodaj), Arg2() {}

const LZespolona WyrazenieZesp::get_arg1() const{
    return this->Arg1;
}

const LZespolona WyrazenieZesp::get_arg2() const{
    return this->Arg2;
}

const Operator WyrazenieZesp::get_op() const{
    return this->Op;
}

void WyrazenieZesp::set_arg1(const LZespolona & L){
    this->Arg1 = L;
}
void WyrazenieZesp::set_arg2(const LZespolona & L){
    this->Arg2 = L;
}
void WyrazenieZesp::set_op(const Operator op){
    this->Op = op;
}

std::ostream & operator << (std::ostream & out, const Operator &O){
    switch(O){
        case Op_Dodaj:
        out << "+";
        break;
        case Op_Odejmij:
        out << "-";
        break;
        case Op_Mnoz:
        out << "*";
        break;
        case Op_Dziel:
        out << "/";
        break;
    }

    return out;
}

std::ostream & operator << (std::ostream & out, WyrazenieZesp &W){
    out << W.get_arg1() << W.get_op() << W.get_arg2() << " = ";
    return out;
}


std::istream & operator >> (std::istream & in, Operator &Op){

char temp;

    in >> temp;
    if(in.fail()) return in;

    switch(temp){
        case '+':
        Op = Op_Dodaj;
        break;
        case '-':
        Op = Op_Odejmij;
        break;
        case '*':
        Op = Op_Mnoz;
        break;
        case '/':
        Op = Op_Dziel;
        break;
        default:
        std::cerr << "Nie rozpoznano działania!" << std::endl;
    }
    return in;
}

std::istream & operator >> (std::istream & in, WyrazenieZesp &W){
    LZespolona liczba;
    Operator Op;

    in >> liczba;
    W.set_arg1(liczba);
    
    in >> Op;
    W.set_op(Op);

    in >> liczba;
    W.set_arg2(liczba);

    return in;
}
