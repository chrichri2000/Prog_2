#include "Node.h"
#include "List.h"
int main()
{
    Nodo<int> n0(3);
    Nodo<int> n1(4);

    List<int> l;
    l.Ins(&n0);
    l.Ins(&n1);
    l.Ins(6);
    l.Ins(7);
    l.stampa();
}