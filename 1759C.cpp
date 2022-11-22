#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int l, r, x, a, b;
    scanf("%d%d%d%d%d", &l, &r, &x, &a, &b);
    int ans = a == b ? 0 : INF;
    if (abs(a - b) >= x)
    {
        ans = min(ans, 1);
    }
    if (abs(a - l) >= x)
    {
        if (abs(l - b) >= x)
        {
            ans = min(ans, 2);
        }
        else if (abs(r - b) >= x)
        {
            assert(abs(r - b) >= x);
            ans = min(ans, 3);
        }
    }
    if (abs(a - r) >= x)
    {
        if (abs(r - b) >= x)
        {
            ans = min(ans, 2);
        }
        else if (abs(l - b) >= x)
        {
            assert(abs(l - b) >= x);
            ans = min(ans, 3);
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
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
