#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

struct Key
{
    int o, e, t, p;
    bool operator<(const Key &other) const
    {
        if (o == other.o)
        {
            if (e == other.e)
            {
                if (t == other.t)
                {
                    return p < other.p;
                }
                return t < other.t;
            }
            return e < other.e;
        }
        return o < other.o;
    }
};

map<Key, bool> dp;

bool solve(int o, int e, int t, int p)
{
    Key k = {o, e, t, p};
    if (dp.find(k) == dp.end())
    {
        if (t)
        {
            if (o && e)
            {
                dp.insert({k, solve(o - 1, e, t ^ 1, p) && solve(o, e - 1, t ^ 1, p)});
            }
            else if (o || e)
            {
                if (o)
                {
                    dp.insert({k, solve(o - 1, e, t ^ 1, p)});
                }
                else
                {
                    dp.insert({k, solve(o, e - 1, t ^ 1, p)});
                }
            }
            else
            {
                dp.insert({k, !p});
            }
        }
        else
        {
            if (o && e)
            {
                dp.insert({k, solve(o - 1, e, t ^ 1, p ^ 1) || solve(o, e - 1, t ^ 1, p)});
            }
            else if (o || e)
            {
                if (o)
                {
                    dp.insert({k, solve(o - 1, e, t ^ 1, p ^ 1)});
                }
                else
                {
                    dp.insert({k, solve(o, e - 1, t ^ 1, p)});
                }
            }
            else
            {
                dp.insert({k, !p});
            }
        }
    }
    return dp[k];
}

void run()
{
    int n, o = 0, e = 0;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        o += v & 1;
        e += (v & 1) ^ 1;
    }
    printf(solve(o, e, 0, 0) ? "Alice\n" : "Bob\n");
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
