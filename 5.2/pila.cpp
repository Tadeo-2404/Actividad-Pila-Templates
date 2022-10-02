#include <iostream>
#include "Pila.hpp"
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
int Pila<T>::getTope()
{
    return this->Tope;
}

template <class T>
void Pila<T>::setTope(int newTope)
{
    Tope = newTope;
}

template <class T>
T& Pila<T>::getUltimo()
{
    return this->EspacioPila[Tope];
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