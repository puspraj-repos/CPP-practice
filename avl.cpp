#include<bits/stdc++.h>
using namespace std;

struct avl
{
    int item;
    avl* left;
    avl* right;
};

avl* create_node(int item)
{
    avl* node = new avl;
    if(node == NULL)
    {
        // not enough memory in heap
        return NULL;
    }
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}


// taking height 0 as base
int height(avl* root)
{
    if(root == NULL)
    {
        return -1;
    }
    return max ( height(root->left), height(root->right))+1;
}

avl* left_rotation(avl* root)
{
    avl* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

avl* right_rotation(avl* root)
{
    avl* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

avl* insert_avl(avl* node, avl* root)
{
    if(root->item >= node->item)
    {
        if(root->left != NULL)
        {
            root->left = insert_avl(node, root->left);
        }
        else
        {
            root->left = node;
            // return root;
        }
    }
    else 
    {
        if(root->right != NULL)
        {
            root->right = insert_avl(node, root->right);
        }
        else 
        {
            root->right = node;
            // return root;
        }
    }
    int diff = height(root->left) - height(root->right);
    if(diff > 1)
    {
        root = right_rotation(root);
    }
    else if(diff < -1)
    {
        root = left_rotation(root);
    }
    return root;
}

avl* insert(int item, avl* root)
{
    avl* node = create_node(item);
    if(root == NULL)
    {
        root = node;
        return root;
    }
    root = insert_avl(node, root);
    return root;
}


void inorder_traversal(avl *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        cout << root->item << " ";
        inorder_traversal(root->right);
    }
}

void preorder_traversal(avl *root)
{
    if (root != NULL)
    {
        cout << root->item << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(avl *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->item << " ";
    }
}


// declaring global variable for avl tree

avl* root = NULL;

int main()
{
    for (int i = 0; i < 8; i++)
    {
        root = insert(i+1, root);
    }
    inorder_traversal(root);
    cout << endl;
    postorder_traversal(root);
    cout << endl;
    preorder_traversal(root);

    // void (*function_pointer_name)(avl* );
    // function_pointer_name = inorder_traversal;
    // function_pointer_name(root);

    
    
}