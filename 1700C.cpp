#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, L = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N], rev[N];
int n;

ll calc(ll *ptr)
{
    ll ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (ptr[i] > ptr[i + 1])
        {
            ll v = ptr[i] - ptr[i + 1];
            ptr[0] -= v;
            ret += v;
        }
    }
    if (ptr[0] < 0)
    {
        ret += ptr[n - 1] - 2 * ptr[0];
    }
    else
    {
        ret += ptr[n - 1];
    }
    return ret;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
        rev[n - i - 1] = arr[i];
    }
    ll ans = min(calc(arr), calc(rev));
    printf("%lld\n", ans);
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
