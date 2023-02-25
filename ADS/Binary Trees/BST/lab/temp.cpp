else
{
    treenode *minRight = temp->right;
    prev = temp;
    while (minRight->left != NULL)
    {
        prev = minRight;
        minRight = minRight->left;
    }
    strcpy(temp->data, minRight->data);
    if (prev->left == minRight)
    {
        prev->left = minRight->right;
    }
    else
    {
        prev->right = minRight->right;
    }
    delete minRight;
}