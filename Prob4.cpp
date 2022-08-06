#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")

const int N = 1e6 + 10, M = 2, L = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Node
{
    int nxt[M];
    Node()
    {
        memset(nxt, -1, sizeof(nxt));
    }
    void clear()
    {
        memset(nxt, -1, sizeof(nxt));
    }
};

int arr[N], tem[N >> 1], sz;
Node tri[M << L];

void insert(int n)
{
    int v = 0;
    for (int i = L - 1; ~i; i--)
    {
        int c = (n >> i) & 1;
        if (tri[v].nxt[c] == -1)
        {
            tri[v].nxt[c] = sz;
            tri[sz++].clear();
        }
        v = tri[v].nxt[c];
    }
}

int getMx(int n)
{
    int v = 0, ret = 0;
    for (int i = L - 1; ~i; i--)
    {
        int c = ((n >> i) & 1 ? 0 : 1);
        if (tri[v].nxt[c] == -1)
        {
            c ^= 1;
            assert(tri[v].nxt[c] != -1);
        }
        ret |= ((((n >> i) & 1) ^ c) << i);
        v = tri[v].nxt[c];
    }
    return ret;
}

int getMn(int n)
{
    int v = 0, ret = 0;
    for (int i = L - 1; ~i; i--)
    {
        int c = ((n >> i) & 1);
        if (tri[v].nxt[c] == -1)
        {
            c ^= 1;
            assert(tri[v].nxt[c] != -1);
        }
        ret |= ((((n >> i) & 1) ^ c) << i);
        v = tri[v].nxt[c];
    }
    return ret;
}

pair<int, int> solve(int s)
{
    sz = 0;
    tri[sz++].clear();
    pair<int, int> ret = {0, INF};
    for (int i = 1; i < s; i++)
    {
        insert(tem[i - 1]);
        ret.first = max(ret.first, getMx(tem[i]));
        ret.second = min(ret.second, getMn(tem[i]));
    }
    return ret;
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n / 2; i++)
    {
        assert(2 * i + 1 < n);
        tem[i + 1] = arr[2 * i] ^ arr[2 * i + 1];
        tem[i + 1] ^= tem[i];
    }
    pair<int, int> a = solve(n / 2 + 1);
    for (int i = 0; i < n / 2 - 1 + (n & 1); i++)
    {
        assert(2 * i + 2 < n);
        tem[i + 1] = arr[2 * i + 1] ^ arr[2 * i + 2];
        tem[i + 1] ^= tem[i];
    }
    pair<int, int> b = solve(n / 2 + (n & 1));
    printf("%d %d\n", max(a.first, b.first), min(a.second, b.second));
    return 0;
}
