#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int frq[N], arr[N];
ll fact[N], ifact[N], inv[N];

void pre()
{
    fact[0] = fact[1] = ifact[0] = ifact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }
}

int nCr(int n, int r)
{
    return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(frq + 1, 0, sizeof(frq[0]) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        frq[arr[i]]++;
    }
    sort(arr, arr + n);
    printf("%d\n", nCr(frq[arr[n - k]], k - count_if(arr, arr + n, [&n, &k](int i)
                                                     { return i > arr[n - k]; })));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}