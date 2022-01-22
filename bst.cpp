#include <bits/stdc++.h>
using namespace std;

class bst
{
public:
    int item;
    bst *left;
    bst *right;
};

bst *create_node(int item)
{
    bst *node = new bst();
    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bst *insert_in_bst(int item, bst *root)
{
    bst *node = create_node(item);
    if (node == NULL)
    {
        return NULL; // not enough memory available;
    }
    if (root == NULL)
    {
        root = node;
        return root;
    }

    bst *temp_node = root;
    int flag = 0; // 0 indicates left, 1 indicates right.
    bst *temp_node_parent = root;

    while (temp_node != NULL)
    {
        if (temp_node->item >= item)
        {
            temp_node_parent = temp_node;
            flag = 0;
            temp_node = temp_node->left;
        }
        else if (temp_node->item < item)
        {
            temp_node_parent = temp_node;
            flag = 1;
            temp_node = temp_node->right;
        }
    }
    if (flag == 1)
    {
        temp_node_parent->right = node;
    }
    else
    {
        temp_node_parent->left = node;
    }

    return root;
}

void inorder_traversal(bst *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->item << " ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(bst *root)
{
    if (root != NULL)
    {
        cout << root->item << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(bst *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->item << " ";
    }
}

int inorder_successor(bst *root)
{
    bst *parent = root;
    while (root->left != NULL)
    {
        parent = root;
        root = root->left;
    }
    parent->left = NULL;
    int val = root->item;
    delete root;
    root = NULL;
    return val;
}

int sum_of_leaf(bst* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL and root->right == NULL)
    {
        return root->item;
    }
    return sum_of_leaf(root->left) + sum_of_leaf(root->right);
}

void remove(int item, bst *root)
{
    bst* root_copy = root;
    if (root_copy == NULL)
    {
        return;
    }
    bst *parent = root_copy;
    int flag = 0;
    while (root_copy != NULL and root_copy->item != item)
    {
        parent = root_copy;
        if (root_copy->item > item)
        {
            flag = 0;
            root_copy = root_copy->left;
        }
        else if (root_copy->item < item)
        {
            flag = 1;
            root_copy = root_copy->right;
        }
    }
    // item found
    if (root_copy != NULL)
    {
        if (root_copy->left == NULL && root_copy->right == NULL)
        {
            // if root is a leaf
            if (flag == 0)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            delete root_copy;
            root_copy = NULL;
        }
        else if (root_copy->left == NULL)
        {
            // if root has only right child.
            bst *temp = root_copy;
            parent->right = root_copy->right;
            delete temp;
            temp = NULL;
        }
        else if (root_copy->right == NULL)
        {
            // if root has only left child.
            bst *temp = root_copy;
            parent->left = root_copy->left;
            delete temp;
            temp = NULL;
        }
        else
        {
            // if root has two element.
            root_copy->item = inorder_successor(root_copy->right);
        }
    }
}

bst *root = NULL;

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     root = insert_in_bst(i, root);
    // }

    root = insert_in_bst(5, root);
    root = insert_in_bst(7, root);
    root = insert_in_bst(6, root);
    root = insert_in_bst(9, root);
    root = insert_in_bst(2, root);
    root = insert_in_bst(1, root);
    root = insert_in_bst(3, root);
    inorder_traversal(root);
    cout << endl;
    preorder_traversal(root);
    cout << endl;
    postorder_traversal(root);

    remove(5,root);
    cout << "After removing " << 5 << endl;
    inorder_traversal(root);
    cout << endl;
    preorder_traversal(root);
    cout << endl;
    postorder_traversal(root);
    cout << "sum of leaf nodes " << sum_of_leaf(root);
}