//source : http://www.usaco.org/index.php?page=viewproblem2&cpid=644

#include <iostream> 
#include <vector>

using namespace std;
    
const int MAX = 3000;

int barns, connections;
vector<int> adj[MAX];
bool visited[MAX], closed[MAX];
int ans;

void dfs(int node)
{
    visited[node] = true;

    for(int i : adj[node])
    {
        if(!visited[i] && !closed[i]) dfs(i);
    }
}
void countComponents()
{
    ans = 0;
    for(int i = 1; i<=barns; i++)
    {
        if(!visited[i] && !closed[i])
        {
            ans++;
            dfs(i);
        }
    }
    
    if(ans > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

    cin >> barns >> connections;
    for(int i = 0; i<connections; i++) //creating adjacency list
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); //bidirectional
        adj[b].push_back(a);
    }
    for(int i = 0; i<barns; i++)
    {
        countComponents();
        int x;
        cin >> x; 
        closed[x] = true;
        
        for(int i = 1; i<=barns; i++)
        {
            visited[i] = false;
        }
    } 
}