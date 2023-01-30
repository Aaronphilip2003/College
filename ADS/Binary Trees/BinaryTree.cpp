#include<iostream>
using namespace std;

class Node{
    int data;
    Node *lChild;
    Node *rChild;
    friend class tree;
};

class tree
{
    Node *root;
    public:
    tree();
    void create_r();
};

tree::tree()
{
    root=NULL;
}

void tree::create_r()
{
    if(root==NULL)
    {
        Node *root;
        root=new Node;
        cout<<"Enter Data of the root node:"<<endl;
        cin>>root->data;
        root->lChild=NULL;
        root->rChild=NULL;
    }
}

int main()
{
    tree bt;
    bt.create_r();
}
