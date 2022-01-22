#include<bits/stdc++.h>
using namespace std;


int partition(int l, int r, vector<int> &arr)
{
    if(l == r)
    {
        return l;
    }
    int temp = arr[r];
    int partition_index = l;
    for(int i = l; i < r; i++)
    {
        if(arr[i] <= temp)
        {
            swap(arr[i], arr[partition_index]);
            partition_index++;
        }
    }
    swap(arr[r], arr[partition_index]);
    return partition_index;

}

void quick_sort(int l, int r, vector<int> &arr)
{
    if(l >= r) return;
    int partition_index = partition(l, r, arr);
    if(partition_index > l)
    quick_sort(l, partition_index - 1, arr);
    if(partition_index < r)
    quick_sort(partition_index + 1, r, arr);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(0, n-1, arr);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}