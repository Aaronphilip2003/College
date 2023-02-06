#include <iostream>
using namespace std;

class treenode
{
    char data[10];
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree
{
    treenode *root;

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
    treenode *curr, *temp;
    int flag = 0;
    char con = 'y';
    do
    {
        if (root == NULL)
        {
            treenode *root;
            root = new treenode;
            cout << "Enter The Node :" << root->data << endl;
            cin >> root->data;
            root->left = NULL;
            root->right = NULL;
        }
        curr = root;
        flag = 0;
        while (flag == 0)
        {
            char ch;
            cout << "Where do you want to add the data, left or right (l/r) :" << endl;
            cin >> ch;
            temp = new treenode;
            if (ch == 'l')
            {
                if (temp->left == NULL)
                {
                    curr = new treenode;
                    cout << "Enter the current node data:" << endl;
                    cin >> curr->data;
                    curr->left = NULL;
                    curr->right = NULL;
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else if (ch == 'r')
            {
                if (temp->right == NULL)
                {
                    curr = new treenode;
                    cout << "Enter the current node data:" << endl;
                    cin >> curr->data;
                    curr->left = NULL;
                    curr->right = NULL;
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        cout << "Do you want to continue:(y/n):" << endl;
        cin >> con;
    } while (con == 'y');
}

class stack
{
    int top;
    treenode *data[30];

public:
    stack()
    {
        top = -1;
    }
    void push(treenode *temp);
    treenode *pop();
    int empty();
    friend class tree;
};

int main()
{
    tree bt;
    bt.create_r();
}