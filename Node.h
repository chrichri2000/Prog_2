#include <iostream>
#ifndef NODE_H
#define NODE_H
using namespace std;

template <class T> class Nodo
{
    private:
        T value;
        Nodo<T> *next;
    
    public:

        Nodo(T value, Nodo<T> *next) : value(value), next(next) {}

        Nodo() : Nodo(0,NULL){}

        Nodo(T value) : Nodo(value,NULL){}

        void setValue(T value) { this->value = value; }
        T getValue() { return value; }
        void setNext(Nodo<T> *next) { this->next = next; }
        Nodo<T> *getNext() { return next; }
};
#endif