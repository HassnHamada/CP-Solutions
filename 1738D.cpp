#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

int K(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] < i)
        {
            return i - 1;
        }
    }
    return n;
}

vector<int> tre[N];
int ans[N];
bool vis[N];

void dfs(int n, int &sz)
{
    for (auto &&i : tre[n])
    {
        assert(vis[i]);
        vis[i] = false;
    }
    for (auto &&i : tre[n])
    {
        if (tre[i].empty())
        {
            ans[sz++] = i;
        }
    }
    for (auto &&i : tre[n])
    {
        if (tre[i].empty())
        {
            continue;
        }
        ans[sz++] = i;
        dfs(i, sz);
    }
}

int B(int sz, int k, int n)
{
    int ret = n + 1;
    for (int i = 0; i < sz; i++)
    {
        if (ans[i] > k)
        {
            ret = ans[i];
        }
    }
    return ret;
}

int S(int sz, int k)
{
    int ret = 0;
    for (int i = 0; i < sz; i++)
    {
        if (ans[i] <= k)
        {
            ret = ans[i];
        }
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    int k = K(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0 && j <= n; j = arr[j])
        {
            if (vis[j])
            {
                break;
            }
            vis[j] = true;
            tre[arr[j]].push_back(j);
        }
    }
    int sz = 0;
    dfs(0, sz);
    dfs(n + 1, sz);
    assert(sz == n);
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
    for (int i = 0; i <= n + 1; i++)
    {
        tre[i].clear();
    }
    // for (int i = 0; i < n; i++)
    // {
    //     assert(arr[ans[i]] == (ans[i] <= k ? B(i, k, n) : S(i, k)));
    // }
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
