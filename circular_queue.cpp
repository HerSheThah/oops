#include<iostream>
#define max 5
using namespace std;
class queue{
	int q[max];
	int f=-1;
	int r=-1;
	public:
		bool isEmpty()
		{
			if(f==-1)
				return true;
			return false;
		}
		bool isFull()
		{
			if((f==0&&r==max-1)||(r+1==f))
				return true;
			return false;
		}
		void enqueue(int el)
		{
			if(!isFull())
			{
				if(f==-1)
					f=0;
				r=(r+1)%max;
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
				f=(f+1)%max;
			}
			else{
				cout<<"queue is empty"<<endl;
			}
		}
		void display()
		{
			if(!isEmpty())
			{
				for(int i=f;i!=r;i=(i+1)%max)
			{
				cout<<q[i]<<" ";
			}
			cout<<q[r]<<endl;
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
	q.enqueue(25);	
	q.enqueue(32);
	q.enqueue(4);
	q.enqueue(52);
	q.enqueue(12);	
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
}
