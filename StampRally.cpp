#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, m, usd[N], vis[N], vid;
vector<pair<int, int>> grf[N];

int dfs(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pq, int z)
{
    // cout << pq.size() << " " << z << endl;
    if (z == 0)
    {
        return 0;
    }
    pair<int, int> f;
    do
    {
        assert(!pq.empty());
        f = pq.top();
        pq.pop();
    } while (vis[f.second] == vid);
    vis[f.second] = vid;
    for (auto &&i : grf[f.second])
    {
        if (usd[i.first] == vid || vis[i.second] == vid)
        {
            continue;
        }
        pq.push(i);
        usd[i.first] = vid;
    }
    return max(dfs(pq, z - 1), f.first);
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        grf[u].emplace_back(i + 1, v);
        grf[v].emplace_back(i + 1, u);
    }
    int q;
    scanf("%d", &q);
    while (vid++ < q)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vis[x] = vis[y] = vid;
        for (auto &&i : grf[x])
        {
            if (usd[i.first] == vid || vis[i.second] == vid)
            {
                continue;
            }
            pq.push(i);
            usd[i.first] = vid;
        }
        for (auto &&i : grf[y])
        {
            if (usd[i.first] == vid || vis[i.second] == vid)
            {
                continue;
            }
            pq.push(i);
            usd[i.first] = vid;
        }
        // cout << pq.size() << endl;
        printf("%d\n", dfs(pq, z - 2));
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
