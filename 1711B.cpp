#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
map<int, vector<int>> mmm;

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        mmm[u].push_back(v);
        mmm[v].push_back(u);
    }
    int ans = INF;
    if (m & 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int s = mmm[i].size();
            if (s & 1)
            {
                ans = min(ans, arr[i]);
            }
            else
            {
                for (auto &&j : mmm[i])
                {
                    int v = mmm[j].size();
                    if (v & 1)
                    {
                        continue;
                    }
                    ans = min(ans, arr[i] + arr[j]);
                }
            }
        }
    }
    else
    {
        ans = 0;
    }
    printf("%d\n", ans);
    mmm.clear();
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