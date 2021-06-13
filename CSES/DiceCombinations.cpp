//source : https://cses.fi/problemset/task/1633

#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const ll NUM = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    vector<int> dice;

    for(int i = 1; i<=6; i++)
    {
        dice.push_back(i);
    }

    dp[0] = 1;

    for(ll i = 0; i<=n; i++)
    {
        for(auto j:dice)
        {
            if(i-j >= 0) dp[i] = (dp[i] + dp[i-j]) % NUM;
        }
    }

    cout << dp[n];
}