#include<iostream>
using namespace std;
int count=0;
struct node{
	int info;
	int weight;
	node *nxt;
};
node *vertice[6];

class graph{
	private:
		int k,j;
		node *temp;
	public:
		void insert()
		{
			
			if(count<=6)
			{
				count++;
				j=1;
				cout<<"Enter the value of vertice\t";
				cin>>k;
				while(j==1)
				{
					node *node1=new node;
					cout<<"Enter the adjecent vertice of "<<k<<"  \t";
					cin>>node1->info;
					cout<<"Enter the weight of node between "<<k<<"\t "<<node1->info<<"\t";
					cin>>node1->weight;
					node1->nxt=NULL;
					
					if(vertice[count] == NULL)
					{
						vertice[count]=node1;
					}
					else
					{
						temp=vertice[count];
						cout<<"count  "<<count;
						while(temp->nxt!=NULL)
						{
							temp=temp->nxt;
						}
						temp->nxt = node1;
					}
					cout<<"if any other adjecent node exist enter 1 otherwise enter 0 or any other number\t";
					cin>>j;
				}
				
			}
			else
			{
				cout<<"You entered the extra data from size\n";
			}
		}
		void print()
		{
			for(int i=1; i<=count; i++)
			{
				temp=vertice[i];
				cout<<i<<"--->";
				while(temp != NULL)
				{
					cout<<temp->info;
					temp=temp->nxt;
					cout<<"\t";
				}
				cout<<endl;
			}
		}
};

int main()
{
	graph g1;
	g1.insert();
	g1.insert();
	g1.insert();
	g1.insert();
	g1.insert();
	g1.insert();
	g1.insert();
	g1.insert();
	g1.print();
}
