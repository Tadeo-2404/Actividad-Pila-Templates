#ifndef CHEQUE_HPP
#define CHEQUE_HPP
#include <string>
using namespace std;

class Cheque
{
private:
    int Numero, CuentaADepositar;
    char Banco[10];
    double Monto;
public:
    Cheque();
    Cheque(int, char[], int, double);
    ~Cheque();
    void ImprimeDatos();

    int getNumero();
    int getCuentaADepositar();
    string getBanco();
    double getMonto();

    void setNumero(int numero);
    void setCuentaADepositar(int cuentaADepositar);
    void setBanco(char banco[]);
    void setMonto(double monto);
};
 
#endif