#include <bits/stdc++.h>
using namespace std;

// index for storing ranges is 1 based

vector<int> left_index, right_index, seg_tree, delta;

int init(int index, int start, int end, vector<int> &arr)
{
    if (start == end)
    {
        left_index[index] = right_index[index] = start;
        seg_tree[index] = arr[start];
        return arr[start];
    }
    int mid = (start + end) / 2;
    int left_val = init(2 * index, start, mid, arr);
    int right_val = init(2 * index + 1, mid + 1, end, arr);
    seg_tree[index] = min(left_val, right_val);
    left_index[index] = start;
    right_index[index] = end;
    return seg_tree[index];
}

int query(int index, int l, int r)
{
    if (left_index[index] >= l and right_index[index] <= r)
    {
        return seg_tree[index];
    }
    else if (left_index[index] > r or right_index[index] < l)
    {
        return INT_MAX;
    }
    int left_ans = query(index * 2, l, r);
    int right_ans = query(index * 2 + 1, l, r);
    return min(left_ans, right_ans);
}

void propagation(int index)
{
    delta[index * 2] += delta[index];
    delta[index * 2 + 1] += delta[index];
    delta[index] = 0;
}

void lazy_propagation(int index)
{
    seg_tree[index] = min(seg_tree[2*index]+delta[2*index], seg_tree[2*index+1]+delta[2*index+1]);
}

int update(int index, int l, int r, int val)
{
    if (left_index[index] >= l and right_index[index] <= r)
    {
        delta[index] += val;
        return delta[index] + seg_tree[index];
    }
    if (left_index[index] > r || right_index[index] < l)
    {
        return INT_MAX;
    }
    propagation(index);
    int left_ans = update(2 * index, l, r, val);
    int right_ans = update(2 * index + 1, l, r, val);
    lazy_propagation(index);
    return seg_tree[index];
}

int main_query(int index, int l, int r)
{
    if (left_index[index] >= l and right_index[index] <= r)
    {
        return delta[index] + seg_tree[index];
    }
    else if (left_index[index] > r || right_index[index] < l)
    {
        return INT_MAX;
    }
    propagation(index);
    int left_ans = main_query(index * 2, l, r);
    int right_ans = main_query(index * 2 + 1, l, r);
    lazy_propagation(index);
    return min(left_ans, right_ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    left_index.resize(4 * n);
    right_index.resize(4 * n);
    seg_tree.resize(4 * n);
    delta.resize(4 * n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(1, 0, n - 1, arr);
    int q;
    cin >> q;
    int l, r, x;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> l >> r;
        if(x == 1)
        {
            int temp;
            cin >> temp;
            update(1, l, r, temp);
        }
        else
        {
            cout << main_query(1, l, r);
        }
    }
}
