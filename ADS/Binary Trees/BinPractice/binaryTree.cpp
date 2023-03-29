#include<iostream>
using namespace std;

class treenode{
	int data;
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree{
	public:
		tree();
		void create_r();
		void create_r(treenode *);
		void inorder_r();
		void inorder_r(treenode *);
		void preorder();
		void preorder(treenode *);
		void postorder();
		void postorder(treenode *);
};

tree::tree()
{
	treenode *root=new treenode();
	root=NULL;
}


void tree::create_r()
{
	treenode *root=new treenode();
	cout<<"Enter the data to be inserted:"<<endl;
	cin>>root->data;
	create_r(root);
}

void tree::create_r(treenode *temp)
{
        char ch;
	cout<<"Do you want to insert data to the left? (y/n):"<<endl;
	cin>>ch;
	if(ch=='y')
	{
		treenode *curr=new treenode();
		temp->left=curr;
		cout<<"Enter the data to be inserted:"<<endl;
		cin>>curr->data;
		create_r(curr);
	}
	cout<<"Do you want to insert data to the right? (y/n):"<<endl;
	cin>>ch;
	if(ch=='y')
	{
		treenode *curr=new treenode();
		temp->right=curr;
		cout<<"Enter the data to be inserted:"<<endl;
		cin>>curr->data;
		create_r(curr);
	}
	
}


void tree::inorder_r()
{
	treenode *root=new treenode();
	root=NULL;
}


void tree::inorder_r(treenode *temp)
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->data<<" ";
		inorder_r(temp->right);
	}
}

void tree::preorder()
{
	treenode *root=new treenode();
	root=NULL;
}

void tree::preorder(treenode *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
		
	}
}

void tree::postorder()
{
	treenode *root=new treenode();
	root=NULL;
}

void tree::postorder(treenode *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}


int main()
{
	tree bt;
	bt.create_r();
	bt.inorder_r();
	return 0;
}

