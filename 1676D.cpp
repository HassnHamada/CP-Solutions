#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int grd[N][M];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (int *)(grd + i) + j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = 0, ii = i, jj = j;
            for (int k = 0; ii + k < n && jj + k < m; k++)
            {
                t += grd[ii + k][jj + k];
            }
            ii = i, jj = j;
            for (int k = 0; ii - k >= 0 && jj - k >= 0; k++)
            {
                t += grd[ii - k][jj - k];
            }
            ii = i, jj = j;
            for (int k = 0; ii - k >= 0 && jj + k < m; k++)
            {
                t += grd[ii - k][jj + k];
            }
            ii = i, jj = j;
            for (int k = 0; ii + k < n && jj - k >= 0; k++)
            {
                t += grd[ii + k][jj - k];
            }
            ans = max(ans, t - 3 * grd[i][j]);
        }
    }
    printf("%d\n", ans);
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