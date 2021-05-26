//source : http://www.usaco.org/index.php?page=viewproblem2&cpid=944

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e5+10;
const int MAX_INT = 2147483647;

int cows, pairs;
pair<int, int> coords[MAX]; //x,y
vector<int> adj[MAX]; //adjacency list
bool visited[MAX];
int minPerimeter = MAX_INT;
int currMinY=MAX_INT, currMinX=MAX_INT, currMaxY=0, currMaxX=0; 

void dfs(int node)
{
   visited[node] = true;
   //find the min and max x and y values for the connected component to later calculate the perimeter
   if(currMinY > coords[node].second) currMinY=coords[node].second;
   if(currMinX > coords[node].first) currMinX=coords[node].first;
   if(currMaxY < coords[node].second) currMaxY=coords[node].second;
   if(currMaxX < coords[node].first) currMaxX=coords[node].first;

   for(int u:adj[node])
   {
      if(!visited[u])
      {
         dfs(u);
      }
   }
}

int main()
{
   ios_base::sync_with_stdio(0); 
   cin.tie(0);
   freopen("fenceplan.in", "r", stdin);
   freopen("fenceplan.out", "w", stdout);
   
   cin >> cows >> pairs; 
   int x,y; 
   for(int i = 1; i<=cows; i++)  //getting coordinates of the cows
   {
      cin >> x >> y;
      coords[i].first = x;
      coords[i].second = y;
   }
   int a,b;
   for(int i = 0; i<pairs; i++) //constructin adjacency list
   {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a); 
   }
   int currPerimeter;
   for(int i = 1; i<=cows; i++)
   {
      //METHOD:
      //find the min and max points of the connected component
      //calculated perimeter
      //check if perimeter is smaller than the last calculated perimeter

      if(!visited[i])
      {
         dfs(i);

         currPerimeter = (currMaxY-currMinY)*2+(currMaxX-currMinX)*2; //calculate the perimeter
         minPerimeter = min(minPerimeter, currPerimeter); //check if its smaller than the current smallest perimter

         currMinX = MAX_INT;
         currMinY = MAX_INT;
         currMaxX = 0;
         currMaxY = 0;
      }
   }
   cout << minPerimeter;
}