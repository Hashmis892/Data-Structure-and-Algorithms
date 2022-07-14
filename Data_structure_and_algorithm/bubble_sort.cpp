#include<iostream>
#include<string>
using namespace std;

void sort(int arr[], int size)
{
	int swap;

	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = swap;
			}
		}
	}
}
void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}

int main()
{
	int arr[]={8, 7, 6, 43, 77, 23, 5, 4, 3, 2, 1};
	int size = 11;
	print(arr, size);
	sort(arr, size);
	print(arr, size);
}
