#ifndef BANCO_HPP
#define BANCO_HPP
#include "../5.2/pila.cpp"
#include "Cheque.hpp"
#include "ChequeRechazado.hpp"

class Banco
{
private:
    Pila<Cheque> Cheques;
    Pila<ChequeRechazado> ChequesRechazados;
public:
    Banco();
    ~Banco();
    void ProcesarCheque();
    void ProcesarChequeRechazado();
    void RegistroCheque(Cheque);
    void RegistroChequeRechazado(ChequeRechazado);
    void respaldarCheques();
    void leerRespaldoCheques();
    void respaldarChequesRechazados();
    void leerRespaldoChequesRechazados();
    void escribirRespaldoCheques();
    void escribirRespaldoChequesRechazados();
};

#endif