//source : https://cses.fi/problemset/task/1682

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5+10;

int cities, connections;
vector<int> adj[MAX], adjreverse[MAX];
bool visited[MAX], visited1[MAX];
bool possible = true;

void dfs1(int node)
{
   visited[node] = true;
   for(int i:adj[node])
   {
       if(!visited[i]) dfs1(i);
   }
}

void dfs2(int node) //here we use the reversed adj list so if we cant reach node i from node 1 it means normally we couldnt reach node 1 from i
{
    visited1[node] = true;
    for(int i:adjreverse[node])
    {
        if(!visited1[i]) dfs2(i);
    }
}


int main()
{
    int a,b;
    cin >> cities >> connections;
    
    for(int i = 0; i<connections; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adjreverse[b].push_back(a);
    }
    //check if all nodes are reachable from node 1
    dfs1(1); 
    for(int i = 1; i<=cities; i++)
    {
        if(!visited[i])
        {
            cout << "NO \n" << 1 << " " << i << endl; 
            possible = false;
        } 

    }
    //check if node 1 is reachable from every node
    dfs2(1);
    for(int i = 1; i<=cities; i++)
    {
        if(!visited1[i])
        {
            cout << "NO \n" << i << " " << 1 << endl; 
            possible = false;
        } 
    }
    
    
    //if we can reach node 1 from every node and we can reach every node from node 1
    if(possible) cout << "YES" << endl;
}