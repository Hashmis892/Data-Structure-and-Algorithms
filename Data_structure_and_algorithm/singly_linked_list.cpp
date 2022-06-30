#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

struct node{
	int roll;
	string name;
	node *next;
} *start;

class link{
	private:
		int select, roll_n;
		node *temp = NULL;
		node *temp1 = NULL;
	public:
		link()
		{
			start = NULL;
		}
		void insert()
		{
			node *node1 = new node;
			cout<<"\n\nEnter the Roll Number: ";
			cin>>node1->roll;
			cout<<"Enter the Name : ";
			cin>>node1->name;
			node1->next = NULL;
			cout<<"\n\nEnter 1 for insertion at last\nEnter 2 for insertion at start\nEnter 3 for insertion at any position\nEnter 4 for insert in ascending order";
			cin>>select;
			switch(select)
			{
				case 1:
					if(start == NULL)
					{
						start = node1;
					}
					else
					{
						temp = start;
						while(temp->next != NULL)
						{
							temp = temp->next;
						}
						temp->next = node1;
					}
					break;
				case 2:
					if(start==NULL)
					{
						start = node1;
					}
					else
					{
						node1->next = start;
						start = node1;
					}
					break;
				case 3:
					if(start == NULL)
					{
						start = node1;
						break;
					}
					cout<<"\n\nEnter the Roll number after that you want to insert the new node";
					cin>>roll_n;
					temp = start;
					while(temp != NULL)
					{
						if(temp->roll == roll_n)
						{
							node1->next = temp->next;
							temp->next = node1;
							break; 
						}
						temp = temp->next;
					}
					if(temp == NULL)
					{
						cout<<"\n\nRoll number you entered is not exist in list\n";
						break;
					}
					break;
				case 4:
					if(start==NULL)
					{
						start = node1;
					}
					else if(node1->roll <= start->roll)
					{
						node1->next = start;
						start = node1;
					}
					else
					{
						temp = start;
						while(1)
						{
							if(temp == NULL)
							{
								temp1->next = node1;
								break;
							}
							else if(temp->roll<=node1->roll)
							{
								temp1 = temp;
								temp = temp->next;	
							}
							else
							{
								node1->next = temp;
								temp1->next = node1;
								break;
							}
						}
					}
					break;
			}
		}
		void print()
		{
			temp = start;
			while(temp != NULL)
			{
				cout<<"Name\t"<<temp->name<<"\tRoll Number\t"<<temp->roll<<endl;
				temp= temp->next;
			}
		}
		void delete_ID()
		{
			cout<<"\nEnter the Roll number which you want to delete:\t";
			cin>>roll_n;
			if(start == NULL)
			{
				cout<<"\nThere is no element to delete\n";
			}
			else
			{
				temp=start;
				while(temp != NULL)
				{
					if(temp == start && temp->roll == roll_n)
					{
						if(temp->next == NULL)
						{
							delete temp;
							start = NULL;
						}
						else
						{
							start = temp->next;
							delete temp;
						}
						break;
					}
					else if(temp->roll == roll_n && temp->next == NULL)
					{
						temp1->next = NULL;
						delete temp;
						break;
					}
					else if(temp->roll == roll_n && temp->next!=NULL)
					{
						temp1->next = temp->next;
						delete temp;
						break;
					}
					temp1=temp;
					temp=temp->next;
				}
				
			}
		}
};
int main()
{
	link l1;
	l1.insert();
	l1.insert();
	l1.insert();
	l1.insert();
	l1.insert();
	l1.print();
	l1.delete_ID();
	l1.print();
	l1.delete_ID();
	l1.print();
	l1.delete_ID();
	l1.print();
	
}
