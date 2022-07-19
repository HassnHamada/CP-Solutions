#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> arr[N];
int dp[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        arr[v].push_back(i);
    }
    memset(dp, -1, sizeof(dp[0]) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 0; j < (int)arr[i].size(); j++)
        {
            if (dp[arr[i][j]] == -1)
            {
                dp[arr[i][j]] = 0;
                int c = 1, p = arr[i][j], k = j + 1;
                for (; k < (int)arr[i].size(); k++)
                {
                    if (~dp[arr[i][k]])
                    {
                        c += dp[arr[i][k]];
                        break;
                    }
                    dp[arr[i][k]] = c;
                    if ((arr[i][k] - p - 1) % 2 == 0)
                    {
                        c += 1;
                        p = arr[i][k];
                    }
                }
                for (int l = j; l < k; l++)
                {
                    dp[arr[i][l]] = c - dp[arr[i][l]];
                }
                ans = max(ans, c);
            }
        }
        printf("%d%c", ans, " \n"[i == n]);
        arr[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}