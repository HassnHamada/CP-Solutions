#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
int arr[N], n;
ll e, o;

bool ok(ll m)
{
    ll ce = m / 2, co = (m + 1) / 2;
    if (co < o)
    {
        return false;
    }
    co -= o;
    return ce + co / 2 >= e;
}

bool ok2(ll m)
{
    ll ce = m / 2, co = (m + 1) / 2;
    if (co < n - o)
    {
        return false;
    }
    co -= n - o;
    return ce + co / 2 >= e + o;
}

void run()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mx = max(mx, arr[i]);
    }
    e = o = 0;
    for (int i = 0; i < n; i++)
    {
        e += (mx - arr[i]) / 2;
        o += (mx - arr[i]) & 1;
    }
    ll l = 0, h = 1ll << 60;
    while (l < h)
    {
        ll m = l + (h - l) / 2;
        // cout << l << " " << h << " " << m << endl;
        if (ok(m) || ok2(m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    printf("%lld\n", h);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}