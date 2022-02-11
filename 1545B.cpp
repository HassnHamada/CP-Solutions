#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10, MOD = 998244353;
bitset<N> bs;
ll s, fact[N], ifact[N], inv[N];
ll nCr(ll n, ll r)
{
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

ll work()
{
    int a = 0, b = 0;
    for (int i = 1; i < s; i++)
    {
        a += (bs[i] & bs[i - 1]);
        i += (bs[i] & bs[i - 1]);
    }
    for (int i = 0; i < s; i++)
    {
        b += !bs[i];
    }
    return nCr(a + b, b);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        for (int i = 0; i < s; i++)
        {
            char v;
            cin >> v;
            bs[i] = v == '1';
        }
        cout << work() << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
