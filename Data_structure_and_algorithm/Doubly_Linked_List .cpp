#include<iostream>
#include<string>
using namespace std;

struct node{
	int roll;
	string name;
	node *nxt;
	node *prv;
} *start;

class link
{
	private:
		int roll_n;
		int select;
		node *present;
		node *previous;
	public:
		link()
		{
			start = NULL;
		}
		void search()
		{
			cout<<"Enter the Roll Number which you want to search:\t ";
			cin>>roll_n;
			present = start;
			while(present != NULL)
			{
				if(present->roll == roll_n)
				{
					cout<<"\nThe Roll Number:\t"<<present->roll<<" which you entered is exist and its Name is:\t"<<present->name<<"\n\n";
					//return present;
					break;
				}
				present = present->nxt;
			}
			if(present == NULL)
			{
				cout<<"\nYour Roll Number does not exist\n";
			}
			//return present;
		}
		void insert()
		{
			node *new_node = new node;
			cout<<"\nEnter the Roll Number:\t";
			cin>>new_node->roll;
			cout<<"Enter the Name:\t";
			cin>>new_node->name;
			new_node->nxt = NULL;
			new_node->prv = NULL;
			
			if(start == NULL)
			{
				cout<<"\nThe list was empty so we add the element at the start\n";
				start = new_node;
			}
			
			else
			{
				cout<<"\nEnter 1 to add at the end\nEnter 2 to add at the start\nEnter 3 to add at any position in the lit\nEnter 4 to add in ascending order\n\n";
				cin>>select;
				switch(select)
				{
					case 1:
						present = start;
						while(present->nxt != NULL)
						{
							present = present->nxt;
						}
						present->nxt = new_node;
						new_node->prv = present;
						break;
					case 2:
						start->prv = new_node;
						new_node->nxt = start;
						start = new_node;
						break;
					case 3:
						cout<<"\nEnter the Roll Number after that you want to enter the new node:\t";
						cin>>roll_n;
						present = start;
						if(present == NULL)
						{
							cout<<"your list is empty\n";
							break;
						}
						else if(present->nxt == NULL)
						{
							present->nxt = new_node;
							new_node->prv = present;
						} 
						else
						{
							while(present != NULL)
							{
								if(present->roll == roll_n)
								{
									new_node->nxt = present->nxt;
									present->nxt->prv = new_node;
									new_node->prv = present;
									present->nxt = new_node;
									break;
								}
								present = present->nxt;
							}
							if(present == NULL)
							{
								cout<<"Roll Number you entered is not exist\n";
							}
							
						}
						break;
					case 4:
						if(start->roll >= new_node->roll)
						{
							start->prv = new_node;
							new_node->nxt = start;
							start = new_node;
							break;
						}
						else
						{
							present = start;
							while(1)
							{
								if(present->nxt == NULL)
								{
									present->nxt = new_node;
									new_node->prv = present;
									break;
								}
								else if(present->roll<=new_node->roll)
								{
									present = present->nxt;
								}
								else
								{
									present=present->prv;
									new_node->nxt = present->nxt;
									present->nxt->prv = new_node;
									new_node->prv = present;
									present->nxt = new_node;
									break;
								}
							}
						}
						break;
				}
			}
		}
		void print()
		{
			if(start == NULL)
			{
				cout<<"\nyour list is empty\n";
			}
			else
			{
				present = start;
				while(present != NULL)
				{
					cout<<"The Name is:\t"<<present->name<<"\tits Roll Number:\t"<<present->roll<<endl;
					present = present->nxt;
				}
//				cout<<"\n\n";
//				while(present->prv != NULL)
//				{
//					cout<<"The Name is:\t"<<present->name<<"\tits Roll Number:\t"<<present->roll<<"\n";
//					present = present->prv;
//				}
			}
			
		}
		void del()
		{
			if(start == NULL)
			{
				cout<<"Your list is empty\n";
			}
			else
			{
				cout<<"Enter the Roll Number which you want to delete:\t";
				cin>>roll_n;
				present = start;
				while(present != NULL)
				{
					if(present->roll == roll_n)
					{
						if(present==start && present->nxt==NULL)
						{
							start==NULL;
							delete present;
						}
						else if(present==start && present->nxt != NULL)
						{
							start = present->nxt;
							present->nxt->prv = NULL;
							delete present;
						}
						else if (present!=start && present->nxt==NULL)
						{
							present->prv->nxt = NULL;
							delete present;
						}
						else if(present!=start && present->nxt!=NULL)
						{
							present->prv->nxt = present->nxt;
							present->nxt->prv = present->prv;
							delete present;
						}
						break;
					}
					present = present->nxt;
				}
				if(present==NULL)
				{
					cout<<"\nYou entered the wrong Roll Number\n";
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
	l1.search();
	l1.print();
	l1.del();
	l1.print();
	l1.del();
	l1.print();
}

