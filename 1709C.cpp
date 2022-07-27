#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];
map<int, bool> dp[N];

bool good(int i, int c, int n, bool p = true)
{
    if (c > n - i)
    {
        return false;
    }
    if (i == n)
    {
        return c == 0;
    }
    if (p && dp[i].find(c) != dp[i].end())
    {
        return dp[i][c];
    }
    if (str[i] == '(')
    {
        bool ret = good(i + 1, c + 1, n, p);
        if (p)
        {
            return dp[i][c] = ret;
        }
        return ret;
    }
    if (str[i] == ')')
    {
        bool ret = c && good(i + 1, c - 1, n, p);
        if (p)
        {
            return dp[i][c] = ret;
        }
        return ret;
    }
    bool ret = good(i + 1, c + 1, n, p);
    if (!ret && c)
    {
        ret = good(i + 1, c - 1, n, p);
    }
    if (p)
    {
        return dp[i][c] = ret;
    }
    return ret;
}

void run()
{

    scanf("%s", str);
    int n = strlen(str);
    assert(n % 2 == 0);
    bool ok = true;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (str[i] == '?')
        {
            dp[i].erase(j);
            str[i] = ')';
            bool a = good(i, j, n);
            dp[i].erase(j);
            str[i] = '(';
            bool b = good(i, j, n);
            dp[i].erase(j);
            assert(a || b);
            ok = a ^ b;
            if (!ok)
            {
                break;
            }
            if (a)
            {
                str[i] = ')';
            }
        }
        if (str[i] == '(')
        {
            j += 1;
        }
        else if (str[i] == ')')
        {
            j -= 1;
        }
        else
        {
            assert(false);
        }
        assert(j >= 0);
    }
    printf(ok ? "YES\n" : "NO\n");
    for (int i = 0; i < n; i++)
    {
        dp[i].clear();
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}

// 1
// (?))()(())()((()?)))