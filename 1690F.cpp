#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int ppp[N];
char str[N];
pair<int, int> dp[N][N];

pair<int, int> calc(int n, char t)
{
    if (str[n] == t)
    {
        return {0, n};
    }
    if (dp[n][t - 'a'].first == -1)
    {
        dp[n][t - 'a'] = calc(ppp[n], t);
        dp[n][t - 'a'].first += 1;
    }
    return dp[n][t - 'a'];
}

void run()
{
    int n;
    scanf("%d%s", &n, str);
    memset(dp, -1, sizeof(dp[0]) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ppp + i);
        ppp[i] -= 1;
    }
    vector<int> vec[N];
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (true)
        {
            assert(str[i] == str[j]);
            auto p = calc(ppp[j], str[i]);
            p.first += 1;
            if (vec[i].empty())
            {
                vec[i].push_back(p.first);
            }
            else
            {
                vec[i].push_back(p.first + vec[i].back());
            }
            if (p.second == i)
            {
                break;
            }
            j = p.second;
        }
    }
    ll ans = -1;
    for (int i = 1; i < n; i++)
    {
        int ok = 0;
        for (int j = 0; j < n; j++)
        {
            for (auto &&k : vec[j])
            {
                if (k == i % vec[j].back())
                {
                    ok += 1;
                    break;
                }
            }
        }
        if (ok == n)
        {
            ans = i;
            break;
        }
    }
    if (ans == -1)
    {
        for (int i = 0; i < n; i++)
        {
            ans = ans * vec[i].back() / __gcd(ans, (ll)vec[i].back());
        }
    }
    printf("%lld\n", ans);
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
