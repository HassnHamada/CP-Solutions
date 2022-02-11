#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 50;
char mat[N][N];
int dp[N][N], h, w;

int dfs(int x, int y)
{
    // cout << x << " " << y << " " << mat[x][y] << endl;
    if (~dp[x][y])
    {
        return dp[x][y];
    }
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int xx = x + (i & 1) - (i >> 1), yy = y + (j & 1) - (j >> 1);
            if (xx >= h || xx < 0 || yy >= w || yy < 0 || mat[xx][yy] != mat[x][y] + 1)
            {
                continue;
            }
            ret = max(ret, dfs(xx, yy));
        }
    }
    return dp[x][y] = ret + 1;
}

int test()
{

    for (int i = 0; i < h; i++)
    {
        memset((int *)(dp + i), -1, w * sizeof(dp[0][0]));
        for (int j = 0; j < w; j++)
        {
            cin >> mat[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mat[i][j] == 'A')
            {
                ret = max(ret, dfs(i, j));
            }
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    while (cin >> h >> w, h)
    {
        cout << "Case " << ++t << ": " << test() << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}