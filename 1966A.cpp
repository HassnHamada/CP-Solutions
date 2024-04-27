#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> frq;
    bool ok = false;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        frq[v]++;
        ok = ok || (frq[v] >= k);
    }
    printf("%d\n", ok ? k - 1 : n);
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