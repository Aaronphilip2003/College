#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    TreeNode *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    TreeNode *create_bstree()
    {
        TreeNode *ptr, *temp;
        int value, flag;
        char ch;

        do
        {
            ptr = new TreeNode;
            cout << "Enter value of node: ";
            cin >> value;

            ptr->data = value;
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
                        }
                        else
                        {
                            temp = temp->left;
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
                        }
                    }
                }
            }

            cout << "Do you want to continue? (y/n): ";
            cin >> ch;

        } while (ch == 'y' || ch == 'Y');

        return root;
    }

    void display_inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            display_inorder(root->left);
            cout << root->data << " ";
            display_inorder(root->right);
        }
    }

    

    TreeNode *search_node(TreeNode *root, int key)
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
    BinarySearchTree bst;
    TreeNode *root;
    int ch, choice, key;
    root = bst.create_bstree();
    bst.display_inorder(root);
    cout << endl;
    cout << "Enter key to search: ";
    cin >> key;
    TreeNode *result = bst.search_node(root, key);
    if (result)
    {
        cout << "Key " << key << " found in the tree.";
    }
    else
    {
        cout << "Key " << key << " not found in the tree.";
    }

    return 0;
}
