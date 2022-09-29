#ifndef PILA_HPP
#define PILA_HPP
#define MAX 10
#include <iostream>
using namespace std;

template <class T>
class Pila
{
private:
    T EspacioPila[MAX];
    int tope;

public:
    Pila();
    void Push(T dato);
    void Pop(T *dato);
    int PilaLlena();
    int PilaVacia();
};

#endif