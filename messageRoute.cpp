//source : https://cses.fi/problemset/task/1667

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e5+10;

int n,m; //amount of computers, amount of connections
vector<int> connection[MAX]; //adjacency list
bool visited[MAX]; //keep track of already visited nodes
int parentNode[MAX]; //this will save the previous/parent node to every node[n]
bool found = false;

void bfs()
{
    queue<int> q;
    visited[1] = true;
    q.push(1);
    parentNode[1] = -1;
    while(!q.empty() && !found)
    {
        int node = q.front(); //bfs for the first element in the queue
        q.pop();

        for(auto u : connection[node]) //for every neighbour of the current node
        {
            if(visited[u]) continue; //if its already visited we already did all the steps for the node so we can skip it

            visited[u] = true; //no we have visited the node
            parentNode[u] = node; //the parent node of u is the element that was first in the queue becuase thats the element we are finding all the neighbours of
            q.push(u); // every neighbour node gets pushed in the queue to bfs on it

            if(u == n)
            {
                found = true; //if the node we are currently on is n we found the node we were looking for
                break;
            }
        }
    }
}
void findWay()
{
    vector<int> route;
    int curr = n;
    while(parentNode[curr] != -1) //we wanna find the exact shortest route which we do by backtracking our way from n to 1 by always going to the parent node of the curr node and saving every step in a vector
    {
        route.push_back(curr); //we save the current node in vector "route"
        curr = parentNode[curr]; //this is how we find the node that is before the current node
    }
    route.push_back(1);
    cout << route.size() << endl; //this is the distance
    for(int i = route.size()-1; i>=0; i--) //this is the shortest route
    {
        cout << route[i] << " ";
    }
}

int main()
{
    cin >> n >> m;
    int a, b;

    for(int i = 0; i<m; i++) //making adjacency list
    {
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    bfs();
    
    if(!found) cout << "IMPOSSIBLE"; //if we didnt find a way to the node n its impossible since there is no way.
    else findWay();
    
}