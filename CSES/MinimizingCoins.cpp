#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll INF = 1e7;

int main()
{
    ll n,x;
    cin >> n >> x;
    ll coins[n];

    for(int i = 0; i<n; i++)
    {
        cin >> coins[i];
    }

    ll dp[x+1];

    for(int i = 0; i<=x; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i = 0; i<=x; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i-coins[j] >= 0) dp[i] = min(dp[i], dp[i-coins[j]]+1); //go back coins[j] in dp to see how we formed this sum and add one since we can use the coin by whose amount we were backtracking to form the new sum dp[i]
        }
    }
    if(dp[x] == INF) cout << -1;
    else cout << dp[x];
}