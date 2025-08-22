#include<bits/stdc++.h>
using namespace std;

int n,m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

vector<int> v;
int cnt = 0;

void dfs(int si, int sj)
{
    // cout << grid[si][sj];
    cnt ++;
    visited[si][sj] = true;

    for(int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;


        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
        {
            dfs(ci, cj);
        }
    }
    
}


int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];


    memset(visited, false, sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && grid[i][j] != '#')
            {
               dfs(i, j);
            //    cout << cnt;
               v.push_back(cnt); 
               cnt = 0;
            }
        }
    }

    sort(v.begin(), v.end());

    if(v.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        for(int x : v)
            cout << x << " ";
    }

    return 0;
}
