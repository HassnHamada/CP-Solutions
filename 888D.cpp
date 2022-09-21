#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll nCr(int n, int r)
{
    ll ret = 1;
    for (int i = r + 1; i <= n; i++)
    {
        ret *= i;
    }
    for (int i = 2; i <= n - r; i++)
    {
        ret /= i;
    }
    return ret;
}

ll per(int k)
{
    vector<int> vec;
    for (int i = 0; i < k; i++)
    {
        vec.push_back(i);
    }
    ll ret = 0;
    while (next_permutation(vec.begin(), vec.end()))
    {
        bool ok = true;
        for (int i = 0; i < k; i++)
        {
            if (i == vec[i])
            {
                ok = false;
            }
        }
        ret += ok;
    }
    return ret;
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = 1;
    for (int i = 1; i <= k; i++)
    {
        ans += nCr(n, n - i) * per(i);
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