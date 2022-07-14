#include<iostream>
#include<string.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
} *ROOT;

class BST{
	private:
		node *temp;
		node *temp1;
		node *temp2;
		int key3;
	public:
		BST(int data1)
		{
			node *node1 = new node;
			node1->data = data1;
			node1->left = NULL;
			node1->right = NULL; 
			ROOT = node1;
		}
		void set_data(int data2)
		{
			bool flag = true;
			node *node1 = new node;
			node1->data = data2;
			node1->left = NULL;
			node1->right = NULL;
			temp = ROOT;
			while(flag == true)	
			{
				if(data2<temp->data && temp->left != NULL)
				{
					temp = temp->left;
				}
				else if(data2>temp->data && temp->right !=NULL)
				{
					temp = temp->right;
				}
				else
				{
					flag = false;
				}
			}
			if(data2>temp->data)
			{
				temp->right = node1;
			}	
			else if(data2<temp->data)
			{
				temp->left = node1;
			}
			else
			{
				cout<<"Duplicate Node\n";
			}
		}
		void preorder(node *root1)
		{
			if(root1 != NULL)
			{
				cout<<root1->data<<"\t";
				preorder(root1->left);
				preorder(root1->right);
			}
			
		}
		void inorder(node *root1)
		{
			if(root1 != NULL)
			{
				inorder(root1->left);
				cout<<root1->data<<"\t";
				inorder(root1->right);
			}
			
		}
		void postorder(node *root1)
		{
			if(root1 != NULL)
			{
				postorder(root1->left);
				postorder(root1->right);
				cout<<root1->data<<"\t";
			}
		}
		node* search(int key)
		{
			temp = ROOT;
			while(temp != NULL)
			{
				if(temp->data == key)
				{
					cout<<"\nData is present";
					return temp;
				}
				else if(key<temp->data)
				{
					temp = temp->left;
				}
				else if(key>temp->data)
				{
					temp = temp->right;
				}
			}
			cout<<"\nData not present";
			return NULL;
		}
		void deletee(int key1)
		{
			temp = ROOT;
			while(temp != NULL)
			{
				if(temp->data == key1)
				{
					if(temp->left==NULL && temp->right==NULL)
					{
						if(temp1->left==temp)
						{
							temp1->left = NULL;
						}
						else
						{
							temp1->right = NULL;
						}
						delete temp;
						return;
					}
					else if(temp->left == NULL && temp->right != NULL)
					{
						temp2=temp;
						temp1=temp;
						temp = temp->right;
						while(temp->left!=NULL)
						{
							temp1=temp;
							temp=temp->left;
						}
						key3 = temp->data;
						temp->data=temp1->data;
						temp1->data=key3;	
					}
					else if((temp->left != NULL && temp->right == NULL) ||(temp->left != NULL && temp->right != NULL) )
					{
						temp2=temp;
						temp1=temp;
						temp = temp->left;
						while(temp->right!=NULL)
						{
							temp1=temp;
							temp=temp->right;
						}
						key3 = temp->data;
						temp->data=temp1->data;
						temp1->data=key3;
					}
				}
				else if(key1>temp->data)
				{
					temp1=temp;
					temp=temp->right;
				}
				else if(key1<temp->data)
				{
					temp1=temp;
					temp=temp->left;
				}
			}
			cout<<"\nData not found";
			return;	
		}
};

int main()
{
	BST t1(50);
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
	t1.preorder(ROOT);
	cout<<"\n";
	t1.inorder(ROOT);
	cout<<"\n";
	t1.postorder(ROOT);
	t1.search(40);
	t1.search(95);
	t1.deletee(60);
	cout<<"\n";
	t1.preorder(ROOT);
}
