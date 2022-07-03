#include<iostream>
#include<string>
using namespace std;

class queue{
	private:
		int	arr[4];
		int element;
		int front;
		int rear;
		int size;
	public:
		queue(){
			size = 4;
			front = -1;
			rear = -1;
			element = 0;
		}
		void enqueue(int num)
		{
			if(element>=size)
			{
				cout<<"Queue is Full\n";
			}
			else
			{
				if(front==-1)
					front=0;
				rear = (rear+1)%size;
				arr[rear] = num;
				element++;
			}
		}
		int dequeue()
		{
			if(element==0)
			{
				cout<<"Queue is empty\n";
				return 0;
			}
			else
			{
				int temp = arr[front];
				front = (front+1)%size;
				element--;
				return temp;
			}
		}
		void display()
		{
			int i=front;
			while(i!=rear)
			{
				cout<<arr[i]<<"->";
				i=(i+1)%size;
			}
			cout<<arr[i]<<endl;
		}
};

int main()
{
	queue q1;
	q1.dequeue();
	q1.enqueue(23);
	q1.enqueue(12);
	q1.enqueue(79);
	q1.enqueue(89);
	q1.enqueue(21);
	q1.display();
	cout<<"element is\t"<<q1.dequeue()<<endl;
	q1.display();
	cout<<"element is\t"<<q1.dequeue()<<endl;
	q1.display();
	
}

