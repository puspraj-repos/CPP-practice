#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int val;
    tree *left, *right;
    tree(int val = 0)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(tree *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

tree* left_rotate(tree* root)
{
    tree* root_right_left = root->right->left;
    root->right->left = root;
    root = root->right;
    root->left->right = root_right_left;
    return root;
}
tree* right_rotate(tree* root)
{
    tree* root_left_right = root->left->right;
    root->left->right = root;
    root = root->left;
    root->right->left = root_left_right;
    return root;
}

tree* balance_tree(stack<tree*> &parents)
{
    tree* current_parent = nullptr;
    while(!parents.empty())
    {
        current_parent = parents.top();
        parents.pop();
        int height_left = height(current_parent->left);
        int height_right = height(current_parent->right);
        if (abs(height_left - height_right) > 1)
        {
            if(height_left > height_right)
            {
                current_parent = right_rotate(current_parent);
            }
            else
            {
                current_parent = left_rotate(current_parent);
            }
            if(!parents.empty() and current_parent->val < parents.top()->val)
            {
                parents.top()->left = current_parent;
            }
            else if(!parents.empty())
            {
                parents.top()->right = current_parent;
            }
            else
            {
                return current_parent;
            }
        }
    }
    return current_parent;
}

tree *insert(tree *root, int val)
{
    tree *node = new tree(val);
    if (root == nullptr)
    {
        root = node;
        return root;
    }
    tree *current = root;
    //stack will store the parents we have visited so far
    stack<tree*> parents;
    while(current != nullptr)
    {
        parents.push(current);
        if (current->val > val)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if(parents.top()->val > val)
    {
        parents.top()->left = node;
    }
    else
    {
        parents.top()->right = node;
    }
    //after inserting the new node, look for the parents if they are balanced or not
    root = balance_tree(parents);
    return root;
}

bool is_leaf(tree* root)
{
    return !(root->left || root->right);
}

bool two_childs(tree *root)
{
    return root->left && root->right;
}

bool single_child(tree* root)
{
    return !(is_leaf(root) || two_childs(root));
}

tree* remove(int val, tree* root)
{
    if(root == nullptr)
    {
        return root;
    }
    stack<tree*> parents;
    tree* current_node = root;
    while(current_node and current_node->val != val)
    {
        parents.push(current_node);
        if(current_node->val < val)
        {
            current_node = current_node->right;
        }
        else
        {
            current_node = current_node->left;
        }
    }
    if(!current_node)
    {
        cout << "element not found" << endl;
        return root;
    }
    else
    {
        //deleting in case of leaf
        if(is_leaf(current_node))
        {
            if(parents.top()->val > val)
            {
                parents.top()->left = nullptr;
            }
            else
            {
                parents.top()->right = nullptr;
            }
            delete current_node;
            current_node = nullptr;
        }
        //deleting in case of node has single child
        else if(single_child(current_node))
        {
            if(parents.top()->val > val)
            {
                if(current_node->left)
                {
                    parents.top()->left = current_node->left;
                }
                else
                {
                    parents.top()->left = current_node->right;
                }
            }
            else
            {
                if(current_node->left)
                {
                    parents.top()->right = current_node->left;
                }
                else
                {
                    parents.top()->right = current_node->right;
                }
            }
            delete current_node;
            current_node = nullptr;
        }
        //deleting in case of node has two childs.
        else
        {
            //find inorder successor
            tree* inorder_successor = current_node->right;
            tree* successor_parent = current_node;
            while(inorder_successor->left != nullptr)
            {
                parents.push(inorder_successor);
                successor_parent = inorder_successor;
                inorder_successor = inorder_successor->left;
            }
            current_node->val = inorder_successor->val;
            if(current_node->right == inorder_successor)
            {
                current_node->right = inorder_successor->right;
            }
            else
            {
                successor_parent->left = inorder_successor->right;
            }
            delete inorder_successor;
            inorder_successor = nullptr;
        }
        root = balance_tree(parents);
        return root;
    }
}


void preorder(tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    tree *root = nullptr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
        //traversing after every insertion to check if the tree is correct or not
        preorder(root);
        cout << endl;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = remove(x, root);
        preorder(root);
        cout << endl;
    }
}