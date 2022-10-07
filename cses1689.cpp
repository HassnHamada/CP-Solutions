#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef unsigned long long ull;

const int N = 1 << 15, M = 8, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
vector<tuple<int, int, int>> grf[M][M];
bool vis[M][M];
int ans[M][M];

// set<pair<ull, ull>> dp;
struct DT
{
    int x, y, d, i;
    // ull s;
};

bool dfs_stk(int x, int y)
{
    stack<DT> stk;
    // stk.push({x, y, 1, 0, 0});
    stk.push({x, y, 1, 0});
    bool ok = false;
    while (!stk.empty())
    {
        DT &t = stk.top();
        // pair<ull, ull> k = {t.s, 1llu << (t.x * M + t.y)};
        // assert((k.first & k.second) == 0);
        // cout << k.first << " " << k.second;
        // if (dp.find(k) != dp.end())
        // {
        //     ans[t.x][t.y] = t.d;
        //     stk.pop();
        //     continue;
        // }
        vis[t.x][t.y] = true;
        if (t.d == M * M)
        {
            ok = true;
            ans[t.x][t.y] = t.d;
            vis[t.x][t.y] = false;
            stk.pop();
            continue;
        }
        if (ok)
        {
            ans[t.x][t.y] = t.d;
            vis[t.x][t.y] = false;
            stk.pop();
            continue;
        }
        auto [_, nx, ny] = grf[t.x][t.y][t.i];
        while (t.i < (int)grf[t.x][t.y].size() && vis[nx][ny])
        {
            tie(_, nx, ny) = grf[t.x][t.y][++t.i];
        }
        if (t.i == (int)grf[t.x][t.y].size())
        {
            vis[t.x][t.y] = false;
            // dp.insert(k);
            stk.pop();
            continue;
        }
        // stk.push({nx, ny, t.d + 1, 0, k.first | k.second});
        stk.push({nx, ny, t.d + 1, 0});
        t.i++;
    }
    return ok;
}

int deg(int i, int j)
{
    int ret = 0;
    for (int k = 0; k < M; k++)
    {
        int ii = i + (k & 0b1 ? 1 : 2) * (k & 0b10 ? -1 : 1), jj = j + (k & 0b1 ? 2 : 1) * (k & 0b100 ? -1 : 1);
        if (ii >= 0 && jj >= 0 && ii < M && jj < M)
        {
            ret += 1;
        }
    }
    assert(ret >= 2);
    assert(ret <= 8);
    return ret;
}

void run()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int ii = i + (k & 0b1 ? 1 : 2) * (k & 0b10 ? -1 : 1), jj = j + (k & 0b1 ? 2 : 1) * (k & 0b100 ? -1 : 1);
                if (ii >= 0 && jj >= 0 && ii < M && jj < M)
                {
                    grf[i][j].push_back({deg(ii, jj), ii, jj});
                }
            }
            sort(grf[i][j].begin(), grf[i][j].end());
        }
    }
    int x, y;
    scanf("%d%d", &x, &y);
    assert(dfs_stk(y - 1, x - 1));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d%c", ans[i][j], " \n"[j + 1 == M]);
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}