#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> tre[N];
int col[N];

void dfs(int c, int p)
{
    int nxt_col = 1;
    assert(col[c] != col[p]);
    for (auto &&i : tre[c])
    {
        if (i == p)
        {
            continue;
        }
        while (nxt_col == col[c] || nxt_col == col[p])
        {
            nxt_col++;
        }
        col[i] = nxt_col++;
        dfs(i, c);
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; i++)
    {
        scanf("%d%d", &u, &v);
        tre[u].push_back(v);
        tre[v].push_back(u);
    }
    dfs(col[1] = 1, 0);
    printf("%d\n", *max_element(col + 1, col + n + 1));
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", col[i], " \n"[i == n]);
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