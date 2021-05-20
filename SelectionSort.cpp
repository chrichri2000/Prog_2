#include <iostream>
#include <fstream>
using namespace std;

void rec_SelectionSort(int *v, int n);
void SelectionSort(int *v, int n);
void swap(int *v,int i, int j);
int min(int *v,int n);

int main() 
{ 
	int v[10] = {1,2,5,8,4,2,5,7,2,5};
	SelectionSort(v,10);
	for(int i=0;i<10;i++) cout << v[i] << " ";
}

void rec_SelectionSort(int *v, int n)
{
	if(n <= 1) return;
	swap(v,min(v,n),0);
	rec_SelectionSort(v+1,n-1);
}

void SelectionSort(int *V,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(V[min] > V[j]) min = j;
		}
		swap(V,min,i);
	}
}

void swap(int *v,int i, int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int min(int *v,int n) // Algoritmo Di Ordinamento NON STABILE
{
	int min = 0;
	for(int i=1;i<n;i++) if(v[i] < v[min]) min = i;
	return min;
}

int min(int *v,int n) // Algoritmo Di Ordinamento STABILE
{
	int min = 0;
	for(int i=1;i<n;i++) if(v[i] <= v[min]) min = i;
	return min;
}
