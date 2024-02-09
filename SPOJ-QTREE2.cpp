// https://www.spoj.com/problems/QTREE2/

#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#include <vector>
#include <assert.h>
#include <map>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(1e5 + 10), M = 20;
int lvl[N];
pair<int, int> par[N][M];
map<int, int> tre[N];

void dfs(int n, int p = -1, int lid = 1)
{
    lvl[n] = lid;
    par[n][0] = {p, tre[n][p]};
    for (auto &&i : tre[n])
    {
        if (i.first == p)
        {
            continue;
        }
        dfs(i.first, n, lid + 1);
    }
}

pair<int, int> lca(int a, int b)
{
    int dist = 0;
    for (int i = M - 1; ~i; i--)
    {
        if (lvl[a] == lvl[b])
        {
            continue;
        }
        else if (lvl[par[a][i].first] >= lvl[b])
        {
            dist += par[a][i].second;
            a = par[a][i].first;
        }
        else if (lvl[par[b][i].first] >= lvl[a])
        {
            dist += par[b][i].second;
            b = par[b][i].first;
        }
    }
    assert(lvl[a] == lvl[b]);
    if (a == b)
    {
        return {a, dist};
    }
    for (int i = M - 1; ~i; i--)
    {
        if (par[a][i].first == par[b][i].first)
        {
            continue;
        }
        dist += par[a][i].second + par[b][i].second;
        a = par[a][i].first;
        b = par[b][i].first;
    }
    assert(a != b);
    assert(lvl[a] == lvl[b]);
    assert(par[a][0].first == par[b][0].first);
    return {par[a][0].first,
            dist + par[a][0].second + par[b][0].second};
}

// Binary lifting
int bl(int a, int s)
{
    for (int i = M - 1; ~i; i--)
    {
        if (s & (1 << i))
        {
            a = par[a][i].first;
        }
    }
    return a;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        tre[a].emplace(b, c);
        tre[b].emplace(a, c);
    }
    dfs(0);
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < n; j++)
        {
            par[j][i].first = par[j][i - 1].first == -1 ? -1 : par[par[j][i - 1].first][i - 1].first;
            par[j][i].second = par[j][i - 1].first == -1 ? 0 : par[j][i - 1].second + par[par[j][i - 1].first][i - 1].second;
        }
    }
    char q[M];
    while (scanf("%s", q), strcmp(q, "DONE"))
    {
        if (!strcmp(q, "DIST"))
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            printf("%d\n", lca(a, b).second);
        }
        else
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            int p = lca(a, b).first;
            if (lvl[a] - lvl[p] >= c)
            {
                printf("%d\n", bl(a, c - 1) + 1);
            }
            else
            {
                // Total distance
                // lvl[a] - lvl[p] + lvl[b] - lvl[p] + 1
                assert(c <= lvl[a] - lvl[p] + lvl[b] - lvl[p] + 1);
                printf("%d\n", bl(b, lvl[a] - lvl[p] + lvl[b] - lvl[p] + 1 - c) + 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        tre[i].clear();
    }
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}