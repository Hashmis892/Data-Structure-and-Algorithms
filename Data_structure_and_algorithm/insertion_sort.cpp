#include<iostream>
#include<string.h>
using namespace std;

void sort(int arr[], int size)
{
	for(int i=1; i<size; i++)
	{
		int j = i-1;
		int swap = arr[i];
		while(arr[j] > swap  && j>=0)
		{
			//swap = arr[i];
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = swap;
	}
}

void print(int arr[], int size)
{
	for(int k=0; k<size; k++)
	{
		cout<<arr[k]<<"\t";
	}
	cout<<"\n";
}

int main()
{
	int arr[] = {23, 98, 12, 2, 1, 43, 99, 24, 9};
	int size = 9;
	print(arr, size);
	sort(arr, size);
	print(arr, size);
}
