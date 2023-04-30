#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char grd[N][N], land = '@';
int vis[N][N], vid;
vector<pair<int, int>> dir = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

void dfs(int x, int y, int n, int m)
{
    assert(vis[x][y] != vid);
    assert(grd[x][y] == land);
    vis[x][y] = vid;
    for (auto &&[i, j] : dir)
    {
        int nx = x + i, ny = y + j;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == vid || grd[nx][ny] != land)
        {
            continue;
        }
        dfs(nx, ny, n, m);
    }
}

void run()
{
    int n, m;
    while (scanf("%d%d", &n, &m), n && m)
    {
        vid++;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", (char *)(grd + i));
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == vid || grd[i][j] != land)
                {
                    continue;
                }
                dfs(i, j, n, m);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}