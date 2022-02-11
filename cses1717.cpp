#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 1 << 20, MOD = 1e9 + 7;
ll fact[N], ifact[N], inv[N];

void run()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
    int n;
    cin >> n;
    ll ans = fact[n];
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + MOD - fact[n] * ifact[i] % MOD * (i & 1 ? 1 : -1)) % MOD;
    }
    cout << ans << endl;
    // inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}