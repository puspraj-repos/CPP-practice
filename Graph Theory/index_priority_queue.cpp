#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    Node *next, *prev;
    Node(int id)
    {
        this->id = id;
        prev = NULL;
        next = NULL;
    }
    Node()
    {
        
    }
};

class LRUCache {
    public:
    Node *front, *last;
    int capacity;
    vector<int> get_value;
    vector<Node*> get_node;
    int count;
public:
    LRUCache(int capacity) {
        get_value.resize(10001, -1);
        get_node.resize(10001, nullptr);
        this->capacity = capacity;
        front = last = NULL;
        count = 0;
    }
    Node* add(int key, int val)
    {
        Node *node = new Node(key);
        //No node
        if(front == NULL)
        {
            front = node;
            last = node;
            get_value[key] = val;
            get_node[key] = node;
            return node;
        }
        //only single node
        else if(front == last)
        {
            node->next = front;
            front->prev = node;
            front = node;
            get_value[key] = val;
            get_node[key] = node;
            return node;
        }
        else
        {
            node->next = front;
            front->prev = node;
            get_value[key] = val;
            get_node[key] = node;
            front = node;
            return node;
        }
    }
    void remove_last()
    {
        if(last->prev == NULL)
        {
            get_node[last->id] = NULL;
            get_value[last->id] = -1;
            front = last = NULL;
            return;
        }
        else
        {
            last->prev->next = NULL;
            get_node[last->id] = NULL;
            get_value[last->id] = -1;
            last = last->prev;
            return;
        }
        
    }
    void remove(int key)
    {
        Node *node = get_node[key];
        //deleting last node
        if(node == last)
        {
            remove_last();
            return;
        }
        //Deleting front node
        else if(node == front)
        {
            front = front->next;
            if(front != NULL)
            {
                front->prev = NULL;
            }
            get_value[key] = -1;
            get_node[key] = NULL;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            get_value[key] = -1;
            get_node[key] = NULL;
            return;
        }
    }
    int get(int key) {
        if(get_value[key] != -1)
        {
            int val = get_value[key];
            remove(key);
            add(key, val);
            return get_value[key];
        }
        else 
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(get_value[key] != -1)
        {
            remove(key);
            add(key, value);
        }
        else if(count < capacity)
        {
            count++;
            add(key, value);
        }
        else
        {
            remove_last();
            add(key, value);
        }
        
    }
    void traverse()
    {
        Node* temp = front;
        while(temp != NULL)
        {
            cout << temp->id << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    // [2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]
    LRUCache obj(2);
    // cout << "hi";
    // obj.put(1,1);
    // // cout << "hi";
    // obj.put(2,2);
    // // cout << "hi";
    // // obj.traverse();
    // cout << obj.get(1) << endl;
    // obj.put(3,3);
    // //obj.traverse();
    // //cout << "hi";
    // cout << obj.get(2) << endl;
    // obj.put(4,4);
    // //cout << "hi";
    // cout << obj.get(1) << endl;
    // //cout << "hi";
    // cout << obj.get(3) << endl;
    // cout << obj.get(4) << endl;

    // ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,0],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
obj.put(1, 0);
obj.put(2, 2);
obj.traverse();
obj.get(1);
obj.traverse();
obj.put(3, 3);
obj.traverse();
obj.get(2);
obj.traverse();
obj.put(4,4);
obj.traverse();
cout << obj.get_value[1] << endl;
obj.get(1);
obj.traverse();
obj.get(3);
obj.get(4);

}