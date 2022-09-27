#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 2e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char mat[N][N];

int n, m;

int dfs(int ii, int jj)
{
    // cout << ii << " " << jj << endl;
    assert(mat[ii][jj] == '*');
    mat[ii][jj] = '\0';
    int ret = 1;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int ni = ii + i, nj = jj + j;
            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
            {
                continue;
            }
            if (mat[ni][nj] == '*')
            {
                ret += dfs(ni, nj);
            }
        }
    }
    // cout << ii << " " << jj << " " << ret << endl;
    return ret;
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat + i));
    }
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        for (int j = 0; ok && j < m; j++)
        {
            if (mat[i][j] == '*' && ((i < n - 1 && j < m - 1 && mat[i + 1][j + 1] == '*' && mat[i + 1][j] != mat[i][j + 1]) ||
                                     (i < n - 1 && j && mat[i + 1][j - 1] == '*' && mat[i + 1][j] != mat[i][j - 1])))
            {
                // cout << i << " " << j << endl;
                ok = dfs(i, j) <= 3;
            }
        }
    }
    for (int i = 0; ok && i < n; i++)
    {
        for (int j = 0; ok && j < m; j++)
        {
            ok = mat[i][j] != '*';
        }
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