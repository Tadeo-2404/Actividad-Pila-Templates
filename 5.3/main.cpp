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
    int select;
    cout << "Menu-Admin de Cheques" << endl;
    do
    {
        cout << "1) Registrar Cheque (Insertar)" << endl;
        cout << "2) Procesar Cheque (Eliminar)" << endl;
        cout << "3) Registrar ChequeRechazado (Insertar)" << endl;
        cout << "4) Procesar ChequeRechazado (Eliminar)" << endl;
        cout << "5) Respaldar y Leer (De Pila a Archivo)" <<endl;
        cout << "6) Escribir Cheques (De Archivo a Pila)" <<endl;
        cout << "7) Salir" << endl;
        cin >> select;
        cin.ignore();

        switch (select)
        {
        case 1:
        {
            int Numero, CuentaADepositar;
            char NombreBanco[10];
            double Monto;
            cout << "Registrar Cheque (Insertar)" <<endl;
            cout << "Ingrese el numero de cheque: " <<endl;
            cin >> Numero;
            cout << "Ingrese la cuenta a depositar: " <<endl;
            cin >> CuentaADepositar;
            cout << "Ingrese el nombre del Banco: " <<endl;
            cin.ignore();
            cin>>NombreBanco;
            cout << "Ingrese el monto: " << endl;
            cin >> Monto;
            Cheque cheque(Numero, NombreBanco, CuentaADepositar, Monto);
            banco.RegistroCheque(cheque);
            break;
        }

        case 2:
        {
            cout << "Procesar Cheque (Eliminar)" << endl;
            banco.ProcesarCheque();
            break;
        }

        case 3:
        {
            cout << "Registrar ChequeRechazado (Insertar)" <<endl;
            int Numero, CuentaADepositar;
            char NombreBanco[10];
            double Monto;
            cout << "Ingrese el numero de cheque: " <<endl;
            cin >> Numero;
            cout << "Ingrese la cuenta a depositar: " <<endl;
            cin >> CuentaADepositar;
            cin.ignore();
            cout << "Ingrese el nombre del Banco: " <<endl;
            cin>>NombreBanco;
            cout << "Ingrese el monto: " <<endl;
            cin >> Monto;
            ChequeRechazado chequeRechazado(Numero, NombreBanco, CuentaADepositar, Monto);
            banco.RegistroChequeRechazado(chequeRechazado);
            break;
        }

        case 4:
        {
            cout << "Procesar ChequeRechazado (Eliminar)" << endl;
            banco.ProcesarChequeRechazado();
            break;
        }

        case 5:
        {
            cout << "Respaldar y leer" << endl;
            banco.respaldarCheques();
            banco.leerRespaldoCheques();
            banco.respaldarChequesRechazados();
            banco.leerRespaldoChequesRechazados();
            break;
        }

        case 6:
        {
            cout << "Escribir Cheques" << endl;
            banco.escribirRespaldoChequesRechazados();
            banco.escribirRespaldoCheques();
            break;
        }

        case 7:
        {
            cout << "Salir" << endl;
            break;
        }

        default:
            cout << "Error: opcion no valida" << endl;
            break;
        }
    } while (select < 7 || select == 0);
}