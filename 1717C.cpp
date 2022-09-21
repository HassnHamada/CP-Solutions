#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int aaa[N], bbb[N];

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
    }
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        ok = aaa[i] <= bbb[i];
    }
    for (int i = 0; ok && i < n; i++)
    {
        if (aaa[i] == bbb[i])
        {
            continue;
        }
        ok = bbb[(i + 1) % n] >= bbb[i] - 1;
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