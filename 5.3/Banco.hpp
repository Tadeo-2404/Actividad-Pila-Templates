#ifndef BANCO_HPP
#define BANCO_HPP
#include "../5.2/Pila.hpp"
#include "../5.3/Cheque.hpp"
#include "../5.3/ChequeRechazado.hpp"

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
    void RegistroCheque(Cheque cheque);
    void RegistroChequeRechazado(ChequeRechazado chequeRechazado);
};

#endif