#include<iostream>
using namespace std;
struct node{
		int val;
		struct node *next;
};
class singly{
	int n;
	struct node *head;
	public:
		singly()
		{
			head=NULL;
			n=0;
		}
		
		void insertBeg(int value)
		{
			struct node *temp;
			temp=new node;
			temp->val=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				n++;
				cout<<temp->val<<" is inserted"<<endl;
				return;
			}
			temp->next=head;
			head=temp;
			n++;
			cout<<head->val<<" is inserted"<<endl;
			
		}
		
		void insertEnd(int value){
			struct node *temp, *cur;
			temp=new node;
			temp->val=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				n++;
				return;				
			}

			for(cur=head;cur->next!=NULL;cur=cur->next);
			cur->next=temp;
			cout<<temp->val<<" is inserted"<<endl;
			n++;
		}
		void insertPos(int pos, int value)
		{

			if(pos==1)
			{
				insertBeg(value);
				return;
			}
			if(pos==n+1)
			{
				insertEnd(value);
				return;
			}
			if(pos<1 || pos>n+1)
			{
				cout<<"Invalid Position"<<endl;
				return;
			}
			struct node *temp, *cur;
			temp=new node;
			temp->val=value;
			temp->next=NULL;
			int i;
			for(cur=head,i=1; i<pos-1; i++,cur=cur->next);
			temp->next=cur->next;
			cur->next=temp;
			cout<<temp->val<<" is inserted in the position "<<pos<<endl;
			n++;
		}
		void delBeg()
		{
			if(head==NULL)
			{
				cout<<"The list is empty"<<endl;
				return;
			}
			cout<<head->val<<" is deleted"<<endl;
			head=head->next;
			
			n--;
			display();
		}
		void delEnd()
		{
			struct node *cur, *prev;
			if(head==NULL)
			{
				cout<<"The list is empty"<<endl;
				return;
			}
			for(prev=head, cur=head;cur->next!=NULL;prev=cur, cur=cur->next);
			if(prev==cur)
			{
				head=NULL;
				delete prev, cur;
				n--;
				return;
			}
			prev->next=NULL;
			cout<<cur->val<<" is deleted"<<endl;
			delete cur;
			n--;
			display();
		}
		void delPos(int pos)
		{
			struct node *cur, *prev;
			int i;
			if(pos<1||pos>n+1)
			{
				cout<<"Invalid position";
				return;
			}
			if(pos==1)
			{
				delBeg();
				return;
			}
			if(pos==n+1)
			{
				delEnd();
				return;
			}
			for(cur=head, prev=head, i=1;i<pos;i++,prev=cur,cur=cur->next);
			prev->next=cur->next;
			cout<<cur->val<<" at position "<<pos<<" is deleted"<<endl;
			delete cur;
			display();
			n--;
		}
		
		void delElement(int el)
		{
			
			if(head==NULL){
				cout<<"List is empty"<<endl;
				return;
			}
			if(head->val==el)
			{
				cout<<head->val<<" is deleted"<<endl;
				head=head->next;
				n--;
				display();
				return;
			}
			struct node *cur, *prev;
			for(cur=head, prev=head;cur->val!=el&&cur!=NULL;prev=cur, cur=cur->next);
			if(cur==NULL)
			{
				cout<<el<<" not found";
				display();
				return;
			}
			prev->next=cur->next;
			cout<<el<<" is deleted";
			delete cur;
			n--;
			display();
		}
		void display()
		{
			struct node *temp;
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				cout<<temp->val<<"-->";
			}
			cout<<endl;
		}
};
int main()
{
	singly s;
	cout<<"---------------INSERT BEGIN---------------"<<endl;
	s.insertBeg(4);
	s.insertBeg(6);
	s.insertBeg(3);
	s.insertBeg(5);
	cout<<"---------------INSERT END---------------"<<endl;
	s.insertEnd(20);
	cout<<"---------------INSERT POS---------------"<<endl;	
	s.insertPos(2, 30);
	s.display();
	cout<<"---------------DELETE BEGIN---------------"<<endl;
	s.delBeg();
	s.delBeg();
	cout<<"---------------DELETE END---------------"<<endl;
	s.delEnd();
	cout<<"---------------DELETE POS---------------"<<endl;
	s.delPos(2);
	cout<<"---------------DELETE ELEMENT---------------"<<endl;
	s.delElement(10);
	s.delElement(1);
}
