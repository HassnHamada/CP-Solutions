#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 18, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int upt[N], arr[N];
pair<int, int> cat;

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        ans += arr[i];
    }
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t & 1)
        {
            int i, x;
            scanf("%d%d", &i, &x);
            i -= 1;
            if (upt[i] != cat.first)
            {
                upt[i] = cat.first;
                arr[i] = cat.second;
            }
            ans += x - arr[i];
            arr[i] = x;
        }
        else
        {
            int x;
            scanf("%d", &x);
            ans = 1ll * x * n;
            cat = {cat.first + 1, x};
        }
        printf("%lld\n", ans);
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
