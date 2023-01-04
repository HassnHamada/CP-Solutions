#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int bbb[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    multiset<int> aaa;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        aaa.insert(v);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", bbb + i);
    }
    // sort(bbb, bbb + m, greater<int>());
    for (int i = 0; i < m; i++)
    {
        aaa.erase(aaa.begin());
        aaa.insert(bbb[i]);
    }
    ll ans = 0;
    for (auto &&i : aaa)
    {
        ans += i;
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}