#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, sz[N];
vector<int> tre[N];

int calcSz(int c, int p = 0)
{
    sz[c] = 1;
    for (int i = 0; i < (int)(tre[c].size()); i++)
    {
        if (tre[c][i] == p)
        {
            swap(tre[c][i], tre[c][tre[c].size() - 1]);
            tre[c].pop_back();
            i -= 1;
            continue;
        }
        sz[c] += calcSz(tre[c][i], c);
    }
    return sz[c];
}

int ans(int c, int p = 0)
{
    if (tre[c].size() == 0)
    {
        return 0;
    }
    else if (tre[c].size() == 1)
    {
        return sz[tre[c][0]] - 1;
    }
    return max(sz[tre[c][0]] - 1 + ans(tre[c][1]),
               sz[tre[c][1]] - 1 + ans(tre[c][0]));
}

void run()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        tre[i].clear();
    }
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    calcSz(1);
    printf("%d\n", ans(1));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
