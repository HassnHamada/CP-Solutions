#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

ll arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n);
    map<ll, set<ll>, greater<ll>> mnums;
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                ok = false;
                break;
            }
            ll a = arr[j] - arr[i], b = arr[i] % a;
            if (a == 1)
            {
                continue;
            }
            mnums[a].insert((a - b) % a);
            if ((int)mnums[a].size() == a)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
    {

        for (auto &&[i, j] : mnums)
        {
            // for (auto &&k : j)
            // {
            //     cout << i << " " << k << endl;
            // }
            for (auto &&[k, l] : mnums)
            {
                if (k <= i)
                {
                    break;
                }
                if (i % k)
                {
                    continue;
                }
                for (auto &&m : l)
                {
                    if (m >= i)
                    {
                        continue;
                    }
                    bool add = true;
                    for (ll o = 0; add && o * i + m < k; o++)
                    {
                        add = l.find(o * i + m) != l.end();
                    }
                    if (add)
                    {
                        j.insert(m % i);
                    }
                }
            }
            if ((int)j.size() == i)
            {
                ok = false;
                break;
            }
        }
    }
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}