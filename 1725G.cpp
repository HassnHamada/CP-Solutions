#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<pair<ll, pair<int, int>>> arr;

void run()
{
    int n;
    scanf("%d", &n);
    ll l = 3, h = INT64_MAX;
    while (h - l > 10)
    {
        assert(h > l);
        ll m = (h - l + 1) / 2 + l;
        if (m % 2 == 0)
        {
            m = (m + 3) / 4 * 4;
            if (m > h)
            {
                m -= 4;
            }
        }
        assert(m <= h);
        assert(m > l);
        if ((m + 1) / 2 + m / 4 - 1 - (m >= 4) > n)
        {
            h = m - 1;
        }
        else
        {
            l = m;
        }
    }
    while (l < h)
    {
        if ((l + 1) / 2 + l / 4 - 1 - (l >= 4) < n)
        {
            l = l + 1;
        }
        else
        {
            break;
        }
    }
    printf("%lld\n", l);
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