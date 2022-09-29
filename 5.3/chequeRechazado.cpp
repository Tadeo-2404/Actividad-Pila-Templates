#include <iostream>
#include "../5.3/ChequeRechazado.hpp"
using namespace std;

ChequeRechazado::ChequeRechazado() {

};

ChequeRechazado::ChequeRechazado(int numeroCuenta, string banco, int cuentaADepositar, double monto) {
    this->Cargo = monto*0.10;
};

void ChequeRechazado::ImprimeDatos()
{
    Cheque::ImprimeDatos();
    cout << endl;
    cout << "Cargo por rechazo: " << this->Cargo;
}

void ChequeRechazado::setCargo(double cargo)
{
    this->Cargo = cargo;
}

double ChequeRechazado::getCargo()
{
    return this->Cargo;
}