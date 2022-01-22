#include<bits/stdc++.h>
using namespace std;


int find(int node, vector<int> &sets)
{
    if(sets[node] == node)
    {
        return node;
    }
    sets[node] = find(sets[node], sets);
    return sets[node];
}


void perform_union(int a, int b, vector<int> &sets, vector<int> &count)
{
    int root_a = find(a, sets);
    int root_b = find(b, sets);
    if(count[root_a] > count[root_b])
    {
        sets[root_b] = root_a;
        count[root_a] += count[root_b];
    }
    else
    {
        sets[root_a] = root_b;
        count[root_b] += count[root_a];
    }
}

void display(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "\t";
    }
}



// [[9,10],[5,8],[2,6],[1,5],[3,8],[4,9],[8,10],[4,10],[6,8],[7,9]]

int main()
{
    int n;
    cin >> n;
    vector<int> sets(n);
    for(int i = 0; i < n; i++)
    {
        sets[i] = i;
    }
    vector<int> count(n, 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        perform_union(a, b, sets, count);
        
        display({0,1,2,3,4,5,6,7,8,9,10});
        cout << endl;
        display(sets);
        cout << endl;
    }

}