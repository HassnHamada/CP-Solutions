#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

std::vector<int> prime;
bool is_composite[N];

void linear_sieve(int n)
{
    std::fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll my_pow(ll b, ll p, ll m = MOD)
{
    b %= m;
    p %= (m - 1);
    ll r = 1;
    while (p)
    {
        if (p & 1)
        {
            r = r * b % m;
        }
        p /= 2;
        b = b * b % m;
    }
    return r;
}

void run()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    linear_sieve(n + 1);
    ll ans = 0, cur = 1, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cur <= m && !is_composite[i])
        {
            cur *= i;
        }
        cnt = m / cur % MOD * cnt % MOD;
        // cout << cur << " " << cnt << endl;
        ans = (ans + my_pow(m, i) - cnt + MOD) % MOD;
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
