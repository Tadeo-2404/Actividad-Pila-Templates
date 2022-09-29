#include <iostream>
#include "pila.cpp"
using namespace std;

int main() {
    Pila<int> ObjPila;
    int valor = 0;

    while (ObjPila.PilaLlena() != 1)
    {
        ObjPila.Push(valor++);

        if(ObjPila.PilaVacia() != 1) 
        {
            ObjPila.Pop(&valor);
            cout << valor <<endl;
        }
    }
    
}

