#include<iostream>
#include<string.h>
using namespace std;

int ver_arr[6][6];

void add_edge(int i, int j)
{
	int value;
	cout<<"Enter the weight of vertice "<<i<<"\t"<<j<<"\t";
	cin>>value;
	cout<<"\n";
	ver_arr[i][j]=value;
	ver_arr[j][i]=value;
}

void print()
{
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=5; j++)
		{
			cout<<ver_arr[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	add_edge(1, 2);
	add_edge(1, 5);
	add_edge(1, 4);
	add_edge(2, 3);
	add_edge(3, 4);
	add_edge(3, 5);
	add_edge(4, 5);
	print();
}
