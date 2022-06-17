#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char aaa[N], bbb[N], vvv[N];
int dp[N][N][N], fff[N], n, m, l;

int newL(int i, char c)
{
    while (i && c != vvv[i])
    {
        i = fff[i - 1];
    }
    return i + (int)(c == vvv[i]);
}

void computeF()
{
    for (int i = 1; i < l; i++)
    {
        fff[i] = newL(fff[i - 1], vvv[i]);
    }
}

int solve(int i = 0, int j = 0, int k = 0)
{
    // cout << i << " " << j << " " << k << endl;
    int &ret = dp[i][j][k];
    if (~ret)
    {
        return ret;
    }
    if (k == l)
    {
        return ret = -INF;
    }
    if (i == n || j == m)
    {
        return ret = 0;
    }
    if (aaa[i] == bbb[j])
    {
        ret = solve(i + 1, j + 1, newL(k, aaa[i])) + 1;
    }
    return ret = max({ret, solve(i + 1, j, k), solve(i, j + 1, k)});
}

void print(int i = 0, int j = 0, int k = 0)
{
    // int &val = dp[i][j][k];
    // cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
    assert(k != l);

    if (i == n || j == m)
    {
        printf("\n");
    }
    else if (aaa[i] == bbb[j] && dp[i][j][k] == dp[i + 1][j + 1][newL(k, aaa[i])] + 1)
    {
        printf("%c", aaa[i]);
        print(i + 1, j + 1, newL(k, aaa[i]));
    }
    else if (dp[i][j][k] == dp[i + 1][j][k])
    {
        print(i + 1, j, k);
    }
    else
    {
        assert(dp[i][j][k] == dp[i][j + 1][k]);
        print(i, j + 1, k);
    }
}

void run()
{
    scanf("%s%s%s", aaa, bbb, vvv);
    n = strlen(aaa);
    m = strlen(bbb);
    l = strlen(vvv);
    computeF();
    // for (int i = 0; i < l; i++)
    // {
    //     cout << fff[i] << " ";
    // }
    // cout << endl;
    memset(dp, -1, sizeof(dp));
    int res = solve();
    if (res)
    {
        print();
    }
    else
    {
        printf("0\n");
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