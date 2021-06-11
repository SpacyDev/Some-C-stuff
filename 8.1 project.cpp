#include <iostream>
#include <time.h>


using namespace std;

void bitonicseq(int *arr,int n,int l)
{
	setlocale(LC_ALL, "ru");
	int k = 0;
	for (int i = 0; i < n/l; i++)
	{
		if (arr[k] > arr[k + 1])
			swap(arr[k], arr[k + 1]);
		if (arr[k + 2] < arr[k + 3]) {
			swap(arr[k + 2], arr[k + 3]);
		}
		k += 4;
		
	}
	k = 0;
	for (int i = 0; i < n / l; i++)
	{
		if (arr[k] > arr[k + 2])
			swap(arr[k], arr[k + 2]);
		
		
		if (arr[k + 4] < arr[k + 6]) {
			swap(arr[k + 4], arr[k + 6]);
		}
		k++;
	}
	k = 0;
	for (int i = 0; i < n / l; i++)
	{
		if (arr[k] > arr[k + 1])
			swap(arr[k], arr[k + 1]);		
		if (arr[k + 4] < arr[k + 5]) {
			swap(arr[k + 4], arr[k + 5]);
		}
		k+=2;
	}
	
}
void bitonic_sort(int* arr, int n, int l)
{
	setlocale(LC_ALL, "ru");
	int k = 0;
	
	for (int i = 0; i < (2*n )/ l; i++)
	{
		if (arr[k] > arr[k + 4])
		{
			swap(arr[k], arr[k + 4]);
		}
		k++;
	}
	k = 0;
	for (int i = 0; i < n / l; i++)
	{
		if (arr[k] > arr[k + 2])
			swap(arr[k], arr[k + 2]);
		if (arr[k + 1] > arr[k + 3])
		{
			swap(arr[k + 1], arr[k + 3]);
		}
		k += 4;
	}
	k = 0;
	for (int i = 0; i <( 2*n/l); i++)
	{
		if (arr[k] > arr[k + 1]) {
			swap(arr[k], arr[k + 1]);
		}
		k += 2;
	}
	k = 0;
	int b = 7;
	cout << "Отсортированный динамический массив по возростанию:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n / l; i++)
	{
		swap(arr[k], arr[b]);
		k++;
		b--;
	}
	cout << "Отсортированный динамический массив по убыванию:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n=8;	
	int* arr = new int[n];
	int l =n/2;
	cout << "Динамический массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1 + rand() % 100;		
		cout << arr[i] << " ";
	}
	cout << endl;
	bitonicseq(arr, n, l);
	bitonic_sort(arr, n, l);
	system("pause");
}

	
	