//source : https://cses.fi/problemset/task/1637

#include <iostream>
#include <sstream>

using namespace std;

const int INF = 1e6;

int main()
{
    int n;
    cin >> n;
    int dp[n+1];

    for(int i = 0; i<=n; i++) dp[i] = INF;

    dp[0] = 0;

    for(int i = 1; i<=n; i++)
    {
        string digits;
        stringstream ss;
        ss << i;
        digits = ss.str();
        for(int j = 0; j<digits.length(); j++)
        {
            int num = digits[j]-'0';
            if(i - num >= 0) dp[i] = min(dp[i], dp[i-num]+1);
        }
    }
    cout << dp[n];
}