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
    if (root == NULL)
    {
        treenode *root;
        root = new treenode;
        cout << "Enter The Root Node :" << root->data << endl;
        cin >> root->data;
        root->left = NULL;
        root->right = NULL;
        treenode *temp, *curr;
        char con;
        do
        {
            temp = root;
            int flag = 0;
            /*curr=new treenode;
            cout<<"enter the current node"<<endl;
            cin>>curr->data;
            curr->left=NULL;
            curr->right=NULL;*/
            while (flag == 0)
            {
                char ch;
                cout << "Where do you want to add the data, left or right of :" << temp->data << endl;
                cin >> ch;
                if (ch = 'l')
                {
                    if (temp->left == NULL)
                    {
                        curr = new treenode;
                        cout << "enter the current node" << endl;
                        cin >> curr->data;
                        curr->left = NULL;
                        curr->right = NULL;
                        temp->left = curr;
                        flag = 1;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (ch = 'r')
                    {
                        if (temp->right == NULL)
                        {
                            curr = new treenode;
                            cout << "enter the current node" << endl;
                            cin >> curr->data;
                            curr->left = NULL;
                            curr->right = NULL;
                            temp->right = curr;
                            flag = 1;
                        }
                        temp = temp->right;
                    } // if end
                }     // else end
            }         // while flag
            cout << "Do You want to continue, y/n" << endl;
            cin >> con;
        } while (con == 'y');
    }
}

int main()
{
    tree bt;
    bt.create_r();
}
