#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
map<pair<int, int>, int> edg;
bool vis[N];
vector<int> grf[N];

void run()
{
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    queue<int> q;
    for (int i = 0, v; i < k; i++)
    {
        scanf("%d", &v);
        q.push(v);
        vis[v] = true;
    }
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        edg.insert({{min(u, v), max(u, v)}, i});
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    while (q.size())
    {
        queue<int> t;
        while (q.size())
        {
            int f = q.front();
            q.pop();
            for (auto &&i : grf[f])
            {
                if (vis[i])
                {
                    continue;
                }
                t.push(i);
                vis[i] = true;
                edg.erase({min(f, i), max(f, i)});
            }
        }
        swap(q, t);
    }
    printf("%d\n", (int)edg.size());
    for (auto &&i : edg)
    {
        printf("%d ", i.second);
    }
    printf("\n");
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