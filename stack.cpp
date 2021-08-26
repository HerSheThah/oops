#include<iostream>
using namespace std;
#define max 100
class stack{
	int arr[max];
	int top=-1;
	public:
		bool isEmpty(){
			if(top==-1)
				return true;
			return false;
		}
		
		bool isFull()
		{
			if(top==max-1)
				return true;
			return false;
		}
		void push(int no)
		{
			if(! isFull())
			{
			top+=1;
			arr[top]=no;
			cout<<arr[top]<<" is inserted"<<endl;
			}
			else{
				cout<<"Stack is full"<<endl;
			}
		}
		void pop()
		{
			if(!isEmpty())
			{
				cout<<arr[top]<<" is poped out"<<endl;
				top-=1;
			}
			else{
				cout<<"Stack is empty"<<endl;
			}
		}
		void display()
		{
			if(isEmpty())
				cout<<"Stack is empty"<<endl;
			else{
				for(int i=0; i<=top;i++)
				{
					cout<<arr[i]<<" ";	
				}
				cout<<endl;	
			}
		}
};
int main()
{
	stack s;
	s.display();
	s.push(2);
	s.push(3);
	s.push(5);
	s.pop();
	s.pop();
	s.pop();
	s.display();
}
