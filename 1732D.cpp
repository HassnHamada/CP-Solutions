#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

map<ll, ll> ans;
map<ll, set<ll>> rem, in;
set<ll> nums;

void run()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char c;
        ll x;
        scanf("\n%c%lld", &c, &x);
        if (c == '+')
        {
            nums.insert(x);
            for (auto &&i : in[x])
            {
                assert(x % i == 0);
                assert(ans[i] > x / i);
                rem[i].erase(x / i);
            }
        }
        else if (c == '-')
        {
            nums.erase(x);
            for (auto &&i : in[x])
            {
                assert(x % i == 0);
                assert(ans[i] > x / i);
                rem[i].insert(x / i);
            }
        }
        else if (c == '?')
        {
            if (ans.find(x) == ans.end())
            {
                ans.insert({x, 1});
            }
            if (rem[x].empty())
            {
                while (nums.find(ans[x] * x) != nums.end())
                {
                    in[ans[x]++ * x].insert(x);
                }
                printf("%lld\n", ans[x] * x);
            }
            else
            {
                printf("%lld\n", (*rem[x].begin()) * x);
            }
        }
        else
        {
            assert(false);
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