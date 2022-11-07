#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e1 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bool don(vector<vector<int>> &mat)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] != i * M + j + 1)
            {
                return false;
            }
        }
    }
    return true;
}

ll key(vector<vector<int>> &mat)
{
    ll ret = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            ret = (ret << 4) | mat[i][j];
        }
    }
    return ret;
}

map<ll, int> dp;
set<ll> stk;

int mxd = 1 << 5;

int solve(vector<vector<int>> &mat, int d = 0)
{
    if (don(mat))
    {
        return 0;
    }
    if (d >= mxd)
    {
        return INF;
    }
    // for (auto &&i : mat)
    // {
    //     for (auto &&j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-----------" << endl;
    ll k = (key(mat) << 5) | d;
    if (stk.find(k) != stk.end())
    {
        return INF;
    }
    if (dp.find(k) != dp.end())
    {
        return dp[k];
    }
    stk.insert(k);
    cout << dp.size() << " " << stk.size() << endl;
    // cout << dp.size() << endl;
    int ret = INF;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == i * M + j + 1)
            {
                continue;
            }
            if (i)
            {
                swap(mat[i - 1][j], mat[i][j]);
                ret = min(ret, 1 + solve(mat, d + 1));
                swap(mat[i - 1][j], mat[i][j]);
            }
            if (i + 1 < M)
            {
                swap(mat[i + 1][j], mat[i][j]);
                ret = min(ret, 1 + solve(mat, d + 1));
                swap(mat[i + 1][j], mat[i][j]);
            }
            if (j)
            {
                swap(mat[i][j - 1], mat[i][j]);
                ret = min(ret, 1 + solve(mat, d + 1));
                swap(mat[i][j - 1], mat[i][j]);
            }
            if (j + 1)
            {
                swap(mat[i][j + 1], mat[i][j]);
                ret = min(ret, 1 + solve(mat, d + 1));
                swap(mat[i][j + 1], mat[i][j]);
            }
        }
    }
    stk.erase(k);
    // if (ret == INF)
    // {
    //     for (auto &&i : mat)
    //     {
    //         for (auto &&j : i)
    //         {
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << "-----------" << endl;
    // }
    // assert(ret != INF);
    mxd = min(mxd, ret);
    return dp[k] = ret;
}

void run()
{
    vector<vector<int>> inp(M, vector<int>(M));
    for (auto &&i : inp)
    {
        for (auto &&j : i)
        {
            scanf("%d", &j);
        }
    }
    printf("%d\n", solve(inp));
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}