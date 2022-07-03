#include<iostream>
#include<string>
using namespace std;

struct node{
	int value;
	node *nxt;
} *front, *rear;
//node *rear;

class queue
{
	private:
		node *temp=NULL;
	public:
		queue()
		{
			front = NULL;
			rear =  NULL;
		}
		void enqueue(int num)
		{
			node *node1 = new node;
			node1->nxt = NULL;
			node1->value = num;
			if(front == NULL)
			{
				front = node1;
				rear = node1;
			}
			else
			{
				rear->nxt = node1;
				rear = node1;
			}
		}
		int dequeue()
		{
			if(front == NULL)
			{
				return 0;
			}
			else
			{
				int t=front->value;
				temp = front;
				front = front->nxt;
				delete temp;
				return t;
			}
		}
		void display()
		{
			temp=front;
			while(temp!=NULL)
			{
				cout<<temp->value<<"->";
				temp = temp->nxt;
			}
			cout<<"\n";
		}
};

int main()
{
	queue q1;
	q1.enqueue(12);
	q1.enqueue(23);
	q1.enqueue(19);
	q1.enqueue(22);
	q1.enqueue(34);
	q1.display();
	cout<<"number is\t"<<q1.dequeue()<<endl;
	q1.display();
}
