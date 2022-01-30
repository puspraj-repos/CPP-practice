#include<bits/stdc++.h>
using namespace std;

vector<int> min_heap;
int heap_size = 0;

void bubble_up(int index)
{
    int parent = (index - 1)/2;
    while(index != 0 and min_heap[index] < min_heap[parent])
    {
        swap(min_heap[index], min_heap[parent]);
        index = parent;
        parent = (index - 1)/2;
    }
}

void swim(int index)
{
    int left = index*2 + 1;
    int right = index*2 + 2;
    int smallest = index;
    if(left < heap_size and min_heap[smallest] > min_heap[left])
    {
        smallest = left;
    }
    if(right < heap_size and min_heap[smallest] > min_heap[right])
    {
        smallest = right;
    }
    if(smallest != index)
    {
        swap(min_heap[smallest], min_heap[index]);
        swim(smallest);
    }
}

void insert(int element)
{
    if(heap_size == 0)
    {
        min_heap.push_back(element);
        heap_size++;
        return;
    }
    min_heap.push_back(element);
    bubble_up(heap_size);
    heap_size++;
}

void remove()
{
    swap(min_heap[0], min_heap[heap_size - 1]);
    min_heap.pop_back();
    heap_size--;
    swim(0);
}
int main()
{
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        insert(x);
    }
    cin >> x;
    for(int i = 0; i < n - x; i++)
    {
        remove();
    }
    cout << min_heap[0] << endl;
}