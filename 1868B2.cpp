#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <vector>
#include <utility>
#include <assert.h>
#include <set>
#include <map>
#include <stack>
#include <bitset>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, EMP = -1;

map<int, set<int>> grf;
int arr[N], ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (low[c] == ids[c])
    {
        cyc[c] = cid++;
        while (true)
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            cyc[t] = cyc[c];
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
}

void tarjan(int n)
{
    for (int i = 0; i < n; i++)
    {
        ids[i] = EMP;
    }
    for (int i = 0; i < n; i++)
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
    }
    assert(stk.empty());
}

void run()
{
    int n;
    scanf("%d", &n);
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        tot += arr[i];
    }
    bool ok = tot % n == 0;
    if (ok)
    {
        int tar = tot / n;
        map<int, vector<int>> out, in;
        for (int i = 0; ok && i < n; i++)
        {
            if (arr[i] == tar)
            {
                out[i].push_back(-1);
                in[-1].push_back(i);
                // printf("-1 -1\n");
                continue;
            }
            for (int j = 0; j <= 30; j++)
            {
                int x = j ? 1 << (j - 1) : j;
                int y = arr[i] + x - tar;
                if (y == 0 || (y > 0 && __builtin_popcount(y) == 1))
                {
                    out[i].push_back(y);
                    in[x].push_back(i);
                    // printf("%d %d\n", x, y);
                }
            }
            ok = !out[i].empty();
            // printf("---\n");
        }
        // for (auto &&i : out)
        // {

        // }

        if (ok)
        {
            for (auto &&i : out)
            {
                for (auto &&j : i.second)
                {
                    if (j == -1)
                    {
                        // grf[i.first].insert(-1);
                        // grf[-1].insert(i.first);
                        continue;
                    }
                    for (auto &&k : in[j])
                    {
                        grf[i.first].insert(k);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                grf[-1].insert(i);
                grf[i].insert(-2);
            }
            for (auto &&i : in[-1])
            {
                grf[-2].insert(i);
                grf[i].insert(-1);

                // for (int j = 0; j < n; j++)
                // {
                //     grf[i].insert(j);
                //     grf[j].insert(i);
                // }
            }

            for (auto &&i : grf)
            {
                printf("%d\t\t", i.first);
                for (auto &&j : i.second)
                {
                    printf("%d ", j);
                }
                printf("\n");
            }

            tarjan(n);
            grf.clear();
            for (int i = 0; i < n; i++)
            {
                printf("%d ", cyc[i]);
                // ok = cyc[i - 1] == cyc[i];
            }
            printf("\n");
            for (int i = 1; ok && i < n; i++)
            {
                ok = cyc[i - 1] == cyc[i];
            }
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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