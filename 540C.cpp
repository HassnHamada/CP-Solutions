#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char brd[N][N];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int x, int y)
{
    for (auto &&[i, j] : dir)
    {
        if (brd[x + i][y + j] == '.')
        {
            brd[x + i][y + j] = 'Y';
            dfs(x + i, y + j);
        }
    }
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", (char *)(brd + i) + 1);
    }
    int sr, sc, er, ec;
    scanf("%d%d%d%d", &sr, &sc, &er, &ec);
    dfs(sr, sc);
    int cnt = 0;
    for (auto &&[i, j] : dir)
    {
        cnt += brd[er + i][ec + j] == 'Y' || ((er + i) == sr && (ec + j) == sc);
    }
    char t = brd[er][ec];
    printf((t == 'X' && cnt >= 1) || (t == 'Y' && cnt >= 2) ? "YES\n" : "NO\n");
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