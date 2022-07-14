#include<iostream>
#include<string.h>
using namespace std;
struct node_t{
	int data;
	node_t *left;
	node_t *right;
} *ROOT;

struct node_q{
	node_t *data2;
	node_q *nxt;
} *front, *rear;

class queue{
	private:
		node_q *temp_q;
	public:
		queue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(node_t *data1)
		{
			node_q *node_q1=new node_q;
			node_q1->data2 = data1;
			node_q1->nxt = NULL;
			if(front==NULL)
			{
				front = node_q1;
				rear = node_q1;
			}
			else
			{
				rear->nxt = node_q1;
				rear = rear->nxt;
			}
		}
		node_t* dequeue()
		{
			temp_q=front;
			node_t *temp = temp_q->data2;
			if(front == NULL)
			{
				cout<<"queue is empty";
				return NULL;
			}
			else if(front==rear)
			{
				front = NULL;
				rear = NULL;
			}
			else
			{
				front = temp_q->nxt;
			}
			delete temp_q;
			return temp;
		}
		
};
class tree:public queue{
	private:
		node_t *temp_t;
		node_t *temp_t1;
	public:
		tree(int value)
		{
			node_t *node_t1=new node_t;
			node_t1->data = value;
			node_t1->left = NULL;
			node_t1->right = NULL;
			ROOT = node_t1;
		}
		void set_data(int value1)
		{
			node_t *node_t2=new node_t;
			node_t2->data = value1;
			node_t2->left = NULL;
			node_t2->right = NULL;
			temp_t = ROOT;
			bool flag = true;
			while(flag == true)
			{
				if(value1<temp_t->data && temp_t->left!=NULL)
				{
					temp_t = temp_t->left;
				}	
				else if(value1>temp_t->data && temp_t->right!=NULL)
				{
					temp_t = temp_t->right;
				}
				else
				{
					flag = false;
				}
			}
			if(value1<temp_t->data)
			{
				temp_t->left = node_t2;
			}
			else if(value1>temp_t->data)
			{
				temp_t->right = node_t2;
			}
			else
			{
				cout<<"Duplicate Node";
			}
		}
		void level_traversing()
		{
			temp_t1=new node_t;
			temp_t1->data=-1;
			temp_t1->left=NULL;
			temp_t1->right=NULL;
			
			temp_t = ROOT;
			enqueue(temp_t);
			enqueue(temp_t1);
			while(front!=NULL)
			{
				temp_t = dequeue();
				
				if(temp_t->left!=NULL)
				{
					enqueue(temp_t->left);
				}
				if(temp_t->right!=NULL)
				{
					enqueue(temp_t->right);
				}
				
				if(temp_t->data==-1)
				{
					cout<<endl;
					if(front!=NULL)
						enqueue(temp_t1);
				}
				else if(temp_t->data!=-1)
				{
					cout<<temp_t->data<<"\t";
				}
			}
			
			
		}
};
int main()
{
	tree t1(50);
	t1.set_data(25);
	t1.set_data(75);
	t1.set_data(20);
	t1.set_data(40);
	t1.set_data(60);
	t1.set_data(80);
	t1.set_data(10);
	t1.set_data(30);
	t1.set_data(45);
	t1.set_data(55);
	t1.set_data(65);
	t1.set_data(85);
	t1.level_traversing();
}

