#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<ll> arr[M];

ll val(int ii)
{
    ll n = arr[ii].size(), ret = 0;
    for (int i = 1; i < n; i++)
    {
        ret += arr[ii][i] * (i + 1);
    }
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        arr[min(i, 2)].clear();
        arr[min(i, 2)].push_back(i + 1);
        for (int j = 0, v; j < m; j++)
        {
            scanf("%d", &v);
            arr[min(i, 2)].push_back(v);
        }
        if (i >= 2)
        {
            if (val(0) != val(2))
            {
                swap(arr[1], arr[2]);
            }
        }
    }
    ll v0 = val(0), v1 = val(1), v2 = val(2);
    assert(v0 != v1);
    if (v0 == v2)
    {
        printf("%lld %lld\n", arr[1][0], v1 - v2);
    }
    else
    {
        printf("%lld %lld\n", arr[0][0], v0 - v2);
    }
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
