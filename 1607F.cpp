#include <bits/stdc++.h>
// #include <string>
// #include <iostream>
using namespace std;
// typedef long long int ll;

const int N = 2e3 + 10;
int dp[N][N], lvl[N][N], n, m;
pair<int, int> grf[N][N];
bool stk[N][N];

bool nok(int r, int c)
{
    return r < 0 || r >= n || c < 0 || c >= m;
}

void dfs(int r, int c, int l = 1)
{
    // cout << r << " " << c << " " << l << endl;
    if (dp[r][c] || stk[r][c])
    {
        return;
    }
    lvl[r][c] = l;
    stk[r][c] = true;
    int nr = grf[r][c].first, nc = grf[r][c].second;
    if (nok(nr, nc))
    {
        dp[r][c] = 1;
    }
    else
    {
        dfs(nr, nc, l + 1);
        if (lvl[nr][nc] && lvl[nr][nc] <= lvl[r][c])
        {
            if (stk[nr][nc])
            {
                dp[r][c] = 1 + lvl[r][c] - lvl[nr][nc];
            }
            else
            {
                dp[r][c] = dp[nr][nc];
            }
        }
        else
        {
            dp[r][c] = 1 + dp[nr][nc];
        }
        lvl[r][c] = min(lvl[r][c], lvl[nr][nc]);
        if (!stk[nr][nc])
        {
            lvl[nr][nc] = 0;
        }
    }
    stk[r][c] = false;
}

void run()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 0;
        }
        // memset(dp + i, 0, m * sizeof(dp[0][0]));
    }
    for (int i = 0; i < n; i++)
    {
        // string s;
        // cin >> s;
        for (int j = 0; j < m; j++)
        {
            // char c = s[j];
            char c;
            cin >> c;
            if (c == 'L')
            {
                grf[i][j] = {i, j - 1};
            }
            else if (c == 'R')
            {
                grf[i][j] = {i, j + 1};
            }
            else if (c == 'D')
            {
                grf[i][j] = {i + 1, j};
            }
            else
            {
                grf[i][j] = {i - 1, j};
            }
        }
    }
    pair<int, pair<int, int>> ans = {0, {0, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << i << " " << j << endl;
            if (!dp[i][j])
            {
                dfs(i, j);
                lvl[i][j] = 0;
            }
            ans = max(ans, {dp[i][j], {i + 1, j + 1}});
        }
    }
    cout << ans.second.first << " " << ans.second.second << " " << ans.first << endl;
}

int main(int argc, char const *argv[])
{
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}