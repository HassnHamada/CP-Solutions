#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char inp[M][N];
set<int> dir[M];

int msk(int x)
{
    int ret = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            auto it = dir[i].find(j + x);
            ret |= (it != dir[i].end()) << (i + 2 * j);
        }
    }
    assert(ret < (1 << 4));
    return ret;
}

int dp[N][M][1 << 4];

int solve(int x, int y)
{

    int &ret = dp[x][y][msk(x)];
    if (~ret)
    {
        return ret;
    }
    if (dir[0].empty() || dir[1].empty())
    {
        return ret = 0;
    }
    auto t0 = *dir[0].begin(), t1 = *dir[1].begin();
    assert((y == 0 ? t0 : t1) > x);
    assert((y == 0 ? t1 : t0) >= x);
    int d0 = t0 - x + (y == 1), d1 = t1 - x + (y == 0);
    if (d0 == d1)
    {
        dir[0].erase(dir[0].begin());
        dir[1].erase(dir[1].begin());
        ret = 1 + min(solve(t0, 0), solve(t1, 1));
        dir[0].insert(t0);
        dir[1].insert(t1);
    }
    else if (d0 < d1)
    {
        dir[0].erase(dir[0].begin());
        ret = min(solve(t0, 0), solve(x, y) + 1);
        dir[0].insert(t0);
    }
    else
    {
        dir[1].erase(dir[1].begin());
        ret = min(solve(t1, 1), solve(x, y) + 1);
        dir[1].insert(t1);
    }
    return ret;
}

void run()
{
    int n, d = 0;
    scanf("%d", &n);
    for (int j = 0; j < M; j++)
    {
        scanf("%s", (char *)(inp + j));
        for (int i = 0; i < n; i++)
        {
            if (inp[j][i] == '1')
            {
                dir[j].insert(i);
                d++;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", d - solve(0, 0));
}

// 16
// 0000101101101100
// 0010101100101000

// 10
// 0101101110
// 0100111010

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}