#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char grd[N][N];

// bool ok(int n, int m)

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(grd + i));
    }

    auto ok = [&n, &m](char c) -> bool
    {
        bool u = false, d = false, l = false, r = false;
        for (int i = 0; i < n; i++)
        {
            l = l || (grd[i][0] == c);
            r = r || (grd[i][m - 1] == c);
        }
        for (int i = 0; i < m; i++)
        {
            u = u || (grd[0][i] == c);
            d = d || (grd[n - 1][i] == c);
        }
        return u && d && l && r;
    };
    bool b = ok('B'), w = ok('W');
    printf(b || w ? "YES\n" : "NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}