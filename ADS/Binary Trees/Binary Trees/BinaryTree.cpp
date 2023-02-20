#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data to be inserted to the left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to be inserted to the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

class queue{
    public:
    int front,rear;
    node* data[30];

    public:
    queue()
    {
        front=-1;
        rear=-1;
    }

    void push(node* temp)
    {
        rear++;
        data[rear]=temp;
    }

    node* pop()
    {
        node* temp;
        front++;
        temp=data[front];
        return temp;
    }

    int is_empty()
    {
        int isempty;
        if(front==rear)
        {
            isempty=0;
        }
        else
        {
            isempty=1;
        }
        return isempty;
    }

};

int main()
{
    node *root = NULL;
    root = buildTree(root);
    return 0;
}