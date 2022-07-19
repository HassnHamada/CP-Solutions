#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e1 + 10, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bool ok(int l, int r)
{
    int n = r - l + 1, ret = 0;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        ret += (v >= l && v <= r ? 1 : 0);
    }
    return ret & 1;
}

void run()
{
    int n;
    scanf("%d", &n);
    int l = 1, h = n;
    while (l < h)
    {
        int m = (h - l) / 2 + l;
        printf("? %d %d\n", l, m);
        fflush(stdout);
        // scanf("%d", &v);
        if (ok(l, m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("! %d\n", l);
    fflush(stdout);
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
