#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char ans[N];
map<pair<int, int>, int> mmm;

int ask(int i, int j)
{
    assert(i <= j);
    if (mmm.find({i, j}) == mmm.end())
    {
        if (i == j)
        {
            mmm[{i, j}] = 1;
        }
        else
        {
            printf("? 2 %d %d\n", i, j);
            fflush(stdout);
            scanf("%d", &mmm[{i, j}]);
        }
    }
    return mmm[{i, j}];
}

int nxt(int i, int n)
{
    int l = i + 1, h = n + 1;
    while (l < h)
    {
        int m = (h - l) / 2 + l;
        int u = ask(i, m), v = ask(i + 1, m);
        assert(u >= v);
        if (u == v)
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (ans[i])
        {
            continue;
        }
        else
        {
            printf("? 1 %d\n", i + 1);
            fflush(stdout);
            scanf("\n%c", ans + i);
            for (int j = i + 1; j < n;)
            {
                j = nxt(j, n);
                if (j <= n)
                {
                    ans[j - 1] = ans[i];
                }
            }
        }
    }
    printf("! %s\n", ans);
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