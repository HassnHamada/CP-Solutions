#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n;
    scanf("%lld", &n);
    ll l = 1, h = n * n;
    while (l < h)
    {
        ll m = (h - l) / 2 + l, v = 0;
        for (int i = 1; i <= n; i++)
        {
            v += min(n, m / i);
        }
        // cout << l << " " << h << " " << m << " " << v << endl;
        if (v <= n * n / 2)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    printf("%lld\n", l);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}