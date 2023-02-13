#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N], qqq[N], pos[N], posq[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        pos[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", qqq + i);
        posq[qqq[i]] = i;
    }
    ll mn = min(pos[1], posq[1]), mx = max(pos[1], posq[1]);
    ll ans = mn * (mn + 1) / 2 + (n - mx) * (n - mx - 1) / 2 + (mx - mn) * (mx - mn - 1) / 2;
    pair<int, int> r1 = {pos[1], pos[1]},
                   r2 = {posq[1], posq[1]};
    for (int i = 2; i <= n; i++)
    {
        pair<ll, ll> r = {min(r1.first, r2.first),
                          max(r1.second, r2.second)};
        // cout << r.first << " " << r.second << endl;
        if ((pos[i] >= r.first && pos[i] <= r.second) || (posq[i] >= r.first && posq[i] <= r.second))
        {
            // pass
            // cout << i << " 0" << endl;
        }
        else
        {
            ll l = 0, h = n - 1;
            if (pos[i] < r.first)
            {
                if (posq[i] < r.first)
                {
                    l = max(pos[i], posq[i]) + 1;
                }
                else
                {
                    assert(posq[i] > r.second);
                    l = pos[i] + 1;
                    h = posq[i] - 1;
                }
            }
            else
            {
                assert(pos[i] > r.second);
                if (posq[i] > r.second)
                {
                    h = min(pos[i], posq[i]) - 1;
                }
                else
                {
                    assert(posq[i] < r.first);
                    l = posq[i] + 1;
                    h = pos[i] - 1;
                }
            }
            // cout << i << " " << l << " " << h << endl;
            ll tem = (r.first - l + 1) * (h - r.second + 1);
            // cout << tem << endl;
            ans += tem;
        }
        r1 = {min(pos[i], r1.first), max(pos[i], r1.second)};
        r2 = {min(posq[i], r2.first), max(posq[i], r2.second)};
    }
    printf("%lld\n", ans + 1);
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