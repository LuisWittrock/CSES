//source : https://cses.fi/problemset/task/1193

#include <iostream> 
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000;

bool visited[MAX][MAX];
char map[MAX][MAX];
int previousStep[MAX][MAX];
int columns, rows;
pair<int, int> start;
pair<int, int> destination;

//0 = up, 1 = down, 2 = right, 3 = left
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
char direction[4] = {'U','D','R','L'};

void bfs()
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {
            pair<int, int> v = make_pair(u.first+dy[i], u.second+dx[i]);
            if(v.first >= rows || v.first < 0 || v.second < 0 || v.second >= columns) continue; //edge cases
            if(map[v.first][v.second] == '#') continue;
            if(visited[v.first][v.second]) continue;
            visited[v.first][v.second] = true; //we are on it so we have visited it
            previousStep[v.first][v.second] = i; //the step we used (U,D,R,L) gets saved cause we need it later to construct the path
            q.push(v); //v gets added to the queue to run bfs on it later
        }
    }
    if(visited[destination.first][destination.second]) //if we visited the destination with bfs we know there is a valid path
    {
        cout << "YES" << endl;
        vector<int> route;

        while(destination != start)
        {
            int p = previousStep[destination.first][destination.second];
            route.push_back(p);
            destination = make_pair(destination.first - dy[p], destination.second - dx[p]); //backtracking the steps
        }
        reverse(route.begin(), route.end());
        
        cout << route.size() << endl;

        for(int i : route)
        {
            cout << direction[i];
        }
    }
    else 
    {
        cout << "NO";
    }
}

int main()
{
   cin >> rows >> columns; 
   
   queue<pair<int, int>> q;

   for(int i = 0; i<rows; i++) //constructing the map
   {
       for(int j = 0; j<columns; j++)
       {
           cin >> map[i][j];
           if(map[i][j] == 'A') 
           {
               start.first = i; 
               start.second = j;
           }
           else if(map[i][j] == 'B')
           {
               destination.first = i;
               destination.second = j;
           }
       }
   }
   bfs();
}