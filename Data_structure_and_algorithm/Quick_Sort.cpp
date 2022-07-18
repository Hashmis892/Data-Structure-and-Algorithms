#include<iostream>
using namespace std;

int partition(int a[], int lb, int ub)
{
	int low=lb;
	int high=ub;
	int key=a[lb];
	int temp;
	while(low<high)
	{
		while(a[low]<=key)
		{
			low++;
		}
		while(a[high]>key)
		{
			high--;
		}
		if(high>=low)
		{
			temp=a[low];
			a[low]=a[high];
			a[high]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[high];
	a[high]=temp;
	return high;
}

void quicksort(int a[], int lb, int ub)
{
	if(lb<ub)
	{
		int temp=partition(a, lb, ub);
		quicksort(a, lb, temp);
		quicksort(a, temp+1, ub);
	}
}

int main()
{
	int a[]={9, 4, 8, 7, 2, 1, 3};
	for(int i=0; i<7; i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\n";
	int lb=0;
	int ub=6;
	quicksort(a, lb, ub);
	for(int i=0; i<7; i++)
	{
		cout<<a[i]<<"\t";
	}
}
