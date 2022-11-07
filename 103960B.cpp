#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 100, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// int dp[N][N][N][2];

struct Key
{
    int a, b, c, d;
    Key(int a_, int b_, int c_, int d_)
    {
        d = d_;
        vector<int> vec = {a_, b_, c_};
        sort(vec.begin(), vec.end());
        a = vec[0];
        b = vec[1];
        c = vec[2];
    }
    bool operator<(const Key &other) const
    {
        if (a == other.a)
        {
            if (b == other.b)
            {
                if (c == other.c)
                {
                    return d < other.d;
                }
                return c < other.c;
            }
            return b < other.b;
        }
        return a < other.a;
    }
};

map<Key, int> dp;
int solve(int a, int b, int c, int p = 1)
{
    Key k(a, b, c, p);
    if (dp.find(k) != dp.end())
    {
        return dp[k];
    }
    for (int i = 1; i <= a; i++)
    {
        if (solve(a - i, b, c, p ^ 1) == p)
        {
            return dp[k] = p;
        }
    }
    for (int i = 1; i <= b; i++)
    {
        if (solve(a, b - i, c, p ^ 1) == p)
        {
            return dp[k] = p;
        }
    }

    for (int i = 1; i <= c; i++)
    {
        if (solve(a, b, c - i, p ^ 1) == p)
        {
            return dp[k] = p;
        }
    }
    return dp[k] = p ^ 1;
}

void run()
{
    dp[{0, 0, 0, 0}] = 1;
    dp[{0, 0, 0, 1}] = 0;
    for (int m = 1; m <= M; m++)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    ans += solve(i, j, k);
                }
            }
        }
        cout << ans << " " << m * m * m << endl;
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}