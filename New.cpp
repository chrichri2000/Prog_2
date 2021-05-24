#include <iostream>
using namespace std;

class ArrayDinamico
{
    private:
        int dim,n;
        int *arr;

    public:
        ArrayDinamico(int dim)
        {
            this->dim = dim;
            n = 0;
            arr = new int[dim];
        }

        void print()
        {
            cout << "Funziona" << endl;
            for(int i=0;i<n;i++) cout << arr[i] << " ";
        }
};

int main()
{
    ArrayDinamico a(10);
    a.print();
}
