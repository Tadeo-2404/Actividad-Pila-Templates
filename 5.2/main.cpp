#include<iostream>
#include "pila.cpp"
using namespace std;

int main() {
    Pila<int> ObjPila;
    int indice;

    if(ObjPila.PilaVacia()) {
        for (indice = 0; indice < MAX; indice++)
        {
            ObjPila + indice*2;
        }
    }

    while (!ObjPila.PilaVacia())
    {
        ObjPila - &indice;
        cout << endl;
        cout << indice;
    }
    
}