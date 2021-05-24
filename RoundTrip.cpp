//source : https://cses.fi/problemset/task/1669

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5+10;

int cities, roads, start;
vector<int> adj_list[MAX]; //the adjacency list
bool visited[MAX]; //keep track of already visited nodes
int previous[MAX]; //save for every node the parent node (for construction the path later)
bool found = false; //tells if we found a path or not

void dfs(int node)
{
    if(visited[node]) //if we have already visited the node it means that we found a path
    {
        found = true;
        start = node; //we know that node must be the starting point

        int end = start;
        int count = 0; //keeps track of how many cities we visit
        vector<int> route; //keep track of the path
        route.push_back(end);
        do
        {
            route.push_back(previous[end]); //constructing the way by finding the parent node for every node until we reach the starting point again
            end = previous[end];
            count++;
        } while(end != start);

        cout << count+1 << endl;

        for(int i : route)
        {
            cout << i << " ";
        }
        exit(0);
    }

    visited[node] = true; //we are on the node so we have visited it
    for(int u : adj_list[node]) //just simple dfs
    {
        if(u != previous[node]) //since we must have atleast 2 cities in between our starting point we cant go back to the city where our parent node has been
        {
            previous[u] = node;
            dfs(u);
        }
        
    }
}

int main()
{
    int a,b;
    cin >> cities >> roads;
    
    for(int i = 0; i<roads; i++) //making the adjacency list
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for(int i = 1; i<cities; i++) //run dfs until there are no unvisited nodes
    {
        if(!visited[i]) dfs(i);        
    }
    
    if(!found) //if we havent found a possible path there is none
    { 
        cout << "IMPOSSIBLE \n";
    }
   
    
}