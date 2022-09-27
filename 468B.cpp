#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
pair<int, int> arr[N];
int nxt[N], vis[N], ans[N], vid = 1;

bool canCon(int ii)
{
    if (vis[ii] == vid)
    {
        return false;
    }
    vis[ii] = vid;
    for (auto &&i : grf[ii])
    {
        if (nxt[i] == -1 || canCon(nxt[i]))
        {
            nxt[ii] = i;
            nxt[i] = ii;
            return true;
        }
    }
    return false;
}

void run()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int u = a - arr[i].first, v = b - arr[i].first;
        int it_u = lower_bound(arr, arr + n, make_pair(u, 0)) - arr,
            it_v = lower_bound(arr, arr + n, make_pair(v, 0)) - arr;
        if (it_u < n && arr[it_u].first == u)
        {
            grf[i].push_back(it_u);
        }
        if (it_v < n && arr[it_v].first == v)
        {
            grf[i].push_back(it_v);
        }
    }
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < n; i++)
    {
        if (nxt[i] == -1)
        {
            for (auto &&j : grf[i])
            {   
                if (nxt[j] == -1)
                {
                    nxt[i] = j;
                    nxt[j] = i;
                    break;
                }
            }
        }
    }
    bool ok = true;
    for (int i = 0; ok && i < n; i++, vid++)
    {
        if (nxt[i] == -1 && canCon(i))
        {
            // pass
        }
        ok = nxt[i] != -1;
    }
    if (ok)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            assert(nxt[nxt[i]] == i);
            if (nxt[i] < i)
            {
                continue;
            }
            if (arr[nxt[i]].first + arr[i].first == a)
            {
                ans[arr[nxt[i]].second] = ans[arr[i].second] = 0;
            }
            else if (arr[nxt[i]].first + arr[i].first == b)
            {
                ans[arr[nxt[i]].second] = ans[arr[i].second] = 1;
            }
            else
            {
                assert(false);
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
    }
    else
    {
        printf("NO\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}