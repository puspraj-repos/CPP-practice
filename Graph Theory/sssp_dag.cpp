
// Single source shortest path, this technique can also be used to find the longest path in a DAG, make all weights as negative.


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

vector<vector<int>> weight;

int top_sort(vector<int> in_degree, vector<int> &topsort)
{
    queue<int> no_dependents;
    int no_of_nodes = in_degree.size();

    for(int i = 0; i < no_of_nodes; i++)
    {
        if(in_degree[i] == 0)
        {
            no_dependents.push(i);
        }
    }
    while(no_dependents.empty() == false)
    {
        int node = no_dependents.front();
        topsort.push_back(node);
        no_dependents.pop();
        int node_out_degree = graph[node].size();
        for(int i = 0; i < node_out_degree; i++)
        {
            in_degree[graph[node][i]]--;
            if(in_degree[graph[node][i]] == 0)
            {
                no_dependents.push(graph[node][i]);
            }
        }
    }
    if(topsort.size() != no_of_nodes)
    {
        return -1;
    }
    else return 0;
}

void display_vector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n, edges, v, w;
    cin >> n;
    graph.resize(n);
    weight.resize(n);
    vector<int> in_degree(n,0);
    for(int i = 0; i < n; i++)
    {
        cin >> edges;
        for(int j = 0; j < edges; j++)
        {
            cin >> v >> w;
            graph[i].push_back(v);
            weight[i].push_back(w); 
            in_degree[v]++;
        }
    }
    vector<int> topsort;
    int verdict = top_sort(in_degree, topsort);
    vector<int> sssp(n, INT_MAX);
    if(verdict != -1)
    {
        sssp[topsort[0]] = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < graph[topsort[i]].size(); j++)
            {
                int temp_weight = sssp[topsort[i]] + weight[topsort[i]][j];
                if (temp_weight < sssp[graph[topsort[i]][j]])
                {
                    sssp[graph[topsort[i]][j]] = temp_weight;
                }
            }
        } 


        display_vector(sssp);
        display_vector(topsort); 
    }
    else 
    {
        cout << "cycle detected" << endl;
    }
}