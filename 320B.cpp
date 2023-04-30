#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct SEG
{
    int i, s, e;
    SEG(int _i, int _s, int _e)
    {
        this->i = _i;
        this->s = _s;
        this->e = _e;
    }
    bool join(const SEG &other)
    {
        if (this->s > other.s && this->s < other.e)
        {
            return true;
        }
        if (this->e > other.s && this->e < other.e)
        {
            return true;
        }
        return false;
    }
};

vector<SEG> inp;
vector<int> grf[N];
int vis[N], vid;

bool dfs(int n, int t)
{
    vis[n] = vid;
    if (n == t)
    {
        return true;
    }
    for (auto &&i : grf[n])
    {
        if (vis[i] == vid)
        {
            continue;
        }
        if (dfs(i, t))
        {
            return true;
        }
    }
    return false;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, q, a, b; i < n; i++)
    {
        scanf("%d%d%d", &q, &a, &b);
        if (q & 1)
        {
            inp.emplace_back(inp.size(), a, b);
            for (int j = 0; j < (int)inp.size() - 1; j++)
            {
                if (inp.back().join(inp[j]))
                {
                    grf[inp.back().i].push_back(inp[j].i);
                }
                if (inp[j].join(inp.back()))
                {
                    grf[inp[j].i].push_back(inp.back().i);
                }
            }
        }
        else
        {
            vid++;
            printf(dfs(a - 1, b - 1) ? "YES\n" : "NO\n");
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}