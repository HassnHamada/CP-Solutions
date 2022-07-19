#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll dp[N];

ll calc(string &s, int i = 0)
{
    if (i == (int)s.size())
    {
        return 1;
    }
    if (~dp[i])
    {
        return dp[i];
    }
    if (s[i] == 'B')
    {
        return dp[i] = calc(s, i + 1);
    }
    return dp[i] = calc(s, i + 1) + calc(s, i + 2);
}

set<ll> vis;
vector<ll> nums;
bool solve(ll n, vector<int> &out)
{
    if (n == 1)
    {
        return true;
    }
    if (vis.find(n) != vis.end())
    {
        return false;
    }
    vis.insert(n);
    for (int i = (int)nums.size() - 1; i; i--)
    {
        if (n % nums[i] == 0 && solve(n / nums[i], out))
        {
            out.push_back(i);
            return true;
        }
    }
    return false;
}

void run()
{
    string s;
    for (int i = 0;; i++)
    {
        s.push_back('B');
        memset(dp, -1, sizeof(dp[0]) * (i + 1));
        ll res = calc(s);
        if (res > 1e15)
        {
            break;
        }
        nums.push_back(res);
        s.pop_back();
        s.push_back('A');
    }
    ll n;
    scanf("%lld", &n);
    vector<int> ans;
    if (solve(n, ans))
    {
        s.clear();
        reverse(ans.begin(), ans.end());
        for (auto &&i : ans)
        {
            for (int j = 0; j < i; j++)
            {
                s.push_back('A');
            }
            s.push_back('B');
        }
        printf("%s", s.c_str());
    }
    else
    {
        printf("IMPOSSIBLE\n");
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