//source : https://cses.fi/problemset/task/1671

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

const int MAX = 1e5+10;
const long long MAX_LONGLONG_VAL =  9223372036854775807;
long long cities, flight;
long long dist[MAX];
vector<pair<long long, long long>> adj[MAX]; //connected node, weight of connection
priority_queue<pair<long long, long long>> q;
bool processed[MAX];

int main()
{

    for(int i = 2; i<MAX; i++) dist[i] = MAX_LONGLONG_VAL;
    dist[1] = 0;
    cin >> cities >> flight;
    long long a,b,w;

    for(int i = 0; i<flight; i++) //constructing adj list with weigths.
    {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }

    q.push(make_pair(0,1)); //Start of djikstra algorithm

    while(!q.empty())
    {
        a = q.top().second;
        q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u:adj[a])
        {
            b = u.first, w = u.second;
            if(dist[a]+w < dist[b])
            {
                dist[b] = dist[a]+w;
                q.push(make_pair(-dist[b], b));
            }
        }
    }

    for(int i = 1; i<=cities; i++)
    {
        cout << dist[i] << " ";
    }
}