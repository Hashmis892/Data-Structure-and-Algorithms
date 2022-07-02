#include<iostream>
#include<string.h>
using namespace std;

struct node{
	int value;
	node *nxt;
} *top;

class stack{
	private:
		node *temp; 
	public:
		stack()
		{
			top = NULL;
		}
		void push(int num)
		{
			node *node1 = new node;
			node1->value = num;
			node1->nxt = NULL;
			if(top == NULL)
			{
				top = node1;
			}
			else
			{
				node1->nxt = top;
				top = node1; 
			}
		}
		int pop()
		{
			if(top == NULL)
			{
				cout<<"Stack is Empty\n\n";
			}
			else
			{
				int t=top->value;
				temp = top;
				top = temp->nxt;
				delete temp;
				return t;
			}
		} 
		void display()
		{
			temp = top;
			while(temp!=NULL)
			{
				cout<<temp->value<<"->";
				temp = temp->nxt;
			}
		}
};

int main()
{
	int i;
	stack s1;
	s1.pop();
	s1.push(12);
	s1.push(32);
	s1.push(23);
	s1.push(22);
	i=s1.pop();
	cout<<"\n"<<i<<"\n\n";
	s1.display();
}
