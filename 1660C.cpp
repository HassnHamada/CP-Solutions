#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n;
int dp[N][M];
char str[N];

int dfs(int c, int p)
{
    if (c == n)
    {
        return p == 0 ? 0 : 1;
    }
    if (dp[c][p] == -1)
    {
        if (p)
        {
            dp[c][p] = dfs(c + 1, p) + 1;
            if (str[c] - 'a' + 1 == p)
            {
                dp[c][p] = min(dp[c][p], dfs(c + 1, 0));
            }
        }
        else
        {
            dp[c][p] = min(dfs(c + 1, p) + 1, dfs(c + 1, str[c] - 'a' + 1));
        }
    }
    return dp[c][p];
}

void run()
{
    scanf("%s", str);
    n = strlen(str);
    memset(dp, -1, sizeof(dp[0]) * n);
    printf("%d\n", dfs(0, 0));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
