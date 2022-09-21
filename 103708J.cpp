#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

int nxtn[N], nxtm[N];
int vis[N], vid;
vector<int> grf[N];

bool canCon(int ii)
{
    if (vis[ii] == vid)
    {
        return false;
    }
    vis[ii] = vid;
    for (auto &&i : grf[ii])
    {
        if (nxtn[i] == -1 || canCon(nxtn[i]))
        {
            nxtn[i] = ii;
            nxtm[ii] = i;
            return true;
        }
    }
    return false;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, k; i < n; i++)
    {
        scanf("%d", &k);
        for (int j = 0, v; j < k; j++)
        {
            scanf("%d", &v);
            grf[v - 1].push_back(i);
        }
    }
    int ans = 0;
    memset(nxtn, -1, sizeof(nxtn[0]) * n);
    memset(nxtm, -1, sizeof(nxtm[0]) * m);
    for (int i = 0; i < m; i++)
    {
        for (auto &&j : grf[i])
        {
            if (nxtn[j] == -1)
            {
                nxtn[j] = i;
                nxtm[i] = j;
                ans += 1;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        vid += 1;
        if (nxtm[i] == -1 && canCon(i))
        {
            ans += 1;
        }
    }
    printf("%d", m - ans);
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