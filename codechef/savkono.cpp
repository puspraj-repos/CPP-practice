#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<int> queue;
        int n, z;
        cin >> n >> z;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            queue.push(x);
        }
        int count = 0;
        int sum = 0, temp;
        while (queue.empty() != true and sum < z)
        {
            temp = queue.top();
            sum += temp;
            //cout << temp << " ";
            count++;
            queue.pop();
            temp = temp/2;
            if(temp != 0)
            {
                queue.push(temp);
            }
        }
        //cout << endl;
        if (sum >= z)
        {
            cout << count << endl;
        }
        else
        {
            cout << "Evacuate" << endl;
        }
    }
}