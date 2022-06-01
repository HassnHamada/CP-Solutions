#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 5, M = 1e3 + 5, MOD = 1e9 + 7;
char pat[M], str[N];
int f[M], dp[N][M], dpL[M][26];

int newL(int l, char c)
{
    int &ret = dpL[l][c - 'a'];
    if (~ret)
    {
        return ret;
    }
    while (l && c != pat[l])
    {
        l = f[l - 1];
    }
    return ret = l += (int)(c == pat[l]);
}

void computeF()
{
    if (!pat[0])
    {
        return;
    }
    f[0] = 0;
    for (int i = 1; pat[i]; i++)
    {
        f[i] = newL(f[i - 1], pat[i]);
    }
}

int solve(int i, int l)
{
    // cout << i << " " << l << endl;
    if (!pat[l])
    {
        return INT32_MAX;
    }
    if (!str[i])
    {
        return 0;
    }
    int &ret = dp[i][l];
    if (~ret)
    {
        return ret;
    }
    return ret = min(solve(i + 1, l) + 1, solve(i + 1, newL(l, str[i])));
}

void run()
{
    // scanf("%s\n", pat);
    memset(dp, -1, sizeof(dp));
    memset(dpL, -1, sizeof(dpL));
    // printf("%s\n%s\n", pat, str);
    computeF();
    printf("%d\n", solve(0, 0));
    // cout << res.size() << endl;
    // for (auto &&i : res)
    // {
    //     printf("%d\n", i);
    // }
    // printf("\n");
}
int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // strcpy(pat, "aab");
    // scanf("%s%s", pat, str);
    // computeF();
    // for (int i = 0; i < pat[i]; i++)
    // {
    //     printf("%d ", f[i]);
    // }
    // printf("\n");
    // auto res = match();
    // for (auto &&i : res)
    // {
    //     printf("%d ", i);
    // }

    // printf("\n");
    // int t;
    // scanf("%d", &t);
    while (~scanf("%s%s", str, pat))
    {
        // pat = (char *)malloc((t + 1) * sizeof(char));
        // f = (int *)malloc(t * sizeof(int));
        run();
        // free(pat);
        // free(f);
    }

    return 0;
}