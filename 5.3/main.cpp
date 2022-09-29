#include <iostream>
#include "banco.cpp"
using namespace std;

void menu();

int main()
{
    menu();
}

void menu() 
{
    Banco banco;
    char select;
    cout << "Menu-Admin de Cheques" <<endl;
    cout << "1) Registrar Cheque (Insertar)" <<endl;
    cout << "2) Procesar Cheque (Eliminar)" <<endl;
    cout << "3) Registrar ChequeRechazado (Insertar)" <<endl;
    cout << "4) Procesar ChequeRechazado (Eliminar)" <<endl;
    cout << "5) Salir" <<endl;
    cin>>select;

    do
    {
        switch (select)
        {
        case '1':
        {
            int Numero, CuentaADepositar;
            string NombreBanco;
            double Monto;
            cout << "Registrar Cheque (Insertar)" <<endl;
            cout << "Ingrese el numero de cheque: " <<endl;
            cin>>Numero;
            cout << "Ingrese la cuenta a depositar: " <<endl;
            cin>>CuentaADepositar;
            cout << "Ingrese el nombre del Banco: " <<endl;
            getline(cin, NombreBanco);
            cout << "Ingrese el monto: " <<endl;
            cin>>Monto;
            Cheque cheque(Numero, NombreBanco, CuentaADepositar, Monto);
            banco.RegistroCheque(cheque);
            break;
        }

        case '2':
        {
            cout << "Procesar Cheque (Eliminar)" <<endl;
            banco.ProcesarCheque();
            break;
        }

        case '3':
        {
            cout << "Registrar ChequeRechazado (Insertar)" <<endl;
            int Numero, CuentaADepositar;
            string NombreBanco;
            double Monto, Cargo;
            cout << "Registrar ChequeRechazado (Insertar)" <<endl;
            cout << "Ingrese el numero de cheque: " <<endl;
            cin>>Numero;
            cout << "Ingrese la cuenta a depositar: " <<endl;
            cin>>CuentaADepositar;
            cout << "Ingrese el nombre del Banco: " <<endl;
            getline(cin, NombreBanco);
            cout << "Ingrese el monto: " <<endl;
            cin>>Monto;
            ChequeRechazado chequeRechazado(Numero, NombreBanco, CuentaADepositar, Monto);
            banco.RegistroChequeRechazado(chequeRechazado);
            break;
        }

        case '4':
        {
            cout << "Procesar ChequeRechazado (Eliminar)" <<endl;
            banco.ProcesarChequeRechazado();
            break;
        }

        case '5':
        {
            cout << "Salir" <<endl;
            break;
        }
        
        default:
            break;
        }
    } while (select != '5');
    
}