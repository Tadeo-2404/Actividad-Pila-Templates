#include <iostream>
#include "ChequeRechazado.hpp"
using namespace std;

ChequeRechazado::ChequeRechazado() {

};

ChequeRechazado::~ChequeRechazado() {
    
}

ChequeRechazado::ChequeRechazado(int numeroCuenta, char *banco, int cuentaADepositar, double monto) {
    setNumero(numeroCuenta);
    setBanco(banco);
    setCuentaADepositar(cuentaADepositar);
    setMonto(monto);
    this->Cargo = monto*0.10;
};

void ChequeRechazado::ImprimeDatos()
{
    Cheque::ImprimeDatos();
    cout << "Cargo por rechazo: " << this->Cargo <<endl;
}

void ChequeRechazado::setCargo(double cargo)
{
    this->Cargo = cargo;
}

double ChequeRechazado::getCargo()
{
    return this->Cargo;
}