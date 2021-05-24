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

        void set_dim(int dim)
        {
            this->dim = dim;
        }

        int get_dim()
        {
            return dim;
        }

        void ins(int x)
        {
            if(n == dim)
            {
                dim*=2;
                int *new_arr = new int[dim];
                for(int i=0;i<n;i++) new_arr[i] = arr[i];
                int *to_delete = arr;
                delete [] to_delete;
                return;
            }
            arr[n++] = x;
        }

        void canc(int i)
        {
            if(n < 0) return;
            if(i == n)
            {
                n--;
                return;
            }
            arr[i] = arr[n-1];
            arr[n-1] = 0;
            n--;
        }

        void print()
        {
            cout << "Funziona" << endl;
            for(int i=0;i<n;i++) cout << arr[i] << " ";
        }
};

int main()
{
    int n = 10;
    ArrayDinamico a(n);
    for(int i=0;i<n;i++) a.ins(i);
    a.print();
    a.canc(10);
    a.print();
}
