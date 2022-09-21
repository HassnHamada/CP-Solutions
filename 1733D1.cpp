#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 3e3 + 10, M = 2, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

char aaa[N], bbb[N];
bool ccc[N];
int nxt[N];

void run()
{
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    scanf("%s\n%s", aaa, bbb);
    for (int i = 0; i < n; i++)
    {
        ccc[i] = aaa[i] != bbb[i];
    }
    if (count(ccc, ccc + n, true) & 1)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = n - 1, j = n; ~i; i--)
        {
            if (ccc[i])
            {
                nxt[i] = j;
                j = i;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ccc[i])
            {
                if (nxt[nxt[i]] < n)
                {
                    ccc[i] = ccc[nxt[nxt[i]]] = false;
                    nxt[nxt[i]] = nxt[nxt[nxt[i]]];
                    ans += y;
                }
                else
                {
                    ccc[i] = ccc[nxt[i]] = false;
                    ans += nxt[i] == i + 1 ? min(2 * y, x) : y;
                }
            }
        }
        printf("%lld\n", ans);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}