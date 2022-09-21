#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    ll g = 0;
    for (int i = 1; i < n; i++)
    {
        g = __gcd(g, abs(arr[i] - arr[0]));
    }
    for (ll i = 0, v; i < m; i++)
    {
        scanf("%lld", &v);
        printf("%lld%c", __gcd(g, arr[0] + v), " \n"[i + 1 == m]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}