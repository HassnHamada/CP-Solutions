#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char buf[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (ll i = 0, s = 1, t = 1; i < n; i++)
    {
        int d, k;
        scanf("%d%d%s", &d, &k, buf);
        int m = strlen(buf), a = count(buf, buf + m, 'a');
        if (a < m)
        {
            (d & 1 ? s : t) = -1;
        }
        else if (~(d & 1 ? s : t))
        {
            (d & 1 ? s : t) += 1ll * k * m;
        }
        if (t == -1)
        {
            printf("YES\n");
        }
        else if (s == -1)
        {
            printf("NO\n");
        }
        else
        {
            assert(s > 0 && t > 0);
            printf(s < t ? "YES\n" : "NO\n");
        }
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
