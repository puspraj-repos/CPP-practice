//Max Heap

#include<bits/stdc++.h>
using namespace std;

void insert_in_heap(int item, vector<int> &heap);

void bubble_up(int key, vector<int> &heap);

void display(vector<int> arr);

void remove_from_heap (vector<int> &heap);

void bubble_down(int key, vector<int> &heap);

int main()
{
    vector<int> heap;
    char ch;

    // do
    // {
    //     int item;
    //     cin >> item;
    //     insert_in_heap(item, heap);
    //     cout << " continue ? (y/n)";
    //     cin>>ch;
    // } while (ch != 'n');

    for (int i = 0; i < 10; i++)
    {
        insert_in_heap(i+1,heap);
    }
    remove_from_heap(heap);
    display(heap);

}

void insert_in_heap(int item, vector<int> &heap)
{
    heap.push_back(item);
    bubble_up(heap.size()-1, heap);
}

void bubble_up(int key, vector<int> &heap)
{
    int parent = (key -1) / 2;
    while(key >=0 && heap[key] > heap[parent])
    {
        swap(heap[key],heap[parent]);
        key = parent;
        parent = (key - 1) / 2;
    }

}

void display(vector<int> arr)
{
    for(vector<int>::iterator i = arr.begin(); i != arr.end(); i++)
    {
        cout << *i << " ";
    }
}

void remove_from_heap (vector<int> &heap)
{
    if(heap.size()==0)
    {
        return;
    }
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    bubble_down(0,heap);
}


void bubble_down(int key, vector<int> &heap)
{
    int left = key * 2 + 1;
    int right = key * 2 + 2;
    int largest = key;
    if(left < heap.size() and heap[left] > heap[largest])
    {
        largest = left;
    }
    if( right < heap.size() and heap[right] > heap[largest])
    {
        largest = right;
    }
    if(largest != key)
    {
        swap(heap[largest], heap[key]);
        bubble_down(largest, heap);
    }
}



    