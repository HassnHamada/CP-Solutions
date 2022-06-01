#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
bool vis[N];
vector<int> tre[N];

void run()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (tre[i].size() == 1)
        {
            q.push(i);
            vis[i] = true;
        }
    }
    int ans = 0, p = 0;
    while (q.size())
    {
        ans += q.size() * p;
        queue<int> tem;
        while (q.size())
        {
            int f = q.front();
            q.pop();
            for (auto &&i : tre[f])
            {
                if (vis[i])
                {
                    continue;
                }
                tem.push(i);
                vis[i] = true;
            }
        }
        swap(q, tem);
        p ^= 1;
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}