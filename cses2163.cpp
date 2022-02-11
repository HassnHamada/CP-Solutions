#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const ll N = 2e5 + 10;
ll bit[N];

void add(ll x, ll v = 1)
{
    for (ll i = x; i < N; i += i & -i)
    {
        bit[i] += v;
    }
}

ll get(ll x)
{
    ll ret = 0;
    for (ll i = x; i; i -= i & -i)
    {
        ret += bit[i];
    }
    return ret;
}

ll ans(ll val)
{
    ll l = 1, h = N;
    while (l < h)
    {
        ll m = l + (h - l) / 2;
        if (get(m) >= val)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    ll n, k;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        add(i);
    }
    for (ll i = 1, j = k % n, v = ans(k % n + 1);; j = (j + k) % (n - i), v = ans(j + 1), i++)
    {
        printf("%lld%c", v, i == n ? '\n' : ' ');
        add(v, -1);
        if (i == n)
        {
            break;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}