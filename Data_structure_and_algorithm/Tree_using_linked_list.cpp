#include<iostream>
#include<string>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
} *ROOT;

class tree{
	private:
		node* temp;
		node* temp1;
	public:
		tree(int key)
		{
			node* node1 = new node;
			ROOT = node1;
			node1->data = key;
			node1->left = NULL;
			node1->right = NULL;
		}
		int set_left(int key)
		{
			node* node2 = new node;
			node2->data = key;
			node2->left = NULL;
			node2->right = NULL;
			ROOT->left = node2;
			return 0;
		}
		int set_right(int key)
		{
			node* node3 = new node;
			node3->data = key;
			node3->left = NULL;
			node3->right = NULL;
			ROOT->right = node3;
//			cout<<"root set right";
			return 0;
		}
		
		void print(node* root1)
		{
			if(ROOT == NULL)
			{
				cout<<"\nNo Data exist";
			}
			else if(root1 != NULL)
			{
				cout<<root1->data<<"\t";
				print(root1->left);
				print(root1->right);
			}
		}
};



int main()
{
	tree t1(1);
	t1.set_left(2);
	t1.set_right(3);
//	t1.set_left(4, 2);
//	t1.set_right(5, 2);
//	t1.set_left(6, 3);
//	t1.set_right(7, 3);
	t1.print(ROOT);
}
