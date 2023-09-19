#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e4 + 10;

int dp[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, -1, sizeof dp);
    dp[m] = 0;
    queue<int> q({m});
    while (!~dp[n])
    {
        int f = q.front();
        q.pop();
        if (!~dp[f + 1] && f + 1 < N)
        {
            q.push(f + 1);
            dp[f + 1] = dp[f] + 1;
        }
        if (f && (f & 1) ^ 1 && !~dp[f >> 1])
        {
            q.push(f >> 1);
            dp[f >> 1] = dp[f] + 1;
        }
    }
    printf("%d\n", dp[n]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    run();
    return 0;
}