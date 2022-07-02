#include<iostream>
#include<string.h>
using namespace std;

class stack{
	private:
		int top,size;
		int arr[3];
	public:
		stack()
		{
			size=2;
			top = -1;
		}
		void push(int num)
		{
			if(top == size)
			{
				cout<<"stack overflow\n";
			}
			else
			{
				top++;
				arr[top]=num;
			}
		}
		int pop()
		{
			if(top==-1)
			{
				cout<<"stack is Empty\n";
				return 0;
			}
			else
			{
				int t;
				t = arr[top];
				top--;
				return t;
			}
		}
		void display()
		{
			for(int i=0; i<=top; i++)
			{
				cout<<arr[i]<<endl;
			}
		}
};

int main()
{
	int i;
	stack s1;
	i=s1.pop();
	cout<<i<<"\n\n";
	s1.push(10);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	i=s1.pop();
	cout<<i<<endl;
	i=s1.pop();
	cout<<i<<endl;
	cout<<"\n";
	s1.display();
}
