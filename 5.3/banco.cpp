#include <iostream>
#include "Banco.hpp"
using namespace std;

Banco::Banco() 
{

}

Banco::~Banco() 
{

}

void Banco::ProcesarCheque() 
{
    Cheque ChequeCliente;
    if(!this->Cheques.PilaVacia()) 
    {
        this->Cheques - &ChequeCliente;
        cout << "Cheque Procesado: " <<endl;
        ChequeCliente.ImprimeDatos();
    } else {
        cout << "No hay cheques por procesar" <<endl;
    }
}

void Banco::ProcesarChequeRechazado()
{
    ChequeRechazado ChequeCliente;
    if(!this->ChequesRechazados.PilaVacia()) 
    {
        this->ChequesRechazados - &ChequeCliente;
        cout << "Cheque Rechazado Procesado: " <<endl;
        ChequeCliente.ImprimeDatos();
    } else {
        cout << "No hay cheques por procesar" <<endl;
    }
}

void Banco::RegistroCheque(Cheque ChequeCliente)
{
    if (!Cheques.PilaLlena())
    {
        cout << "Registrando el cheque : ";
        ChequeCliente.ImprimeDatos();
        Cheques + ChequeCliente;
    } else {
        cout << "No se pudo registrar el cheque rechazado por falta de espacio" <<endl;
    }
}

void Banco::RegistroChequeRechazado(ChequeRechazado ChequeCliente)
{
    if (!ChequesRechazados.PilaLlena())
    {
        cout << "Registrando el cheque : ";
        ChequeCliente.ImprimeDatos();
        ChequesRechazados + ChequeCliente;
    } else {
        cout << "No se pudo registrar el cheque rechazado por falta de espacio" <<endl;
    }
}