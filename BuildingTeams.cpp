//source : https://cses.fi/problemset/task/1668

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5+10;

int n,m; //n = number of students, m = number of friendships between them
vector<int> adjList[MAX]; //adjecency list to keep track of whos friends with who
bool color[MAX]; //keep track of the "color" of each node
bool visited[MAX]; //keep track of all the visited nodes
bool impossible = false;

void dfs(int node, bool c = false)
{
    visited[node] = true;
    color[node] = c;

    for(int u:adjList[node])
    {
        if(visited[u])
        {
            if(color[u] == c)
            {
                impossible = true;
            }
        }
        else
        {
            dfs(u, !c);
        }
    }
}

int main()
{
    int a,b;

    cin >> n >> m;

    for(int i = 0; i<m; i++)
    {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for(int i = 1; !impossible && i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    if(!impossible)
    {
        for(int i = 1; i<=n; i++)
        {
            if(color[i]) cout << "1 ";
            else cout << "2 ";
        }
    }
    else 
    {
        cout << "IMPOSSIBLE";
    }
}