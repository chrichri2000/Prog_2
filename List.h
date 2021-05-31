#include "Node.h"
using namespace std;
#ifndef LIST_H
#define LIST_H

template <class T> class List
{
    private:
        Node<T> *head, *tail;
        int n,ascend;

    public:
        List(int n, int ascend) : n(n), ascend(ascend), head(NULL), tail(NULL) {}
        List() : List(0,1) {}

        void setAscend(int ascend) { this->ascend = ascend; }
        int getAscend() { return this->ascend; }

        void Ins_Head( T x )
        {
            Node<T> *new_node = new Node<T>(x);
            n++;

            if(head == NULL && tail == NULL) 
            { 
                head = new_node;
                tail = new_node;
                return; 
            }
                new_node->setNext(head);
                head->setPrev(new_node);
                head = new_node;
        }

        void Ins_Tail( T x )
        {
            Node<T> *new_node = new Node<T>(x);
            n++;

            if(head == NULL && tail == NULL)
            {
                tail = head = new_node;
                return;
            }
            new_node->setPrev(tail);
            tail->setNext(new_node);
            tail = new_node;
        }

        void Ins(T x)
        {
            Node<T> *new_nodo = new Node<T>(x);
            n++;

            if(head == NULL && tail == NULL)
            {
                head = tail = new_nodo;
            }
            
            Node<T> *tmp = head;
            if(ascend == 1)
            {
                while(tmp && tmp->getValue() < new_nodo->getValue()) { tmp = tmp->getNext(); }
                new_nodo->setNext(tmp->getNext());
                new_nodo->setPrev(tmp);
                tmp->setNext(new_nodo);
                new_nodo->getNext()->setPrev(new_nodo);
                return;
            }

            else
            {
                while(tmp && tmp->getValue() > new_nodo->getValue()) { tmp = tmp->getNext(); }
                new_nodo->setNext(tmp->getNext());
                new_nodo->setPrev(tmp);
                tmp->setNext(new_nodo);
                new_nodo->getNext()->setPrev(new_nodo);
                return;
            }
        }

        void Canc( T value )
        {
            if(head == NULL ) return;
            Node<T> *current = head;
            while(current && current->getValue() != value)
            {
                current = current->getNext();
            }
            if(!current) return;
            n--;
            if(head == current)
            {
                head = current->getNext();
                head->setPrev(NULL);
                delete current;
                return;
            }

            if(tail == current)
            {
                tail = current->getPrev();
                tail->setNext(NULL);
                delete current;
                return;
            }
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }

        string to_String() const
        {
            stringstream ss;
            if( head == NULL ) return "Nothing to show";
            Node<T> *current = head;
            while( current!=NULL )
            {
                current = current->getNext();
                ss << current->getValue() << " ";
            }
            return ss.str();
        }

        friend ostream &operator <<(ostream &os, const List<T> &l)
        {
            if(l.head == NULL ) return os;
            Node<T> *current = l.head;
            while(current != NULL) 
            { 
                os << current->getValue() << " "; 
                current = current->getNext();
            }
            return os;
        }
};
#endif