#include <iostream>
using namespace std;

class Node
{
    char data[20];
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
    root = NULL;
}

void tree::create_r()
{
    if (root == NULL)
    {
        Node *root;
        root = new Node;
        cout << "Enter the data of the root node:" << endl;
        cin >> root->data;
        root->lChild = NULL;
        root->rChild = NULL;
        Node *temp, *curr;
        char con;
        do
        {
            temp = root;
            int flag = 0;
            cout << "Do you want to continue (y/n):" << endl;
            cin >> con;
        } while (con != 'n');
    }
}

int main()
{
    tree bt;
    bt.create_r();
    cout << "CREATED!" << endl;
}