#include<bits/stdc++.h>
using namespace std;

//deleting node : 
// for leaf node --> delete the node
// for node with single child --> delete the node after copying the child node to parent node.
// for node with two child --> find the inorder successor and replace the node.

template<class T>
struct tree
{
    T data;
    tree* left;
    tree* right;
};

template<class T>
tree<T>* create_node(T data)
{
    tree<T> *temp = new tree<T>();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

template<typename P>
void insert_into_bst(tree<P>* &root, P data)
{
    tree<P>* new_node = create_node(data);
    if(root == NULL)
    {
        root = new_node; 
        return;
    }
    tree<P> *temp = root;
    tree<P> *parent;
    int flag;
    while(temp != NULL)
    {
        parent = temp;
        if(temp->data < data)
        {
            flag = 0;
            temp = temp->right;
        }
        else
        {
            flag = 1;
            temp = temp->left;
        }
    }
    if(flag == 0)
    {
        parent->right = new_node;
    }
    else
    {
        parent->left = new_node;
    }
}

template<typename T>
void preorder(tree<T>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}


template<typename T>
tree<T>* delete_element(tree<T>* root, T data)
{
    tree<T>* global_root = root;
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == data)
    {
        //need to change the root itself
        if(root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
            return root;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            tree<T>* temp = root;
            if(root->left == NULL)
            {
                root = root->right;
                delete temp;
                temp = NULL;
            }
            else
            {
                root = root->left;
                delete temp;
                temp = NULL;
            }
            return root;
        }
        else
        {
            
            //find inorder successor
            tree<T>* successor = root->right;
            tree<T>* successor_parent = root;
            while(successor->left != NULL)
            {
                successor_parent = successor;
                successor = successor->left;
            }
            // if(flag == 0)
            // {
            //     parent->right->data = successor->data;
            // }
            // else
            // {
            //     parent->left->data = successor->data;
            // }
            root->data = successor->data;

            if(successor_parent->left->data == successor->data)
            {
                delete successor;
                successor_parent->left = NULL;
            }
            else if(successor_parent->right->data == successor->data)
            {
                delete successor;
                successor_parent->right = NULL;
            }
            return root;

        }



    }
    tree<T>* parent = root;
    int flag = 0;
    while(root != NULL && root->data != data)
    {
        parent = root;
        if(data > root->data)
        {
            flag = 0;
            root = root->right;
        }
        else
        {
            flag = 1;
            root = root->left;
        }
    }
    if(root == NULL)
    {
        // search unsuccessful
        return global_root;
    }
    else
    {
        if(root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
            if(flag == 0)
            {
                parent->right = NULL;
            }
            else
            {
                parent->left = NULL;
            }
            return global_root;
        }
        else if(root->left == NULL || root->right == NULL)
        {
            tree<T>* temp = root;
            if(root->left == NULL)
            {
                if(flag == 0)
                {
                    parent->right = root->right;
                }
                else
                {
                    parent->left = root->right;

                }
            }
            else
            {
                if(flag == 0)
                {
                    parent->right = root->left;
                }
                else
                {
                    parent->left = root->left;
                }
            }
            delete root;
            root = NULL;
            return global_root;
        }
        else
        {
            //find inorder successor
            tree<T>* successor = root->right;
            tree<T>* successor_parent = root;
            while(successor->left != NULL)
            {
                successor_parent = successor;
                successor = successor->left;
            }
            if(flag == 0)
            {
                parent->right->data = successor->data;
            }
            else
            {
                parent->left->data = successor->data;
            }
            if(successor_parent->left->data == successor->data)
            {
                delete successor;
                successor_parent->left = NULL;
            }
            else if(successor_parent->right->data == successor->data)
            {
                delete successor;
                successor_parent->right = NULL;
            }
        }
    }
    return global_root;
}

int main()
{
    int n;
    cin >> n;
    tree<int> *root = NULL;
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        insert_into_bst(root, x);
    }

    root = delete_element(root, int(6));
    preorder(root);
}