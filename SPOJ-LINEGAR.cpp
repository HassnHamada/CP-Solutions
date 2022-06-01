#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5, M = 1e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int n, m, dp[N][5][3][3][2];
char str[N];

int solve(int c, int x, int y, int z, int p)
{
    if (x == -1 || x == 5 || y == 3 || z == 3)
    {
        return 0;
    }
    if (c == n)
    {
        return 1;
    }
    int &ret = dp[c][x][y][z][p];
    if (~ret)
    {
        return ret;
    }
    if (p)
    {
        return ret = (solve(c + 1, x + 1, y + 1, 0, 1) + solve(c + 1, x - 1, 0, z + 1, 1)) % m;
    }
    if (str[c] == 'L')
    {
        assert(y != 2);
        return ret = solve(c + 1, x + 1, y + 1, 0, 0);
    }
    assert(z != 2);
    return ret = (solve(c + 1, x + 1, y + 1, 0, 1) + solve(c + 1, x - 1, 0, z + 1, 0)) % m;
}

void run()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d%d%s", &n, &m, str);
    printf("%d\n", solve(0, 2, 0, 0, 0));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}