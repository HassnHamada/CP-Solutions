#include <bits/stdc++.h>
// #include "./stdc++.h"
using namespace std;
typedef long long int ll;

const int N = 1e5 + 10;
// ll dis[N][10];
int per[N];
bool vis[N], vis2[N];
vector<int> adj[N];

bool dfs(int n, int &x)
{
    if (vis[n])
    {
        x = n;
        return true;
    }
    if (vis2[n])
    {
        return false;
    }
    vis[n] = vis2[n] = true;
    for (int i : adj[n])
    {
        per[i] = n;
        if (dfs(i, x))
        {
            return true;
        }
        // per[i] = -1;
    }
    vis[n] = false;
    return false;
}

int main(int argc, char const *argv[])
{
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis2[i])
        {
            continue;
        }
        if (dfs(i, x))
        {
            break;
        }
    }
    if (x)
    {
        vector<int> ans;
        ans.push_back(x);
        for (int i = per[x]; i != x; i = per[i])
        {
            ans.push_back(i);
        }
        ans.push_back(x);
        reverse(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (int i : ans)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}