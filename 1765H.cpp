#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N], ans[N];
bitset<N> in;
vector<int> pre_req[N];

bool solve(int n, int sz)
{
    if (n == sz)
    {
        return true;
    }
    bool ret = false;
    for (int i = 0; i < sz; i++)
    {
        if (in[i])
        {
            continue;
        }
        bool ok = n < arr[i];
        for (auto &&j : pre_req[i])
        {
            ok = ok & in[j];
        }
        if (ok)
        {
            in[i] = 1;
            if (solve(n + 1, sz))
            {
                ans[i] = min(ans[i], n);
                ret = true;
            }
            in[i] = 0;
        }
    }
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0, a, b; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        pre_req[--b].push_back(--a);
    }
    memset(ans, 0x3f, sizeof(ans));
    solve(0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}