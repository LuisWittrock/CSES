#include <iostream>
#include <vector>

//link to problem: https://cses.fi/problemset/task/1666/

using namespace std;

const int MN = 1e5+10;

int n, m, components = 0; //number of citys, number of streets
vector<int> adj_list[MN]; //adcecency list
bool visited[MN]; //keeps track of nodes visited
int connection[MN]; //keeps track of nodes from the different connected components

void dfs(int node) //runs dfs 
{
    visited[node] = true; //too know that we have already visited the node
    for(int u:adj_list[node])
    {
         if(!visited[u]) dfs(u); //run dfs on unvisited neighbours of the current node
    }
}

int countComponents()
{
    int count = 0;
    for(int i = 1; i<=n; ++i) 
    {
        if(!visited[i]) //run dfs on node that hasnt been visited to find a new connected component
        {
            connection[count++]=i; // safe a node from the connected component for later to know where to put edges
            dfs(i); 
        }
    }
    return count; //returns the amount of connected components in the graph
}

int main()
{
    
    int a,b;
    cin >> n >> m;
    
    for(int i = 0; i<m; i++) //construct adjecency list
    {
        cin >> a >> b;
        adj_list[a].push_back(b); //non directional graph representation
        adj_list[b].push_back(a);
    }
    components = countComponents();
    cout << components-1 << endl; //the number of edges needed to connect a graph is nodes-1 that also 
    //goes for connected components so we want connected components-1 as the amount of edges needed.

    for(int i = 1; i<components; ++i) 
    {
        cout << connection[i-1] << " " << connection[i] << endl; //in connection we keeped track of a node from every connected component now we just have to use them to make connections.
    }
}






