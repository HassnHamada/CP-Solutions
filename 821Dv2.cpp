#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
set<int> aaa[N], bbb[N];
bitset<N> visa, visb;
int n, m, k;
map<pair<int, int>, int> cst;

void add(pair<int, int> p, queue<pair<pair<int, int>, int>> &q, int c)
{
    for (int i = -2; i < 3; i++)
    {
        int x = i + p.first, y = i + p.second;
        if (x > 0 && x <= n && !visa[x])
        {
            visa[x].flip();
            for (auto &&j : aaa[x])
            {
                if (abs(i) + abs(p.second - j) <= 1)
                {
                    continue;
                }
                q.push({{x, j}, c});
            }
        }
        if (y > 0 && y <= m && !visb[y])
        {
            visb[y].flip();
            for (auto &&j : bbb[y])
            {
                if (abs(p.first - j) + abs(i) <= 1)
                {
                    continue;
                }
                q.push({{j, y}, c});
            }
        }
    }
}

void run()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v; i < k; i++)
    {
        scanf("%d%d", &u, &v);
        aaa[u].insert(v);
        bbb[v].insert(u);
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 0});
    while (q.size())
    {
        pair<pair<int, int>, int> f = q.front();
        q.pop();
        pair<int, int> x = f.first;
        int y = f.second;
        if (cst.find(x) != cst.end())
        {
            continue;
        }
        set<pair<int, int>> sss;
        queue<pair<int, int>> t;
        t.push(x);
        while (t.size())
        {
            pair<int, int> ff = t.front();
            t.pop();
            auto it = aaa[ff.first].lower_bound(ff.second);
            if (cst.find(ff) != cst.end() || it == aaa[ff.first].end() || *it != ff.second)
            {
                continue;
            }
            sss.insert(ff);
            t.push({ff.first + 1, ff.second});
            t.push({ff.first - 1, ff.second});
            t.push({ff.first, ff.second + 1});
            t.push({ff.first, ff.second - 1});
            cst[ff] = y;
        }
        for (auto &&j : sss)
        {
            add(j, q, y + 1);
        }
    }
    if (cst.find({n, m}) == cst.end())
    {
        int ans = INT32_MAX;
        for (int i = n - 1; i <= n; i++)
        {
            for (auto &&j : aaa[i])
            {
                if (cst.find({i, j}) == cst.end())
                {
                    continue;
                }
                ans = min(ans, cst[{i, j}]);
            }
        }
        for (int i = m - 1; i <= m; i++)
        {
            for (auto &&j : bbb[i])
            {
                if (cst.find({j, i}) == cst.end())
                {
                    continue;
                }
                ans = min(ans, cst[{j, i}]);
            }
        }
        printf("%d\n", ans == INT32_MAX ? -1 : ans + 1);
    }
    else
    {
        printf("%d\n", cst[{n, m}]);
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