#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

struct BIT
{
    int tre[N << 1];
    void init(int n)
    {
        memset(tre, 0, sizeof(tre[0]) * 4 * n);
    }
    void add(int pos, int val)
    {
        for (++pos; pos <= (N << 1); pos += (pos & (-pos)))
        {
            tre[pos - 1] += val;
        }
    }
    int get(int pos)
    {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
        {
            ret += tre[pos - 1];
        }
        return ret;
    }
} bit;

void run()
{
    int n;
    scanf("%d", &n);
    bit.init(n);
    ll ans = 0;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        ans += bit.get(n) - bit.get(v - 1);
        bit.add(v, 1);
    }
    printf("%lld\n", ans);
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