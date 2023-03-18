#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char grd[N][N];
int vis[N][N], vid;
vector<pair<int, int>> dir_8 = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
vector<pair<int, int>> dir_4 = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

int dfs(int x, int y, int n, int m, char c)
{
    int ret = 1;
    vis[x][y] = vid;
    for (auto &&[i, j] : dir_4)
    {
        int nx = x + i, ny = y + j;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == vid || grd[nx][ny] != c)
        {
            continue;
        }
        ret += dfs(nx, ny, n, m, c);
    }
    return ret;
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
        vector<pair<char, int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == vid || grd[i][j] == '.')
                {
                    continue;
                }
                ans.emplace_back(grd[i][j], dfs(i, j, n, m, grd[i][j]));
            }
        }
        sort(ans.begin(), ans.end(), [](const pair<char, int> &p1, const pair<char, int> &p2)
             { return p1.second == p2.second ? p1.first < p2.first : p2.second < p1.second; });
        printf("Problem %d:\n", vid);
        for (auto &&[i, j] : ans)
        {
            printf("%c %d\n", i, j);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}