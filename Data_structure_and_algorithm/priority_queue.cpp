#include<iostream>
#include<string>
using namespace std;

struct node{
	int value;
	int priority;
	node *nxt;
} *front, *rear;

class queue{
	private:
		node *temp, *temp1;
	public:
		queue()
		{
			front = NULL;
		}
		void enqueue(int value_1, int priority_1)
		{
			node *node1 = new node;
			node1->value = value_1;
			node1->priority = priority_1;
			node1->nxt = NULL;
			if(front==NULL)
			{
				front = node1;
				rear = node1;
			}
			else
			{
				if(front->priority>=node1->priority)
				{
					node1->nxt = front;
					front = node1;
					
				}
				else if(node1->priority>=rear->priority)
				{
					rear->nxt=node1;
					rear = rear->nxt;
				}
				else
				{
					temp = front;
					while(temp!=NULL)
					{
						if(temp->priority<=node1->priority)
						{
							temp1=temp;
							temp=temp->nxt;
						}
						else
						{
							temp1->nxt = node1;
							node1->nxt = temp;
							break;
						}
					}
				}
				
			}
		}
		int dequeue()
		{
			if(front==NULL)
			{
				cout<<"Queue is Empty\n";
				return 0;
			}
			else
			{
				temp = front;
				int t = temp->value;
				if(front->nxt==NULL)
				{
					front = NULL;
					rear = NULL;
				}
				else
				{
					front=front->nxt;
				}
				delete temp;
				return t;
			}
		}
		void print()
		{
			temp=front;
			while(temp!=NULL)
			{
				cout<<"value\t"<<temp->value<<"\tPriority\t"<<temp->priority<<endl;
				temp=temp->nxt;
			}
		}
}; 

int main()
{
	queue q1;
	q1.dequeue();
	q1.enqueue(12,3);
	q1.enqueue(32,1);
	q1.enqueue(23,1);
	q1.enqueue(43,5);
	q1.enqueue(87,2);
	q1.print();
	cout<<"value"<<q1.dequeue()<<endl;
	q1.print();
	cout<<"value"<<q1.dequeue()<<endl;
	q1.print();
}
