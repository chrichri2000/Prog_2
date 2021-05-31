#include <iostream>
#include <sstream>
using namespace std;
#ifndef NODE_H
#define NODE_H

template <class T> class Node
{
    private:
        T value;
        Node<T> *next, *prev;

        int compare(const Node<T> &n) const
        {
            if(this->value == n.value()) return 0;
            if(this->value < n.value()) return -1;
            if(this->value > n.value()) return 1;
            return 0;
        }
    
    public:
        Node(T value, Node<T> *next, Node<T> *prev) : value(value), next(next), prev(prev) {}
        Node(T x) : Node(x,NULL,NULL) {}
        Node() : Node(0,NULL,NULL) {}

        void setValue(T value) { this->value = value; }
        void setNext(Node<T> *next) { this->next = next; }
        void setPrev(Node<T> *prev) { this->prev = prev; }

        T getValue() const { return this->value; }
        Node<T> *getNext() const { return this->next; }
        Node<T> *getPrev() const { return this->prev; }

        string to_String()
        {
            stringstream ss;
            ss << "Valore del nodo: " << value << "successivo: " << next << "precedente: " << prev << "."<< endl;
            return ss.str();
        }

        friend ostream &operator <<(ostream &os, const Node<T> &n)
        {
            os << n.to_String() << endl;
            return os;
        }

        bool operator <(Node<T> &n)
        {
            return this->compare(n) < 0;
        }

        bool operator >(Node<T> &n)
        {
            return this->compare(n) > 0;
        }

        bool operator <=(Node<T> &n)
        {
            return this->compare(n) <= 0;
        }

        bool operator >=(Node<T> &n)
        {
            return this->compare(n) >= 0;
        }

        bool operator ==(Node<T> &n)
        {
            return this->compare(n) == 0;
        }

};
#endif