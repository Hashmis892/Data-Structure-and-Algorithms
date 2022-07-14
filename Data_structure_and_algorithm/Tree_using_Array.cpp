#include<iostream>
#include<string.h>
using namespace std;
char tree[10];

int root(char key)
{
	if(tree[0] != '\0')
	{
		cout<<"root is already present\n";
	}
	else
	{
		tree[0]=key;
		return 0;
	}
}

int set_left(char key, int parent)
{
	if(tree[parent] == '\0')
	{
		cout<<"Parent is not present\n";
	}
	else
	{
		tree[(parent*2)+1] = key;
	}
	return 0;
}

int set_right(char key, int parent)
{
	if(tree[parent] == '\0')
	{
		cout<<"parent is not present\n";
	}
	else
	{
		tree[(parent*2)+2] = key;
	}
	return 0;
}

int print_tree(char tree[])
{
	for(int i=0; i<=10; i++)
	{
		if(tree[i] == '\0')
		{
			cout<<"-\t";
		}
		else
		{
			cout<<tree[i]<<"\t";
		}
	}
}

int main()
{
	root('A');
	set_left('B', 0);
	set_right('C', 0);
	set_left('D', 2);
	set_left('E', 3);
	set_right('F', 5);
	print_tree(tree);
}
