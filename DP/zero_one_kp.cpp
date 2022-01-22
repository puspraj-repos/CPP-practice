#include<bits/stdc++.h>
using namespace std;






int kp(int w, int profit, int counter, vector<int> cost, vector<int> weight)
{
    int max1 = profit, max2 = profit;
    if(counter >= 0)
    {
        max1 = kp(w, profit, counter - 1, cost, weight);
        if(w - weight[counter] >= 0)
        max2 = kp(w-weight[counter], profit + cost[counter], counter - 1, cost, weight);
        return max(max1, max2);
    }
    else 
    {
        return profit;
    }
}

int main()
{
    int n, w, item_cost, item_weight;
    cin >> n >> w;
    vector<int> cost, weight;
    for(int i = 0; i < n; i++)
    {
        cin >> item_cost >> item_weight;
        cost.push_back(item_cost);
        weight.push_back(item_weight);
    }
    int profit = kp(w, 0, n-1, cost, weight);
    cout << "profit " << profit;

}