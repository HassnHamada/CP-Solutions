#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 6, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int nxtn[N], nxtm[N];
bool nnnv[N];
int n, m;
struct DT
{
    int v, l, r;
    void init(int _v)
    {
        v = _v;
        for (int i = 0; i < 3; i++)
        {
            r += _v % 10;
            _v /= 10;
        }
        for (int i = 0; i < 3; i++)
        {
            l += _v % 10;
            _v /= 10;
        }
        assert(_v == 0);
    }
} nnn[N], mmm[N];

bool canCon(int ii)
{
    if (nnnv[ii])
    {
        return false;
    }
    nnnv[ii] = true;
    for (int j = 0; j < m; j++)
    {
        if ((nnn[ii].l == mmm[j].r || nnn[ii].r == mmm[j].l) && (nxtm[j] == -1 || canCon(nxtm[j])))
        {
            nxtm[j] = ii;
            nxtn[ii] = j;
            return true;
        }
    }
    return false;
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        nnn[i].init(v);
    }
    for (int i = 0, v; i < m; i++)
    {
        scanf("%d", &v);
        mmm[i].init(v);
    }
    memset(nxtn, -1, sizeof(nxtn[0]) * n);
    memset(nxtm, -1, sizeof(nxtm[0]) * m);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        memset(nnnv, 0, sizeof(nnnv[0]) * n);
        if (nxtn[i] == -1 && canCon(i))
        {
            ans.push_back(i);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto &&i : ans)
    {
        assert(nxtn[i] != -1);
        if (nnn[i].l == mmm[nxtn[i]].r)
        {
            printf("AT %d %d\n", nnn[i].v, mmm[nxtn[i]].v);
        }
        else
        {
            assert(nnn[i].r == mmm[nxtn[i]].l);
            printf("TA %d %d\n", mmm[nxtn[i]].v, nnn[i].v);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}