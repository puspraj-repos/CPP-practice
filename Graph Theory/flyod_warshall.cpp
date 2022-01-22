#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int **graph = new int*[n];
    for(int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                graph[i][j] = INT_MAX/2;
            }
        }
    }
    int u, v, w;
    int e; 
    cin >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] < (graph[i][k] + graph[k][j]))
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
}