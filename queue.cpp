#include<iostream>
#define max 100
using namespace std;
class queue{
	int q[max];
	int f=0;
	int r=-1;
	public:
		bool isEmpty()
		{
			if(r<f)
				return true;
			return false;
		}
		bool isFull()
		{
			if(r==max-1)
				return true;
			return false;
		}
		void enqueue(int el)
		{
			if(!isFull())
			{
				r+=1;
				q[r]=el;
				cout<<q[r]<<" is added to queue"<<endl;
			}
			else{
				cout<<"Queue is full"<<endl;
			}
		}
		void dequeue()
		{
			if(!isEmpty())
			{
				cout<<q[f]<<" is removed from queue"<<endl;
				f+=1;
			}
			else{
				cout<<"queue is empty"<<endl;
			}
		}
		void display()
		{
			if(!isEmpty())
			{
				for(int i=f;i<=r;i++)
			{
				cout<<q[i]<<" ";
			}
			cout<<endl;
			}
			else{
				cout<<"The queue is empty"<<endl;
				
			}
		}
};
int main()
{
	queue q;
	q.display();
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(20);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
}
