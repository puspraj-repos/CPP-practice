#include<bits/stdc++.h>
using namespace std;

struct tree
{
    int val;
    tree *left, *right;
};

tree* create_node(int val)
{
    tree *node = new tree;
    node->left = nullptr;
    node->right = nullptr;
    node->val = val;
    return node;
}


void inorder(tree *root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


tree* insert_into_bst(tree *root, int val)
{
    tree *node = create_node(val);
    if(root == nullptr)
    {
        root = node;
        return root;
    }
    tree *parent = root, *temp = root;
    while(temp != nullptr)
    {
        parent = temp;
        if(temp->val < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if(parent->val > val)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }
    return root;
}

void delete_leaf(tree* node, tree* parent)
{
    if(parent->val > node->val)
    {
        parent->left = nullptr;
    }
    else
    {
        parent->right = nullptr;
    }
    delete node;
    node = nullptr;
}

void delete_node_with_double_child(tree *node, tree *parent)
{
    tree *temp = node->right, *temp_parent = node;

    //swapping technique, this even works in case of root node, parent is not required at all except for leaf case

    while(temp->left != nullptr)
    {
        temp_parent = temp;
        temp = temp->left;
    }

    //Adjusting values for successor's parent
    if(temp_parent->val > temp->val)
    {
        temp_parent->left = temp->right;
    }
    else
    {
        temp_parent->right = temp->right;
    }
    //no need to adjust node's left or right, because node is not changed rather value is updated
    node->val = temp->val;

    //no adjustment needed for node's parent as it is pointing to same node but value is updated.

    //deleting the inorder successor of node
    delete temp;
    temp = nullptr;

    /*
    // finding inorder successor
    bool flag = 1;
    while(temp->left != nullptr)
    {
        flag = 0;
        temp_parent = temp;
        temp = temp->left;
    }
    if(flag)
    {
        temp_parent->right = temp->right;
    }
    else
    {
        temp_parent->left = temp->right;
    }
    //adjusting successor as the deleted node
    temp->left = node->left;
    temp->right = node->right;

    //adjusting parent of node which was supposed to be deleted
    if(parent->val > node->val)
    {
        parent->left = temp;
    }
    else
    {
        parent->right = temp;
    }
    //releasing memory
    delete node;
    node = nullptr;
    */

}

void delete_node_with_single_child(tree *node, tree *parent)
{
    if(parent->val > node->val)
    {
        parent->left = node->left != nullptr ? node->left : node->right;
    }
    else
    {
        parent->right = node->left != nullptr ? node->left : node->right;
    }
}

tree* delete_from_bst(tree *root, int val)
{
    if(root == nullptr)
    {
        cout << "can't delete" << endl;
        return root;
    }
    tree *parent = root, *temp = root;
    while(temp != nullptr and temp->val != val)
    {
        parent = temp;
        if(temp->val < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if(temp == nullptr)
    {
        cout << "can't find required value" << endl;
        return root;
    }
    else
    {
        //it is a leaf node
        if(temp->left == nullptr && temp->right == nullptr)
        {
            delete_leaf(temp, parent);
        }
        //it has two childs
        else if(temp->left != nullptr and temp->right != nullptr)
        {
            delete_node_with_double_child(temp, parent);
        }
        //it has one child
        else
        {
            delete_node_with_single_child(temp, parent);
        }
    }
    return root;
}


int main()
{
    int n, x;
    tree *root = nullptr;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert_into_bst(root, x);
    }
    inorder(root);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> x;
        delete_from_bst(root, x);
        inorder(root);
    }
}