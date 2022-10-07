#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int skl[M][N], typ[N];

void solve(int *ptr_0, int sz0, int *ptr_1, int sz1)
{
    ll ans = ptr_0[0], p = 0;
    while (true)
    {
        if (p)
        {
            if (sz0 == 1)
            {
                break;
            }
            ans += 2ll * ptr_0[--sz0];
        }
        else
        {

            if (sz1 == 0)
            {
                break;
            }
            ans += 2ll * ptr_1[--sz1];
        }
        p ^= 1;
    }
    while (sz0 > 1)
    {
        ans += ptr_0[--sz0];
    }
    while (sz1 > 0)
    {
        ans += ptr_1[--sz1];
    }
    printf("%lld\n", ans);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", typ + i);
    }
    int sz0 = 0, sz1 = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &skl[typ[i]][typ[i] ? sz1++ : sz0++]);
    }
    if (sz0 == 0 || sz1 == 0)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += skl[typ[i]][i];
        }
        printf("%lld\n", ans);
        return;
    }
    sort(skl[0], skl[0] + sz0);
    sort(skl[1], skl[1] + sz1);
    if (sz1 > sz0 || (sz0 == sz1 && skl[1][0] < skl[0][0]))
    {
        solve(skl[1], sz1, skl[0], sz0);
    }
    else
    {
        solve(skl[0], sz0, skl[1], sz1);
    }
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
