//source : https://cses.fi/problemset/task/1192

#include <iostream>
#include <vector>


using namespace std;

const int MAX = 1000;

int columns, rows, count = 0;
string map[MAX];
bool visited[MAX][MAX];

void floodfill(int y, int x)
{
    if(y >= rows || x >= columns || y < 0 || x < 0) return;
    if(visited[y][x]) return;
    visited[y][x] = true;
    if(map[y][x] == '#') return;

    floodfill(y+1, x);
    floodfill(y-1, x);
    floodfill(y, x+1);
    floodfill(y, x-1); 
}

int main()
{
    cin >> rows >> columns;

    for(int i = 0; i<rows; i++)
    {
        cin >> map[i];
    }
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
        {
            if(!visited[i][j] && map[i][j] != '#')
            {
                floodfill(i, j);
                count++;
            }
        }
    }
    cout << count;
}