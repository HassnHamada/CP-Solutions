#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e2 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N][N];

void solve(int is, int ie, int js, int je, int n)
{
    // cout << is << " " << ie << " " << js << " " << je << endl;
    assert(ie - is == je - js);
    if (ie - is < 2)
    {
        return;
    }
    for (int i = is; i < ie; i++)
    {
        int v = 0;
        for (; v < n; v++)
        {
            bool ok = true;
            for (int j = js; j < je; j++)
            {
                if (i == j + is)
                {
                    continue;
                }
                if ((ans[i][i - is] + ans[j + is][j]) % n == v)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                break;
            }
        }
        assert(v != n);
        for (int j = i + 1; j < ie; j++)
        {
            ans[i][j - is] = v;
        }
    }
    solve((ie - is + 1) / 2 + is, ie, js, (je - js) / 2 + js, n);
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (int *)(ans + i) + i);
    }
    solve(0, n, 0, n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d%c", ans[i][j], " \n"[j + 1 == n]);
        }
    }
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