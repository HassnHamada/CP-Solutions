#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// int arr[N], ans[N];

struct BIT
{
    int arr[N], n;
    void init(int n)
    {
        this->n = n;
        this->clear();
    }
    void add(int i, int v)
    {
        for (i++; i <= n; i += (i & (-i)))
        {
            arr[i - 1] += v;
        }
    }
    int get(int i)
    {
        int ret = 0;
        for (i++; i; i -= (i & (-i)))
        {
            ret += arr[i - 1];
        }
        return ret;
    }
    void clear()
    {
        memset(arr, 0, sizeof(arr[0]) * n);
    }
} bit;

void run()
{
    int n, ans = 0;
    scanf("%d", &n);
    bit.init(n + 1);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (bit.get(n) - bit.get(v) == 0)
        {
            bit.add(v, 1);
        }
        else
        {
            ans += 1;
            bit.clear();
        }
    }
    printf("%d\n", ans);
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
