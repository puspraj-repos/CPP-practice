#include<bits/stdc++.h>
using namespace std;

vector<int> heap;

void bubble_up(int index)
{
    int parent = (index-1)/2;
    if(heap[parent] > heap[index])
    {
        swap(heap[parent], heap[index]);
        bubble_up(parent);
    }
}

void swim(int index)
{
    int left = index*2+1;
    int right = index*2+2;
    int heap_size = heap.size();
    int smallest = index;
    if(left < heap_size)
    {
        if(heap[left] < heap[smallest])
        {
            smallest = left;
        }
    }
    if(right < heap_size)
    {
        if(heap[right] < heap[smallest])
        {
            smallest = right;
        }
    }
    if(index != smallest)
    {
        swap(heap[index], heap[smallest]);
        swim(smallest);
    }

}

void insert(int item)
{
    heap.push_back(item);
    bubble_up(heap.size() - 1);
}

void remove()
{
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    if(heap.size() > 0)
    swim(0);
}

void display(vector<int> heap)
{
    for(int i = 0; i < heap.size(); i++)
    {
        cout <<i << "\t";
    }
    cout << endl;
    for(int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << "\t";
    }
}

int main()
{
    int n, item;
    cin >> n;
    while (n--)
    {
        cin >> item;
        insert(item);
        display(heap);

    }
    cout << endl << endl;
    while(heap.size() > 0)
    {
        cout << heap[0] << " ";
        remove();
    }
}