#include <iostream>
#include <string.h>
using namespace std;
class bstree;
class treenode
{

public:
    char data[30];
    treenode *left, *right;
    friend class bstree;
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
                int c;
                temp = root;
                flag = 0;
                while (flag != 1)
                {
                    c = strcmp(ptr->data, temp->data);
                    if (c < 0)
                    {
                        if (temp->left == NULL)
                        {
                            temp->left = ptr;
                            flag = 1;
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
                        }
                        else
                        {
                            temp = temp->right;
                            flag = 0;
                        }
                    }
                }
            }
            cout << "Do you want to continue(y/n):";
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
        cout << endl;
    }
};

treenode *copy(treenode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    treenode *newNode = new treenode();
    strcpy(newNode->data, node->data);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

treenode *mirror_tree(treenode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    treenode *ptr = new treenode;
    strcpy(ptr->data, root->data);
    ptr->left = mirror_tree(root->right);
    ptr->right = mirror_tree(root->left);

    return ptr;
}

void delete_node(char value[], treenode *root)
{
    treenode *temp = root;
    treenode *prev = NULL;
    bool found = false;

    // Find the node to be deleted
    while (temp != NULL && !found)
    {
        int cmp = strcmp(value, temp->data); // compare value with node value
        if (cmp == 0)
        {
            found = true; // if cmp is 0, it means that node is found
        }
        else
        {
            prev = temp;
            if (cmp < 0) // if cmp is less than 0, it means that the node might be to the left
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right; // if cmp is greater than 0, it means that the node might be to the right
            }
        }
    }

    if (!found)
    {
        cout << "Value not found in the tree!" << endl;
        return;
    }

    // Node has no child
    if (temp->left == NULL && temp->right == NULL)
    {
        if (prev == NULL) // means that this was the root node
        {
            root = NULL;
        }
        else if (prev->left == temp)
        {
            prev->left = NULL;
        }
        else
        {
            prev->right = NULL;
        }
        delete temp;
    } // node had no children so we deleted it and updated its parent node that is prev to point to NULL

    // Node has one child
    else if ((temp->left == NULL) != (temp->right == NULL)) // ensures only one child exists
    {
        treenode *child;
        if (temp->left != NULL)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }

        if (prev == NULL)
        {
            root = child;
        }
        else if (prev->left == temp)
        {
            prev->left = child;
        }
        else
        {
            prev->right = child;
        }
        delete temp;
    }

    // Node has two children
    
    cout << "Value deleted from the tree!" << endl;
}

int main()
{
    bstree b1;
    bstree b2;
    treenode *root1;
    root1 = b1.create_bstree();
    cout << endl;
    cout << "Breadth-First Traversal:" << endl;
    b1.display_bfs(root1);
    treenode *copied_root = copy(root1);
    treenode *mirrored_root = mirror_tree(root1);
    cout << "Copied tree " << endl;
    b2.display_bfs(copied_root);
    cout << endl;
    cout << "Mirrored tree " << endl;
    b2.display_bfs(mirrored_root);
    cout << endl;
    delete_node("aryan", root1);
    b1.display_bfs(root1);

    return 0;
}
