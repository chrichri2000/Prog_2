#include "Node.h"
#ifndef LIST_H
#define LIST_H
template <class T> class List
{
    private:
        int n,len;
        Nodo<T> *head;
    
    public:
        List(int n,int len,Nodo<T> *head) : n(n), len(len), head(head) {}

        List() : List(0,10,NULL) {}

        void Ins(Nodo<T> *x) //Inserimento In Coda
        {
            if(n >= len) return;
            n++;
            if(head == NULL)
            {
                head = x;
                return;
            }
            Nodo<T>* current = head;
            while(current->getNext() != NULL)
            {
                current = current->getNext();
            }
            current->setNext(x);
            x->setNext(NULL);
        }

        void Ins(T value)
        {
            if(n >= len) return;
            n++;
            if(head == NULL)
            {
                head->setValue(value);
                return;
            }
            Nodo<T>* new_node = new Nodo<T>(value);
            Nodo<T>* current = head;
            while(current->getNext() != NULL)
            {
                current = current->getNext();
            }
            current->setNext(new_node);
            new_node->setNext(NULL);
        }

        void stampa()
        {
            if(head == NULL) return;
            Nodo<T> *current = head;
            while(current!=NULL)
            {
                cout << current->getValue() << endl;
                current = current->getNext();
            }
        }
};
#endif