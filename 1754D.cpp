#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int frq[N];

bool ok(int x)
{
    for (int i = 1; i < x; i++)
    {
        if (frq[i] % (i + 1))
        {
            return false;
        }
        frq[i + 1] += frq[i] / (i + 1);
    }
    return true;
}

void run()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        frq[v]++;
    }
    printf(ok(x) ? "Yes\n" : "No\n");
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