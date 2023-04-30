#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

map<pair<int, int>, int> dis;
set<pair<int, int>> grd;

void run()
{
    int x0, y0, x1, y1, n;
    scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &n);
    for (int i = 0, r, a, b; i < n; i++)
    {
        scanf("%d%d%d", &r, &a, &b);
        for (int j = a; j <= b; j++)
        {
            grd.emplace(r, j);
        }
    }
    dis[{x0, y0}] = 0;
    queue<pair<int, int>> q;
    q.push({x0, y0});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                pair<int, int> np = {x + i, y + j};
                if (dis.find(np) != dis.end() || grd.find(np) == grd.end())
                {
                    continue;
                }
                dis[np] = dis[{x, y}] + 1;
                q.push(np);
            }
        }
    }
    printf("%d\n", dis.find({x1, y1}) == dis.end() ? -1 : dis[{x1, y1}]);
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