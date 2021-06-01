//source : https://open.kattis.com/problems/birthday

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int p, c;
bool adj[100][100];
bool visited[100];

void dfs(int node)
{
    visited[node] = true;

    for(int i = 0; i<p; i++)
    {
        if(adj[node][i] && !visited[i])
        {
            dfs(i);
        }
    }
}

void solve()
{
    memset(adj, false, sizeof(adj));
    vector<pair<int, int>> edge;
    for(int i = 0; i<c; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
        edge.push_back(make_pair(a,b));
    }

    for(pair<int, int> x : edge)
    {
        adj[x.first][x.second] = false;
        adj[x.second][x.first] = false;
        memset(visited, false, sizeof(visited));

        dfs(0);

        for(int i = 0; i<p; i++)
        {
            if(!visited[i])
            {
                cout << "YES \n";
                return;
            }
        }


        adj[x.first][x.second] = true;
        adj[x.second][x.first] = true;
    }
    cout << "NO \n";
}

int main()
{
    while(cin >> p >> c && (p || c))
    {
        solve();
    }     
}