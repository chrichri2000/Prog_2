#include "Node.h"
#include "List.h"

int main()
{
    List<int> l;
    l.Ins_Tail(1);
    l.Ins_Tail(3);
    l.Ins_Tail(7);
    l.Canc(7);
    cout << l << endl;
}