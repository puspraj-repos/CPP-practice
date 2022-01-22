#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> visited)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
    }

int dfs(int r, int c, vector<vector<int>> &visited, vector<vector<int>> &matrix, int row, int col)
    {
        if(visited[r][c] != 0)
        {
            return visited[r][c];
        }
        int u = 1, d = 1, l = 1, right = 1;
        if(r + 1 < row)
        {
            if(matrix[r + 1][c] > matrix[r][c])
            {
                d =  1 + dfs(r+1, c, visited, matrix, row, col);
            }
        }
        if(c + 1 < col)
        {
            if(matrix[r][c+ 1] > matrix[r][c])
            {
                right =  1 + dfs(r, c+1, visited, matrix, row, col);
            }
        }
        if(r - 1 >= 0)
        {
            if(matrix[r-1][c] > matrix[r][c])
            {
                if(r == 1 and c == 0)
                {
                    cout << " hi" << endl;
                }
                u =  1 + dfs(r-1, c, visited, matrix, row, col);
            }
        }
        if(c - 1 >= 0)
        {
            if(matrix[r][c-1] > matrix[r][c])
            {
                l = 1 + dfs(r, c-1, visited, matrix, row, col);
            }
        }
        
        visited[r][c] = max(max(max(u,d),l),right);
        return visited[r][c];
    }


int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> visited(m);
        for(int i = 0; i < m; i++)
        {
            visited[i].resize(n, 0);
        }
        int ans = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = dfs(i, j, visited, matrix, m, n);
                if(temp > ans)
                {
                    ans = temp;
                }
            }
        }
        display(visited);
        return ans;
    }

    int main()
    {
        vector<vector<int>> matrix(3);
        int x;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> x;
                matrix[i].push_back(x);

            }
        }
        int ans = longestIncreasingPath(matrix);
    }