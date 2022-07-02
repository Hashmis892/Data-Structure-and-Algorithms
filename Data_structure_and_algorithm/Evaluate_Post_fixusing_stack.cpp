#include<iostream>
#include<math.h>
#include<string>
using namespace std;

struct node{
	int value;
	node *nxt;
} *top;

class stack{
	private:
		node *temp = NULL;
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
		if (top==NULL)
		{
			cout<<"pushing value num"<<num<<endl;
			top=node1;
		}	
		else
		{
			cout<<"pushing value num"<<num<<endl;
			node1->nxt=top;
			top=node1;
		}	
	}
	int pop()
	{
		if(top==NULL)
		{
			return 0;
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
};

class eval_post_fix:public stack{
	
public:
	int eval(string str)
	{
		//cout<<"in eval\n";
		int size=str.size();
		for(int i=0; i<size; i++)
		{
			int j=IsOperator(str[i]);
			if(j == 1)
			{
				int num2 = pop();
				cout<<"num2   "<<num2<<endl;
				int num1 = pop();
				cout<<"num1   "<<num1<<endl;
				int res = evaluate(num1, num2, str[i]);
				cout<<"res    "<<res<<endl;
				push(res);
			}
			else if(j==-1)
			{
				push(str[i]-'0');
			}
		}
		return (top->value);
	}
	int IsOperator(char ch)
	{
		if(ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/')
		{
			cout<<"in If"<<endl;
			return 1;
		}
		cout<<"with out If"<<endl;
		return -1;
	}
	int evaluate(int a, int b, char op)
	{
		switch(op)
		{
			case '+':
				cout<<"addition\n";
				return a+b;
			case '-':
				cout<<"subtraction\n";
				return a-b;
			case '/':
				cout<<"division\n";
				return a/b;
			case '*':
				cout<<"multiplication\n";
				return a*b;
			case '^':
				cout<<"power\n";
				return pow(a,b);
		}
	}
	
};


int main()
{
	eval_post_fix p1;
	string postfix="623+-382/+*2^3+";
	int result = p1.eval(postfix);
	cout<<"Result = "<<result;
	
}

