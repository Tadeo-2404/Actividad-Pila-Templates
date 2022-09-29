#ifndef CHEQUERECHAZADO_HPP
#define CHEQUERECHAZADO_HPP
#include <iostream>
#include "../5.3/Cheque.hpp"

class ChequeRechazado: public Cheque
{
private:
    double Cargo;
public:
    ChequeRechazado();
    ChequeRechazado(int, string, int, double);
    ~ChequeRechazado();
    void ImprimeDatos();
    double getCargo();
    void setCargo(double cargo);
};

#endif