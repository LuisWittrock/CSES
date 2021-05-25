//source : http://www.usaco.org/index.php?page=viewproblem2&cpid=668
//I needed half the time to just understand the problem statement since it was kinda unclear what was wanted coded completely the wrong exersice once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 200;

int cows;
vector<int> adj[MAX];
bool visited[MAX];
int arr[MAX][3];
int best = 1;

void dfs(int node)
{
    if(visited[node]) return;
    visited[node] = true;
    for(int u:adj[node])
    {
        
        if(!visited[u])
        {
            best++;
            dfs(u);
        }
    }
}
int dist(int i, int j)
{
    return (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);
}

int main()
{
    int x,y,p;
    
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

    cin >> cows;

    //getting info of the cows

    for(int i = 0; i<cows; i++)
    {
        cin >> x >> y >> p;
        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = p;
    }

    //constructing the graph

    for(int i = 0; i<cows; i++)
    {
        for(int j = 0; j<cows; j++)
        {
            //calculate distance
            int distance = dist(i,j);
            if(i != j && distance <= arr[i][2] * arr[i][2]) adj[i].push_back(j);
        }
    }
    int sol = 0;
    //checking for the node with the most neighbours
    for(int i = 0; i<cows; i++)
    {
        fill(visited, visited+cows, false);
        best = 1;
        dfs(i);
        sol = max(best, sol);
        
        
    }

    cout << sol << endl;
}