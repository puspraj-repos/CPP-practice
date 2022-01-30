#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        if(n > 1 and k == 1)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> arr;
        arr.push_back(1);
        if(n == 1)
        {
           print_vector(arr); 
           continue;
        }
        int count = 2;
        for(int i = 0; i < k - 2; i++)
        {
            arr.push_back(count);
            count++;
        }
        while(n >= count)
        {
            arr.push_back(n);
            n--;
        }

        print_vector(arr);
    }
}