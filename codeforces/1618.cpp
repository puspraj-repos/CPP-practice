#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        unordered_map<int,int> lookup;
        cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            lookup[x]++;
        }
        stack<pair<int, int>> arr;
        int ans = 0;
        for(auto i : lookup)
        {
            arr.push({i.first, i.second});
        }
        while(k!=0)
        {
            pair<int, int> first, second;
            first = arr.top();
            arr.pop();
            if(arr.empty() == true)
            {
                ans+=1;
                k--;
                arr.push({first.first, first.second - 2});
                continue;
            }
            second = arr.top();
            arr.pop();
            first.second = first.second - 1;
            second.second = second.second - 1;
            k--;
            if(second.second != 0)
            {
                arr.push(second);
            }
            if(first.second != 0)
            {
                arr.push(first);
            }
        }
        while(arr.empty() == false)
        {
            auto temp = arr.top();
            ans = ans + (temp.first*temp.second);
            arr.pop();
        }
        cout << ans << endl;
    }   
}

//1 10 10 1 10 2 7 10 3
//10 7 3 2 1
//4  1 1 1 2


 // abcdefgh
 // 3
 //1 abcdefgh
 //2 bacdefgh
 //3 cabdefgh
 //4 dbacefgh
 //5 ecabdfgh
 //6 fdbacegh
 //7 gecabdfh
 //8 hfdbaceg