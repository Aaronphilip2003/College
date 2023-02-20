#include <iostream>
using namespace std;
class treenode
{
    string data, meaning;
    treenode *left, *right;
    friend class bstree;
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
    struct treenode *create_bstree()
    {
        treenode *ptr, *temp;
        char ch;
        int flag;
        do
        {
            ptr = new treenode;
            cout << "Enter data of node: ";
            cin >> ptr->data;
            cout << "Enter meaning of node: ";
            cin >> ptr->meaning;
            ptr->left = ptr->right = NULL;
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

    treenode *copy_rec(treenode *root)
    {
        treenode *temp;
        temp = NULL;
        if (root != NULL)
        {
            temp = new treenode;
            temp->data = root->data;
            temp->meaning = root->meaning;
            temp->left = copy_rec(root->left);
            temp->right = copy_rec(root->right);
        }
        return temp;
    }

    void mirror_rec(treenode *root)
    {
        treenode *temp;
        temp = NULL;
        if (root == NULL)
        {
            return;
        }
        else
        {
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            mirror_rec(root->left);
            mirror_rec(root->right);
        }
    }

    void display_inorder(treenode *root)
    {
        if (root != NULL)
        {
            display_inorder(root->left);
            cout << root->data << ": " << root->meaning << endl;
            display_inorder(root->right);
        }
    }

    treenode *search_node(treenode *root, string key)
    {
        if (root == NULL || root->data == key)
        {
            return root;
        }

        if (key < root->data)
        {
            return search_node(root->left, key);
        }

        return search_node(root->right, key);
    }
};

int main()
{
    bstree b1;
    struct treenode *root1, *root2;
    int ch, choice;
    string key;
    root1 = b1.create_bstree();
    // b1.mirror_rec(root1);
    b1.display_inorder(root1);
    b1.search_node(root1, "word");
}
