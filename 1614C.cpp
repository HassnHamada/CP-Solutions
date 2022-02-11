#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10, MOD = 1e9 + 7;
int ans[N], to[N];
set<int> emp;
// pair<int, int> arr[N];
struct inp
{
    int l, r, v;
    bool operator<(inp &other)
    {
        int rl1 = this->r - this->l,
            rl2 = other.r - other.l;
        if (rl1 == rl2)
        {
            return this->l < other.l;
        }
        return rl1 < rl2;
    }
} arr[N];

struct BIT
{
    int tre[N << 1];
    void init()
    {
        memset(tre, 0, sizeof(tre));
    }
    void add(int pos, int val)
    {
        for (++pos; pos <= (N << 1); pos += (pos & (-pos)))
        {
            tre[pos - 1] ^= val;
        }
    }
    int get(int pos)
    {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
        {
            ret ^= tre[pos - 1];
        }
        return ret;
    }
} bit;

void add(int l, int r, int v)
{
    v ^= bit.get(r) ^ bit.get(l - 1);
    if (v)
    {
        int i = *emp.lower_bound(l);
        // assert(i <= r);
        ans[i] = v;
        bit.add(i, v);
    }
    for (int i = l; i <= r; i++)
    {
        emp.erase(i);
    }
}

int xorSum(int n)
{
    int bits = 0;
    for (int i = 1; i <= n; i++)
    {
        bits |= ans[i];
    }
    return 1ll * bits * to[n - 1] % MOD;
}
void run()
{
    int n, m;
    cin >> n >> m;
    bit.init();
    emp.clear();
    for (int i = 1; i <= n; i++)
    {
        emp.insert(i);
    }
    memset(ans, 0, sizeof(int) * n);

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].l >> arr[i].r >> arr[i].v;
    }
    sort(arr, arr + m);
    for (int i = 0; i < m; i++)
    {
        // cout << arr[i].l << " " << arr[i].r << " " << arr[i].v << endl;
        add(arr[i].l, arr[i].r, arr[i].v);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ans[i] << " \n"[i == n];
    // }
    cout << xorSum(n) << endl;
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    to[0] = 1;
    for (int i = 1; i < N; i++)
    {
        to[i] = 2ll * to[i - 1] % MOD;
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}