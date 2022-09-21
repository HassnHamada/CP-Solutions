#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int tre[N][N];
char grd[N][N];

void add(int i, int j, ll val)
{
    for (i++; i <= N; i += (i & (-i)))
    {
        for (int jj = j + 1; jj <= N; jj += (jj & (-jj)))
        {
            tre[i - 1][jj - 1] += val;
        }
    }
}

int get(int i, int j)
{
    int ret = 0;
    for (i++; i; i -= (i & (-i)))
    {
        for (int jj = j + 1; jj; jj -= (jj & (-jj)))
        {
            ret += tre[i - 1][jj - 1];
        }
    }
    return ret;
}

int get(int si, int sj, int ei, int ej)
{
    return get(ei, ej) - get(ei, sj - 1) - get(si - 1, ej) + get(si - 1, sj - 1);
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", (char *)(grd + i) + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grd[i][j] == '*')
            {
                add(i, j, 1);
            }
        }
    }

    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, y;
            scanf("%d%d", &y, &x);
            if (grd[y][x] == '.')
            {
                grd[y][x] = '*';
                add(y, x, 1);
            }
            else
            {
                grd[y][x] = '.';
                add(y, x, -1);
            }
        }
        else
        {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            printf("%d\n", get(y1, x1, y2, x2));
        }
    }
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