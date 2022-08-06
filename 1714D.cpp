#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int dp[N];
char tem[N];
string ttt;
vector<string> sss;
int n;

bool match(const char *s1, const char *s2, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        if (*(s1 + i) != *(s2 + i))
        {
            return false;
        }
    }
    return true;
}

int solve(int i = 0)
{
    assert(i <= (int)ttt.size());
    if (i == (int)ttt.size())
    {
        return dp[i] = 0;
    }
    if (dp[i] == -1)
    {
        dp[i] = INF;
        for (auto &&j : sss)
        {
            if (match(j.c_str(), ttt.c_str() + i, j.size()))
            {
                for (int k = 1; k <= (int)j.size(); k++)
                {
                    dp[i] = min(dp[i], solve(i + k) + 1);
                }
            }
        }
    }
    return dp[i];
}

void prn(int i = 0)
{
    assert(i <= (int)ttt.size());
    if (i < (int)ttt.size())
    {
        assert(dp[i] != -1 && dp[i] != INF);
        for (int j = 0; j < n; j++)
        {
            if (match(sss[j].c_str(), ttt.c_str() + i, sss[j].size()))
            {
                for (int k = 1; k <= (int)sss[j].size(); k++)
                {
                    if (dp[i + k] + 1 == dp[i])
                    {
                        printf("%d %d\n", j + 1, i + 1);
                        prn(i + k);
                        return;
                    }
                }
            }
        }
    }
}

void run()
{
    scanf("%s", tem);
    scanf("%d", &n);
    ttt = tem;
    sss.clear();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", tem);
        sss.emplace_back(tem);
    }
    memset(dp, -1, sizeof(dp));
    int res = solve();
    if (res == INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", res);
        prn();
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
