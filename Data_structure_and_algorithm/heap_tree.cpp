#include<iostream>
#include<string>
using namespace std;
int count=0;

class heapp{
	private:
		int heap[10];
		int i,n,temp,size,largest;
	public:
		heapp()
		{
			size=10;
			n=0;
			//heap[0]=value;
		}
		void insert(int value)
		{
			if(n<size)
			{
				n++;
				i=n;
				count=n;
				heap[i] = value;
				while(i>1)
				{
					if(heap[i]>heap[i/2])
					{
						temp=heap[i];
						heap[i] = heap[i/2];
						heap[i/2] = temp;
						i=i/2;
					}
					else
						return;
				}
			
			}
			else
			{
				cout<<"No more data can be inserted\n";
			}
		}
		void deletee()
		{
			i=1;
			int temp=heap[1];
			heap[1]=heap[n];
			heap[n]=temp;
			n--;
			largest = i;
			while(i<n)
			{
				if(heap[i*2]>heap[largest] && 2*i<=n)
				{
					largest=i*2;
				}
				if(heap[(i*2)+1]>heap[largest] && (2*i+1)<=n)
				{
					largest=i*2+1;
				}
				if(largest!=i)
				{
					temp=heap[i];
					heap[i]=heap[largest];
					heap[largest]=temp;
					i=largest;
				}
				else
					return;
			}
		}
		void heapsort()
		{
			for(int l=n; l>=1; l--)
			{
				deletee();
			}
			for(int s=1; s<=count; s++)
			{
				cout<<heap[s]<<"\t";
			}
		}
		
		
		void print()
		{
			cout<<"\nTotal Count: "<<n<<endl;
			for(int k=1; k<=n; k++)
			{
				cout<<heap[k]<<"\t";
			}
			cout<<endl;
		}
};
int main()
{
	heapp h1;
	h1.insert(25);
	h1.insert(18);
	h1.insert(20);
	h1.insert(7);
	h1.insert(21);
	h1.insert(3);
	h1.insert(40);
	h1.insert(16);
	h1.insert(22);
//	h1.insert(55);
//	h1.insert(65);
//	h1.insert(80);
//	h1.insert(85);
	h1.print();
	h1.deletee();
	h1.print();
	h1.heapsort();
}
