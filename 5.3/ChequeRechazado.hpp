#ifndef CHEQUERECHAZADO_HPP
#define CHEQUERECHAZADO_HPP
#include <iostream>
#include "Cheque.hpp"

class ChequeRechazado: public Cheque
{
private:
    double Cargo;
public:
    ChequeRechazado();
    ChequeRechazado(int, char[], int, double);
    ~ChequeRechazado();
    void ImprimeDatos();
    double getCargo();
    void setCargo(double cargo);
};

#endif