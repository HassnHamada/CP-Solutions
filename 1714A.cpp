#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 24 * 60, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];

void run()
{
    int n, h, m, ans = 59 + 23 * 60;
    scanf("%d%d%d", &n, &h, &m);
    m += h * 60;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        v += u * 60;
        v = (v - m + M) % M;
        ans = min(v, ans);
    }
    printf("%d %d\n", ans / 60, ans % 60);
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
