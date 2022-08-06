#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int dp[N][N];
char aaa[N], bbb[N];
int n, m, vid;

bool solve(int i, int j)
{
    if (j == m)
    {
        return true;
    }
    if (i == n)
    {
        return false;
    }
    int &ret = dp[i][j];
    if (ret == vid)
    {
        return false;
    }
    ret = vid;
    bool ok = solve(i + 1, j);
    if (!ok && aaa[i] == bbb[j])
    {
        ok = solve(i + 1, j + 1);
    }
    return ok;
}

void run()
{
    scanf("%d%d", &n, &m);
    scanf("%s", aaa);
    scanf("%s", bbb);
    bool ok = true;
    for (int i = 1; ok && i < m; i++)
    {
        ok = aaa[n - i] == bbb[m - i];
    }
    n = n - m + 1;
    m = 1;
    printf(ok && solve(0, 0) ? "YES\n" : "NO\n");
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
        vid += 1;
        run();
    }

    return 0;
}
