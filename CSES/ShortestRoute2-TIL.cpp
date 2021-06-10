//source : https://cses.fi/problemset/task/1672

#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;
const int INF = 2147483;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int cities, roads, query;
vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> queries;
int dist[MAX];
bool processed[MAX];

int main()
{
    cin >> cities >> roads >> query;

    int a,b,w;

    

    for(int i = 0; i<roads; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }

    for(int i = 0; i<query; i++)
    {
        cin >> a >> b;
        queries.push_back(make_pair(a, b));
    }

    priority_queue<pair<int, int>> q;
    for(auto route:queries)
    {
        
        while(!q.empty()) q.pop();

        //find shortest path between route.first and route.second if there is no path print -1
        memset(dist, 0x3f, sizeof dist);
        memset(processed, false, sizeof processed);

        dist[route.first] = 0;
        //dijkstra
        
        q.push(make_pair(0, route.first));

        while(!q.empty())
        {
            //cout << route.first << " -> " << route.second << endl;
            a = q.top().second;
            q.pop();

            if(processed[a]) continue;
            processed[a] = true;

            for(auto u:adj[a])
            {
                b = u.first;
                w = u.second;

                if(dist[a]+w < dist[b])
                {
                    dist[b] = dist[a]+w;
                    q.push(make_pair(-dist[b],b));
                }
            }
        }
        if(dist[route.second] != 1061109567) cout << dist[route.second] << endl;
        else cout << -1 << endl;
        
    }
}