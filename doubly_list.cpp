#include<iostream>
using namespace std;
struct node{
		int val;
		struct node *next, *prev;
};
class doubly{
	int n;
	struct node *head;
	public:
		doubly()
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
			temp->prev=NULL;
			if(head==NULL)
			{
				head=temp;
				n++;
				cout<<head->val<<" is inserted"<<endl;
				return;
			}
			temp->next=head;
			head->prev=temp;
			head=temp;
			n++;
			cout<<head->val<<" is inserted"<<endl;
		}
		void insertEnd(int value){
			struct node *temp, *cur;
			temp=new node;
			temp->val=value;

			temp->next=NULL;
			temp->prev=NULL;
					
			if(head==NULL)
			{
				head=temp;
				n++;
				return;				
			}

			for(cur=head;cur->next!=NULL;cur=cur->next);
			cur->next=temp;
			temp->prev=cur;
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
			temp->prev=NULL;
			int i;
			for(cur=head,i=1; i<pos-1; i++,cur=cur->next);
			temp->next=cur->next;
			cur->next->prev=temp;
			temp->prev=cur;
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
			if(head!=NULL)
				head->prev=NULL;
			n--;
			display();
		}
		void delEnd()
		{
			struct node *cur, *p;
			if(head==NULL)
			{
				cout<<"The list is empty"<<endl;
				return;
			}
			for(p=head, cur=head;cur->next!=NULL;p=cur, cur=cur->next);
			if(p==cur)
			{
				head=NULL;
				delete p, cur;
				n--;
				return;
			}
			p->next=NULL;
			cout<<cur->val<<" is deleted"<<endl;
			delete cur;
			n--;
			display();
		}
		void delPos(int pos)
		{
			struct node *c, *p;
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
			for(c=head, p=head, i=1;i<pos;i++,p=c,c=c->next);
			p->next=c->next;
			c->next->prev=p;
			cout<<c->val<<" at position "<<pos<<" is deleted"<<endl;
			delete c;
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
		void reverse()
		{
			struct node *temp, *rev;
			for(temp=head;temp->next!=NULL;temp=temp->next);
			for(rev=temp;rev!=NULL;rev=rev->prev){
				cout<<rev->val<<"-->";
			}
			cout<<endl;
		}
};
int main()
{
	doubly d;
	cout<<"---------------INSERT BEGIN---------------"<<endl;
	d.insertBeg(4);
	d.insertBeg(6);
	d.insertBeg(3);
	d.insertBeg(5);
	cout<<"---------------INSERT END---------------"<<endl;
	d.insertEnd(20);
	d.display();
	cout<<"---------------INSERT POS---------------"<<endl;	
	d.insertPos(2, 30);
	d.display();
	cout<<"---------------DELETE BEGIN---------------"<<endl;
	d.delBeg();
	d.delBeg();
	cout<<"---------------DELETE END---------------"<<endl;
	d.delEnd();
	cout<<"---------------DELETE POS---------------"<<endl;
	d.delPos(2);
	cout<<"---------------REVERSE---------------"<<endl;
	d.reverse();
}
