#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1 << 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N >> 1];
int nxt[N], vis[N >> 1], vid;

bool canCon(int ii)
{
    assert(ii < (N >> 1));
    if (vis[ii] == vid)
    {
        return false;
    }
    vis[ii] = vid;
    for (auto &&i : grf[ii])
    {
        assert(i < N);
        if (nxt[i] == -1 || canCon(nxt[i]))
        {
            nxt[i] = ii;
            nxt[ii] = i;
            return true;
        }
    }
    return false;
}

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, a, b; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        grf[a].push_back(b ^ (1 << 9));
        // grf[b ^ (1 << 9)].push_back(a);
    }
    int ans = 0;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 1; i <= n; i++)
    {
        for (auto &&j : grf[i])
        {
            if (nxt[j] == -1)
            {
                nxt[j] = i;
                nxt[i] = j;
                ans++;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vid++;
        if (nxt[i] == -1 && canCon(i))
        {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        if (nxt[i] == -1)
        {
            continue;
        }
        assert(ans--);
        printf("%d %d\n", i, nxt[i] ^ (1 << 9));
    }
    assert(ans == 0);
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