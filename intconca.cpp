#include <bits/stdc++.h>
using namespace std;

int process(int n, long long l, long long r, vector<int> arr);
int lowest(int current, int start, int end, long long l, vector<int> arr);
int highest(int current, int start, int end, long long r, vector<int> arr);
long long compute(long long a, long long b);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        long long ans = process(n, l, r, arr);
        cout << ans << endl;
    }
}

int process(int n, long long l, long long r, vector<int> arr)
{
    int result1, result2;
    long long ans = 0;
    for (int i = n / 2; i < n; i++)
    {
        result2 = highest(i, 0, n - 1, r, arr);
        // cout << "Result1: " << result1 << endl;
        if (result2 != -1)
        {
            result1 = lowest(i, 0, n - 1, l, arr);
            // cout << "Result2: " << result2 << endl;
            if (result1 != -1)
            {
                ans = ans + result2 - result1 + 1;
            }
        }
        else break;
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        result1 = lowest(i, 0, n - 1, l, arr);
        // cout << "Result1: " << result1 << endl;
        if (result1 != -1)
        {
            result2 = highest(i, 0, n - 1, r, arr);
            // cout << "Result2: " << result2 << endl;
            if (result2 != -1)
            {
                ans = ans + result2 - result1 + 1;
            }
        }
        else break;
    }
        return ans;
}

// int lowest(int current, int start, int end, long long l, vector<int> arr)
// {
//     int low = start, high = end, returnvalue = -1;
//     int mid = (low + end) / 2;
//     long long ans;
//     string formation = "", current_str = to_string(arr[current]);
//     while (low <= high)
//     {
//         formation = current_str + to_string(arr[mid]);
//         ans = stoll(formation);
//         if (ans >= l)
//         {
//             high = mid - 1;
//             returnvalue = mid;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//         mid = (low + high) / 2;
//     }
//     return returnvalue;
// }

// int highest(int current, int start, int end, long long r, vector<int> arr)
// {
//     int low = start, high = end, returnvalue = -1;
//     int mid = (low + high) / 2;
//     long long ans;
//     string formation = "", current_str = to_string(arr[current]);
//     while ( low <= high)
//     {
//         formation = current_str + to_string(arr[mid]);
//         ans = stoll(formation);
//         if(ans <= r)
//         {
//             returnvalue = mid;
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//         mid = (low + high) / 2;
//     }
//     return returnvalue;
// }

int lowest(int current, int start, int end, long long l, vector<int> arr)
{
    int low = start, high = end, returnvalue = -1;
    int mid = (low + end) / 2;
    long long ans;
    while (low <= high)
    {
        ans = compute(arr[current], arr[mid]);
        if (ans >= l)
        {
            high = mid - 1;
            returnvalue = mid;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return returnvalue;
}
int highest(int current, int start, int end, long long r, vector<int> arr)
{
    int low = start, high = end, returnvalue = -1;
    int mid = (low + high) / 2;
    long long ans;
    while (low <= high)
    {
        ans = compute(arr[current], arr[mid]);
        if (ans <= r)
        {
            returnvalue = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    return returnvalue;
}

long long compute(long long a, long long b)
{
    if (b >= 10000000)
    {
        return a * 100000000 + b;
    }
    else if (b >= 1000000)
    {
        return a * 10000000 + b;
    }
    else if (b >= 100000)
    {
        return a * 1000000 + b;
    }
    else if (b >= 10000)
    {
        return a * 100000 + b;
    }
    else if (b >= 1000)
    {
        return a * 10000 + b;
    }
    else if (b >= 100)
    {
        return a * 1000 + b;
    }
    else if (b >= 10)
    {
        return a * 100 + b;
    }
    else
    {
        return a * 10 + b;
    }
}