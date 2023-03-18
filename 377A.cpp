#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char maz[N][N];

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, int &k)
{
    maz[i][j] = '.';
    k -= 1;
    for (int l = 0; k && l < 4; l++)
    {
        if (maz[i + dir[l][0]][j + dir[l][1]] == 'X')
        {
            dfs(i + dir[l][0], j + dir[l][1], k);
        }
    }
}

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(maz + i));
    }
    int sz = -k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maz[i][j] == '.')
            {
                sz += 1;
                maz[i][j] = 'X';
            }
        }
    }
    bool ok = false;
    for (int i = 0; !ok && i < n; i++)
    {
        for (int j = 0; !ok && j < m; j++)
        {
            if (maz[i][j] == 'X')
            {
                dfs(i, j, sz);
                ok = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", (char *)(maz + i));
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