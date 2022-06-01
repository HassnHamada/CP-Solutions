#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int nxt[N], prv[N], arr[N], idx[N];
bitset<N> prime;

void sieve(int n, vector<int> &out)
{
    prime.set();
    prime[0].flip();
    for (ll i = 3; i * i <= n; i += 2)
    {
        for (ll j = i * i; prime[i / 2] && j <= n; j += 2 * i)
        {
            prime[j / 2] = 0;
        }
    }
    out.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i / 2])
        {
            out.push_back(i);
        }
    }
}

void run()
{
    ll n, ans = 0;
    scanf("%lld", &n);
    vector<int> vec;
    sieve(N, vec);
    for (auto &&q : vec)
    {
        ll qq = 1ll * q * q * q;
        ll a = upper_bound(vec.begin(), vec.end(), n / qq) - vec.begin(),
           b = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
        ans += min(a, b);
    }
    printf("%lld\n", ans);
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