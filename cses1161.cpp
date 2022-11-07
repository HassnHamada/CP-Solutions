#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 2, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int x, n;
    scanf("%d%d", &x, &n);
    multiset<int> ms;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        ms.insert(v);
    }
    ll ans = 0;
    while (ms.size() > 1)
    {
        int a = *ms.begin();
        ms.erase(ms.begin());
        int b = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(a + b);
        ans += a + b;
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}