#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int aaa[N], bbb[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    sort(aaa, aaa + n);
    ll ans = 0;
    int tar = 1;
    for (int i = 0; i < n; i++)
    {
        if (aaa[i] < tar)
        {
            continue;
        }
        if (aaa[i] == tar)
        {
            tar += 1;
            continue;
        }
        ans += aaa[i] - tar;
        tar += 1;
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