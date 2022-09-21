#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k, g = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        g = __gcd(g, v % k);
    }
    g = __gcd(g, k);
    printf("%d\n", k / g);
    for (int i = 0; i < k; i++)
    {
        if (i % g == 0)
        {
            printf("%d ", i);
        }
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