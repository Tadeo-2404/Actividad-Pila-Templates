#ifndef PILA_HPP
#define PILA_HPP
#define MAX 2

template <class T>
class Pila
{
private:
    T EspacioPila[MAX];
    int Tope;

public:
    Pila();
    void operator + (T);
    void operator - (T*);
    int PilaLlena();
    int PilaVacia();
    int getTope();
    void setTope(int tope);
    T& getUltimo();
};


#endif