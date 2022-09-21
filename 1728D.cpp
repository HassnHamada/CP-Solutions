#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 2e3 + 10, M = 26, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

char str[N];
int dp[N][N][M];

char ans[3][10] = {"Bob", "Alice", "Draw"};

int solve(int l, int r, char lc = '\0')
{
    if (r - l == 1)
    {
        return str[r] == str[l] ? 2 : 1;
    }
    int p = (r - l) & 1;
    int &ret = dp[l][r][p ? 0 : lc - 'a'];
    if (~ret)
    {
        return ret;
    }
    int r1 = solve(l + 1, r, str[l]), r2 = solve(l, r - 1, str[r]);
    if (r1 == p || r2 == p)
    {
        return ret = p;
    }
    if (p)
    {
        return ret = (r1 == 2 || r2 == 2 ? 2 : p ^ 1);
    }
    if ((r1 == 2 && str[l] < lc) || (r2 == 2 && str[r] < lc))
    {
        return ret = p;
    }
    if ((r1 == 2 && str[l] == lc) || (r2 == 2 && str[r] == lc))
    {
        return ret = 2;
    }
    return ret = p ^ 1;
}

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        memset((int *)(dp + i), -1, sizeof(dp[0][0]) * n);
    }
    printf("%s\n", ans[solve(0, n - 1)]);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}