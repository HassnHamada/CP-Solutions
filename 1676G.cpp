#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e3 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
vector<int> tre[N];
char ccc[N];
int bbb[N];

int dfs(int n)
{
    int v = ccc[n] == 'W' ? 1 : -1;
    for (auto &&i : tre[n])
    {
        v += dfs(i);
    }
    return bbb[n] = v;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        tre[i].clear();
    }
    for (int i = 1, v; i < n; i++)
    {
        scanf("%d", &v);
        tre[v - 1].push_back(i);
    }
    scanf("%s", ccc);
    memset(bbb, 0, sizeof(bbb[0]) * n);
    dfs(0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (int)(bbb[i] == 0);
        // cout << bbb[i] << " ";
    }
    // cout << endl;
    printf("%d\n", ans);
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