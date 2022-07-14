#include<iostream>
#include<string.h>
using namespace std;

void sort(int arr[])
{
	int loc,temp;	
	for(int j=0; j<9; j++)
	{
		loc = j;
		for(int i=j+1; i<=9; i++)
		{
			if(arr[i]<arr[loc])
			{
				loc = i;
			}
		}
		temp = arr[loc];
		arr[loc] = arr[j];
		arr[j] = temp;
	}
}
void print(int arr[])
{
	for(int i=0; i<=9; i++)
	{
		cout<<arr[i]<<"\t";
	}
}


int main()
{
	int arr[]={12, 23, 8, 9, 2, 5, 6, 34, 27, 11};
	print(arr);
	cout<<"\n";
	sort(arr);
	print(arr);
}
