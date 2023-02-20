#include <iostream>

using namespace std;

class bstree;

class treenode
{
    string data;
    treenode *left, *right;
    friend class bstree;

public:
    treenode()
    {
        left = NULL;
        right = NULL;
    }
};

class bsqueue
{
    int front, rear;
    treenode *data[30];

public:
    bsqueue()
    {
        front = -1;
        rear = -1;
    }

    void push(treenode *temp)
    {
        rear++;
        data[rear] = temp;
    }

    treenode *pop()
    {
        treenode *temp;
        front++;
        temp = data[front];
        return temp;
    }

    int is_empty()
    {
        int isempty;
        if (front == rear)
        {
            isempty = 0;
        }
        else
        {
            isempty = 1;
        }
        return isempty;
    }
};

class bstree
{
    treenode *root;

public:
    bstree()
    {
        root = NULL;
    }

    treenode *create_bstree()
    {
        treenode *ptr, *temp;
        char ch;
        int flag;
        do
        {
            ptr = new treenode;
            cout << "Enter data of node: ";
            cin >> ptr->data;
            if (root == NULL)
            {
                root = ptr;
            }
            else
            {
                temp = root;
                flag = 0;
                while (flag != 1)
                {
                    if (ptr->data < temp->data)
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = ptr;
                            flag = 1;
                            break;
                        }
                        else
                        {
                            temp = temp->left;
                            flag = 0;
                        }
                    }
                    else
                    {
                        if (temp->right == NULL)
                        {
                            temp->right = ptr;
                            flag = 1;
                            break;
                        }
                        else
                        {
                            temp = temp->right;
                            flag = 0;
                        }
                    }
                }
            }
            cout << "Do you want to continue?";
            cin >> ch;
        } while (ch == 'y');
        return root;
    }

    void display_bfs(treenode *root)
    {
        if (root == NULL)
        {
            return;
        }

        bsqueue q;
        q.push(root);
        while (q.is_empty() != 0)
        {
            treenode *temp = q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
};

int main()
{
    bstree b1;
    treenode *root1;
    root1 = b1.create_bstree();
    b1.display_bfs(root1);
    return 0;
}
