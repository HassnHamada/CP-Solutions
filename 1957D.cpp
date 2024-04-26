#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 31, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], evn[N], odd[N], revn[N], rodd[N], _xor[N], rxor[N], pre[N], suf[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    ll ans = 0;
    revn[n + 1] = rodd[n + 1] = rxor[n + 1] = suf[n + 1] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1, k = 1, l = 0; j <= n; j++)
        {
            evn[j] = evn[j - 1] + (k ^= (arr[j] & 1));
            odd[j] = odd[j - 1] + (l ^= (arr[j] & 1));
            _xor[j] = _xor[j - 1] ^ (arr[j] & 1);
            pre[j] = pre[j - 1] + _xor[j];
        }
        for (int j = n, k = 1, l = 0; j; j--)
        {
            revn[j] = revn[j + 1] + (k ^= (arr[j] & 1));
            rodd[j] = rodd[j + 1] + (l ^= (arr[j] & 1));
            rxor[j] = rxor[j + 1] ^ (arr[j] & 1);
            suf[j] = suf[j + 1] + rxor[j];
        }
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] == 1)
            {
                ll lo = suf[1] - suf[j], ro = pre[n] - pre[j],
                   lz = j - 1 - lo, rz = n - j - ro;
                ans = (ans + (ro + _xor[j]) * (lz + (rxor[j] ^ 1)) + (lo + _xor[j]) * (rz + (rxor[j] ^ 1))) % MOD;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            arr[j] >>= 1;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
