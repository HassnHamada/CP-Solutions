#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char sss[N], ttt[N];
int fff[N];

int newL(int i, char c)
{
    while (i && ttt[i] != c)
    {
        i = fff[i - 1];
    }
    return i + (int)(ttt[i] == c);
}

void computeF()
{
    for (int i = 1; ttt[i]; i++)
    {
        fff[i] = newL(fff[i - 1], ttt[i]);
    }
}

void run()
{
    scanf("%s%s", sss, ttt);
    int n = strlen(sss), m = strlen(ttt);
    computeF();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> mx(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; ~i; i--)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = dp[i + 1][0];
            if (sss[i] == '?' || sss[i] == ttt[j])
            {
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);
                dp[i][j] = max(dp[i][j], mx[i + 1][fff[j]]);
                dp[i][j] += (j + 1) / m;
            }

            mx[i][j] = max(dp[i][j], j ? dp[i][fff[j - 1]] : 0);
        }
    }
    printf("%d\n", dp[0][0]);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
