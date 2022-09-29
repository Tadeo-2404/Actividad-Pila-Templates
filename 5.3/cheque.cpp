#include <iostream>
#include "../5.3/Cheque.hpp"
using namespace std;

Cheque::Cheque() 
{

}

Cheque::Cheque(int Numero, string Banco, int CuentaADepositar, double Monto)
{
    this->Numero = Numero;
    this->Banco = Banco;
    this->CuentaADepositar = CuentaADepositar;
    this->Monto = Monto;
}

Cheque::~Cheque() {

}

void Cheque::ImprimeDatos() 
{
    cout << "Numero de cheque: " << this->Numero <<endl;
    cout << "Banco: " << this->Banco <<endl;
    cout << "Despositado: " << this->CuentaADepositar <<endl;
    cout << "Monto: " << this->Monto <<endl;
}

int Cheque::getNumero()
{
    return this->Numero;
}

int Cheque::getCuentaADepositar()
{
    return this->CuentaADepositar;
}

string Cheque::getBanco() 
{
    return this->Banco;
}

double Cheque::getMonto()
{
    return this->Monto;
}

void Cheque::setNumero(int numero) 
{
    this->Numero = numero;
}

void Cheque::setBanco(string banco)
{
    this->Banco = banco;
}

void Cheque::setCuentaADepositar(int cuenta) 
{
    this->CuentaADepositar = cuenta;
}

void Cheque::setMonto(double monto)
{
    this->Monto = monto;
}