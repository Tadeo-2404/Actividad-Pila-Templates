#include <iostream>
#include "Pila.hpp"
using namespace std;

template <class T>
Pila<T>::Pila() 
{
    this->tope = -1;
}

template <class T>
void Pila<T>::Push(T dato) 
{
    if(!Pila::PilaLlena()) {
        EspacioPila[++this->tope] = dato;
    } else {
        cout << "Error de desbordamiento. Pila llena" <<endl;
    }
}

template <class T>
void Pila<T>::Pop(T *dato) 
{
    if(!Pila::PilaVacia()) {
        *dato = EspacioPila[this->tope--];
    } else {
        cout << "Error de desbordamiento. Pila vacia" <<endl;
    }
}

template <class T>
int Pila<T>::PilaLlena() 
{
    if(this->tope == MAX -1) 
    {
        return 1;
    } else {
        return 0;
    }
}

template <class T>
int Pila<T>::PilaVacia() 
{
    if(this->tope == -1) 
    {
        return 1;
    } else {
        return 0;
    }
}