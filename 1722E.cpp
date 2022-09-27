#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll mat[N][N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    memset(mat, 0, sizeof(mat));

    for (int i = 0, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        mat[x][y] += x * y;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int hs, ws, hb, wb;
        scanf("%d%d%d%d", &hs, &ws, &hb, &wb);
        printf("%lld\n", mat[hb - 1][wb - 1] - mat[hb - 1][ws] - mat[hs][wb - 1] + mat[hs][ws]);
    }
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