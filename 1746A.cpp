#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k, o = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        o += v;
    }
    printf(o ? "YES\n" : "NO\n");
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
