#include<iostream>
using namespace std;
struct node {
	int value;
	struct node *left;
	struct node *right;
};
typedef struct node *nodeptr;
class tree{
	public:
		struct node *root;
		tree()
		{
			root=NULL;
		}
		void insert(int x, nodeptr &p)
		{
			if(p==NULL)
			{
				p=new node;
				p->value=x;
				p->left=NULL;
				p->right=NULL;
				cout<<p->value<<" is inserted"<<endl;	
				return;
			}
			
			if(x<p->value)
				insert(x, p->left);
			else
				insert(x, p->right);
		}
		void inorder(nodeptr &p)
		{
			if(p!=NULL)
			{
				inorder(p->left);
				cout<<p->value<<"->";
				inorder(p->right);
			}
		}
		void preorder(nodeptr &p)
		{
			if(p!=NULL)
			{
				cout<<p->value<<"->";
				preorder(p->left);
				preorder(p->right);
			}
		}
		void postorder(nodeptr &p)
		{
			if(p!=NULL)
			{
				postorder(p->left);
				postorder(p->right);
				cout<<p->value<<"->";
			}
		}
		void small(nodeptr &p)
		{
			struct node *cur;
			for(cur=p; cur->left!=NULL; cur=cur=cur->left);
			cout<<"\n"<<cur->value<<" is the smallest"<<endl;
		}
		void large(nodeptr &p)
		{
			struct node *cur;
			for(cur=p;cur->right;cur=cur->right);
			cout<<"\n"<<cur->value<<" is the largest"<<endl;
		}
//		void del(int x, nodeptr &p)
//		{
//			
//			if(p==NULL)
//			{
//				cout<<"Tree is empty"<<endl;
//				return;
//			}
//			if(x<p->value)
//				del(x, p->left);
//			else if(x>p->value)
//				del(x, p->right);
//			else
//			{
//				struct node *t;
//				if(p->left==NULL && p->right==NULL)
//				{	
//					t=p;
//					delete t;
//					cout<<x<<" is deleted"<<endl; 
//				}	
//				else if(p->left==NULL)
//				{
//					t=p;
//					p=p->right;
//					delete t;
//					cout<<x<<" is deleted"<<endl;
//				}
//				else if(p->right==NULL)
//				{
//					t=p;
//					p=p->left;
//					delete t;
//					cout<<x<<" is deleted"<<endl;
//				}
//				else{
//					delmin(p->right);
//				}
//				
//				
//			}
//		}
//		void delmin(nodeptr &p)
//		{
//			struct node *t;
//			if(p->left==NULL)
//			{
//				t=p;
//				p=p->right;
//				delete t;
//			}
//			else{
//				delmin(p->left);
//			}
//		}

//TODO delete min implement later
};
int main()
{
	tree t;
	t.insert(4, t.root);
	t.insert(5, t.root);
	t.insert(2, t.root);
	t.insert(6, t.root);
	t.insert(3, t.root);
	t.insert(1, t.root);	
	cout<<"------------InOrder--------------"<<endl;
	t.inorder(t.root);
	cout<<"\n---------PreOrder-------------"<<endl;
	t.preorder(t.root);
	cout<<"\n---------PostOrder-------------"<<endl;
	t.postorder(t.root);
	t.small(t.root);
	t.large(t.root);
}
