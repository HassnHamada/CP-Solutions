#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    ll n, k, b, s;
    scanf("%lld%lld%lld%lld", &n, &k, &b, &s);
    // cout << ((b * k <= s) && (s < (b + n) * k)) << endl;
    if (b * k <= s && s <= k * (b + 1) - 1 + (n - 1) * (k - 1))
    {
        vector<ll> ans;
        ans.push_back(min(k * (b + 1) - 1, s));
        s -= ans.back();
        if (k > 1)
        {
            int m = (s + k - 1 - 1) / (k - 1);
            assert(m < n);
            for (int i = 0; i < m; i++)
            {
                ans.push_back(min(k - 1, s));
                s -= ans.back();
            }
        }
        assert(s == 0);
        while ((int)ans.size() < n)
        {
            ans.push_back(0);
        }
        assert((int)ans.size() == n);
        for (auto &&i : ans)
        {
            printf("%lld ", i);
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
    // printf("%d\n", m == 1 ? 0 : 2 * (n - 1) + (m - 1) + 1);
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