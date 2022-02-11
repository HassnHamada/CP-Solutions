#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 10, M = 1e3 + 10, MOD = 1e9 + 7;
ll n, m, mat[M][1 << N];

ll dp(int c, int mask)
{
    if (c == m)
    {
        return mask == 0;
    }
    if (~mat[c][mask])
    {
        return mat[c][mask];
    }
    int cat = (~mask) & ((1 << n) - 1);
    ll ret = dp(c + 1, cat);
    cat &= cat >> 1;
    for (int i = cat; i; i = (i - 1) & cat)
    {
        if (i & (i << 1))
        {
            continue;
        }
        assert((mask & (i | (i << 1))) == 0);
        ret = (ret + dp(c + 1, (~(mask | i | (i << 1))) & ((1 << n) - 1))) % MOD;
    }
    return mat[c][mask] = ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    scanf("%lld%lld", &n, &m);
    memset(mat, -1, sizeof(mat));
    printf("%lld\n", dp(0, 0));
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
