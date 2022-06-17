#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e4 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int aaa[N], bbb[N], ccc[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
        ccc[i] = aaa[i] - bbb[i];
    }
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        ok = ok && ccc[i] >= 0;
    }
    int mx = 0;
    for (int i = 0; ok && i < n; i++)
    {
        mx = max(mx, ccc[i]);
    }
    for (int i = 0; ok && i < n; i++)
    {
        if (bbb[i] == 0)
        {
            continue;
        }
        assert(aaa[i] != 0);
        ok = ok && ccc[i] == mx;
    }
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
