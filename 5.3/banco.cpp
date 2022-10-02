#include <iostream>
#include "Banco.hpp"
#include "cheque.cpp"
#include "chequeRechazado.cpp"
#include <fstream>
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
    if(!Cheques.PilaVacia()) 
    {
        Cheques - &ChequeCliente;
        cout << "Cheque Procesado: " <<endl;
        ChequeCliente.ImprimeDatos();
    } else {
        cout << "No hay cheques por procesar" <<endl;
        return;
    }
}

void Banco::ProcesarChequeRechazado()
{
    ChequeRechazado ChequeClienteRechazado;
    if(!ChequesRechazados.PilaVacia()) 
    {
        ChequesRechazados - &ChequeClienteRechazado;
        cout << "Cheque Rechazado Procesado: " <<endl;
        ChequeClienteRechazado.ImprimeDatos();
    } else {
        cout << "No hay cheques por procesar" <<endl;
        return;
    }
}

void Banco::RegistroCheque(Cheque ChequeCliente)
{
    if (!Cheques.PilaLlena())
    {
        cout << "Registrando el cheque : " <<endl;
        ChequeCliente.ImprimeDatos();
        Cheques + ChequeCliente;
    } else {
        cout << "No se pudo registrar el cheque rechazado por falta de espacio" <<endl;
       return;
    }
}

void Banco::RegistroChequeRechazado(ChequeRechazado ChequeClienteRechazado)
{
    if (!ChequesRechazados.PilaLlena())
    {
        cout << "Registrando el cheque rechazado: " <<endl;
        ChequeClienteRechazado.ImprimeDatos();
        ChequesRechazados + ChequeClienteRechazado;
    } else {
        cout << "No se pudo registrar el cheque rechazado por falta de espacio" <<endl;
        return;
    }
}

void Banco::respaldarCheques() 
{
    cout << "Escribir Cheques" <<endl;
    ofstream archivoEntrada;
    archivoEntrada.open("cheques.dat", ios::app | ios::binary);

    if(archivoEntrada.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    archivoEntrada.clear();
    int topeOriginal = this->Cheques.getTope();
    int topeAux = this->Cheques.getTope();
    Cheque cheque;

    while (true)
    {
        if(topeAux == -1) break;
        cout << "tope: " << topeAux << endl;
        cheque = this->Cheques.getUltimo();
        cout << "Numero: " << cheque.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << cheque.getCuentaADepositar() <<endl;
        cout << "Banco: " << cheque.getBanco() <<endl;
        cout << "Monto: " << cheque.getMonto() <<endl;
        cout << "----------------------------" <<endl;
        archivoEntrada.write(reinterpret_cast<char*>(&cheque), sizeof(Cheque));
        cout << "Se ha respaldado el cheque: "  << cheque.getNumero() <<endl;
        cout << endl;
        topeAux--;
        this->Cheques.setTope(topeAux);
    }

    this->Cheques.setTope(topeOriginal);
    archivoEntrada.close();
    cout << "Se han respaldado los Cheques Correctamente" <<endl;
}

void Banco::leerRespaldoCheques() 
{
    cout << "Leer Cheques" <<endl;
    ifstream archivoSalida;
    archivoSalida.open("cheques.dat", ios::app | ios::binary);

    if(archivoSalida.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    archivoSalida.clear();
    int topeOriginal = this->Cheques.getTope();
    int topeAux = this->Cheques.getTope();
    Cheque cheque;

    while (true)
    {
        if(topeAux == -1) break;
        cout << "tope: " << topeAux << endl;
        cheque = this->Cheques.getUltimo();
        cout << "Numero: " << cheque.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << cheque.getCuentaADepositar() <<endl;
        cout << "Banco: " << cheque.getBanco() <<endl;
        cout << "Monto: " << cheque.getMonto() <<endl;
        cout << "----------------------------" <<endl;
        archivoSalida.read(reinterpret_cast<char*>(&cheque), sizeof(Cheque));
        cout << "Se ha leido el cheque: "  << cheque.getNumero() <<endl;
        cout << endl;
        topeAux--;
        this->Cheques.setTope(topeAux);
    }

    this->Cheques.setTope(topeOriginal);
    archivoSalida.close();
    cout << "Se han leido los Cheques Correctamente" <<endl;
}


void Banco::respaldarChequesRechazados() 
{
    cout << "Escribir Cheques Rechazados" <<endl;
    ofstream archivoEntrada;
    archivoEntrada.open("cheques_rech.dat", ios::app | ios::binary);

    if(archivoEntrada.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    archivoEntrada.clear();
    int topeOriginal = this->ChequesRechazados.getTope();
    int topeAux = this->ChequesRechazados.getTope();
    Cheque cheque;

    while (true)
    {
        if(topeAux == -1) break;
        cout << "tope: " << topeAux << endl;
        cheque = this->ChequesRechazados.getUltimo();
        cout << "Numero: " << cheque.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << cheque.getCuentaADepositar() <<endl;
        cout << "Banco: " << cheque.getBanco() <<endl;
        cout << "Monto: " << cheque.getMonto() <<endl;
        cout << "----------------------------" <<endl;
        archivoEntrada.write(reinterpret_cast<char*>(&cheque), sizeof(Cheque));
        cout << "Se ha respaldado el cheque: "  << cheque.getNumero() <<endl;
        cout << endl;
        topeAux--;
        this->ChequesRechazados.setTope(topeAux);
    }

    this->ChequesRechazados.setTope(topeOriginal);
    archivoEntrada.close();
    cout << "Se han respaldado los Cheques Rechazados Correctamente" <<endl;
}

void Banco::leerRespaldoChequesRechazados() 
{
    cout << "Leer Cheques Rechazados" <<endl;
    ifstream archivoSalida;
    archivoSalida.open("cheques_rech.dat", ios::app | ios::binary);

    if(archivoSalida.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    archivoSalida.clear();
    int topeOriginal = this->ChequesRechazados.getTope();
    int topeAux = this->ChequesRechazados.getTope();
    Cheque cheque;

    while (true)
    {
        if(topeAux == -1) break;
        cout << "tope: " << topeAux << endl;
        cheque = this->ChequesRechazados.getUltimo();
        cout << "Numero: " << cheque.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << cheque.getCuentaADepositar() <<endl;
        cout << "Banco: " << cheque.getBanco() <<endl;
        cout << "Monto: " << cheque.getMonto() <<endl;
        cout << "----------------------------" <<endl;
        archivoSalida.read(reinterpret_cast<char*>(&cheque), sizeof(Cheque));
        cout << "Se ha leido el cheque: "  << cheque.getNumero() <<endl;
        cout << endl;
        topeAux--;
        this->ChequesRechazados.setTope(topeAux);
    }

    this->ChequesRechazados.setTope(topeOriginal);
    archivoSalida.close();
    cout << "Se han leido los Cheques Rechazados Correctamente" <<endl;
}

void Banco::escribirRespaldoCheques() 
{
    cout << "Escribir Cheques" <<endl;
    ifstream archivoCheques;
    archivoCheques.open("cheques.dat", ios::app | ios::binary);

    if(archivoCheques.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    Cheque cheque;

    while (true)
    {
        archivoCheques.read(reinterpret_cast<char*>(&cheque), sizeof(Cheque));
        if(archivoCheques.eof()) break;
        cout << "Numero: " << cheque.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << cheque.getCuentaADepositar() <<endl;
        cout << "Banco: " << cheque.getBanco() <<endl;
        cout << "Monto: " << cheque.getMonto() <<endl;
        cout << "----------------------------" <<endl;
        this->RegistroCheque(cheque);
        cout << "Se ha escrito el cheque: "  << cheque.getNumero() <<endl;
        cout << endl;
    }
    archivoCheques.close();
    cout << "Se han escrito los Cheques Correctamente" <<endl;
}

void Banco::escribirRespaldoChequesRechazados() 
{
    cout << "Escribir Cheques Rechazados" <<endl;
    ifstream archivoChequesRechazados;
    archivoChequesRechazados.open("cheques_rech.dat", ios::app | ios::binary);

    if(archivoChequesRechazados.fail())
    {
        cout << "Error: no se pudo abrir el archivo" <<endl;
        exit(1);
    }

    ChequeRechazado chequeRechazado;

    while (true)
    {
        archivoChequesRechazados.read(reinterpret_cast<char*>(&chequeRechazado), sizeof(ChequeRechazado));
        cout << "Numero: " << chequeRechazado.getNumero() <<endl;
        cout << "Cuenta A Depositar: " << chequeRechazado.getCuentaADepositar() <<endl;
        cout << "Banco: " << chequeRechazado.getBanco() <<endl;
        cout << "Monto: " << chequeRechazado.getMonto() <<endl;
        cout << "Cargo: " << chequeRechazado.getCargo() <<endl;
        cout << "----------------------------" <<endl;
        this->RegistroChequeRechazado(chequeRechazado);
        cout << "Se ha escrito el cheque rechazado: "  << chequeRechazado.getNumero() <<endl;
        if(archivoChequesRechazados.eof()) break;
        cout << endl;
    }

    archivoChequesRechazados.close();
    cout << "Se han escrito los Cheques Rechazados Correctamente" <<endl;
}

