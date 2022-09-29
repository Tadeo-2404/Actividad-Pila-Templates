#include <iostream>
#include <5.2/Pila.hpp>
using namespace std;

template <class T>
Pila<T>::Pila():Tope(-1)
{}

template <class T>
int Pila<T>::PilaLlena() 
{
    if(this->Tope == MAX-1) 
    {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
int Pila<T>::PilaVacia()
{
    if(this->Tope == -1)
    {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
void Pila<T>::operator + (T valor) 
{
    this->Tope++;
    this->EspacioPila[this->Tope] = valor;
}

template <class T>
void Pila<T>::operator - (T *valor) 
{
    *valor = this->EspacioPila[this->Tope];
    this->Tope--;
}