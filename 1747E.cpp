#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<int, ll> dp[N][N];
int n, m;

ll solve(int a, int b, int l = 1)
{
    assert(a <= n);
    assert(b <= m);
    if (a == n && b == m)
    {
        return l;
    }
    if (dp[a][b].find(l) == dp[a][b].end())
    {
        ll ret = 0;
        for (int i = b + 1; i <= m; i++)
        {
            ret = (ret + solve(a, i, l + 1)) % MOD;
        }
        for (int i = a + 1; i <= n; i++)
        {
            ret = (ret + solve(i, b, l + 1)) % MOD;
        }
        for (int i = a + 1; i <= n; i++)
        {
            for (int j = b + 1; j <= m; j++)
            {
                ret = (ret + solve(i, j, l + 1)) % MOD;
            }
        }
        dp[a][b].emplace(l, ret);
    }
    return dp[a][b][l];
}

void run()
{
    // scanf("%d%d", &n, &m);
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            n = i;
            m = j;
            printf("%lld\t\t\t", solve(0, 0) % MOD);
            for (int ii = 0; ii <= n; ii++)
            {
                for (int jj = 0; jj <= m; jj++)
                {
                    dp[ii][jj].clear();
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}