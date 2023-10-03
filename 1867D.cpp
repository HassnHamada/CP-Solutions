#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <vector>
#include <stack>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, EMP = -1;

int arr[N], ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    if (ids[arr[c]] == EMP)
    {
        dfs(arr[c]);
    }
    if (onStk[arr[c]])
    {
        low[c] = min(low[c], low[arr[c]]);
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
    for (int i = 1; i <= n; i++)
    {
        ids[i] = EMP;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
    }
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        ok &= k == 1 ? arr[i] == i : arr[i] != i;
    }
    if (ok && k > 1)
    {
        tarjan(n);
        map<int, int> mmm;
        for (int i = 1; i <= n; i++)
        {
            mmm[cyc[i]] += 1;
        }
        for (auto &&i : mmm)
        {
            if (i.second == 1)
            {
                continue;
            }
            ok &= i.second == k;
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